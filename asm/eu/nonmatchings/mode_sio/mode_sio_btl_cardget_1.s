.syntax unified
	.text
	.align 2, 0
	.global mode_sio_btl_cardget_1
	.thumb
	.thumb_func
	.type mode_sio_btl_cardget_1, %function
mode_sio_btl_cardget_1:
	.incbin "roms/B8CP.gba", 0xafadc, 0x1e4
.syntax divided
