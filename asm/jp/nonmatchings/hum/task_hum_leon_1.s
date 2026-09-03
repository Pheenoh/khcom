.syntax unified
	.text
	.align 2, 0
	.global task_hum_leon_1
	.thumb
	.thumb_func
	.type task_hum_leon_1, %function
task_hum_leon_1:
	.incbin "roms/B8CJ.gba", 0x59960, 0x320
.syntax divided
