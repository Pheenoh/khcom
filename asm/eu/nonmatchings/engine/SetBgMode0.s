.syntax unified
	.text
	.align 2, 0
	.global SetBgMode0
	.thumb
	.thumb_func
	.type SetBgMode0, %function
SetBgMode0:
	.incbin "roms/B8CP.gba", 0x4f40, 0xb8
.syntax divided
