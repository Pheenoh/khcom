.syntax unified
	.align 2, 0
	.global ply_modt
	.thumb
	.thumb_func
	.type ply_modt, %function
ply_modt:
	.incbin "roms/B8CJ.gba", 0x11f7e4, 0x18
.syntax divided
