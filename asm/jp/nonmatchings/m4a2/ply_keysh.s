.syntax unified
	.align 2, 0
	.global ply_keysh
	.thumb
	.thumb_func
	.type ply_keysh, %function
ply_keysh:
	.incbin "roms/B8CJ.gba", 0x11f744, 0x14
.syntax divided
