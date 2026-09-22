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
        fields(region, set(), {'assets', 'named_assets', 'binary_assets'}, version)
        for key in ('assets', 'named_assets', 'binary_assets'):
            if not isinstance(region.get(key, []), list):
                raise ValueError(f'{version}: {key} must be a list')
        rom = roms.get(version)
        limit = ROM_END if rom is None else min(ROM_END, ROM_BASE + len(rom))
        assets, spans = {}, []
        names = set()
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
            fields(asset, {'name', 'address', 'size', 'sha256', 'kind'}, {'unit'}, version + ' binary asset')
            name = identifier(asset['name'], version + ' binary asset')
            kind = asset['kind']
            if not isinstance(kind, str) or kind not in ('Sprite', 'AnimHeader', 'SongHeader', 'Tiles4bpp', 'Tilemap'):
                raise ValueError(f'{name}: unsupported binary asset kind')
            address, size = extent(asset['address'], asset['size'], limit, name)
            header, stride = {'Sprite': (2, 6), 'AnimHeader': (6, 4), 'SongHeader': (4, 4),
                              'Tiles4bpp': (0, 32), 'Tilemap': (0, 2)}[kind]
            unit = asset.get('unit')
            if unit is not None and (not isinstance(unit, str)
                                     or not re.fullmatch(r'[A-Za-z_][A-Za-z0-9_]*\.s', unit)):
                raise ValueError(f'{name}: binary definition owner must be an assembler filename')
            if kind in ('Tiles4bpp', 'Tilemap') and unit is None:
                raise ValueError(f'{name}: raw graphics require an object definition')
            alignment = 4 if kind == 'SongHeader' else 2
            if address % alignment or size < header or (size - header) % stride:
                raise ValueError(f'{name}: binary alignment or size disagrees with format')
            digest = asset['sha256']
            if not isinstance(digest, str) or not re.fullmatch(r'[0-9a-f]{64}', digest):
                raise ValueError(f'{name}: invalid binary SHA-256')
            if rom is not None:
                data = rom[address - ROM_BASE:address - ROM_BASE + size]
                if kind in ('Tiles4bpp', 'Tilemap'):
                    expected = size
                elif kind == 'SongHeader':
                    expected = 8 + data[0] * 4 if data[0] else 4
                else:
                    count = struct.unpack_from('<H', data, header - 2)[0]
                    expected = header + count * stride
                if size != expected:
                    raise ValueError(f'{name}: binary size differs from complete format extent')
                if hashlib.sha256(data).hexdigest() != digest:
                    raise ValueError(f'{name}: original binary ROM SHA-256 differs')
            item = {'name': name, 'address': address, 'size': size, 'kind': kind,
                    'sha256': digest, 'ctype': {'Sprite': 'u8', 'Tiles4bpp': 'u8',
                                              'Tilemap': 'u16'}.get(kind, kind),
                    'groups': ['binary_assets']}
            if unit is not None:
                item['unit'] = unit
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
        result['regions'][version] = {'assets': list(assets.values())}
    return result


def load_sidecar(path, roms=None):
    path = Path(path)
    document = json.loads(path.read_text()) if path.exists() else {'version': 1, 'regions': {}}
    return normalize_sidecar(document, roms)


def load_sidecars(directory, roms=None):
    combined = {'version': 1, 'provenance': {}, 'regions': {version: {
        'assets': [], 'named_assets': [], 'binary_assets': []} for version in VERSIONS}}
    for path in sorted(Path(directory).glob('*_data.json')):
        document = json.loads(path.read_text())
        normalize_sidecar(document, roms)
        for key, value in document.get('provenance', {}).items():
            combined['provenance'][path.name + ':' + key] = value
        for version, region in document['regions'].items():
            for key in ('assets', 'named_assets', 'binary_assets'):
                combined['regions'][version][key].extend(region.get(key, []))
    return normalize_sidecar(combined, roms)


def managed_asset_names(document):
    return {asset['name'] for plan in document['regions'].values() for asset in plan['assets']}


def asset_symbols(plan, ledger=()):
    existing = dict(ledger)
    collisions = {asset['name'] for asset in plan['assets']} & existing.keys()
    if collisions:
        raise ValueError('regional data collides with symbols.txt: ' + ', '.join(sorted(collisions)))
    return [(asset['name'], asset['address']) for asset in plan['assets'] if 'unit' not in asset]


