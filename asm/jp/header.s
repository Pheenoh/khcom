@ GBA cartridge header (JP / B8CJ)

	.arm
	.section .text
	.global _start
_start:
	b EntryPoint
	.incbin "roms/B8CJ.gba", 0x4, 0xBC
