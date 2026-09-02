.syntax unified
	.align 2, 0
	.global GetAngleDiff16
	.thumb
	.thumb_func
	.type GetAngleDiff16, %function
GetAngleDiff16:
	.incbin "roms/B8CJ.gba", 0x585c, 0x40
.syntax divided
