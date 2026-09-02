.syntax unified
	.align 2, 0
	.global ply_bend
	.thumb
	.thumb_func
	.type ply_bend, %function
ply_bend:
	.incbin "roms/B8CJ.gba", 0x11f7b0, 0x14
.syntax divided
