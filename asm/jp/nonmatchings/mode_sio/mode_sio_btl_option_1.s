.syntax unified
	.align 2, 0
	.global mode_sio_btl_option_1
	.thumb
	.thumb_func
	.type mode_sio_btl_option_1, %function
mode_sio_btl_option_1:
	.incbin "roms/B8CJ.gba", 0xaf6d0, 0x100
.syntax divided
