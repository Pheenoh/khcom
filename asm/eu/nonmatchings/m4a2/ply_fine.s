.syntax unified
	.text
	.align 2, 0
	.global ply_fine
	.thumb
	.thumb_func
	.type ply_fine, %function
ply_fine:
	.incbin "roms/B8CP.gba", 0x11e0d0, 0x38
.syntax divided
