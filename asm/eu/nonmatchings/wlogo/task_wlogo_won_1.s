.syntax unified
	.text
	.align 2, 0
	.global task_wlogo_won_1
	.thumb
	.thumb_func
	.type task_wlogo_won_1, %function
task_wlogo_won_1:
	.incbin "roms/B8CP.gba", 0xb1314, 0x188
.syntax divided
