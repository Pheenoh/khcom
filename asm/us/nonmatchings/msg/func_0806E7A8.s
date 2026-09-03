.syntax unified
	.align 2, 0
	.global func_0806E7A8
	.thumb
	.thumb_func
	.type func_0806E7A8, %function
func_0806E7A8: @ 0806E7A8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	movs r1, #0xD0
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r1, [r0, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	ldr r1, [r5, #0x00]
	adds r7, r1, r0
	ldr r1, [r7, #0x00]
	ldr r0, _0806E7F8 @ =0x000003A7
	cmp r1, r0
	bne _0806E7E4
	ldr r0, _0806E7FC @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x80
	bl ListPoolFirst
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _0806E7E4
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x02
	movs r3, #0x00
	orrs r0, r2
	str r0, [r4, #0x34]
	str r1, [r4, #0x38]
_0806E7E4:
	ldr r1, [r7, #0x18]
	movs r0, #0x0F
	ands r0, r1
	cmp r0, #0x03
	beq _0806E828
	cmp r0, #0x03
	bhi _0806E800
	cmp r0, #0x02
	beq _0806E806
	b _0806E95A
_0806E7F8: .4byte 0x000003A7
_0806E7FC: .4byte 0x02039B84
_0806E800:
	cmp r0, #0x04
	beq _0806E8A6
	b _0806E95A
_0806E806:
	adds r0, r5, #0x0
	adds r0, #0x28
	movs r2, #0xD0
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r1, [r1, #0x00]
	ldr r2, [r5, #0x00]
	lsls r3, r1, #0x03
	adds r3, r3, r1
	lsls r3, r3, #0x02
	adds r3, r3, r2
	ldr r1, [r3, #0x08]
	ldr r2, [r3, #0x0C]
	ldr r3, [r3, #0x10]
	bl EvtObjSetPos
	b _0806E95A
_0806E828:
	adds r0, r5, #0x0
	adds r0, #0x2C
	movs r3, #0xD0
	lsls r3, r3, #0x01
	adds r6, r5, r3
	ldr r2, [r6, #0x00]
	ldr r3, [r5, #0x00]
	lsls r1, r2, #0x03
	adds r1, r1, r2
	lsls r1, r1, #0x02
	adds r1, r1, r3
	ldr r1, [r1, #0x08]
	movs r2, #0xD2
	lsls r2, r2, #0x01
	adds r4, r5, r2
	ldrh r2, [r4, #0x00]
	bl ApproachValue
	adds r0, r5, #0x0
	adds r0, #0x30
	ldr r2, [r6, #0x00]
	ldr r3, [r5, #0x00]
	lsls r1, r2, #0x03
	adds r1, r1, r2
	lsls r1, r1, #0x02
	adds r1, r1, r3
	ldr r1, [r1, #0x0C]
	ldrh r2, [r4, #0x00]
	bl ApproachValue
	adds r0, r5, #0x0
	adds r0, #0x34
	ldr r2, [r6, #0x00]
	ldr r3, [r5, #0x00]
	lsls r1, r2, #0x03
	adds r1, r1, r2
	lsls r1, r1, #0x02
	adds r1, r1, r3
	ldr r1, [r1, #0x10]
	ldrh r2, [r4, #0x00]
	bl ApproachValue
	ldr r0, [r4, #0x00]
	subs r0, #0x01
	str r0, [r4, #0x00]
	cmp r0, #0x00
	bne _0806E95A
	ldr r1, [r6, #0x00]
	ldr r2, [r5, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x18]
	movs r1, #0x80
	lsls r1, r1, #0x05
	ands r0, r1
	cmp r0, #0x00
	bne _0806E95A
	adds r0, r5, #0x0
	bl func_0806E9BC
	b _0806E95A
_0806E8A6:
	movs r0, #0x20
	ands r1, r0
	cmp r1, #0x00
	bne _0806E8D0
	movs r0, #0xCE
	lsls r0, r0, #0x01
	adds r3, r5, r0
	ldr r2, _0806E8CC @ =0x0903380C
	adds r0, r5, #0x0
	adds r0, #0x26
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	movs r1, #0x02
	ldsh r0, [r0, r1]
	b _0806E8EA
	.byte 0x00, 0x00
_0806E8CC: .4byte 0x0903380C
_0806E8D0:
	movs r2, #0xCE
	lsls r2, r2, #0x01
	adds r3, r5, r2
	ldr r2, _0806E904 @ =0x0903380C
	adds r0, r5, #0x0
	adds r0, #0x26
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	movs r1, #0x04
	ldsh r0, [r0, r1]
_0806E8EA:
	str r0, [r3, #0x00]
	ldrh r1, [r7, #0x14]
	adds r0, r1, #0x0
	cmp r0, #0x01
	bne _0806E908
	movs r2, #0xCE
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldr r1, [r5, #0x34]
	ldr r0, [r0, #0x00]
	subs r1, r1, r0
	str r1, [r5, #0x34]
	b _0806E95A
_0806E904: .4byte 0x0903380C
_0806E908:
	cmp r0, #0x02
	bne _0806E91C
	movs r3, #0xCE
	lsls r3, r3, #0x01
	adds r0, r5, r3
	ldr r1, [r5, #0x34]
	ldr r0, [r0, #0x00]
	adds r1, r1, r0
	str r1, [r5, #0x34]
	b _0806E95A
_0806E91C:
	ldr r4, _0806E96C @ =0x08121400
	movs r2, #0xFF
	adds r0, r2, #0x0
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r3, #0x00
	ldsh r1, [r0, r3]
	movs r0, #0xCE
	lsls r0, r0, #0x01
	adds r3, r5, r0
	ldr r0, [r3, #0x00]
	muls r1, r0
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x2C]
	adds r0, r0, r1
	str r0, [r5, #0x2C]
	ldrh r0, [r7, #0x14]
	ands r2, r0
	adds r2, #0x40
	lsls r2, r2, #0x01
	adds r2, r2, r4
	movs r1, #0x00
	ldsh r0, [r2, r1]
	negs r0, r0
	ldr r1, [r3, #0x00]
	muls r1, r0
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x30]
	adds r0, r0, r1
	str r0, [r5, #0x30]
_0806E95A:
	ldr r2, [r7, #0x18]
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0x00
	beq _0806E970
	movs r2, #0xD8
	lsls r2, r2, #0x01
	adds r1, r5, r2
	b _0806E980
_0806E96C: .4byte 0x08121400
_0806E970:
	movs r1, #0x80
	lsls r1, r1, #0x0B
	ands r1, r2
	cmp r1, #0x00
	beq _0806E988
	movs r3, #0xD8
	lsls r3, r3, #0x01
	adds r1, r5, r3
_0806E980:
	ldrb r0, [r1, #0x00]
	adds r0, #0x04
	strb r0, [r1, #0x00]
	b _0806E990
_0806E988:
	movs r2, #0xD8
	lsls r2, r2, #0x01
	adds r0, r5, r2
	strb r1, [r0, #0x00]
_0806E990:
	ldr r0, [r7, #0x18]
	movs r1, #0x80
	lsls r1, r1, #0x0C
	ands r0, r1
	cmp r0, #0x00
	beq _0806E9AC
	movs r3, #0xDB
	lsls r3, r3, #0x01
	adds r2, r5, r3
	ldrb r0, [r2, #0x00]
	movs r1, #0x01
	eors r0, r1
	strb r0, [r2, #0x00]
	b _0806E9B6
_0806E9AC:
	movs r0, #0xDB
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x01
	strb r0, [r1, #0x00]
_0806E9B6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
