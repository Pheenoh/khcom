.syntax unified
	.align 2, 0
	.global task_btl_pause_3
	.thumb
	.thumb_func
	.type task_btl_pause_3, %function
task_btl_pause_3:
	.incbin "roms/B8CJ.gba", 0x305e8, 0x1c
.syntax divided
