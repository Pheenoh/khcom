.syntax unified
	.align 2, 0
	.global task_status_0
	.thumb
	.thumb_func
	.type task_status_0, %function
task_status_0:
	.incbin "roms/B8CJ.gba", 0xd7594, 0xd8
.syntax divided
