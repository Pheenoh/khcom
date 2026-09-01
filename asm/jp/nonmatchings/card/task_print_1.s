.syntax unified
	.align 2, 0
	.global task_print_1
	.thumb
	.thumb_func
	.type task_print_1, %function
task_print_1:
	.incbin "roms/B8CJ.gba", 0xae63c, 0x4
.syntax divided
