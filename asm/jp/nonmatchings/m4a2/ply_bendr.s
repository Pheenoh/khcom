.syntax unified
	.text
	.align 2, 0
	.global ply_bendr
	.thumb
	.thumb_func
	.type ply_bendr, %function
ply_bendr:
	.incbin "roms/B8CJ.gba", 0x11f7c4, 0x14
.syntax divided
