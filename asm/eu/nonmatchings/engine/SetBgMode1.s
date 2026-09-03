.syntax unified
	.text
	.align 2, 0
	.global SetBgMode1
	.thumb
	.thumb_func
	.type SetBgMode1, %function
SetBgMode1:
	.incbin "roms/B8CP.gba", 0x4ff8, 0xa8
.syntax divided
