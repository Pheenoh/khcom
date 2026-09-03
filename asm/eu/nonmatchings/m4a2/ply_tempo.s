.syntax unified
	.text
	.align 2, 0
	.global ply_tempo
	.thumb
	.thumb_func
	.type ply_tempo, %function
ply_tempo:
	.incbin "roms/B8CP.gba", 0x11e1d4, 0x14
.syntax divided
