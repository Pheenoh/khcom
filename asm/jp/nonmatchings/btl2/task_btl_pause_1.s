.syntax unified
	.align 2, 0
	.global task_btl_pause_1
	.thumb
	.thumb_func
	.type task_btl_pause_1, %function
task_btl_pause_1:
	.incbin "roms/B8CJ.gba", 0x30254, 0x340
.syntax divided
