import struct
import unittest
from unittest.mock import patch

from function_pointer_evidence import load_function_modes, literal_pointer_pairs, trace_literal_loads


class FunctionPointerEvidenceTest(unittest.TestCase):
    def modes(self, output):
        with patch('function_pointer_evidence.subprocess.check_output', return_value=output):
            return load_function_modes('fixture.elf', 0x08000000, 0x08000020)

    def test_both_thumb_symbol_formats_and_arm(self):
        output = ('   1: 08000001     4 FUNC       GLOBAL DEFAULT    1 modern_thumb\n'
                  '   2: 08000008     4 THUMB_FUNC LOCAL  DEFAULT    1 legacy_thumb\n'
                  '   3: 08000010     8 FUNC       GLOBAL DEFAULT    1 arm_function\n')
        self.assertEqual(self.modes(output), {0x08000000: 'thumb', 0x08000008: 'thumb',
                                             0x08000010: 'arm'})

    def test_excludes_nonfunctions_undefined_absolute_and_outside_range(self):
        output = ('   1: 08000004     4 OBJECT     GLOBAL DEFAULT    1 data\n'
                  '   2: 08000008     0 NOTYPE     GLOBAL DEFAULT    1 label\n'
                  '   3: 0800000d     0 FUNC       GLOBAL DEFAULT  UND undefined\n'
                  '   4: 08000010     0 THUMB_FUNC GLOBAL DEFAULT  ABS alias\n'
                  '   5: 07fffffc     4 THUMB_FUNC GLOBAL DEFAULT    1 before\n'
                  '   6: 08000020     4 THUMB_FUNC GLOBAL DEFAULT    1 after\n')
        self.assertEqual(self.modes(output), {})

    def test_legacy_thumb_symbols_preserve_literal_pointer_evidence(self):
        source = struct.pack('<HHI', 0x4800, 0x4770, 0x08123400)
        target = struct.pack('<HHI', 0x4800, 0x4770, 0x08124500)
        modern = '   1: 08000001     8 FUNC       GLOBAL DEFAULT    1 reader\n'
        legacy = '   1: 08000000     8 THUMB_FUNC GLOBAL DEFAULT    1 reader\n'
        for output in (modern, legacy):
            with self.subTest(output=output):
                modes = self.modes(output)
                loads = trace_literal_loads(source, 0x08000000, 8, modes[0x08000000])
                pairs = list(literal_pointer_pairs(source, target, 0x08000000,
                                                   0x08000000, 8, loads))
                self.assertEqual(pairs, [(0x08123400, 0x08124500)])


if __name__ == '__main__':
    unittest.main()
