.syntax unified
	.text
	.align 2, 0
	.global task_emy_01_1
	.thumb
	.thumb_func
	.type task_emy_01_1, %function
task_emy_01_1:
	.incbin "roms/B8CP.gba", 0x3b700, 0x1fc
.syntax divided
