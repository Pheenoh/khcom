.syntax unified
	.align 2, 0
	.global task_bos_lst_fal_1
	.thumb
	.thumb_func
	.type task_bos_lst_fal_1, %function
task_bos_lst_fal_1:
	.incbin "roms/B8CJ.gba", 0x111e80, 0x98
.syntax divided
