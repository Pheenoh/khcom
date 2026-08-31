.syntax unified
	.align 2, 0
	.global task_btl_born_1
	.thumb
	.thumb_func
	.type task_btl_born_1, %function
task_btl_born_1:
	.incbin "roms/B8CJ.gba", 0x40080, 0xd0
.syntax divided
