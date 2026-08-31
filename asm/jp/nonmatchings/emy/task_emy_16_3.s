.syntax unified
	.align 2, 0
	.global task_emy_16_3
	.thumb
	.thumb_func
	.type task_emy_16_3, %function
task_emy_16_3:
	.incbin "roms/B8CJ.gba", 0x38e40, 0x1c
.syntax divided
