.syntax unified
	.align 2, 0
	.global ply_pan
	.thumb
	.thumb_func
	.type ply_pan, %function
ply_pan:
	.incbin "roms/B8CJ.gba", 0x11f79c, 0x14
.syntax divided
