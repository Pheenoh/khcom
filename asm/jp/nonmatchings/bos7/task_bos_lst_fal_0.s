.syntax unified
	.align 2, 0
	.global task_bos_lst_fal_0
	.thumb
	.thumb_func
	.type task_bos_lst_fal_0, %function
task_bos_lst_fal_0:
	.incbin "roms/B8CJ.gba", 0x111c80, 0x200
.syntax divided
