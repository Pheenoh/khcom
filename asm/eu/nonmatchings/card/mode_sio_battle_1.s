.syntax unified
	.text
	.align 2, 0
	.global mode_sio_battle_1
	.thumb
	.thumb_func
	.type mode_sio_battle_1, %function
mode_sio_battle_1:
	.incbin "roms/B8CP.gba", 0xabcec, 0x728
.syntax divided
