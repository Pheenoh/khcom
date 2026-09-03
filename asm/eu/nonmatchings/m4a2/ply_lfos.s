.syntax unified
	.text
	.align 2, 0
	.global ply_lfos
	.thumb
	.thumb_func
	.type ply_lfos, %function
ply_lfos:
	.incbin "roms/B8CP.gba", 0x11e838, 0x14
.syntax divided
