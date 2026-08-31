.syntax unified
	.align 2, 0
	.global task_btl_premire_2
	.thumb
	.thumb_func
	.type task_btl_premire_2, %function
task_btl_premire_2:
	.incbin "roms/B8CJ.gba", 0x319f0, 0xd4
.syntax divided
