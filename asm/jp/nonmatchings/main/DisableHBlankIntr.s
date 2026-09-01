.syntax unified
	.align 2, 0
	.global DisableHBlankIntr
	.thumb
	.thumb_func
	.type DisableHBlankIntr, %function
DisableHBlankIntr:
	.incbin "roms/B8CJ.gba", 0x300, 0x34
.syntax divided
