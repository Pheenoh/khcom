.syntax unified
	.align 2, 0
	.global ply_port
	.thumb
	.thumb_func
	.type ply_port, %function
ply_port:
	.incbin "roms/B8CJ.gba", 0x11f810, 0x18
.syntax divided
