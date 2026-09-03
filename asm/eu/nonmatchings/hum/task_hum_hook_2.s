.syntax unified
	.text
	.align 2, 0
	.global task_hum_hook_2
	.thumb
	.thumb_func
	.type task_hum_hook_2, %function
task_hum_hook_2:
	.incbin "roms/B8CP.gba", 0x50d18, 0x1c
.syntax divided
