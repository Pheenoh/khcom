.syntax unified
	.text
	.align 2, 0
	.global ModeUpdate
	.thumb
	.thumb_func
	.type ModeUpdate, %function
ModeUpdate:
	.incbin "roms/B8CP.gba", 0x1178, 0x148
.syntax divided
