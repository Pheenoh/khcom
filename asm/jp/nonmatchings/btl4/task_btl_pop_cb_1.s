.syntax unified
	.align 2, 0
	.global task_btl_pop_cb_1
	.thumb
	.thumb_func
	.type task_btl_pop_cb_1, %function
task_btl_pop_cb_1:
	.incbin "roms/B8CJ.gba", 0x5cd04, 0x20
.syntax divided
