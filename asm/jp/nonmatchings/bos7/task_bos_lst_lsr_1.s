.syntax unified
	.align 2, 0
	.global task_bos_lst_lsr_1
	.thumb
	.thumb_func
	.type task_bos_lst_lsr_1, %function
task_bos_lst_lsr_1:
	.incbin "roms/B8CJ.gba", 0x1117a4, 0x148
.syntax divided
