.syntax unified
	.align 2, 0
	.global mode_sio_chg_card_0
	.thumb
	.thumb_func
	.type mode_sio_chg_card_0, %function
mode_sio_chg_card_0:
	.incbin "roms/B8CJ.gba", 0xb1d94, 0x66c
.syntax divided
