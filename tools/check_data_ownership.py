import argparse
import ast
import json
import re
import subprocess
from collections import defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent


def active_objects(root, version):
    result = set()
    for line in (root / 'config' / version / 'units.txt').read_text().splitlines():
        line = line.split('#', 1)[0].strip()
        if not line:
            continue
        name = line.split()[0].split('(', 1)[0]
        if name.endswith('.c'):
            result.add('src/' + Path(name).stem + '.o')
    return sorted(result)


def read_symbols(path, prefix):
    output = subprocess.check_output([prefix + 'nm', '-S', '--defined-only', str(path)], text=True)
    result = []
    for line in output.splitlines():
        match = re.fullmatch(r'([0-9a-fA-F]+)(?:\s+([0-9a-fA-F]+))?\s+([A-Za-z])\s+(\S+)', line.strip())
        if match:
            result.append({'name': match[4], 'value': int(match[1], 16),
                           'size': int(match[2] or '0', 16), 'kind': match[3]})
    return result


def read_placements(path, version):
    result = {}
    for statement in ast.parse(path.read_text()).body:
        if not isinstance(statement, ast.Assign):
            continue
        for target in statement.targets:
            if not isinstance(target, ast.Name) or target.id not in ('UNIT_BSS', 'UNIT_COMMON'):
                continue
            section = 'common' if target.id == 'UNIT_COMMON' else 'bss'
            for owner, value in ast.literal_eval(statement.value).items():
                address = value.get(version) if isinstance(value, dict) else value
                if address is not None:
                    result[owner, section] = address
    return result


def read_sections(path, prefix):
    output = subprocess.check_output([prefix + 'objdump', '-h', str(path)], text=True)
    result = {}
    for line in output.splitlines():
        match = re.match(r'\s*\d+\s+(\S+)\s+([0-9a-fA-F]+)\s+([0-9a-fA-F]+)\s', line)
        if match:
            result[match[1]] = {'size': int(match[2], 16), 'value': int(match[3], 16)}
    return result


def ram_address(value):
    return 0x02000000 <= value < 0x02040000 or 0x03000000 <= value < 0x03008000


def number(value):
    return int(value, 0) if isinstance(value, str) else value


def check(objects, linked, ledger, placements, contracts, sections=None):
    errors = []
    exports = defaultdict(list)
    final = defaultdict(list)
    for symbol in linked:
        final[symbol['name']].append(symbol)
    ram_count = 0
    allocations = []
    for owner, symbols in objects.items():
        for symbol in symbols:
            name, kind = symbol['name'], symbol['kind']
            if kind in 'BDCR':
                exports[name].append(owner)
                if name in ledger:
                    errors.append(f'{owner}: {name} is overridden by symbols.txt')
            if kind not in 'BbCc' or symbol['size'] == 0:
                continue
            ram_count += 1
            candidates = [s for s in final[name] if s['kind'] in 'Bb' and ram_address(s['value'])]
            section = 'common' if kind in 'Cc' and (owner, 'common') in placements else 'bss'
            base = placements.get((owner, section))
            if base is None:
                errors.append(f'{owner}: {name} has no RAM section placement')
                continue
            if kind in 'Bb':
                expected = base + symbol['value']
                candidates = [s for s in candidates if s['value'] == expected]
            if not candidates:
                errors.append(f'{owner}: {name} is discarded or placed incorrectly')
            elif not any(s['size'] == symbol['size'] for s in candidates):
                errors.append(f'{owner}: {name} linked size differs from its definition')
            else:
                matching = [s for s in candidates if s['size'] == symbol['size']]
                if len(matching) == 1:
                    address = matching[0]['value']
                    end = address + symbol['size']
                    if not ram_address(end - 1):
                        errors.append(f'{owner}: {name} extends outside RAM')
                    allocations.append((address, end, owner, name))
    for name, owners in exports.items():
        if len(owners) > 1:
            errors.append(f'{name}: multiple owners: {", ".join(owners)}')
    allocations.sort()
    for index, left in enumerate(allocations):
        for right in allocations[index + 1:]:
            if right[0] >= left[1]:
                break
            errors.append(f'overlapping RAM definitions: {left[2]}:{left[3]} and {right[2]}:{right[3]}')
    for owner, contract in contracts.items():
        if owner not in objects:
            errors.append(f'{owner}: contracted owner is not linked')
            continue
        definitions = {s['name']: s for s in objects[owner] if s['kind'] in 'BbCc' and s['size']}
        layouts = contract.get('sections', [contract])
        names = [name for layout in layouts for name in layout['symbols']]
        expected_names = set(names)
        if len(names) != len(expected_names):
            errors.append(f'{owner}: duplicate objects in layout contract')
        if set(definitions) != expected_names:
            errors.append(f'{owner}: RAM definition set differs from layout contract')
        intervals = []
        section_intervals = []
        for layout in layouts:
            base = number(layout['base'])
            limit = base + number(layout['size'])
            section_name = layout.get('section', '.bss.' + Path(owner).stem)
            section_intervals.append((base, limit, section_name))
            if sections is not None:
                section = sections.get(section_name)
                if section != {'value': base, 'size': limit - base}:
                    errors.append(f'{owner}: {section_name} extent differs from layout contract')
            for name, spec in layout['symbols'].items():
                address = base + number(spec['offset'])
                size = number(spec['size'])
                if size <= 0 or address < base or address + size > limit:
                    errors.append(f'{owner}: {name} is outside its layout contract')
                intervals.append((address, address + size, name))
                definition = definitions.get(name)
                if definition is None or definition['size'] != size:
                    errors.append(f'{owner}: {name} definition size does not match {size:#x}')
                if not any(s['kind'] in 'Bb' and s['value'] == address and s['size'] == size for s in final[name]):
                    errors.append(f'{owner}: {name} does not match expected RAM address {address:#010x}')
        section_intervals.sort()
        for left, right in zip(section_intervals, section_intervals[1:]):
            if left[1] > right[0]:
                errors.append(f'{owner}: overlapping contract sections {left[2]} and {right[2]}')
        intervals.sort()
        for left, right in zip(intervals, intervals[1:]):
            if left[1] > right[0]:
                errors.append(f'{owner}: overlapping contract objects {left[2]} and {right[2]}')
    return errors, ram_count


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('version', choices=('us', 'jp', 'eu'))
    parser.add_argument('--binutils-prefix', default='arm-none-eabi-')
    args = parser.parse_args()
    version = args.version
    build = ROOT / 'build' / version
    objects = {owner: read_symbols(build / owner, args.binutils_prefix)
               for owner in active_objects(ROOT, version)}
    linked = read_symbols(build / f'com_{version}.elf', args.binutils_prefix)
    ledger = set(re.findall(r'^(\w+)\s*=', (ROOT / 'config' / version / 'symbols.txt').read_text(), re.M))
    placements = read_placements(ROOT / 'configure.py', version)
    path = ROOT / 'config' / 'ram_layout.json'
    contracts = json.loads(path.read_text()).get(version, {}) if path.exists() else {}
    sections = read_sections(build / f'com_{version}.elf', args.binutils_prefix)
    errors, count = check(objects, linked, ledger, placements, contracts, sections)
    for error in errors:
        print(f'{version}: {error}')
    if errors:
        raise SystemExit(1)
    print(f'{version}: data ownership OK ({len(objects)} C objects, {count} RAM definitions, {len(contracts)} layout contracts)')


if __name__ == '__main__':
    main()
