.syntax unified
	.align 2, 0
	.global ply_mod
	.thumb
	.thumb_func
	.type ply_mod, %function
ply_mod:
	.incbin "roms/B8CJ.gba", 0x11fda8, 0x14
.syntax divided
