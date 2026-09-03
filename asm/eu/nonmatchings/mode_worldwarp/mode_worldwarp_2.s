.syntax unified
	.text
	.align 2, 0
	.global mode_worldwarp_2
	.thumb
	.thumb_func
	.type mode_worldwarp_2, %function
mode_worldwarp_2:
	.incbin "roms/B8CP.gba", 0xff870, 0xa4
.syntax divided
