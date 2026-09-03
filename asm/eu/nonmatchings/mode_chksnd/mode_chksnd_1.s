.syntax unified
	.text
	.align 2, 0
	.global mode_chksnd_1
	.thumb
	.thumb_func
	.type mode_chksnd_1, %function
mode_chksnd_1:
	.incbin "roms/B8CP.gba", 0xc214, 0xec
.syntax divided
