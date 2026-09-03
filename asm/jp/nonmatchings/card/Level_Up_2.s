.syntax unified
	.align 2, 0
	.global Level_Up_2
	.thumb
	.thumb_func
	.type Level_Up_2, %function
Level_Up_2:
	.incbin "roms/B8CJ.gba", 0x9fff0, 0x80c
.syntax divided
