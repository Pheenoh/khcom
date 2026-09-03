.syntax unified
	.text
	.align 2, 0
	.global ply_modt
	.thumb
	.thumb_func
	.type ply_modt, %function
ply_modt:
	.incbin "roms/B8CP.gba", 0x11e288, 0x18
.syntax divided
