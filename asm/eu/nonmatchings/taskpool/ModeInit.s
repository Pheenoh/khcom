.syntax unified
	.text
	.align 2, 0
	.global ModeInit
	.thumb
	.thumb_func
	.type ModeInit, %function
ModeInit:
	.incbin "roms/B8CP.gba", 0x1054, 0x60
.syntax divided
