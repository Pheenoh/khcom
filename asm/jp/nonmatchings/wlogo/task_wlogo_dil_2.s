.syntax unified
	.align 2, 0
	.global task_wlogo_dil_2
	.thumb
	.thumb_func
	.type task_wlogo_dil_2, %function
task_wlogo_dil_2:
	.incbin "roms/B8CJ.gba", 0xb5ffc, 0x34
.syntax divided
