.syntax unified
	.text
	.align 2, 0
	.global task_hum_leon_1
	.thumb
	.thumb_func
	.type task_hum_leon_1, %function
task_hum_leon_1:
	.incbin "roms/B8CP.gba", 0x5ddec, 0x320
.syntax divided
