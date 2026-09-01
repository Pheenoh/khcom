.syntax unified
	.align 2, 0
	.global task_bos_lst_1
	.thumb
	.thumb_func
	.type task_bos_lst_1, %function
task_bos_lst_1:
	.incbin "roms/B8CJ.gba", 0x10f344, 0x51c
.syntax divided
