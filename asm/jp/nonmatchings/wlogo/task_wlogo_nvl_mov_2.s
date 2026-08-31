.syntax unified
	.align 2, 0
	.global task_wlogo_nvl_mov_2
	.thumb
	.thumb_func
	.type task_wlogo_nvl_mov_2, %function
task_wlogo_nvl_mov_2:
	.incbin "roms/B8CJ.gba", 0xb5964, 0x38
.syntax divided
