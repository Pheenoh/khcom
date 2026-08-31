.syntax unified
	.align 2, 0
	.global task_wlogo_agr_1
	.thumb
	.thumb_func
	.type task_wlogo_agr_1, %function
task_wlogo_agr_1:
	.incbin "roms/B8CJ.gba", 0xb60d4, 0x394
.syntax divided
