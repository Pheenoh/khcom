.syntax unified
	.align 2, 0
	.global task_wlogo_bks_obj_2
	.thumb
	.thumb_func
	.type task_wlogo_bks_obj_2, %function
task_wlogo_bks_obj_2:
	.incbin "roms/B8CJ.gba", 0xb7ec4, 0x40
.syntax divided
