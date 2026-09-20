import re
import struct
import subprocess


ROM_BASE = 0x08000000


def literal_address(instruction, address, mode):
    if mode == 'thumb':
        if instruction & 0xF800 != 0x4800:
            return None
        return ((address + 4) & ~3) + (instruction & 0xFF) * 4
    if mode == 'arm':
        if instruction & 0x0F7F0000 != 0x051F0000 or instruction >> 28 == 15:
            return None
        return address + 8 + (instruction & 0xFFF) * (1 if instruction & 0x00800000 else -1)
    raise ValueError('instruction mode must be Thumb or ARM')


def parse_literal_loads(output):
    result = {}
    for line in output.splitlines():
        match = re.match(r'^\s*([0-9a-fA-F]+):\s+([0-9a-fA-F]{8}|[0-9a-fA-F]{4})\s+(ldr[a-z]*)\s', line)
        if match is None:
            continue
        address, instruction = int(match[1], 16), int(match[2], 16)
        mode = 'thumb' if len(match[2]) == 4 else 'arm'
        if literal_address(instruction, address, mode) is not None:
            result[address] = mode
    return result


def load_literal_loads(path, start, end, prefix='arm-none-eabi-'):
    output = subprocess.check_output([prefix + 'objdump', '-d', f'--start-address={start:#x}',
                                      f'--stop-address={end:#x}', str(path)], text=True)
    return parse_literal_loads(output)


def load_function_modes(path, start, end, prefix='arm-none-eabi-'):
    output = subprocess.check_output([prefix + 'readelf', '-sW', str(path)], text=True)
    result = {}
    for line in output.splitlines():
        match = re.match(r'^\s*\d+:\s+([0-9a-fA-F]+)\s+\S+\s+(FUNC|THUMB_FUNC)\s+\S+\s+\S+\s+\d+\s+', line)
        if match:
            address = int(match[1], 16)
            if start <= (address & ~1) < end:
                result[address & ~1] = 'thumb' if match[2] == 'THUMB_FUNC' or address & 1 else 'arm'
    return result


def signed(value, bits):
    return value - (1 << bits) if value & (1 << (bits - 1)) else value


def thumb_switch_targets(rom, address, start, limit):
    if address - 12 < start:
        return [], []
    shift, load, add, indirect, jump = struct.unpack_from('<5H', rom, address - 8 - ROM_BASE)
    index = shift & 7
    temporary = (load >> 8) & 7
    if (shift != (0x0080 | index << 3 | index) or load & 0xF800 != 0x4800
            or index == temporary or add not in (0x1800 | temporary << 6 | index << 3 | index,
                                                 0x1800 | index << 6 | temporary << 3 | index)
            or indirect != (0x6800 | index << 3 | index) or jump != (0x4687 | index << 3)):
        return [], []
    compare, branch = struct.unpack_from('<2H', rom, address - 12 - ROM_BASE)
    if compare & 0xFF00 == (0x2800 | index << 8) and branch & 0xFF00 == 0xD800:
        count = (compare & 0xFF) + 1
        default = address - 10 + 4 + signed(branch & 0xFF, 8) * 2
    elif address - 14 >= start:
        compare, branch, otherwise = struct.unpack_from('<3H', rom, address - 14 - ROM_BASE)
        destination = address - 12 + 4 + signed(branch & 0xFF, 8) * 2
        if (compare & 0xFF00 != (0x2800 | index << 8) or branch & 0xFF00 != 0xD900
                or destination != address - 8 or otherwise & 0xF800 != 0xE000):
            return [], []
        count = (compare & 0xFF) + 1
        default = address - 10 + 4 + signed(otherwise & 0x7FF, 11) * 2
    else:
        return [], []
    if address - 8 <= default <= address:
        return [], []
    pool = literal_address(load, address - 6, 'thumb')
    if pool < start or pool + 4 > limit:
        return [], []
    table = struct.unpack_from('<I', rom, pool - ROM_BASE)[0]
    if table % 4 or table < start or table + count * 4 > limit:
        return [], []
    targets = struct.unpack_from('<' + 'I' * count, rom, table - ROM_BASE)
    if any(target % 2 or target < start or target + 2 > limit for target in targets):
        return [], []
    return targets, range(table, table + count * 4, 2)


