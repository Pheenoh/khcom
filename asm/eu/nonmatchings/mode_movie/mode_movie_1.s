.syntax unified
	.text
	.align 2, 0
	.global mode_movie_1
	.thumb
	.thumb_func
	.type mode_movie_1, %function
mode_movie_1:
	.incbin "roms/B8CP.gba", 0xd650, 0x490
.syntax divided
