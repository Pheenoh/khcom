.syntax unified
	.align 2, 0
	.global func_0803473C
	.thumb
	.thumb_func
	.type func_0803473C, %function
func_0803473C: @ 0803473C
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, _08034768 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0x2C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x53
	beq _080347A0
	cmp r0, #0x53
	bgt _0803476C
	cmp r0, #0x2D
	beq _08034784
	cmp r0, #0x2D
	ble _080347BE
	cmp r0, #0x40
	beq _08034792
	b _080347BE
	.byte 0x00, 0x00
_08034768: .4byte 0x02039BA0
_0803476C:
	cmp r0, #0xAD
	beq _080347B2
	cmp r0, #0xAD
	bgt _0803477A
	cmp r0, #0x80
	beq _080347AE
	b _080347BE
_0803477A:
	cmp r0, #0xC0
	beq _080347B6
	cmp r0, #0xD3
	beq _080347BA
	b _080347BE
_08034784:
	movs r3, #0x04
	adds r2, r5, #0x0
	adds r2, #0xA4
	ldrh r1, [r2, #0x00]
	movs r0, #0x02
	orrs r0, r1
	b _080347CA
_08034792:
	movs r3, #0x03
	adds r2, r5, #0x0
	adds r2, #0xA4
	ldrh r1, [r2, #0x00]
	movs r0, #0x02
	orrs r0, r1
	b _080347CA
_080347A0:
	movs r3, #0x02
	adds r2, r5, #0x0
	adds r2, #0xA4
	ldrh r1, [r2, #0x00]
	movs r0, #0x02
	orrs r0, r1
	b _080347CA
_080347AE:
	movs r3, #0x01
	b _080347C0
_080347B2:
	movs r3, #0x02
	b _080347C0
_080347B6:
	movs r3, #0x03
	b _080347C0
_080347BA:
	movs r3, #0x04
	b _080347C0
_080347BE:
	movs r3, #0x00
_080347C0:
	adds r2, r5, #0x0
	adds r2, #0xA4
	ldrh r1, [r2, #0x00]
	ldr r0, _0803480C @ =0x0000FFFD
	ands r0, r1
_080347CA:
	strh r0, [r2, #0x00]
	adds r1, r5, #0x0
	adds r1, #0xA8
	ldr r0, [r1, #0x00]
	cmp r0, r6
	bne _080347DA
	movs r0, #0x04
	orrs r7, r0
_080347DA:
	str r6, [r1, #0x00]
	lsls r4, r6, #0x02
	adds r4, r4, r6
	lsls r4, r4, #0x04
	lsls r0, r3, #0x04
	ldr r1, _08034810 @ =0x0813CDDC
	adds r0, r0, r1
	adds r4, r4, r0
	adds r0, r5, #0x0
	adds r0, #0x08
	ldrb r1, [r4, #0x0C]
	ldr r3, [r4, #0x04]
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	adds r2, r7, #0x0
	bl func_08005974
	ldr r0, [r5, #0x00]
	ldr r1, [r4, #0x08]
	bl func_08002A10
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0803480C: .4byte 0x0000FFFD
_08034810: .4byte 0x0813CDDC
.syntax divided
