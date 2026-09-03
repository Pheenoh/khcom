.syntax unified
	.text
	.align 2, 0
	.global ply_keysh
	.thumb
	.thumb_func
	.type ply_keysh, %function
ply_keysh:
	.incbin "roms/B8CP.gba", 0x11e1e8, 0x14
.syntax divided
