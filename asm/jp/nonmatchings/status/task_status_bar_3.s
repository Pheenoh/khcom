.syntax unified
	.align 2, 0
	.global task_status_bar_3
	.thumb
	.thumb_func
	.type task_status_bar_3, %function
task_status_bar_3:
	.incbin "roms/B8CJ.gba", 0xd7b9c, 0x18
.syntax divided
