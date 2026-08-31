.syntax unified
	.align 2, 0
	.global task_btl_hpoth_1
	.thumb
	.thumb_func
	.type task_btl_hpoth_1, %function
task_btl_hpoth_1:
	.incbin "roms/B8CJ.gba", 0x5d544, 0x2ac
.syntax divided
