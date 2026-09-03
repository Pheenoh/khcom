.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_arm_0
	.thumb
	.thumb_func
	.type task_bos_tm_arm_0, %function
task_bos_tm_arm_0:
	.incbin "roms/B8CP.gba", 0xb7950, 0x2d8
.syntax divided
