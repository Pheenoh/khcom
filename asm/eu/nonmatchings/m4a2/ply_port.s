.syntax unified
	.text
	.align 2, 0
	.global ply_port
	.thumb
	.thumb_func
	.type ply_port, %function
ply_port:
	.incbin "roms/B8CP.gba", 0x11e2b4, 0x18
.syntax divided
