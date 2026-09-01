.syntax unified
	.align 2, 0
	.global task_print_3
	.thumb
	.thumb_func
	.type task_print_3, %function
task_print_3:
	.incbin "roms/B8CJ.gba", 0xae64c, 0x60c
.syntax divided
