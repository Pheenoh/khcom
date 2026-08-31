.syntax unified
	.align 2, 0
	.global task_wlogo_atl_1
	.thumb
	.thumb_func
	.type task_wlogo_atl_1, %function
task_wlogo_atl_1:
	.incbin "roms/B8CJ.gba", 0xb5394, 0x154
.syntax divided
