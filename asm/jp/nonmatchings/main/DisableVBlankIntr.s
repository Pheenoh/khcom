.syntax unified
	.align 2, 0
	.global DisableVBlankIntr
	.thumb
	.thumb_func
	.type DisableVBlankIntr, %function
DisableVBlankIntr:
	.incbin "roms/B8CJ.gba", 0x294, 0x40
.syntax divided
