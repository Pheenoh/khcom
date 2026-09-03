.syntax unified
	.text
	.align 2, 0
	.global task_emy_08_1
	.thumb
	.thumb_func
	.type task_emy_08_1, %function
task_emy_08_1:
	.incbin "roms/B8CP.gba", 0x3c6e0, 0x500
.syntax divided
