.syntax unified
	.align 2, 0
	.global task_wlogo_dil_1
	.thumb
	.thumb_func
	.type task_wlogo_dil_1, %function
task_wlogo_dil_1:
	.incbin "roms/B8CJ.gba", 0xb5eb8, 0x144
.syntax divided
