.syntax unified
	.text
	.align 2, 0
	.global task_frd_pan_1
	.thumb
	.thumb_func
	.type task_frd_pan_1, %function
task_frd_pan_1:
	.incbin "roms/B8CP.gba", 0x4cef0, 0x504
.syntax divided
