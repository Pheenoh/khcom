.syntax unified
	.align 2, 0
	.global mode_sio_btl_connect_1
	.thumb
	.thumb_func
	.type mode_sio_btl_connect_1, %function
mode_sio_btl_connect_1:
	.incbin "roms/B8CJ.gba", 0xaed60, 0x188
.syntax divided
