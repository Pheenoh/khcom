.syntax unified
	.text
	.align 2, 0
	.global ply_bend
	.thumb
	.thumb_func
	.type ply_bend, %function
ply_bend:
	.incbin "roms/B8CP.gba", 0x11e254, 0x14
.syntax divided
