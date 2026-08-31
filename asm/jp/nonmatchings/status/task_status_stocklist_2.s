.syntax unified
	.align 2, 0
	.global task_status_stocklist_2
	.thumb
	.thumb_func
	.type task_status_stocklist_2, %function
task_status_stocklist_2:
	.incbin "roms/B8CJ.gba", 0xd81e4, 0xc4
.syntax divided
