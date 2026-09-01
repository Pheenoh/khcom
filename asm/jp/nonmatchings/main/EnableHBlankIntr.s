.syntax unified
	.align 2, 0
	.global EnableHBlankIntr
	.thumb
	.thumb_func
	.type EnableHBlankIntr, %function
EnableHBlankIntr:
	.incbin "roms/B8CJ.gba", 0x2d4, 0x2c
.syntax divided
