.syntax unified
	.text
	.align 2, 0
	.global Level_Up_2
	.thumb
	.thumb_func
	.type Level_Up_2, %function
Level_Up_2:
	.incbin "roms/B8CP.gba", 0xa0680, 0x7d0
.syntax divided
