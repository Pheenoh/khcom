.syntax unified
	.align 2, 0
	.global mode_sio_btl_cardget_1
	.thumb
	.thumb_func
	.type mode_sio_btl_cardget_1, %function
mode_sio_btl_cardget_1:
	.incbin "roms/B8CJ.gba", 0xb17a8, 0x160
.syntax divided
