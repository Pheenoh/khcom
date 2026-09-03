.syntax unified
	.text
	.align 2, 0
	.global ply_lfos
	.thumb
	.thumb_func
	.type ply_lfos, %function
ply_lfos:
	.incbin "roms/B8CJ.gba", 0x11fd94, 0x14
.syntax divided
