.syntax unified
	.align 2, 0
	.global task_wlogo_bks_obj_1
	.thumb
	.thumb_func
	.type task_wlogo_bks_obj_1, %function
task_wlogo_bks_obj_1:
	.incbin "roms/B8CJ.gba", 0xb7e20, 0xa4
.syntax divided
