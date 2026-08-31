.syntax unified
	.align 2, 0
	.global task_wlogo_hlw_1
	.thumb
	.thumb_func
	.type task_wlogo_hlw_1, %function
task_wlogo_hlw_1:
	.incbin "roms/B8CJ.gba", 0xb5d64, 0xd4
.syntax divided
