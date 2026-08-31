.syntax unified
	.align 2, 0
	.global task_btl_start_1
	.thumb
	.thumb_func
	.type task_btl_start_1, %function
task_btl_start_1:
	.incbin "roms/B8CJ.gba", 0x31b64, 0x60
.syntax divided
