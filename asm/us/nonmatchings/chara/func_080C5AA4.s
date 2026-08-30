.syntax unified
	.align 2, 0
	.global func_080C5AA4
	.thumb
	.thumb_func
	.type func_080C5AA4, %function
func_080C5AA4: @ 080C5AA4
	push {r4, lr}
	ldr r0, _080C5AD0 @ =0x0203C3A8
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bne _080C5B34
	ldr r0, _080C5AD4 @ =0x0203C3A0
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bne _080C5B24
	bl func_08001390
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _080C5AE0
	ldr r1, _080C5AD8 @ =0x02039B68
	ldr r0, _080C5ADC @ =0x0000FEFE
	b _080C5AF0
_080C5AD0: .4byte 0x0203C3A8
_080C5AD4: .4byte 0x0203C3A0
_080C5AD8: .4byte 0x02039B68
_080C5ADC: .4byte 0x0000FEFE
_080C5AE0:
	bl func_08001390
	movs r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _080C5B04
	ldr r1, _080C5AF8 @ =0x02039B68
	ldr r0, _080C5AFC @ =0x0000AFAF
_080C5AF0:
	strh r0, [r1, #0x00]
	ldr r4, _080C5B00 @ =0x0203C3B0
	b _080C5B16
	.byte 0x00, 0x00
_080C5AF8: .4byte 0x02039B68
_080C5AFC: .4byte 0x0000AFAF
_080C5B00: .4byte 0x0203C3B0
_080C5B04:
	ldr r1, _080C5B1C @ =0x02039B68
	ldr r4, _080C5B20 @ =0x0203C3B0
	adds r0, r1, #0x0
	movs r3, #0x00
	adds r2, r1, #0x6
_080C5B0E:
	strh r3, [r2, #0x00]
	subs r2, #0x02
	cmp r2, r0
	bge _080C5B0E
_080C5B16:
	ldrh r0, [r4, #0x00]
	strh r0, [r1, #0x02]
	b _080C5B42
_080C5B1C: .4byte 0x02039B68
_080C5B20: .4byte 0x0203C3B0
_080C5B24:
	ldr r1, _080C5B2C @ =0x02039B68
	ldr r0, _080C5B30 @ =0x0000ECEC
	strh r0, [r1, #0x00]
	b _080C5B42
_080C5B2C: .4byte 0x02039B68
_080C5B30: .4byte 0x0000ECEC
_080C5B34:
	ldr r1, _080C5B4C @ =0x02039B68
	movs r2, #0x00
	adds r0, r1, #0x6
_080C5B3A:
	strh r2, [r0, #0x00]
	subs r0, #0x02
	cmp r0, r1
	bge _080C5B3A
_080C5B42:
	movs r0, #0x00
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080C5B4C: .4byte 0x02039B68
.syntax divided
