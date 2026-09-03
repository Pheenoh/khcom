.syntax unified
	.text
	.align 2, 0
	.global task_bos_lst_bit_1
	.thumb
	.thumb_func
	.type task_bos_lst_bit_1, %function
task_bos_lst_bit_1:
	.incbin "roms/B8CP.gba", 0x10f4d4, 0x748
.syntax divided