def trace_literal_loads(rom, start, size, mode):
    limit = start + size
    if start < ROM_BASE or limit > ROM_BASE + len(rom) or size < 0:
        return {}
    queued, visited, pools, result = [(start, mode)], set(), set(), {}
    while queued:
        address, mode = queued.pop()
        width = 2 if mode == 'thumb' else 4
        if (address, mode) in visited or address < start or address + width > limit or address % width or address in pools:
            continue
        visited.add((address, mode))
        instruction = struct.unpack_from('<H' if width == 2 else '<I', rom, address - ROM_BASE)[0]
        pool = literal_address(instruction, address, mode)
        if pool is not None and pool % 4 == 0 and ROM_BASE <= pool <= ROM_BASE + len(rom) - 4:
            result[address] = mode
            pools.update((pool, pool + 2))
        following = address + width
        if mode == 'thumb':
            if instruction & 0xF800 == 0xE000:
                queued.append((address + 4 + signed(instruction & 0x7FF, 11) * 2, mode))
                continue
            if instruction & 0xF000 == 0xD000 and instruction & 0x0F00 < 0x0E00:
                queued.append((address + 4 + signed(instruction & 0xFF, 8) * 2, mode))
            elif instruction & 0xF800 == 0xF000:
                if following + 2 > limit:
                    continue
                suffix = struct.unpack_from('<H', rom, following - ROM_BASE)[0]
                if suffix & 0xF800 != 0xF800:
                    continue
                following += 2
            elif instruction & 0xF800 == 0xF800 or instruction & 0xFF00 in (0xBD00, 0xDE00):
                continue
            elif instruction & 0xFF87 == 0x4700:
                if instruction == 0x4778:
                    queued.append(((address + 4) & ~3, 'arm'))
                continue
            elif instruction & 0xFC00 == 0x4400:
                destination = (instruction & 7) | ((instruction >> 4) & 8)
                if destination == 15 and (instruction >> 8) & 3 in (0, 2):
                    targets, table = thumb_switch_targets(rom, address, start, limit)
                    pools.update(table)
                    queued.extend((target, mode) for target in targets)
                    continue
        else:
            condition = instruction >> 28
            if condition == 15:
                continue
            if instruction & 0x0E000000 == 0x0A000000 and not instruction & 0x01000000:
                queued.append((address + 8 + signed(instruction & 0xFFFFFF, 24) * 4, mode))
                if condition == 14:
                    continue
            elif instruction & 0x0FFFFFF0 == 0x012FFF10:
                if condition == 14:
                    continue
            elif ((instruction & 0x0C000000 == 0 and (instruction >> 12) & 15 == 15
                   and (instruction >> 21) & 15 not in (8, 9, 10, 11))
                  or (instruction & 0x0C100000 == 0x04100000 and (instruction >> 12) & 15 == 15)
                  or (instruction & 0x0E108000 == 0x08108000)):
                if condition == 14:
                    continue
        queued.append((following, mode))
    return {address: mode for address, mode in result.items() if address not in pools}


def literal_pointer_pairs(us, target, source_start, target_start, size, loads):
    if (size < 0 or source_start < ROM_BASE or target_start < ROM_BASE
            or source_start + size > ROM_BASE + len(us) or target_start + size > ROM_BASE + len(target)):
        return
    pairs = set()
    for offset in range(0, size, 2):
        address = source_start + offset
        mode = loads.get(address)
        if mode is None:
            continue
        width, format = (2, '<H') if mode == 'thumb' else (4, '<I')
        if offset + width > size or address % width or (target_start + offset) % width:
            continue
        source_instruction = struct.unpack_from(format, us, address - ROM_BASE)[0]
        target_instruction = struct.unpack_from(format, target, target_start + offset - ROM_BASE)[0]
        mask = 0xFF00 if mode == 'thumb' else 0xFF7FF000
        if source_instruction & mask != target_instruction & mask:
            continue
        source_pool = literal_address(source_instruction, address, mode)
        target_pool = literal_address(target_instruction, target_start + offset, mode)
        if source_pool is None or target_pool is None:
            continue
        if (source_pool % 4 or target_pool % 4 or source_pool < ROM_BASE or target_pool < ROM_BASE
                or source_pool + 4 > ROM_BASE + len(us) or target_pool + 4 > ROM_BASE + len(target)):
            continue
        pairs.add((source_pool, target_pool))
    for source_pool, target_pool in sorted(pairs):
        source_word = struct.unpack_from('<I', us, source_pool - ROM_BASE)[0]
        target_word = struct.unpack_from('<I', target, target_pool - ROM_BASE)[0]
        if source_word >> 24 in (0x02, 0x03, 0x08, 0x09) and target_word >> 24 in (0x02, 0x03, 0x08, 0x09):
            yield source_word, target_word
