.syntax unified
	.align 2, 0
	.global task_emy_16_2
	.thumb
	.thumb_func
	.type task_emy_16_2, %function
task_emy_16_2:
	.incbin "roms/B8CJ.gba", 0x38e24, 0x1c
.syntax divided
