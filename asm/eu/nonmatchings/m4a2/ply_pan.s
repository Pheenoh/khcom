.syntax unified
	.text
	.align 2, 0
	.global ply_pan
	.thumb
	.thumb_func
	.type ply_pan, %function
ply_pan:
	.incbin "roms/B8CP.gba", 0x11e240, 0x14
.syntax divided
