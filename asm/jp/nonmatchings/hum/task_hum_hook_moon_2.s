.syntax unified
	.align 2, 0
	.global task_hum_hook_moon_2
	.thumb
	.thumb_func
	.type task_hum_hook_moon_2, %function
task_hum_hook_moon_2:
	.incbin "roms/B8CJ.gba", 0x4c950, 0x1d8
.syntax divided
