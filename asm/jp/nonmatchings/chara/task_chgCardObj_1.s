.syntax unified
	.align 2, 0
	.global task_chgCardObj_1
	.thumb
	.thumb_func
	.type task_chgCardObj_1, %function
task_chgCardObj_1:
	.incbin "roms/B8CJ.gba", 0xc5408, 0x158
.syntax divided
