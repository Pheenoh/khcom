.syntax unified
	.align 2, 0
	.global task_wlogo_nvl_1
	.thumb
	.thumb_func
	.type task_wlogo_nvl_1, %function
task_wlogo_nvl_1:
	.incbin "roms/B8CJ.gba", 0xb558c, 0x1b0
.syntax divided
