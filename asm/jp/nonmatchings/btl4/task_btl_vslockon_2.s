.syntax unified
	.align 2, 0
	.global task_btl_vslockon_2
	.thumb
	.thumb_func
	.type task_btl_vslockon_2, %function
task_btl_vslockon_2:
	.incbin "roms/B8CJ.gba", 0x5d21c, 0x60
.syntax divided
