.syntax unified
	.text
	.align 2, 0
	.global ply_mod
	.thumb
	.thumb_func
	.type ply_mod, %function
ply_mod:
	.incbin "roms/B8CP.gba", 0x11e84c, 0x14
.syntax divided
