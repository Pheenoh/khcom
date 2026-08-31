.syntax unified
	.align 2, 0
	.global task_wlogo_hwt_obj_1
	.thumb
	.thumb_func
	.type task_wlogo_hwt_obj_1, %function
task_wlogo_hwt_obj_1:
	.incbin "roms/B8CJ.gba", 0xb4e84, 0x100
.syntax divided
