import argparse
import hashlib
import json
import re
import struct
import subprocess
from pathlib import Path

from rom_data_evidence import ROM_BASE, ROM_END, number


VERSIONS = {'us': 'B8CE', 'jp': 'B8CJ', 'eu': 'B8CP'}
ENCODINGS = {'utf16le': ('u16', 2), 'shift_jis': ('u8', 1),
             'singlebyte': ('u8', 1), 'ascii': ('u8', 1)}
IDENTIFIER = re.compile(r'[A-Za-z_][A-Za-z0-9_]*')
UNIT = re.compile(r'[A-Za-z_][A-Za-z0-9_]*\.c')
SECTION = re.compile(r'\.(?:data|rodata)(?:[._][A-Za-z0-9_]+)*')


def fields(value, required, optional, label):
    if not isinstance(value, dict) or not required <= set(value) <= required | optional:
        raise ValueError(f'{label}: invalid fields, requires {sorted(required)}')


def identifier(value, label):
    if not isinstance(value, str) or not IDENTIFIER.fullmatch(value):
        raise ValueError(f'{label}: invalid C identifier')
    return value


def extent(address, size, limit, label):
    address = number(address, label + ' address')
    size = number(size, label + ' size')
    if not size or address < ROM_BASE or address + size > limit:
        raise ValueError(f'{label}: extent is outside ROM or empty')
    return address, size


def disjoint(spans, label):
    ordered = sorted(spans)
    for left, right in zip(ordered, ordered[1:]):
        if left[1] > right[0]:
            raise ValueError(f'{label}: overlapping {left[2]} and {right[2]}')


