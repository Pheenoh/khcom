.syntax unified
	.align 2, 0
	.global mode_test_0
	.thumb
	.thumb_func
	.type mode_test_0, %function
mode_test_0:
	.incbin "roms/B8CJ.gba", 0x5efcc, 0x3c
.syntax divided
