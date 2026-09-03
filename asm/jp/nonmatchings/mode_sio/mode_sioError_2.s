.syntax unified
	.text
	.align 2, 0
	.global mode_sioError_2
	.thumb
	.thumb_func
	.type mode_sioError_2, %function
mode_sioError_2:
	.incbin "roms/B8CJ.gba", 0xb4008, 0x2c
.syntax divided
