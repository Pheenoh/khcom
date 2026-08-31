.syntax unified
	.align 2, 0
	.global task_wlogo_tt_2
	.thumb
	.thumb_func
	.type task_wlogo_tt_2, %function
task_wlogo_tt_2:
	.incbin "roms/B8CJ.gba", 0xb74f8, 0x16c
.syntax divided
