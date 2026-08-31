.syntax unified
	.align 2, 0
	.global task_bos_lst_edg_2
	.thumb
	.thumb_func
	.type task_bos_lst_edg_2, %function
task_bos_lst_edg_2:
	.incbin "roms/B8CJ.gba", 0x11088c, 0x74
.syntax divided
