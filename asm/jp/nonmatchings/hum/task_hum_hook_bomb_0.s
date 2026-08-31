.syntax unified
	.align 2, 0
	.global task_hum_hook_bomb_0
	.thumb
	.thumb_func
	.type task_hum_hook_bomb_0, %function
task_hum_hook_bomb_0:
	.incbin "roms/B8CJ.gba", 0x4cb40, 0x18c
.syntax divided
