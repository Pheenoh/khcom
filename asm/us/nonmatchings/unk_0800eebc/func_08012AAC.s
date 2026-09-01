.syntax unified
	.align 2, 0
	.global func_08012AAC
	.thumb
	.thumb_func
	.type func_08012AAC, %function
func_08012AAC: @ 08012AAC
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r6, r1, #0x0
	adds r7, r2, #0x0
	adds r5, r3, #0x0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08012BAE
	bl func_08012674
	ldr r0, _08012AE8 @ =0x02034928
	ldr r2, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0x4C
	movs r0, #0x14
	strh r0, [r1, #0x00]
	str r6, [r2, #0x10]
	str r7, [r2, #0x14]
	cmp r4, #0x01
	beq _08012AFC
	cmp r4, #0x01
	bgt _08012AEC
	cmp r4, #0x00
	beq _08012AF2
	b _08012B06
_08012AE8: .4byte 0x02034928
_08012AEC:
	cmp r4, #0x02
	beq _08012B00
	b _08012B06
_08012AF2:
	ldr r1, _08012AF8 @ =0xFFFFEC00
	adds r0, r5, r1
	b _08012B04
_08012AF8: .4byte 0xFFFFEC00
_08012AFC:
	str r5, [r2, #0x18]
	b _08012B06
_08012B00:
	ldr r3, _08012B2C @ =0xFFFFF000
	adds r0, r5, r3
_08012B04:
	str r0, [r2, #0x18]
_08012B06:
	mov r5, sp
	adds r5, #0x06
	ldr r0, _08012B30 @ =0x02034928
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x10]
	ldr r3, [r0, #0x14]
	ldr r0, [r0, #0x18]
	str r0, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r5, #0x0
	bl WorldToScreen
	cmp r4, #0x01
	beq _08012B58
	cmp r4, #0x01
	bgt _08012B34
	cmp r4, #0x00
	beq _08012B3A
	b _08012B8E
_08012B2C: .4byte 0xFFFFF000
_08012B30: .4byte 0x02034928
_08012B34:
	cmp r4, #0x02
	beq _08012B78
	b _08012B8E
_08012B3A:
	ldr r0, _08012B54 @ =0x09EDA558
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r5, r3]
	bl func_08006778
	movs r0, #0x81
	lsls r0, r0, #0x02
	bl m4aSongNumStart
	b _08012B8E
_08012B54: .4byte 0x09EDA558
_08012B58:
	ldr r0, _08012B70 @ =0x09EDA840
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r5, r3]
	bl func_08006778
	ldr r0, _08012B74 @ =0x00000205
	bl m4aSongNumStart
	b _08012B8E
_08012B70: .4byte 0x09EDA840
_08012B74: .4byte 0x00000205
_08012B78:
	ldr r0, _08012BB8 @ =0x09EDA828
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r5, r3]
	bl func_08006778
	ldr r0, _08012BBC @ =0x00000206
	bl m4aSongNumStart
_08012B8E:
	ldr r0, _08012BC0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	ldr r0, _08012BC4 @ =0x02034928
	ldr r1, [r0, #0x00]
	ldrh r2, [r1, #0x34]
	movs r0, #0x08
	orrs r0, r2
	strh r0, [r1, #0x34]
	ldr r0, _08012BC8 @ =0x08012909
	str r0, [r1, #0x04]
_08012BAE:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08012BB8: .4byte 0x09EDA828
_08012BBC: .4byte 0x00000206
_08012BC0: .4byte 0x02039B84
_08012BC4: .4byte 0x02034928
_08012BC8: .4byte func_08012908
.syntax divided
