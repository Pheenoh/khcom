.syntax unified
	.align 2, 0
	.global task_btl_vslockon_1
	.thumb
	.thumb_func
	.type task_btl_vslockon_1, %function
task_btl_vslockon_1:
	.incbin "roms/B8CJ.gba", 0x5d1c0, 0x5c
.syntax divided
