.syntax unified
	.align 2, 0
	.global mode_test_2
	.thumb
	.thumb_func
	.type mode_test_2, %function
mode_test_2:
	.incbin "roms/B8CJ.gba", 0x5f088, 0x20
.syntax divided
