.syntax unified
	.align 2, 0
	.global task_btl_pop_cb_2
	.thumb
	.thumb_func
	.type task_btl_pop_cb_2, %function
task_btl_pop_cb_2:
	.incbin "roms/B8CJ.gba", 0x5cd24, 0x44
.syntax divided
