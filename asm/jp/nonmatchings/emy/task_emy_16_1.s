.syntax unified
	.align 2, 0
	.global task_emy_16_1
	.thumb
	.thumb_func
	.type task_emy_16_1, %function
task_emy_16_1:
	.incbin "roms/B8CJ.gba", 0x38c10, 0x214
.syntax divided
