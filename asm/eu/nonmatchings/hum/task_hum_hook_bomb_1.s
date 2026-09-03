.syntax unified
	.text
	.align 2, 0
	.global task_hum_hook_bomb_1
	.thumb
	.thumb_func
	.type task_hum_hook_bomb_1, %function
task_hum_hook_bomb_1:
	.incbin "roms/B8CP.gba", 0x5112c, 0x258
.syntax divided
