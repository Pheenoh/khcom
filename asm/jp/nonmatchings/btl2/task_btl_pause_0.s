.syntax unified
	.align 2, 0
	.global task_btl_pause_0
	.thumb
	.thumb_func
	.type task_btl_pause_0, %function
task_btl_pause_0:
	.incbin "roms/B8CJ.gba", 0x301f8, 0x5c
.syntax divided
