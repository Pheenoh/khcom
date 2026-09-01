.syntax unified
	.align 2, 0
	.global task_print_0
	.thumb
	.thumb_func
	.type task_print_0, %function
task_print_0:
	.incbin "roms/B8CJ.gba", 0xae630, 0xc
.syntax divided
