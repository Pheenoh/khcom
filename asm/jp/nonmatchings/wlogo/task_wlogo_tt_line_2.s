.syntax unified
	.align 2, 0
	.global task_wlogo_tt_line_2
	.thumb
	.thumb_func
	.type task_wlogo_tt_line_2, %function
task_wlogo_tt_line_2:
	.incbin "roms/B8CJ.gba", 0xb78d4, 0xc
.syntax divided
