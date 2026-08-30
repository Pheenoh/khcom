.syntax unified
	.align 2, 0
	.global func_080CAA50
	.thumb
	.thumb_func
	.type func_080CAA50, %function
func_080CAA50: @ 080CAA50
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, _080CAA78 @ =0x0203C420
	ldrb r0, [r0, #0x14]
	cmp r0, #0x53
	beq _080CAAB0
	cmp r0, #0x53
	bgt _080CAA7C
	cmp r0, #0x2D
	beq _080CAA94
	cmp r0, #0x2D
	ble _080CAACE
	cmp r0, #0x40
	beq _080CAAA2
	b _080CAACE
	.byte 0x00, 0x00
_080CAA78: .4byte 0x0203C420
_080CAA7C:
	cmp r0, #0xAD
	beq _080CAAC2
	cmp r0, #0xAD
	bgt _080CAA8A
	cmp r0, #0x80
	beq _080CAABE
	b _080CAACE
_080CAA8A:
	cmp r0, #0xC0
	beq _080CAAC6
	cmp r0, #0xD3
	beq _080CAACA
	b _080CAACE
_080CAA94:
	movs r3, #0x04
	adds r2, r5, #0x0
	adds r2, #0xA0
	ldrh r1, [r2, #0x00]
	movs r0, #0x02
	orrs r0, r1
	b _080CAADA
_080CAAA2:
	movs r3, #0x03
	adds r2, r5, #0x0
	adds r2, #0xA0
	ldrh r1, [r2, #0x00]
	movs r0, #0x02
	orrs r0, r1
	b _080CAADA
_080CAAB0:
	movs r3, #0x02
	adds r2, r5, #0x0
	adds r2, #0xA0
	ldrh r1, [r2, #0x00]
	movs r0, #0x02
	orrs r0, r1
	b _080CAADA
_080CAABE:
	movs r3, #0x01
	b _080CAAD0
_080CAAC2:
	movs r3, #0x02
	b _080CAAD0
_080CAAC6:
	movs r3, #0x03
	b _080CAAD0
_080CAACA:
	movs r3, #0x04
	b _080CAAD0
_080CAACE:
	movs r3, #0x00
_080CAAD0:
	adds r2, r5, #0x0
	adds r2, #0xA0
	ldrh r1, [r2, #0x00]
	ldr r0, _080CAB1C @ =0x0000FFFD
	ands r0, r1
_080CAADA:
	strh r0, [r2, #0x00]
	adds r1, r5, #0x0
	adds r1, #0xA4
	ldr r0, [r1, #0x00]
	cmp r0, r6
	bne _080CAAEA
	movs r0, #0x04
	orrs r7, r0
_080CAAEA:
	str r6, [r1, #0x00]
	lsls r4, r6, #0x02
	adds r4, r4, r6
	lsls r4, r4, #0x04
	lsls r0, r3, #0x04
	ldr r1, _080CAB20 @ =0x096FCF54
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
_080CAB1C: .4byte 0x0000FFFD
_080CAB20: .4byte 0x096FCF54
.syntax divided
