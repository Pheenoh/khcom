.syntax unified
	.align 2, 0
	.global task_wlogo_hwt_obj_2
	.thumb
	.thumb_func
	.type task_wlogo_hwt_obj_2, %function
task_wlogo_hwt_obj_2:
	.incbin "roms/B8CJ.gba", 0xb4f84, 0x34
.syntax divided
