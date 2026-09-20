import re
from pathlib import Path


def materialize_assets(plan, units, version, build_dir):
    groups = {}
    for asset in plan['assets']:
        if 'unit' in asset:
            groups.setdefault(asset['unit'], []).append(asset)
    result, emitted = [], set()
    for source, obj, flags, section in units:
        name = Path(obj).stem + '.s'
        if name not in groups:
            result.append((source, obj, flags, section))
            continue
        original = Path('asm') / version / name
        if not original.exists():
            original = Path('asm') / name
        match = re.search(r'\.incbin\s+"assets/' + re.escape(version)
                          + r'/([0-9A-F]{8})-([0-9A-F]{8})\.bin"', original.read_text())
        if match is None:
            raise ValueError(f'{name}: asset owner requires an address-bounded source slice')
        start, end = (int(value, 16) for value in match.groups())
        text = source.read_text()
        matches = list(re.finditer(r'\.incbin\s+"([^"\n]+)"[^\n]*', text))
        if len(matches) != 1 or matches[0][0] != '.incbin "' + matches[0][1] + '"':
            raise ValueError(f'{name}: asset owner must contain one complete slice')
        match = matches[0]
        body = []
        cursor = start
        for asset in sorted(groups[name], key=lambda item: item['address']):
            address, size, symbol = asset['address'], asset['size'], asset['name']
            if address < cursor or address + size > end:
                raise ValueError(f'{symbol}: asset definition overlaps or exceeds its owner')
            if address > cursor:
                body.append(f'\t.incbin "{match[1]}", {cursor - start}, {address - cursor}')
            body.extend([f'\t.global {symbol}', f'\t.type {symbol}, %object', symbol + ':',
                         f'\t.incbin "{match[1]}", {address - start}, {size}',
                         f'\t.size {symbol}, . - {symbol}'])
            cursor = address + size
        if cursor < end:
            body.append(f'\t.incbin "{match[1]}", {cursor - start}, {end - cursor}')
        target = Path(build_dir) / 'asm' / 'objects' / name
        target.parent.mkdir(parents=True, exist_ok=True)
        output = text[:match.start()] + '\n'.join(body) + text[match.end():]
        if not target.exists() or target.read_text() != output:
            target.write_text(output)
        result.append((target, obj, flags, section))
        emitted.add(name)
    if emitted != set(groups):
        raise ValueError('asset definition owners are inactive: ' + ', '.join(sorted(set(groups) - emitted)))
    return result
