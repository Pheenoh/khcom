import json
import struct
from pathlib import Path


ROM_BASE = 0x08000000
ROM_END = 0x0A000000


def load_evidence(path):
    path = Path(path)
    return json.loads(path.read_text()) if path.exists() else {'version': 1, 'tables': []}


def number(value, label):
    if isinstance(value, bool) or not isinstance(value, (int, str)):
        raise ValueError(f'{label}: expected an integer or hexadecimal address')
    try:
        result = int(value, 0) if isinstance(value, str) else value
    except ValueError as error:
        raise ValueError(f'{label}: invalid integer {value!r}') from error
    if result < 0:
        raise ValueError(f'{label}: negative values are not allowed')
    return result


def data_symbol_map(evidence, version, us, target, seed, us_code_end, target_code_end):
    if not isinstance(evidence, dict) or set(evidence) != {'version', 'tables'}:
        raise ValueError('ROM data evidence requires version and tables')
    if type(evidence['version']) is not int or evidence['version'] != 1:
        raise ValueError('unsupported ROM data evidence version')
    if not isinstance(evidence['tables'], list) or version not in ('jp', 'eu'):
        raise ValueError('invalid ROM data evidence tables or target version')
    spans = []
    names = set()
    required = {'name', 'provenance', 'us', 'targets', 'size', 'stride', 'pointer_offsets'}
    for table in evidence['tables']:
        if not isinstance(table, dict) or set(table) != required:
            raise ValueError('each evidence table requires name, provenance, us, targets, size, stride and pointer_offsets')
        name = table['name']
        if not isinstance(name, str) or not name.strip() or name in names:
            raise ValueError('evidence table names must be nonempty and unique')
        names.add(name)
        if not isinstance(table['provenance'], str) or not table['provenance'].strip():
            raise ValueError(f'{name}: independent span provenance is required')
        targets = table['targets']
        if not isinstance(targets, dict) or not targets or not set(targets) <= {'jp', 'eu'}:
            raise ValueError(f'{name}: targets must specify JP and/or EU addresses')
        start = number(table['us'], name + ' US start')
        other_starts = {key: number(value, name + ' ' + key + ' start') for key, value in targets.items()}
        size = number(table['size'], name + ' size')
        stride = number(table['stride'], name + ' stride')
        offsets = table['pointer_offsets']
        if not isinstance(offsets, list) or not offsets:
            raise ValueError(f'{name}: pointer_offsets must be a nonempty list')
        offsets = [number(value, name + ' pointer offset') for value in offsets]
        if not size or not stride or stride % 4 or size % stride:
            raise ValueError(f'{name}: size must contain whole word-aligned records')
        if len(set(offsets)) != len(offsets) or any(offset % 4 or offset + 4 > stride for offset in offsets):
            raise ValueError(f'{name}: pointer offsets must be distinct aligned words within each record')
        if start % 4 or not us_code_end <= start or start + size > min(ROM_END, ROM_BASE + len(us)):
            raise ValueError(f'{name}: US span lies outside aligned post-code ROM data')
        if any(at % 4 or at < ROM_BASE or at + size > ROM_END for at in other_starts.values()):
            raise ValueError(f'{name}: invalid target span')
        if version not in other_starts:
            continue
        other = other_starts[version]
        if other < target_code_end or other + size > min(ROM_END, ROM_BASE + len(target)):
            raise ValueError(f'{name}: {version} span lies outside post-code ROM data')
        spans.append((name, start, other, size, stride, sorted(offsets)))
    for index, label in ((1, 'US'), (2, version)):
        ordered = sorted(spans, key=lambda span: span[index])
        for left, right in zip(ordered, ordered[1:]):
            if left[index] + left[3] > right[index]:
                raise ValueError(f'{left[0]} and {right[0]}: overlapping {label} evidence spans')
    votes = {}
    for name, start, other, size, stride, offsets in spans:
        source_bytes = us[start - ROM_BASE:start - ROM_BASE + size]
        target_bytes = target[other - ROM_BASE:other - ROM_BASE + size]
        source_masked = bytearray(source_bytes)
        target_masked = bytearray(target_bytes)
        for record in range(0, size, stride):
            for offset in offsets:
                at = record + offset
                source_masked[at:at + 4] = bytes(4)
                target_masked[at:at + 4] = bytes(4)
        if source_masked != target_masked:
            raise ValueError(f'{name}: nonpointer bytes differ in {version}')
        for record in range(0, size, stride):
            for offset in offsets:
                at = record + offset
                source_word = struct.unpack_from('<I', source_bytes, at)[0]
                target_word = struct.unpack_from('<I', target_bytes, at)[0]
                site = f'{name}+{at:#x}'
                if source_word == target_word == 0:
                    continue
                if not (us_code_end <= source_word < min(ROM_END, ROM_BASE + len(us))
                        and target_code_end <= target_word < min(ROM_END, ROM_BASE + len(target))):
                    raise ValueError(f'{site}: pointer slots require corresponding post-code ROM data or NULL')
                if source_word in seed and seed[source_word] != target_word:
                    raise ValueError(f'{site}: data pointer conflicts with independent mapping for {source_word:#010x}')
                internal = [span for span in spans
                            if span[1] <= source_word < span[1] + span[3]
                            or span[2] <= target_word < span[2] + span[3]]
                if internal:
                    anchored = any(seed.get(left) == right
                                   and 0 <= source_word - left < length
                                   and source_word - left == target_word - right
                                   for _, left, right, length, _, _ in internal)
                    if seed.get(source_word) != target_word and not anchored:
                        raise ValueError(f'{site}: self or circular table pointers need independent mappings')
                    continue
                candidates = votes.setdefault(source_word, {})
                candidates.setdefault(target_word, []).append(site)
    result = {}
    provenance = {}
    for source_word, candidates in votes.items():
        if len(candidates) != 1:
            raise ValueError(f'{source_word:#010x}: conflicting ROM data evidence from {candidates}')
        target_word, sites = next(iter(candidates.items()))
        if source_word not in seed:
            result[source_word] = target_word
            provenance[source_word] = tuple(sites)
    return result, provenance