def normalize_sidecar(document, roms=None):
    fields(document, {'version', 'regions'}, {'provenance'}, 'regional data sidecar')
    if type(document['version']) is not int or document['version'] != 1:
        raise ValueError('unsupported regional data sidecar version')
    provenance = document.get('provenance', {})
    if not isinstance(provenance, dict) or any(not isinstance(key, str) or not key.strip()
                                              or not isinstance(value, str) or not value.strip()
                                              for key, value in provenance.items()):
        raise ValueError('regional data provenance must contain nonempty explanatory strings')
    regions = document['regions']
    if not isinstance(regions, dict) or not set(regions) <= set(VERSIONS):
        raise ValueError('regional data regions must be US, JP and/or EU')
    roms = {} if roms is None else roms
    result = {'version': 1, 'provenance': dict(provenance), 'regions': {}}
    for version in VERSIONS:
        region = regions.get(version, {})
        fields(region, set(), {'placements', 'assets', 'named_assets', 'binary_assets'}, version)
        for key in ('placements', 'assets', 'named_assets', 'binary_assets'):
            if not isinstance(region.get(key, []), list):
                raise ValueError(f'{version}: {key} must be a list')
        rom = roms.get(version)
        limit = ROM_END if rom is None else min(ROM_END, ROM_BASE + len(rom))
        placements, assets, spans = [], {}, []
        owners, names = set(), set()
        for placement in region.get('placements', []):
            fields(placement, {'unit', 'section', 'address', 'size', 'objects'},
                   {'sha256'}, version + ' placement')
            unit, section = placement['unit'], placement['section']
            if not isinstance(unit, str) or not UNIT.fullmatch(unit):
                raise ValueError(f'{version}: placement unit must be a C filename')
            if not isinstance(section, str) or not SECTION.fullmatch(section):
                raise ValueError(f'{unit}: placement requires a ROM data section')
            key = unit, section
            label = f'{version}: {unit}({section})'
            if key in owners:
                raise ValueError(f'{label}: duplicate placement')
            owners.add(key)
            address, size = extent(placement['address'], placement['size'], limit, label)
            digest = placement.get('sha256')
            if digest is not None:
                if not isinstance(digest, str) or not re.fullmatch(r'[0-9a-f]{64}', digest):
                    raise ValueError(f'{label}: invalid SHA-256')
                if rom is not None and hashlib.sha256(rom[address - ROM_BASE:address - ROM_BASE + size]).hexdigest() != digest:
                    raise ValueError(f'{label}: original ROM SHA-256 differs')
            objects = placement['objects']
            if not isinstance(objects, list) or not objects:
                raise ValueError(f'{label}: objects must be a nonempty list')
            normalized, occupied = [], []
            for obj in objects:
                fields(obj, {'name', 'offset', 'size'}, {'consumer'}, label + ' object')
                name = identifier(obj['name'], label)
                offset, length = number(obj['offset'], name + ' offset'), number(obj['size'], name + ' size')
                if name in names:
                    raise ValueError(f'{version}: duplicate object name {name}')
                if not length or offset + length > size:
                    raise ValueError(f'{name}: object is outside its placement or empty')
                names.add(name)
                item = {'name': name, 'offset': offset, 'size': length}
                if 'consumer' in obj:
                    consumer = obj['consumer']
                    if (not isinstance(consumer, list) or not consumer
                            or not isinstance(consumer[0], str) or not IDENTIFIER.fullmatch(consumer[0])
                            or any(not (type(index) is int and index >= 0)
                                   and not (isinstance(index, str) and index.strip()) for index in consumer[1:])):
                        raise ValueError(f'{name}: consumer must identify a symbol and indices or explanatory text')
                    item['consumer'] = list(consumer)
                normalized.append(item)
                occupied.append((offset, offset + length, name))
            disjoint(occupied, label + ' objects')
            item = {'unit': unit, 'section': section, 'address': address, 'size': size,
                    'objects': normalized}
            if digest is not None:
                item['sha256'] = digest
            placements.append(item)
            spans.append((address, address + size, unit + '(' + section + ')'))

        def add_asset(name, address, size, encoding, group):
            identifier(name, version + ' asset')
            if not isinstance(encoding, str) or encoding not in ENCODINGS:
                raise ValueError(f'{name}: unsupported literal encoding')
            address, size = extent(address, size, limit, name)
            ctype, width = ENCODINGS[encoding]
            if address % width or size % width:
                raise ValueError(f'{name}: literal alignment or size disagrees with encoding')
            item = {'name': name, 'address': address, 'size': size, 'encoding': encoding,
                    'ctype': ctype, 'groups': [group]}
            previous = assets.get(address)
            if previous is not None:
                if any(previous[key] != item[key] for key in ('name', 'size', 'encoding')):
                    raise ValueError(f'{name}: conflicting duplicate literal address')
                if group not in previous['groups']:
                    previous['groups'].append(group)
                return
            if name in names:
                raise ValueError(f'{version}: colliding object or asset name {name}')
            names.add(name)
            if rom is not None:
                data = rom[address - ROM_BASE:address - ROM_BASE + size]
                chunks = [data[offset:offset + width] for offset in range(0, size, width)]
                if chunks[-1] != bytes(width) or bytes(width) in chunks[:-1]:
                    raise ValueError(f'{name}: literal size must end at its first terminator')
                if encoding == 'ascii' and any(value >= 128 for value in data):
                    raise ValueError(f'{name}: non-ASCII byte in ASCII literal')
            assets[address] = item
            spans.append((address, address + size, name))

        for group in region.get('assets', []):
            fields(group, {'encoding', 'symbol_prefix', 'literals'}, {'group'}, version + ' asset group')
            if not isinstance(group['encoding'], str) or group['encoding'] not in ENCODINGS:
                raise ValueError(f'{version}: unsupported literal encoding')
            prefix = identifier(group['symbol_prefix'], version + ' symbol prefix')
            label = group.get('group', prefix)
            if not isinstance(label, str) or not label.strip() or not isinstance(group['literals'], list):
                raise ValueError(f'{version}: invalid asset group or literals')
            for literal in group['literals']:
                if not isinstance(literal, list) or len(literal) != 2:
                    raise ValueError(f'{version}: each literal requires address and size')
                address = number(literal[0], label + ' literal address')
                add_asset(f'{prefix}{address:08X}', address, literal[1], group['encoding'], label)
        for asset in region.get('named_assets', []):
            fields(asset, {'name', 'address', 'size', 'encoding'}, set(), version + ' named asset')
            add_asset(asset['name'], asset['address'], asset['size'], asset['encoding'], 'named_assets')
        for asset in region.get('binary_assets', []):
            fields(asset, {'name', 'address', 'size', 'sha256', 'kind'}, set(), version + ' binary asset')
            name = identifier(asset['name'], version + ' binary asset')
            kind = asset['kind']
            if not isinstance(kind, str) or kind not in ('Sprite', 'AnimHeader', 'SongHeader'):
                raise ValueError(f'{name}: unsupported binary asset kind')
            address, size = extent(asset['address'], asset['size'], limit, name)
            header, stride = {'Sprite': (2, 6), 'AnimHeader': (6, 4), 'SongHeader': (4, 4)}[kind]
            alignment = 4 if kind == 'SongHeader' else 2
            if address % alignment or size < header or (size - header) % stride:
                raise ValueError(f'{name}: binary alignment or size disagrees with format')
            digest = asset['sha256']
            if not isinstance(digest, str) or not re.fullmatch(r'[0-9a-f]{64}', digest):
                raise ValueError(f'{name}: invalid binary SHA-256')
            if rom is not None:
                data = rom[address - ROM_BASE:address - ROM_BASE + size]
                if kind == 'SongHeader':
                    expected = 8 + data[0] * 4 if data[0] else 4
                else:
                    count = struct.unpack_from('<H', data, header - 2)[0]
                    expected = header + count * stride
                if size != expected:
                    raise ValueError(f'{name}: binary size differs from complete format extent')
                if hashlib.sha256(data).hexdigest() != digest:
                    raise ValueError(f'{name}: original binary ROM SHA-256 differs')
            item = {'name': name, 'address': address, 'size': size, 'kind': kind,
                    'sha256': digest, 'ctype': 'u8' if kind == 'Sprite' else kind,
                    'groups': ['binary_assets']}
            previous = assets.get(address)
            if previous is not None:
                if previous != item:
                    raise ValueError(f'{name}: conflicting duplicate binary address')
                continue
            if name in names:
                raise ValueError(f'{version}: colliding object or asset name {name}')
            names.add(name)
            assets[address] = item
            spans.append((address, address + size, name))
        disjoint(spans, version + ' ROM data')
        result['regions'][version] = {'placements': placements, 'assets': list(assets.values())}
    return result


