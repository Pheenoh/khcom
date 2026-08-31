.syntax unified
	.align 2, 0
	.global task_hum_hook_bomb_1
	.thumb
	.thumb_func
	.type task_hum_hook_bomb_1, %function
task_hum_hook_bomb_1:
	.incbin "roms/B8CJ.gba", 0x4cccc, 0x258
.syntax divided
