.syntax unified
	.align 2, 0
	.global task_emy_test_3
	.thumb
	.thumb_func
	.type task_emy_test_3, %function
task_emy_test_3:
	.incbin "roms/B8CJ.gba", 0x3f008, 0xc
.syntax divided
