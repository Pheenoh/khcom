.syntax unified
	.align 2, 0
	.global task_btl_hpoth_2
	.thumb
	.thumb_func
	.type task_btl_hpoth_2, %function
task_btl_hpoth_2:
	.incbin "roms/B8CJ.gba", 0x5d7f0, 0x1f4
.syntax divided
