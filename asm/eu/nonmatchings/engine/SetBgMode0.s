.syntax unified
	.text
	.align 2, 0
	.global SetBgMode0
	.thumb
	.thumb_func
	.type SetBgMode0, %function
SetBgMode0:
	.incbin "roms/B8CP.gba", 0x4f2c, 0xc0
.syntax divided
