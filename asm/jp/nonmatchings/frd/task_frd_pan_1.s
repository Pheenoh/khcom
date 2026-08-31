.syntax unified
	.align 2, 0
	.global task_frd_pan_1
	.thumb
	.thumb_func
	.type task_frd_pan_1, %function
task_frd_pan_1:
	.incbin "roms/B8CJ.gba", 0x48aa4, 0x504
.syntax divided
