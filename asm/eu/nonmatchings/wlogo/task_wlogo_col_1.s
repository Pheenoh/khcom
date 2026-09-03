.syntax unified
	.text
	.align 2, 0
	.global task_wlogo_col_1
	.thumb
	.thumb_func
	.type task_wlogo_col_1, %function
task_wlogo_col_1:
	.incbin "roms/B8CP.gba", 0xb1d9c, 0x180
.syntax divided
