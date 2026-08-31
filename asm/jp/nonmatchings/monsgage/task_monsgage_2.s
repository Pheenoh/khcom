.syntax unified
	.align 2, 0
	.global task_monsgage_2
	.thumb
	.thumb_func
	.type task_monsgage_2, %function
task_monsgage_2:
	.incbin "roms/B8CJ.gba", 0x5cb98, 0x84
.syntax divided
