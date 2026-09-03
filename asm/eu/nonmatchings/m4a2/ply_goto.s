.syntax unified
	.text
	.align 2, 0
	.global ply_goto
	.thumb
	.thumb_func
	.type ply_goto, %function
ply_goto:
	.incbin "roms/B8CP.gba", 0x11e148, 0x20
.syntax divided
