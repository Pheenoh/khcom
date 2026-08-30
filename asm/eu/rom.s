@ Remainder of the ROM (0xC0 - 0x2000000), not yet disassembled.

	.arm
	.section .text
	.global EntryPoint
EntryPoint:
	.incbin "roms/B8CP.gba", 0xC0, 0x1FFFF40
