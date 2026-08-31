.syntax unified
	.align 2, 0
	.global task_wlogo_atl_2
	.thumb
	.thumb_func
	.type task_wlogo_atl_2, %function
task_wlogo_atl_2:
	.incbin "roms/B8CJ.gba", 0xb54e8, 0x4
.syntax divided
