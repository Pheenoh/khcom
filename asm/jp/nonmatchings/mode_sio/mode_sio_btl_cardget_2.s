.syntax unified
	.align 2, 0
	.global mode_sio_btl_cardget_2
	.thumb
	.thumb_func
	.type mode_sio_btl_cardget_2, %function
mode_sio_btl_cardget_2:
	.incbin "roms/B8CJ.gba", 0xb1908, 0x4
.syntax divided
