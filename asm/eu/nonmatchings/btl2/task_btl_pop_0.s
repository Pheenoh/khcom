.syntax unified
	.text
	.align 2, 0
	.global task_btl_pop_0
	.thumb
	.thumb_func
	.type task_btl_pop_0, %function
task_btl_pop_0:
	.incbin "roms/B8CP.gba", 0x347a0, 0x47c
.syntax divided