def load_sidecar(path, roms=None):
    path = Path(path)
    document = json.loads(path.read_text()) if path.exists() else {'version': 1, 'regions': {}}
    return normalize_sidecar(document, roms)


def load_sidecars(directory, roms=None):
    combined = {'version': 1, 'provenance': {}, 'regions': {version: {
        'placements': [], 'assets': [], 'named_assets': [], 'binary_assets': []} for version in VERSIONS}}
    for path in sorted(Path(directory).glob('*_data.json')):
        document = json.loads(path.read_text())
        normalize_sidecar(document, roms)
        for key, value in document.get('provenance', {}).items():
            combined['provenance'][path.name + ':' + key] = value
        for version, region in document['regions'].items():
            for key in ('placements', 'assets', 'named_assets', 'binary_assets'):
                combined['regions'][version][key].extend(region.get(key, []))
    return normalize_sidecar(combined, roms)


def managed_placements(document):
    return set().union(*(placement_overrides(plan) for plan in document['regions'].values()))


def managed_asset_names(document):
    return {asset['name'] for plan in document['regions'].values() for asset in plan['assets']}


def asset_symbols(plan, ledger=()):
    existing = dict(ledger)
    owned = {obj['name'] for placement in plan['placements'] for obj in placement['objects']}
    collisions = (owned | {asset['name'] for asset in plan['assets']}) & existing.keys()
    if collisions:
        raise ValueError('regional data collides with symbols.txt: ' + ', '.join(sorted(collisions)))
    return [(asset['name'], asset['address']) for asset in plan['assets']]


