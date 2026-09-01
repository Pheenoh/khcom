.syntax unified
	.align 2, 0
	.global mode_sio_chg_connect_2
	.thumb
	.thumb_func
	.type mode_sio_chg_connect_2, %function
mode_sio_chg_connect_2:
	.incbin "roms/B8CJ.gba", 0xb1c78, 0x2c
.syntax divided
