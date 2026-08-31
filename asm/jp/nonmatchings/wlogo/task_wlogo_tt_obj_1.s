.syntax unified
	.align 2, 0
	.global task_wlogo_tt_obj_1
	.thumb
	.thumb_func
	.type task_wlogo_tt_obj_1, %function
task_wlogo_tt_obj_1:
	.incbin "roms/B8CJ.gba", 0xb7788, 0x34
.syntax divided
