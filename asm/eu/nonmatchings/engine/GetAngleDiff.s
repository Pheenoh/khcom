.syntax unified
	.text
	.align 2, 0
	.global GetAngleDiff
	.thumb
	.thumb_func
	.type GetAngleDiff, %function
GetAngleDiff:
	.incbin "roms/B8CP.gba", 0x59d4, 0x188
.syntax divided
