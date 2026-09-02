.syntax unified
	.align 2, 0
	.global ply_tune
	.thumb
	.thumb_func
	.type ply_tune, %function
ply_tune:
	.incbin "roms/B8CJ.gba", 0x11f7fc, 0x14
.syntax divided
