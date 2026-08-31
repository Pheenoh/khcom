.syntax unified
	.align 2, 0
	.global task_hum_leon_3
	.thumb
	.thumb_func
	.type task_hum_leon_3, %function
task_hum_leon_3:
	.incbin "roms/B8CJ.gba", 0x59c8c, 0x3c
.syntax divided
