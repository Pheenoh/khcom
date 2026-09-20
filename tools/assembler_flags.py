import struct
import subprocess
import tempfile
from pathlib import Path


ARM_AS_FLAGS = ['-mcpu=arm7tdmi', '-march=armv4t', '-mthumb-interwork', '-meabi=gnu']


def software_fp_flags(assembler):
    with tempfile.TemporaryDirectory(prefix='khcom-as-abi-') as directory:
        output = Path(directory) / 'probe.o'
        for flags in (['-mfpu=fpa', '-mfloat-abi=soft'], ['-mfpu=softfpa']):
            output.unlink(missing_ok=True)
            result = subprocess.run([assembler, *ARM_AS_FLAGS, *flags, '-o', str(output), '-'],
                                    input=b'', capture_output=True)
            if result.returncode or not output.is_file():
                continue
            data = output.read_bytes()
            if (len(data) >= 52 and data[:7] == b'\x7fELF\x01\x01\x01'
                    and struct.unpack_from('<H', data, 18)[0] == 40
                    and struct.unpack_from('<I', data, 36)[0] == 0x204):
                return ' '.join(ARM_AS_FLAGS + flags)
    raise ValueError(f'{assembler}: cannot emit GNU software-FP ARM7 objects compatible with the historical assembler')
