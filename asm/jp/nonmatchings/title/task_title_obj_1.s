.syntax unified
	.align 2, 0
	.global task_title_obj_1
	.thumb
	.thumb_func
	.type task_title_obj_1, %function
task_title_obj_1:
	.incbin "roms/B8CJ.gba", 0xd6730, 0x60
.syntax divided
