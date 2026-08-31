.syntax unified
	.align 2, 0
	.global task_wlogo_tvt_3
	.thumb
	.thumb_func
	.type task_wlogo_tvt_3, %function
task_wlogo_tvt_3:
	.incbin "roms/B8CJ.gba", 0xb6b10, 0x18
.syntax divided
