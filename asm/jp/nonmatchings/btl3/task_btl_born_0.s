.syntax unified
	.align 2, 0
	.global task_btl_born_0
	.thumb
	.thumb_func
	.type task_btl_born_0, %function
task_btl_born_0:
	.incbin "roms/B8CJ.gba", 0x40064, 0x1c
.syntax divided
