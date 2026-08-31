.syntax unified
	.align 2, 0
	.global mode_sio_chg_connect_1
	.thumb
	.thumb_func
	.type mode_sio_chg_connect_1, %function
mode_sio_chg_connect_1:
	.incbin "roms/B8CJ.gba", 0xb1be4, 0x94
.syntax divided
