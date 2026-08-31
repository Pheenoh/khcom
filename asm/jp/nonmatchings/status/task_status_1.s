.syntax unified
	.align 2, 0
	.global task_status_1
	.thumb
	.thumb_func
	.type task_status_1, %function
task_status_1:
	.incbin "roms/B8CJ.gba", 0xd7868, 0x30
.syntax divided
