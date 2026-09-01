.syntax unified
	.align 2, 0
	.global task_print_2
	.thumb
	.thumb_func
	.type task_print_2, %function
task_print_2:
	.incbin "roms/B8CJ.gba", 0xae640, 0xc
.syntax divided
