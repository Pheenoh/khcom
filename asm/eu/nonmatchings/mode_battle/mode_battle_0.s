.syntax unified
	.text
	.align 2, 0
	.global mode_battle_0
	.thumb
	.thumb_func
	.type mode_battle_0, %function
mode_battle_0:
	.incbin "roms/B8CP.gba", 0xa100, 0xaec
.syntax divided
