.syntax unified
	.align 2, 0
	.global task_bos_lst_edg_1
	.thumb
	.thumb_func
	.type task_bos_lst_edg_1, %function
task_bos_lst_edg_1:
	.incbin "roms/B8CJ.gba", 0x11075c, 0x130
.syntax divided
