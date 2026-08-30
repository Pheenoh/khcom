@ GBA cartridge header (US / B8CE)
@ 0x00: entry branch, 0x04-0x9F: Nintendo logo, 0xA0-0xBF: title/code/checksum

	.arm
	.section .text
	.global _start
_start:
	b EntryPoint
	.incbin "roms/B8CE.gba", 0x4, 0xBC
