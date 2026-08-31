.syntax unified
	.align 2, 0
	.global mode_sio_chg_card_2
	.thumb
	.thumb_func
	.type mode_sio_chg_card_2, %function
mode_sio_chg_card_2:
	.incbin "roms/B8CJ.gba", 0xb2cb8, 0xdc
.syntax divided
