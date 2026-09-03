.syntax unified
	.text
	.align 2, 0
	.global ply_rept
	.thumb
	.thumb_func
	.type ply_rept, %function
ply_rept:
	.incbin "roms/B8CP.gba", 0x11e198, 0x30
.syntax divided
