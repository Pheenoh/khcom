.syntax unified
	.align 2, 0
	.global task_status_stocklist_1
	.thumb
	.thumb_func
	.type task_status_stocklist_1, %function
task_status_stocklist_1:
	.incbin "roms/B8CJ.gba", 0xd81b0, 0x34
.syntax divided
