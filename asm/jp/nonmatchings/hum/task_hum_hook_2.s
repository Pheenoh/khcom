.syntax unified
	.text
	.align 2, 0
	.global task_hum_hook_2
	.thumb
	.thumb_func
	.type task_hum_hook_2, %function
task_hum_hook_2:
	.incbin "roms/B8CJ.gba", 0x4c8b8, 0x1c
.syntax divided
