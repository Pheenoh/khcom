.syntax unified
	.align 2, 0
	.global ply_fine
	.thumb
	.thumb_func
	.type ply_fine, %function
ply_fine:
	.incbin "roms/B8CJ.gba", 0x11f62c, 0x38
.syntax divided
