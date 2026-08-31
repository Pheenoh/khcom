.syntax unified
	.align 2, 0
	.global task_hum_leon_0
	.thumb
	.thumb_func
	.type task_hum_leon_0, %function
task_hum_leon_0:
	.incbin "roms/B8CJ.gba", 0x598e4, 0x7c
.syntax divided
