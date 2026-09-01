.syntax unified
	.align 2, 0
	.global VBlankIntr
	.thumb
	.thumb_func
	.type VBlankIntr, %function
VBlankIntr:
	.incbin "roms/B8CJ.gba", 0x4dc, 0xc8
.syntax divided
