	.arm
	.section .text
	.global EntryPoint
EntryPoint:
	.incbin "roms/B8CJ.gba", 0xC0, 0x180
