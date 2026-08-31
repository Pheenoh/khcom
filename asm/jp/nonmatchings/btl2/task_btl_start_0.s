.syntax unified
	.align 2, 0
	.global task_btl_start_0
	.thumb
	.thumb_func
	.type task_btl_start_0, %function
task_btl_start_0:
	.incbin "roms/B8CJ.gba", 0x31aec, 0x78
.syntax divided
