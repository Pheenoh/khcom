.syntax unified
	.align 2, 0
	.global task_bos_lst_ctr_2
	.thumb
	.thumb_func
	.type task_bos_lst_ctr_2, %function
task_bos_lst_ctr_2:
	.incbin "roms/B8CJ.gba", 0x11236c, 0x108
.syntax divided
