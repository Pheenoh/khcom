.syntax unified
	.text
	.align 2, 0
	.global ply_lfodl
	.thumb
	.thumb_func
	.type ply_lfodl, %function
ply_lfodl:
	.incbin "roms/B8CP.gba", 0x11e27c, 0xc
.syntax divided
