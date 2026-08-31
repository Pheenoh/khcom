.syntax unified
	.align 2, 0
	.global mode_sio_btl_option_2
	.thumb
	.thumb_func
	.type mode_sio_btl_option_2, %function
mode_sio_btl_option_2:
	.incbin "roms/B8CJ.gba", 0xb05b4, 0x144
.syntax divided
