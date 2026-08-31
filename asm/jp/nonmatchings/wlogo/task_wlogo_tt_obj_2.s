.syntax unified
	.align 2, 0
	.global task_wlogo_tt_obj_2
	.thumb
	.thumb_func
	.type task_wlogo_tt_obj_2, %function
task_wlogo_tt_obj_2:
	.incbin "roms/B8CJ.gba", 0xb77bc, 0x30
.syntax divided
