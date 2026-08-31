.syntax unified
	.align 2, 0
	.global task_bos_tm_arm_2
	.thumb
	.thumb_func
	.type task_bos_tm_arm_2, %function
task_bos_tm_arm_2:
	.incbin "roms/B8CJ.gba", 0xbc9f4, 0x230
.syntax divided
