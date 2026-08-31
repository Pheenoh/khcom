.syntax unified
	.align 2, 0
	.global task_wlogo_hwt_3
	.thumb
	.thumb_func
	.type task_wlogo_hwt_3, %function
task_wlogo_hwt_3:
	.incbin "roms/B8CJ.gba", 0xb4d7c, 0x10
.syntax divided
