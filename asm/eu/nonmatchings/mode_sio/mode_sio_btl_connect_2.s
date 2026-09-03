.syntax unified
	.text
	.align 2, 0
	.global mode_sio_btl_connect_2
	.thumb
	.thumb_func
	.type mode_sio_btl_connect_2, %function
mode_sio_btl_connect_2:
	.incbin "roms/B8CP.gba", 0xac7f0, 0x2c
.syntax divided
