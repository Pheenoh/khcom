.syntax unified
	.text
	.align 2, 0
	.global ply_pend
	.thumb
	.thumb_func
	.type ply_pend, %function
ply_pend:
	.incbin "roms/B8CJ.gba", 0x11f6e0, 0x14
.syntax divided
