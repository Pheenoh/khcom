.syntax unified
	.align 2, 0
	.global task_monsgage_1
	.thumb
	.thumb_func
	.type task_monsgage_1, %function
task_monsgage_1:
	.incbin "roms/B8CJ.gba", 0x5c9c0, 0x1d8
.syntax divided
