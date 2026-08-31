.syntax unified
	.align 2, 0
	.global task_btl_lockon_2
	.thumb
	.thumb_func
	.type task_btl_lockon_2, %function
task_btl_lockon_2:
	.incbin "roms/B8CJ.gba", 0x1d594, 0x68
.syntax divided
