.syntax unified
	.align 2, 0
	.global task_hum_hook_bomb_3
	.thumb
	.thumb_func
	.type task_hum_hook_bomb_3, %function
task_hum_hook_bomb_3:
	.incbin "roms/B8CJ.gba", 0x4cff4, 0x6c
.syntax divided
