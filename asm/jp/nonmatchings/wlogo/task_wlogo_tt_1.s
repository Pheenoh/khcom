.syntax unified
	.align 2, 0
	.global task_wlogo_tt_1
	.thumb
	.thumb_func
	.type task_wlogo_tt_1, %function
task_wlogo_tt_1:
	.incbin "roms/B8CJ.gba", 0xb70a4, 0x454
.syntax divided
