.syntax unified
	.align 2, 0
	.global task_title_obj_2
	.thumb
	.thumb_func
	.type task_title_obj_2, %function
task_title_obj_2:
	.incbin "roms/B8CJ.gba", 0xd6790, 0x68
.syntax divided
