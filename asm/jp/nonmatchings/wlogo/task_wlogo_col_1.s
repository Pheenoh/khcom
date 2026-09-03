.syntax unified
	.text
	.align 2, 0
	.global task_wlogo_col_1
	.thumb
	.thumb_func
	.type task_wlogo_col_1, %function
task_wlogo_col_1:
	.incbin "roms/B8CJ.gba", 0xb5b4c, 0x180
.syntax divided
