.syntax unified
	.align 2, 0
	.global task_status_bar_1
	.thumb
	.thumb_func
	.type task_status_bar_1, %function
task_status_bar_1:
	.incbin "roms/B8CJ.gba", 0xd7994, 0x188
.syntax divided
