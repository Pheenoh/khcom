.syntax unified
	.text
	.align 2, 0
	.global ld_r3_tp_adr_i_unchecked
	.thumb
	.thumb_func
	.type ld_r3_tp_adr_i_unchecked, %function
ld_r3_tp_adr_i_unchecked:
	.incbin "roms/B8CP.gba", 0x11e82c, 0xc
.syntax divided
