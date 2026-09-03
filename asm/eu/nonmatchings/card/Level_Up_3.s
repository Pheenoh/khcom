.syntax unified
	.text
	.align 2, 0
	.global Level_Up_3
	.thumb
	.thumb_func
	.type Level_Up_3, %function
Level_Up_3:
	.incbin "roms/B8CP.gba", 0xa0d7c, 0x118
.syntax divided