def placement_overrides(plan):
    return {(placement['unit'], placement['section']): (placement['address'], placement['size'])
            for placement in plan['placements']}


def merge_placements(base, plan, code_end=ROM_BASE, rom_end=ROM_END, managed=()):
    if not plan['placements'] and not managed:
        return list(base)
    replacements = placement_overrides(plan)
    result, seen = [], set()
    for address, size, line in base:
        match = re.fullmatch(r'\s*([^()]+)\(([^()]+)\)\s*', line)
        if match is None:
            raise ValueError(f'invalid C data placement line {line!r}')
        key = match[1], match[2]
        if key in seen:
            raise ValueError(f'duplicate C data placement {line}')
        seen.add(key)
        if key in managed and key not in replacements:
            continue
        if key in replacements:
            address, size = replacements[key]
        result.append((address, size, line))
    for (unit, section), (address, size) in replacements.items():
        if (unit, section) not in seen:
            result.append((address, size, f'{unit}({section})'))
    spans = []
    for address, size, line in result:
        if type(address) is not int or type(size) is not int or size < 0 or address < code_end or address + size > rom_end:
            raise ValueError(f'{line}: placement is outside post-code ROM data')
        if size:
            spans.append((address, address + size, line))
    disjoint(spans, 'merged C data')
    return sorted(result)


def validate_active_sections(plan, active, managed=()):
    expected = set(placement_overrides(plan))
    active = list(active)
    missing = expected - set(active)
    absent = (set(active) & set(managed)) - expected
    duplicated = {key for key in expected if active.count(key) > 1}
    if missing or absent or duplicated:
        raise ValueError(f'regional data active sections differ: missing={sorted(missing)}, '
                         f'absent={sorted(absent)}, duplicate={sorted(duplicated)}')


def linker_assertions(placement, after=False):
    label = placement['unit'] + '(' + placement['section'] + ')'
    address = placement['address'] + (placement['size'] if after else 0)
    edge = 'end' if after else 'start'
    result = [f'ASSERT(ABSOLUTE(.) == {address:#010x}, "regional data {edge}: {label}");']
    if after:
        for obj in placement['objects']:
            name = obj['name']
            address = placement['address'] + obj['offset']
            result.append(f'ASSERT(ABSOLUTE({name}) == {address:#010x}, "regional data object: {name}");')
    return result


def read_layout(path, prefix='arm-none-eabi-'):
    output = subprocess.check_output([prefix + 'objdump', '-h', '-t', str(path)], text=True)
    sections, symbols = {}, []
    for line in output.splitlines():
        match = re.match(r'\s*\d+\s+(\S+)\s+([0-9a-fA-F]+)\s+([0-9a-fA-F]+)\s', line)
        if match:
            sections[match[1]] = {'size': int(match[2], 16), 'value': int(match[3], 16)}
        match = re.fullmatch(r'([0-9a-fA-F]+) (.{7})\s+(\S+)\s+([0-9a-fA-F]+)\s+(\S+)', line)
        if match and match[3] != '*UND*':
            symbols.append({'name': match[5], 'value': int(match[1], 16), 'size': int(match[4], 16),
                            'section': match[3], 'flags': match[2]})
    return {'sections': sections, 'symbols': symbols}


