.syntax unified
	.align 2, 0
	.global func_080F0108
	.thumb
	.thumb_func
	.type func_080F0108, %function
func_080F0108: @ 080F0108
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r5, r4, #0x0
	adds r5, #0x08
	ldr r7, [r5, #0x08]
	cmp r1, #0x00
	beq _080F0144
	cmp r1, #0x01
	bne _080F0144
	adds r3, r4, #0x0
	adds r3, #0xDC
	ldr r2, _080F013C @ =0x08121400
	ldr r0, _080F0140 @ =0x03007480
	ldr r0, [r0, #0x00]
	movs r1, #0xFF
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	b _080F0162
_080F013C: .4byte 0x08121400
_080F0140: .4byte 0x03007480
_080F0144:
	adds r3, r4, #0x0
	adds r3, #0xDC
	ldr r2, _080F0184 @ =0x08121400
	ldr r0, _080F0188 @ =0x03007480
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x01
	movs r1, #0xFF
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
_080F0162:
	ldr r1, [r3, #0x00]
	adds r2, r1, r0
	adds r6, r3, #0x0
	ldrh r1, [r4, #0x04]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _080F018C
	ldr r4, [r5, #0x08]
	subs r0, r2, r4
	movs r1, #0x50
	bl func_0811D5EC
	adds r4, r4, r0
	str r4, [r5, #0x08]
	b _080F0196
	.byte 0x00, 0x00
_080F0184: .4byte 0x08121400
_080F0188: .4byte 0x03007480
_080F018C:
	ldr r1, [r5, #0x08]
	subs r0, r2, r1
	asrs r0, r0, #0x04
	adds r1, r1, r0
	str r1, [r5, #0x08]
_080F0196:
	ldr r1, [r5, #0x0C]
	ldr r0, [r5, #0x08]
	cmp r1, r0
	bge _080F01A6
	str r7, [r5, #0x08]
	ldr r1, _080F01AC @ =0xFFFFE400
	adds r0, r7, r1
	str r0, [r6, #0x00]
_080F01A6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080F01AC: .4byte 0xFFFFE400
.syntax divided
