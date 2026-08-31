.syntax unified
	.align 2, 0
	.global task_bos_lst_ptl_1
	.thumb
	.thumb_func
	.type task_bos_lst_ptl_1, %function
task_bos_lst_ptl_1:
	.incbin "roms/B8CJ.gba", 0x111af8, 0xd8
.syntax divided
