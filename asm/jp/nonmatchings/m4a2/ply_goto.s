.syntax unified
	.align 2, 0
	.global ply_goto
	.thumb
	.thumb_func
	.type ply_goto, %function
ply_goto:
	.incbin "roms/B8CJ.gba", 0x11f6a4, 0x20
.syntax divided
