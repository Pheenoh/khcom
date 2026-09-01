.syntax unified
	.align 2, 0
	.global task_bos_lst_3
	.thumb
	.thumb_func
	.type task_bos_lst_3, %function
task_bos_lst_3:
	.incbin "roms/B8CJ.gba", 0x10fe74, 0x9c
.syntax divided
