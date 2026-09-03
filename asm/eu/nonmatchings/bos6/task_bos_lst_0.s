.syntax unified
	.text
	.align 2, 0
	.global task_bos_lst_0
	.thumb
	.thumb_func
	.type task_bos_lst_0, %function
task_bos_lst_0:
	.incbin "roms/B8CP.gba", 0x10aeb8, 0x414
.syntax divided
