.syntax unified
	.text
	.align 2, 0
	.global mode_sioError_1
	.thumb
	.thumb_func
	.type mode_sioError_1, %function
mode_sioError_1:
	.incbin "roms/B8CJ.gba", 0xb3fcc, 0xc
.syntax divided
