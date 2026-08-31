.syntax unified
	.align 2, 0
	.global task_status_stocklist_3
	.thumb
	.thumb_func
	.type task_status_stocklist_3, %function
task_status_stocklist_3:
	.incbin "roms/B8CJ.gba", 0xd82a8, 0x4c
.syntax divided
