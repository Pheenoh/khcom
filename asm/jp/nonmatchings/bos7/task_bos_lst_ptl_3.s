.syntax unified
	.align 2, 0
	.global task_bos_lst_ptl_3
	.thumb
	.thumb_func
	.type task_bos_lst_ptl_3, %function
task_bos_lst_ptl_3:
	.incbin "roms/B8CJ.gba", 0x111c58, 0x28
.syntax divided
