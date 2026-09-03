.syntax unified
	.text
	.align 2, 0
	.global task_chgCardObj_1
	.thumb
	.thumb_func
	.type task_chgCardObj_1, %function
task_chgCardObj_1:
	.incbin "roms/B8CP.gba", 0xc1658, 0x158
.syntax divided
