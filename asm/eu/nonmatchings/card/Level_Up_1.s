.syntax unified
	.text
	.align 2, 0
	.global Level_Up_1
	.thumb
	.thumb_func
	.type Level_Up_1, %function
Level_Up_1:
	.incbin "roms/B8CP.gba", 0x9ef54, 0xc44
.syntax divided
