.syntax unified
	.text
	.align 2, 0
	.global task_hum_hook_3
	.thumb
	.thumb_func
	.type task_hum_hook_3, %function
task_hum_hook_3:
	.incbin "roms/B8CJ.gba", 0x4c8d4, 0x28
.syntax divided
