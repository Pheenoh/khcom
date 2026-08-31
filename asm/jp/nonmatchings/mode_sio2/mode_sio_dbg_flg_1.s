.syntax unified
	.align 2, 0
	.global mode_sio_dbg_flg_1
	.thumb
	.thumb_func
	.type mode_sio_dbg_flg_1, %function
mode_sio_dbg_flg_1:
	.incbin "roms/B8CJ.gba", 0xc7224, 0x1d4
.syntax divided
