.syntax unified
	.align 2, 0
	.global task_wlogo_hwt_1
	.thumb
	.thumb_func
	.type task_wlogo_hwt_1, %function
task_wlogo_hwt_1:
	.incbin "roms/B8CJ.gba", 0xb4bf0, 0x188
.syntax divided
