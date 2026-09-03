.syntax unified
	.text
	.align 2, 0
	.global task_btl_premire_1
	.thumb
	.thumb_func
	.type task_btl_premire_1, %function
task_btl_premire_1:
	.incbin "roms/B8CP.gba", 0x35904, 0x4e4
.syntax divided
