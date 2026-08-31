.syntax unified
	.align 2, 0
	.global task_bos_lst_bit_0
	.thumb
	.thumb_func
	.type task_bos_lst_bit_0, %function
task_bos_lst_bit_0:
	.incbin "roms/B8CJ.gba", 0x110bbc, 0x1d0
.syntax divided
