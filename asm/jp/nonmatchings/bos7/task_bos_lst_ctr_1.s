.syntax unified
	.align 2, 0
	.global task_bos_lst_ctr_1
	.thumb
	.thumb_func
	.type task_bos_lst_ctr_1, %function
task_bos_lst_ctr_1:
	.incbin "roms/B8CJ.gba", 0x11208c, 0x2e0
.syntax divided
