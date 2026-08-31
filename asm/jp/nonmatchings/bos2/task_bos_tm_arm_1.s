.syntax unified
	.align 2, 0
	.global task_bos_tm_arm_1
	.thumb
	.thumb_func
	.type task_bos_tm_arm_1, %function
task_bos_tm_arm_1:
	.incbin "roms/B8CJ.gba", 0xbc938, 0xbc
.syntax divided
