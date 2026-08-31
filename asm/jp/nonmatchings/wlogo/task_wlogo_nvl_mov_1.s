.syntax unified
	.align 2, 0
	.global task_wlogo_nvl_mov_1
	.thumb
	.thumb_func
	.type task_wlogo_nvl_mov_1, %function
task_wlogo_nvl_mov_1:
	.incbin "roms/B8CJ.gba", 0xb57f0, 0x174
.syntax divided
