.syntax unified
	.align 2, 0
	.global task_wlogo_tt_3
	.thumb
	.thumb_func
	.type task_wlogo_tt_3, %function
task_wlogo_tt_3:
	.incbin "roms/B8CJ.gba", 0xb7664, 0x38
.syntax divided
