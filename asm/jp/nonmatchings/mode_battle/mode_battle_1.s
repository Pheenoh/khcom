.syntax unified
	.align 2, 0
	.global mode_battle_1
	.thumb
	.thumb_func
	.type mode_battle_1, %function
mode_battle_1:
	.incbin "roms/B8CJ.gba", 0xa4bc, 0xe8
.syntax divided
