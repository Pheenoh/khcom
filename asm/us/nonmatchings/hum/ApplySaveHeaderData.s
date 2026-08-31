.syntax unified
	.align 2, 0
	.global ApplySaveHeaderData
	.thumb
	.thumb_func
	.type ApplySaveHeaderData, %function
ApplySaveHeaderData: @ 0805A104
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	bl SaveRepairHeader
	adds r3, r0, #0x0
	cmp r3, #0x02
	bne _0805A150
	ldrh r5, [r4, #0x00]
	movs r0, #0x01
	ands r0, r5
	adds r6, r5, #0x0
	cmp r0, #0x00
	beq _0805A128
	ldr r0, _0805A184 @ =0x02039BB0
	ldr r1, [r0, #0x08]
	movs r2, #0x20
	orrs r1, r2
	str r1, [r0, #0x08]
_0805A128:
	movs r0, #0x04
	ands r0, r6
	cmp r0, #0x00
	beq _0805A13C
	ldr r0, _0805A184 @ =0x02039BB0
	ldr r1, [r0, #0x08]
	movs r2, #0x80
	lsls r2, r2, #0x04
	orrs r1, r2
	str r1, [r0, #0x08]
_0805A13C:
	ands r3, r5
	lsls r0, r3, #0x10
	cmp r0, #0x00
	beq _0805A150
	ldr r0, _0805A184 @ =0x02039BB0
	ldr r1, [r0, #0x08]
	movs r2, #0x80
	lsls r2, r2, #0x02
	orrs r1, r2
	str r1, [r0, #0x08]
_0805A150:
	movs r0, #0x00
	bl SaveRepairFileLarge
	cmp r0, #0x02
	bne _0805A188
	ldr r2, _0805A184 @ =0x02039BB0
	ldrb r1, [r4, #0x04]
	movs r3, #0xDE
	lsls r3, r3, #0x01
	adds r0, r2, r3
	strb r1, [r0, #0x00]
	ldrb r0, [r4, #0x05]
	adds r3, #0x01
	adds r1, r2, r3
	strb r0, [r1, #0x00]
	ldrb r0, [r4, #0x06]
	adds r3, #0x01
	adds r1, r2, r3
	strb r0, [r1, #0x00]
	movs r0, #0xE0
	lsls r0, r0, #0x01
	adds r1, r2, r0
	ldr r0, [r4, #0x08]
	str r0, [r1, #0x00]
	b _0805A1A6
	.byte 0x00, 0x00
_0805A184: .4byte 0x02039BB0
_0805A188:
	ldr r2, _0805A1D8 @ =0x02039BB0
	movs r1, #0xDE
	lsls r1, r1, #0x01
	adds r0, r2, r1
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r3, _0805A1DC @ =0x000001BD
	adds r0, r2, r3
	strb r1, [r0, #0x00]
	adds r3, #0x01
	adds r0, r2, r3
	strb r1, [r0, #0x00]
	adds r3, #0x02
	adds r0, r2, r3
	str r1, [r0, #0x00]
_0805A1A6:
	movs r0, #0x01
	bl SaveRepairFileLarge
	cmp r0, #0x02
	bne _0805A1E0
	ldr r2, _0805A1D8 @ =0x02039BB0
	ldrb r1, [r4, #0x0C]
	movs r3, #0xE2
	lsls r3, r3, #0x01
	adds r0, r2, r3
	strb r1, [r0, #0x00]
	ldrb r0, [r4, #0x0D]
	adds r3, #0x01
	adds r1, r2, r3
	strb r0, [r1, #0x00]
	ldrb r0, [r4, #0x0E]
	adds r3, #0x01
	adds r1, r2, r3
	strb r0, [r1, #0x00]
	movs r0, #0xE4
	lsls r0, r0, #0x01
	adds r1, r2, r0
	ldr r0, [r4, #0x10]
	str r0, [r1, #0x00]
	b _0805A1FE
_0805A1D8: .4byte 0x02039BB0
_0805A1DC: .4byte 0x000001BD
_0805A1E0:
	ldr r2, _0805A230 @ =0x02039BB0
	movs r1, #0xE2
	lsls r1, r1, #0x01
	adds r0, r2, r1
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r3, _0805A234 @ =0x000001C5
	adds r0, r2, r3
	strb r1, [r0, #0x00]
	adds r3, #0x01
	adds r0, r2, r3
	strb r1, [r0, #0x00]
	adds r3, #0x02
	adds r0, r2, r3
	str r1, [r0, #0x00]
_0805A1FE:
	movs r0, #0x00
	bl SaveRepairFileSmall
	cmp r0, #0x02
	bne _0805A238
	ldr r2, _0805A230 @ =0x02039BB0
	ldrb r1, [r4, #0x14]
	movs r3, #0xE6
	lsls r3, r3, #0x01
	adds r0, r2, r3
	strb r1, [r0, #0x00]
	ldrb r0, [r4, #0x15]
	adds r3, #0x01
	adds r1, r2, r3
	strb r0, [r1, #0x00]
	ldrb r0, [r4, #0x16]
	adds r3, #0x01
	adds r1, r2, r3
	strb r0, [r1, #0x00]
	movs r0, #0xE8
	lsls r0, r0, #0x01
	adds r1, r2, r0
	ldr r0, [r4, #0x18]
	str r0, [r1, #0x00]
	b _0805A256
_0805A230: .4byte 0x02039BB0
_0805A234: .4byte 0x000001C5
_0805A238:
	ldr r2, _0805A288 @ =0x02039BB0
	movs r1, #0xE6
	lsls r1, r1, #0x01
	adds r0, r2, r1
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r3, _0805A28C @ =0x000001CD
	adds r0, r2, r3
	strb r1, [r0, #0x00]
	adds r3, #0x01
	adds r0, r2, r3
	strb r1, [r0, #0x00]
	adds r3, #0x02
	adds r0, r2, r3
	str r1, [r0, #0x00]
_0805A256:
	movs r0, #0x01
	bl SaveRepairFileSmall
	cmp r0, #0x02
	bne _0805A290
	ldr r2, _0805A288 @ =0x02039BB0
	ldrb r1, [r4, #0x1C]
	movs r3, #0xEA
	lsls r3, r3, #0x01
	adds r0, r2, r3
	strb r1, [r0, #0x00]
	ldrb r0, [r4, #0x1D]
	adds r3, #0x01
	adds r1, r2, r3
	strb r0, [r1, #0x00]
	ldrb r0, [r4, #0x1E]
	adds r3, #0x01
	adds r1, r2, r3
	strb r0, [r1, #0x00]
	movs r0, #0xEC
	lsls r0, r0, #0x01
	adds r1, r2, r0
	ldr r0, [r4, #0x20]
	str r0, [r1, #0x00]
	b _0805A2AE
_0805A288: .4byte 0x02039BB0
_0805A28C: .4byte 0x000001CD
_0805A290:
	ldr r2, _0805A2B4 @ =0x02039BB0
	movs r1, #0xEA
	lsls r1, r1, #0x01
	adds r0, r2, r1
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r3, _0805A2B8 @ =0x000001D5
	adds r0, r2, r3
	strb r1, [r0, #0x00]
	adds r3, #0x01
	adds r0, r2, r3
	strb r1, [r0, #0x00]
	adds r3, #0x02
	adds r0, r2, r3
	str r1, [r0, #0x00]
_0805A2AE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0805A2B4: .4byte 0x02039BB0
_0805A2B8: .4byte 0x000001D5
.syntax divided
