.syntax unified
	.text
	.align 2, 0
	.global EnemyUsecard_1
	.thumb
	.thumb_func
	.type EnemyUsecard_1, %function
EnemyUsecard_1:
	.incbin "roms/B8CP.gba", 0x90688, 0x12c
.syntax divided
