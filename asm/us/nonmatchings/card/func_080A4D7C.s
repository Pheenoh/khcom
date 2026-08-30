.syntax unified
	.align 2, 0
	.global func_080A4D7C
	.thumb
	.thumb_func
	.type func_080A4D7C, %function
func_080A4D7C: @ 080A4D7C
	adds r1, r0, #0x0
	ldr r0, _080A4D8C @ =0x02034B00
	ldr r3, [r0, #0x00]
	cmp r3, #0x00
	bne _080A4D90
	movs r0, #0x00
	b _080A4DA6
	.byte 0x00, 0x00
_080A4D8C: .4byte 0x02034B00
_080A4D90:
	movs r2, #0x86
	lsls r2, r2, #0x01
	adds r0, r3, r2
	ldr r2, [r1, #0x04]
	ldr r1, [r1, #0x00]
	str r1, [r0, #0x00]
	str r2, [r0, #0x04]
	ldr r0, _080A4DA8 @ =0x00000145
	adds r1, r3, r0
	movs r0, #0x01
	strb r0, [r1, #0x00]
_080A4DA6:
	bx lr
_080A4DA8: .4byte 0x00000145
.syntax divided
