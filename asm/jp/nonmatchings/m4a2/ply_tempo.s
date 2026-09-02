.syntax unified
	.align 2, 0
	.global ply_tempo
	.thumb
	.thumb_func
	.type ply_tempo, %function
ply_tempo:
	.incbin "roms/B8CJ.gba", 0x11f730, 0x14
.syntax divided
