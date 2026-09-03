.syntax unified
	.text
	.align 2, 0
	.global ply_patt
	.thumb
	.thumb_func
	.type ply_patt, %function
ply_patt:
	.incbin "roms/B8CP.gba", 0x11e168, 0x1c
.syntax divided
