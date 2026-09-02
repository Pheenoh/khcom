.syntax unified
	.align 2, 0
	.global ld_r3_tp_adr_i
	.thumb
	.thumb_func
	.type ld_r3_tp_adr_i, %function
ld_r3_tp_adr_i:
	.incbin "roms/B8CJ.gba", 0x11f698, 0xc
.syntax divided
