.syntax unified
	.align 2, 0
	.global task_status_3
	.thumb
	.thumb_func
	.type task_status_3, %function
task_status_3:
	.incbin "roms/B8CJ.gba", 0xd78a4, 0x18
.syntax divided
