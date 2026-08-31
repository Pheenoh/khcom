.syntax unified
	.align 2, 0
	.global mode_test_1
	.thumb
	.thumb_func
	.type mode_test_1, %function
mode_test_1:
	.incbin "roms/B8CJ.gba", 0x5f008, 0x80
.syntax divided
