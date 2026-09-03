.syntax unified
	.text
	.align 2, 0
	.global ply_endtie
	.thumb
	.thumb_func
	.type ply_endtie, %function
ply_endtie:
	.incbin "roms/B8CP.gba", 0x11e7c4, 0x4c
.syntax divided
