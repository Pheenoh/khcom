.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ld_r3_tp_adr_i
	.thumb
	.thumb_func
	.type ld_r3_tp_adr_i, %function
ld_r3_tp_adr_i:
	ldr r2, [r1, 0x40]
ld_r3_tp_adr_i_r2:
	adds r3, r2, 0x1
	str r3, [r1, 0x40]
	ldrb r3, [r2]
	b chk_adr_r2
	.align 2, 0
.syntax divided
