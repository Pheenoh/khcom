.syntax unified
	.align 2, 0
	.global task_bos_lst_fal_3
	.thumb
	.thumb_func
	.type task_bos_lst_fal_3, %function
task_bos_lst_fal_3:
	.incbin "roms/B8CJ.gba", 0x111f90, 0x84
.syntax divided
