.syntax unified
	.text
	.align 2, 0
	.global mode_sio_btl_option_2
	.thumb
	.thumb_func
	.type mode_sio_btl_option_2, %function
mode_sio_btl_option_2:
	.incbin "roms/B8CP.gba", 0xae710, 0x144
.syntax divided
