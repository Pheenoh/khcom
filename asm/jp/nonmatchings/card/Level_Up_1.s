.syntax unified
	.text
	.align 2, 0
	.global Level_Up_1
	.thumb
	.thumb_func
	.type Level_Up_1, %function
Level_Up_1:
	.incbin "roms/B8CJ.gba", 0x9ea84, 0xaa8
.syntax divided
