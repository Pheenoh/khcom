.syntax unified
	.align 2, 0
	.global task_btl_pop_3
	.thumb
	.thumb_func
	.type task_btl_pop_3, %function
task_btl_pop_3:
	.incbin "roms/B8CJ.gba", 0x30928, 0x18
.syntax divided
