.syntax unified
	.text
	.align 2, 0
	.global ply_lfodl
	.thumb
	.thumb_func
	.type ply_lfodl, %function
ply_lfodl:
	.incbin "roms/B8CJ.gba", 0x11f7d8, 0xc
.syntax divided
