.syntax unified
	.align 2, 0
	.global task_wlogo_atl_3
	.thumb
	.thumb_func
	.type task_wlogo_atl_3, %function
task_wlogo_atl_3:
	.incbin "roms/B8CJ.gba", 0xb54ec, 0x28
.syntax divided
