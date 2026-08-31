.syntax unified
	.align 2, 0
	.global task_btl_lockon_3
	.thumb
	.thumb_func
	.type task_btl_lockon_3, %function
task_btl_lockon_3:
	.incbin "roms/B8CJ.gba", 0x1d5fc, 0x18
.syntax divided
