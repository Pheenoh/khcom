.syntax unified
	.align 2, 0
	.global task_btl_hpenm_1
	.thumb
	.thumb_func
	.type task_btl_hpenm_1, %function
task_btl_hpenm_1: @ 0802FE94
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, _0802FEAC @ =0x02039B84
	ldr r3, [r0, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xA0
	ldr r0, [r0, #0x00]
	cmp r0, #0x04
	bne _0802FEB0
	movs r0, #0x00
	b _08030032
	.byte 0x00, 0x00
_0802FEAC: .4byte 0x02039B84
_0802FEB0:
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0802FED4
	ldr r0, _0802FED0 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	ldr r3, [r0, #0x7C]
	movs r0, #0x01
	strb r0, [r4, #0x14]
	b _0802FEEC
	.byte 0x00, 0x00
_0802FED0: .4byte 0x02039B9C
_0802FED4:
	ldr r1, [r3, #0x78]
	cmp r1, #0x00
	bne _0802FEE6
	ldrb r0, [r4, #0x14]
	cmp r0, #0x00
	bne _0802FEE2
	b _08030030
_0802FEE2:
	strb r1, [r4, #0x14]
	b _08030030
_0802FEE6:
	movs r0, #0x01
	strb r0, [r4, #0x14]
	ldr r3, [r3, #0x78]
_0802FEEC:
	adds r0, r3, #0x0
	adds r0, #0xD8
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0802FEF8
	adds r3, r0, #0x0
_0802FEF8:
	ldr r0, [r4, #0x18]
	cmp r0, r3
	beq _0802FF64
	str r3, [r4, #0x18]
	ldrh r0, [r3, #0x2C]
	strh r0, [r4, #0x1E]
	movs r0, #0x2E
	ldsh r1, [r3, r0]
	cmp r1, #0x50
	bgt _0802FF12
	movs r0, #0x00
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF12:
	cmp r1, #0xA0
	bgt _0802FF1C
	movs r0, #0x01
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF1C:
	cmp r1, #0xF0
	bgt _0802FF26
	movs r0, #0x02
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF26:
	movs r0, #0xA0
	lsls r0, r0, #0x01
	cmp r1, r0
	bgt _0802FF34
	movs r0, #0x03
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF34:
	movs r0, #0xC8
	lsls r0, r0, #0x01
	cmp r1, r0
	bgt _0802FF42
	movs r0, #0x04
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF42:
	movs r0, #0xF0
	lsls r0, r0, #0x01
	cmp r1, r0
	bgt _0802FF50
	movs r0, #0x05
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF50:
	movs r0, #0x8C
	lsls r0, r0, #0x02
	cmp r1, r0
	bgt _0802FF5E
	movs r0, #0x06
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF5E:
	movs r0, #0x07
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF64:
	ldrh r0, [r4, #0x1E]
	movs r1, #0x1E
	ldsh r2, [r4, r1]
	movs r5, #0x2C
	ldsh r1, [r3, r5]
	cmp r2, r1
	bge _0802FF86
	adds r0, #0x05
	strh r0, [r4, #0x1E]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r3, #0x2C]
	movs r5, #0x2C
	ldsh r1, [r3, r5]
	cmp r0, r1
	ble _0802FF9E
	b _0802FF9C
_0802FF86:
	cmp r2, r1
	ble _0802FF9E
	subs r0, #0x05
	strh r0, [r4, #0x1E]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r3, #0x2C]
	movs r5, #0x2C
	ldsh r1, [r3, r5]
	cmp r0, r1
	bge _0802FF9E
_0802FF9C:
	strh r2, [r4, #0x1E]
_0802FF9E:
	movs r0, #0x1E
	ldsh r1, [r4, r0]
	movs r0, #0x8C
	lsls r0, r0, #0x02
	cmp r1, r0
	bgt _0802FFAE
	movs r0, #0x00
	b _0802FFC8
_0802FFAE:
	movs r0, #0x8C
	lsls r0, r0, #0x03
	cmp r1, r0
	bgt _0802FFBA
	movs r0, #0x01
	b _0802FFC8
_0802FFBA:
	movs r0, #0xD2
	lsls r0, r0, #0x03
	cmp r1, r0
	bgt _0802FFC6
	movs r0, #0x02
	b _0802FFC8
_0802FFC6:
	movs r0, #0x03
_0802FFC8:
	str r0, [r4, #0x20]
	ldr r0, [r4, #0x20]
	cmp r0, #0x01
	beq _0802FFFC
	cmp r0, #0x01
	bcc _0803000C
	cmp r0, #0x02
	beq _0802FFEC
	cmp r0, #0x03
	bne _08030030
	movs r1, #0x1E
	ldsh r0, [r4, r1]
	ldr r2, _0802FFE8 @ =0xFFFFF970
	adds r0, r0, r2
	b _08030024
	.byte 0x00, 0x00
_0802FFE8: .4byte 0xFFFFF970
_0802FFEC:
	movs r5, #0x1E
	ldsh r0, [r4, r5]
	ldr r1, _0802FFF8 @ =0xFFFFFBA0
	adds r0, r0, r1
	b _08030024
	.byte 0x00, 0x00
_0802FFF8: .4byte 0xFFFFFBA0
_0802FFFC:
	movs r2, #0x1E
	ldsh r0, [r4, r2]
	ldr r5, _08030008 @ =0xFFFFFDD0
	adds r0, r0, r5
	b _08030024
	.byte 0x00, 0x00
_08030008: .4byte 0xFFFFFDD0
_0803000C:
	movs r1, #0x1C
	ldsh r0, [r4, r1]
	cmp r0, #0x06
	bgt _08030020
	movs r2, #0x1E
	ldsh r0, [r4, r2]
	lsls r0, r0, #0x08
	movs r5, #0x2E
	ldsh r1, [r3, r5]
	b _0803002A
_08030020:
	movs r1, #0x1E
	ldsh r0, [r4, r1]
_08030024:
	lsls r0, r0, #0x08
	movs r1, #0x8C
	lsls r1, r1, #0x02
_0803002A:
	bl __divsi3
	str r0, [r4, #0x10]
_08030030:
	movs r0, #0x01
_08030032:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
