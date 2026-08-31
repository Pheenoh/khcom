.syntax unified
	.align 2, 0
	.global task_bos_lst_fal_2
	.thumb
	.thumb_func
	.type task_bos_lst_fal_2, %function
task_bos_lst_fal_2:
	.incbin "roms/B8CJ.gba", 0x111f18, 0x78
.syntax divided
