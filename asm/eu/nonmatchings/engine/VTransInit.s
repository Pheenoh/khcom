.syntax unified
	.text
	.align 2, 0
	.global VTransInit
	.thumb
	.thumb_func
	.type VTransInit, %function
VTransInit:
	.incbin "roms/B8CP.gba", 0x438c, 0x3c
.syntax divided
