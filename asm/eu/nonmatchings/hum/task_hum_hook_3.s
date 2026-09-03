.syntax unified
	.text
	.align 2, 0
	.global task_hum_hook_3
	.thumb
	.thumb_func
	.type task_hum_hook_3, %function
task_hum_hook_3:
	.incbin "roms/B8CP.gba", 0x50d34, 0x28
.syntax divided
