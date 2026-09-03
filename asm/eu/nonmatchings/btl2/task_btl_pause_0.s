.syntax unified
	.text
	.align 2, 0
	.global task_btl_pause_0
	.thumb
	.thumb_func
	.type task_btl_pause_0, %function
task_btl_pause_0:
	.incbin "roms/B8CP.gba", 0x3436c, 0x84
.syntax divided
