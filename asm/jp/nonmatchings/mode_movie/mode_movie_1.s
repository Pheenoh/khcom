.syntax unified
	.align 2, 0
	.global mode_movie_1
	.thumb
	.thumb_func
	.type mode_movie_1, %function
mode_movie_1:
	.incbin "roms/B8CJ.gba", 0x5ece4, 0x2dc
.syntax divided
