.syntax unified
	.align 2, 0
	.global task_wlogo_tt_line_1
	.thumb
	.thumb_func
	.type task_wlogo_tt_line_1, %function
task_wlogo_tt_line_1:
	.incbin "roms/B8CJ.gba", 0xb781c, 0xb8
.syntax divided
