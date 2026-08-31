.syntax unified
	.align 2, 0
	.global task_hum_hook_moon_3
	.thumb
	.thumb_func
	.type task_hum_hook_moon_3, %function
task_hum_hook_moon_3:
	.incbin "roms/B8CJ.gba", 0x4cb28, 0x18
.syntax divided
