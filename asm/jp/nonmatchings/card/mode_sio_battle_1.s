.syntax unified
	.text
	.align 2, 0
	.global mode_sio_battle_1
	.thumb
	.thumb_func
	.type mode_sio_battle_1, %function
mode_sio_battle_1:
	.incbin "roms/B8CJ.gba", 0xae890, 0x374
.syntax divided
