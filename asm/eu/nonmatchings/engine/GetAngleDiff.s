.syntax unified
	.text
	.align 2, 0
	.global GetAngleDiff
	.thumb
	.thumb_func
	.type GetAngleDiff, %function
GetAngleDiff:
	.incbin "roms/B8CP.gba", 0x5b24, 0x38
.syntax divided
