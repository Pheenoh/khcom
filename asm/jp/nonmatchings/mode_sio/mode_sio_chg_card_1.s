.syntax unified
	.align 2, 0
	.global mode_sio_chg_card_1
	.thumb
	.thumb_func
	.type mode_sio_chg_card_1, %function
mode_sio_chg_card_1:
	.incbin "roms/B8CJ.gba", 0xb2400, 0xe4
.syntax divided
