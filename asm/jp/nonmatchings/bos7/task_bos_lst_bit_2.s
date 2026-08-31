.syntax unified
	.align 2, 0
	.global task_bos_lst_bit_2
	.thumb
	.thumb_func
	.type task_bos_lst_bit_2, %function
task_bos_lst_bit_2:
	.incbin "roms/B8CJ.gba", 0x1114d8, 0xd8
.syntax divided
