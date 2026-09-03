.syntax unified
	.text
	.align 2, 0
	.global mode_sio_dbg_flg_1
	.thumb
	.thumb_func
	.type mode_sio_dbg_flg_1, %function
mode_sio_dbg_flg_1:
	.incbin "roms/B8CP.gba", 0xc36b0, 0x3e8
.syntax divided
