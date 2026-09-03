.syntax unified
	.text
	.align 2, 0
	.global mode_sio_btl_cardget_0
	.thumb
	.thumb_func
	.type mode_sio_btl_cardget_0, %function
mode_sio_btl_cardget_0:
	.incbin "roms/B8CP.gba", 0xaf824, 0xac
.syntax divided
