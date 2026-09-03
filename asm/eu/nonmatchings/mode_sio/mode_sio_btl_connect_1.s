.syntax unified
	.text
	.align 2, 0
	.global mode_sio_btl_connect_1
	.thumb
	.thumb_func
	.type mode_sio_btl_connect_1, %function
mode_sio_btl_connect_1:
	.incbin "roms/B8CP.gba", 0xac588, 0x268
.syntax divided
