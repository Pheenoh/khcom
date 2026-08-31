.syntax unified
	.align 2, 0
	.global task_bos_lst_lsr_2
	.thumb
	.thumb_func
	.type task_bos_lst_lsr_2, %function
task_bos_lst_lsr_2:
	.incbin "roms/B8CJ.gba", 0x1118ec, 0x170
.syntax divided