def read_layout(path, prefix='arm-none-eabi-'):
    output = subprocess.check_output([prefix + 'objdump', '-h', '-t', str(path)], text=True)
    sections, symbols = {}, []
    for line in output.splitlines():
        match = re.match(r'\s*\d+\s+(\S+)\s+([0-9a-fA-F]+)\s+([0-9a-fA-F]+)\s', line)
        if match:
            sections[match[1]] = {'size': int(match[2], 16), 'value': int(match[3], 16)}
            alignment = re.search(r'2\*\*(\d+)\s*$', line)
            if alignment:
                sections[match[1]]['alignment'] = 1 << int(alignment[1])
        match = re.fullmatch(r'([0-9a-fA-F]+) (.{7})\s+(\S+)\s+([0-9a-fA-F]+)\s+(\S+)', line)
        if match and match[3] != '*UND*':
            symbols.append({'name': match[5], 'value': int(match[1], 16), 'size': int(match[4], 16),
                            'section': match[3], 'flags': match[2]})
    return {'sections': sections, 'symbols': symbols}


def check_layout(plan, objects, linked):
    errors, final = [], {}
    for symbol in linked['symbols']:
        final.setdefault(symbol['name'], []).append(symbol)
    asset_names = {asset['name'] for asset in plan['assets'] if 'unit' not in asset}
    for unit, layout in objects.items():
        for symbol in layout['symbols']:
            if symbol['name'] in asset_names and 'g' in symbol['flags']:
                errors.append(f'{unit}: asset binding shadows a compiled definition of {symbol["name"]}')
    for asset in plan['assets']:
        definitions = final.get(asset['name'], [])
        if 'unit' in asset:
            owned = objects.get(asset['unit'], {}).get('symbols', [])
            owned = [symbol for symbol in owned if symbol['name'] == asset['name']]
            if (len(owned) != 1 or owned[0]['size'] != asset['size']
                    or 'O' not in owned[0]['flags'] or owned[0]['section'] != '.rodata'
                    or len(definitions) != 1 or definitions[0]['value'] != asset['address']
                    or definitions[0]['size'] != asset['size'] or 'O' not in definitions[0]['flags']
                    or definitions[0]['section'] == '*ABS*'):
                errors.append(f'{asset["name"]}: asset object address, size or owner differs')
        elif len(definitions) != 1 or definitions[0]['value'] != asset['address'] or definitions[0]['section'] != '*ABS*':
            errors.append(f'{asset["name"]}: asset binding is missing or differs from its regional address')
    return errors


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('version', choices=VERSIONS)
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parent.parent)
    parser.add_argument('--manifest', type=Path)
    parser.add_argument('--binutils-prefix', default='arm-none-eabi-')
    parser.add_argument('--rom', type=Path)
    args = parser.parse_args()
    root, version = args.root, args.version
    paths = [root / args.manifest] if args.manifest else sorted((root / 'config').glob('*_data.json'))
    if not any(path.exists() for path in paths):
        print(f'{version}: no regional data contracts')
        return
    roms = {version: args.rom.read_bytes()} if args.rom else {}
    document = (load_sidecar(root / args.manifest, roms) if args.manifest
                else load_sidecars(root / 'config', roms))
    plan = document['regions'][version]
    if not plan['assets']:
        print(f'{version}: no regional data contracts')
        return
    ledger = []
    for line in (root / 'config' / version / 'symbols.txt').read_text().splitlines():
        line = line.split('#', 1)[0].strip()
        if line:
            name, address = line.split('=')
            ledger.append((name.strip(), int(address.strip(), 16)))
    asset_symbols(plan, ledger)
    listed = set()
    for line in (root / 'config' / version / 'units.txt').read_text().splitlines():
        line = line.split('#', 1)[0].strip()
        if line:
            listed.add(line.split()[0])
    units = {unit for unit in listed if unit.endswith('.c')}
    build = root / 'build' / version
    objects = {unit: read_layout(build / 'src' / (Path(unit).stem + '.o'), args.binutils_prefix) for unit in sorted(units)}
    for unit in {asset['unit'] for asset in plan['assets'] if 'unit' in asset}:
        if unit not in listed:
            raise ValueError(f'{unit}: asset definition owner is not active')
        objects[unit] = read_layout(build / 'asm' / (Path(unit).stem + '.o'), args.binutils_prefix)
    linked = read_layout(build / f'com_{version}.elf', args.binutils_prefix)
    errors = check_layout(plan, objects, linked)
    for error in errors:
        print(f'{version}: {error}')
    if errors:
        raise SystemExit(1)
    binary_count = sum('kind' in asset for asset in plan['assets'])
    label = f'{len(plan["assets"]) - binary_count} literals'
    if binary_count:
        label += f', {binary_count} binary bindings'
    print(f'{version}: regional data OK ({label})')


if __name__ == '__main__':
    main()
