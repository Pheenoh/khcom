.syntax unified
	.align 2, 0
	.global task_btl_premire_1
	.thumb
	.thumb_func
	.type task_btl_premire_1, %function
task_btl_premire_1:
	.incbin "roms/B8CJ.gba", 0x3150c, 0x4e4
.syntax divided
