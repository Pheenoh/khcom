@ GBA cartridge header (EU / B8CP)

	.arm
	.section .text
	.global _start
_start:
	b EntryPoint
	.incbin "roms/B8CP.gba", 0x4, 0xBC
