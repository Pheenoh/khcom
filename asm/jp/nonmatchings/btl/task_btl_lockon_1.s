.syntax unified
	.align 2, 0
	.global task_btl_lockon_1
	.thumb
	.thumb_func
	.type task_btl_lockon_1, %function
task_btl_lockon_1:
	.incbin "roms/B8CJ.gba", 0x1d530, 0x64
.syntax divided
