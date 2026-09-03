.syntax unified
	.text
	.align 2, 0
	.global mode_sio_battle_0
	.thumb
	.thumb_func
	.type mode_sio_battle_0, %function
mode_sio_battle_0:
	.incbin "roms/B8CJ.gba", 0xae658, 0x238
.syntax divided
