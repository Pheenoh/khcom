.syntax unified
	.align 2, 0
	.global mode_sio_dbg_flg_0
	.thumb
	.thumb_func
	.type mode_sio_dbg_flg_0, %function
mode_sio_dbg_flg_0:
	.incbin "roms/B8CJ.gba", 0xc70f0, 0x134
.syntax divided
