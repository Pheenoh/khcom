.syntax unified
	.align 2, 0
	.global mode_sio_dbg_flg_2
	.thumb
	.thumb_func
	.type mode_sio_dbg_flg_2, %function
mode_sio_dbg_flg_2:
	.incbin "roms/B8CJ.gba", 0xc73f8, 0x28
.syntax divided
