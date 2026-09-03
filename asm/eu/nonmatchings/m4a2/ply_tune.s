.syntax unified
	.text
	.align 2, 0
	.global ply_tune
	.thumb
	.thumb_func
	.type ply_tune, %function
ply_tune:
	.incbin "roms/B8CP.gba", 0x11e2a0, 0x14
.syntax divided
