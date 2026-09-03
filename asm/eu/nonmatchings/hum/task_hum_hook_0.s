.syntax unified
	.text
	.align 2, 0
	.global task_hum_hook_0
	.thumb
	.thumb_func
	.type task_hum_hook_0, %function
task_hum_hook_0:
	.incbin "roms/B8CP.gba", 0x4fa04, 0xb4
.syntax divided
