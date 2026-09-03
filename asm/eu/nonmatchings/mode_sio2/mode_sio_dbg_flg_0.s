.syntax unified
	.text
	.align 2, 0
	.global mode_sio_dbg_flg_0
	.thumb
	.thumb_func
	.type mode_sio_dbg_flg_0, %function
mode_sio_dbg_flg_0:
	.incbin "roms/B8CP.gba", 0xc34c8, 0x1e8
.syntax divided
