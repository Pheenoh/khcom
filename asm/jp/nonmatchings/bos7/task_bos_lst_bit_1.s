.syntax unified
	.align 2, 0
	.global task_bos_lst_bit_1
	.thumb
	.thumb_func
	.type task_bos_lst_bit_1, %function
task_bos_lst_bit_1:
	.incbin "roms/B8CJ.gba", 0x110d8c, 0x74c
.syntax divided