def check_layout(plan, objects, linked):
    errors, final = [], {}
    for symbol in linked['symbols']:
        final.setdefault(symbol['name'], []).append(symbol)
    asset_names = {asset['name'] for asset in plan['assets']}
    for unit, layout in objects.items():
        for symbol in layout['symbols']:
            if symbol['name'] in asset_names and 'g' in symbol['flags']:
                errors.append(f'{unit}: asset binding shadows a compiled definition of {symbol["name"]}')
    for placement in plan['placements']:
        unit, section = placement['unit'], placement['section']
        label = unit + '(' + section + ')'
        layout = objects.get(unit)
        if layout is None:
            errors.append(f'{label}: placement owner is not active')
            continue
        actual_section = layout['sections'].get(section)
        if actual_section is None or actual_section['size'] != placement['size']:
            errors.append(f'{label}: compiled section size differs from placement')
        actual = {}
        for symbol in layout['symbols']:
            if symbol['section'] == section and 'O' in symbol['flags'] and symbol['size']:
                actual.setdefault(symbol['name'], []).append(symbol)
        expected = {obj['name'] for obj in placement['objects']}
        if set(actual) != expected:
            errors.append(f'{label}: compiled object set differs from placement')
        for obj in placement['objects']:
            name, offset, size = obj['name'], obj['offset'], obj['size']
            definitions = actual.get(name, [])
            if len(definitions) != 1 or definitions[0]['value'] != offset or definitions[0]['size'] != size:
                errors.append(f'{label}: {name} compiled offset or size differs from placement')
            definitions = final.get(name, [])
            if (len(definitions) != 1 or definitions[0]['value'] != placement['address'] + offset
                    or definitions[0]['size'] != size or 'O' not in definitions[0]['flags']
                    or definitions[0]['section'] == '*ABS*'):
                errors.append(f'{label}: {name} linked address or size differs from placement')
    for asset in plan['assets']:
        definitions = final.get(asset['name'], [])
        if len(definitions) != 1 or definitions[0]['value'] != asset['address'] or definitions[0]['section'] != '*ABS*':
            errors.append(f'{asset["name"]}: asset binding is missing or differs from its regional address')
    return errors


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('version', choices=VERSIONS)
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parent.parent)
    parser.add_argument('--manifest', type=Path)
    parser.add_argument('--binutils-prefix', default='arm-none-eabi-')
    args = parser.parse_args()
    root, version = args.root, args.version
    paths = [root / args.manifest] if args.manifest else sorted((root / 'config').glob('*_data.json'))
    if not any(path.exists() for path in paths):
        print(f'{version}: no regional data contracts')
        return
    rom = (root / 'roms' / (VERSIONS[version] + '.gba')).read_bytes()
    document = (load_sidecar(root / args.manifest, {version: rom}) if args.manifest
                else load_sidecars(root / 'config', {version: rom}))
    plan = document['regions'][version]
    if not plan['placements'] and not plan['assets']:
        print(f'{version}: no regional data contracts')
        return
    ledger = []
    for line in (root / 'config' / version / 'symbols.txt').read_text().splitlines():
        line = line.split('#', 1)[0].strip()
        if line:
            name, address = line.split('=')
            ledger.append((name.strip(), int(address.strip(), 16)))
    asset_symbols(plan, ledger)
    units = set()
    active = []
    for line in (root / 'config' / version / 'units.txt').read_text().splitlines():
        line = line.split('#', 1)[0].strip()
        if not line:
            continue
        match = re.fullmatch(r'([^()\s]+)(?:\(([^()]+)\))?(?:\s+.*)?', line)
        if match and match[1].endswith('.c'):
            units.add(match[1])
            active.append((match[1], match[2] or '.text'))
    validate_active_sections(plan, active, managed_placements(document))
    build = root / 'build' / version
    objects = {unit: read_layout(build / 'src' / (Path(unit).stem + '.o'), args.binutils_prefix) for unit in sorted(units)}
    linked = read_layout(build / f'com_{version}.elf', args.binutils_prefix)
    errors = check_layout(plan, objects, linked)
    for error in errors:
        print(f'{version}: {error}')
    if errors:
        raise SystemExit(1)
    count = sum(len(placement['objects']) for placement in plan['placements'])
    binary_count = sum('kind' in asset for asset in plan['assets'])
    label = f'{len(plan["assets"]) - binary_count} literals'
    if binary_count:
        label += f', {binary_count} binary bindings'
    print(f'{version}: regional data OK ({len(plan["placements"])} sections, {count} objects, {label})')


if __name__ == '__main__':
    main()
