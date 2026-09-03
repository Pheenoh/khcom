.syntax unified
	.text
	.align 2, 0
	.global task_wlogo_tvt_1
	.thumb
	.thumb_func
	.type task_wlogo_tvt_1, %function
task_wlogo_tvt_1:
	.incbin "roms/B8CJ.gba", 0xb680c, 0x2d0
.syntax divided
