.syntax unified
	.align 2, 0
	.global mode_battle_2
	.thumb
	.thumb_func
	.type mode_battle_2, %function
mode_battle_2:
	.incbin "roms/B8CJ.gba", 0xa5a4, 0x64
.syntax divided
