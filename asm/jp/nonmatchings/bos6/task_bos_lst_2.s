.syntax unified
	.align 2, 0
	.global task_bos_lst_2
	.thumb
	.thumb_func
	.type task_bos_lst_2, %function
task_bos_lst_2:
	.incbin "roms/B8CJ.gba", 0x10f860, 0x614
.syntax divided
