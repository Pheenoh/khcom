.syntax unified
	.align 2, 0
	.global task_btl_pop_1
	.thumb
	.thumb_func
	.type task_btl_pop_1, %function
task_btl_pop_1:
	.incbin "roms/B8CJ.gba", 0x308b4, 0x30
.syntax divided
