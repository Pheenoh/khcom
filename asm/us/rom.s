@ Remainder of the ROM (0xC0 - 0x2000000), not yet disassembled.
@ As code and data get split out, carve pieces off of this incbin.

	.arm
	.section .text
	.global EntryPoint
EntryPoint:
	.incbin "roms/B8CE.gba", 0xC0, 0x1FFFF40
