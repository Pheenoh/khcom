.syntax unified
	.align 2, 0
	.global func_080A4DAC
	.thumb
	.thumb_func
	.type func_080A4DAC, %function
func_080A4DAC: @ 080A4DAC
	ldr r0, _080A4DB8 @ =0x02034B00
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080A4DBC
	movs r0, #0x00
	b _080A4DC8
_080A4DB8: .4byte 0x02034B00
_080A4DBC:
	movs r2, #0xA3
	lsls r2, r2, #0x01
	adds r1, r0, r2
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r0, #0x01
_080A4DC8:
	bx lr
	.byte 0x00, 0x00
.syntax divided
