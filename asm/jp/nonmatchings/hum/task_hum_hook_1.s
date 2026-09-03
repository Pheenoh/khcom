.syntax unified
	.text
	.align 2, 0
	.global task_hum_hook_1
	.thumb
	.thumb_func
	.type task_hum_hook_1, %function
task_hum_hook_1:
	.incbin "roms/B8CJ.gba", 0x4b658, 0x1260
.syntax divided
