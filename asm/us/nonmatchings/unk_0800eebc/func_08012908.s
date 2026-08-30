.syntax unified
	.align 2, 0
	.global func_08012908
	.thumb
	.thumb_func
	.type func_08012908, %function
func_08012908: @ 08012908
	push {r4, r5, lr}
	add sp, #-0x008
	bl func_08006B74
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08012950
	ldr r4, _08012948 @ =0x02034928
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x00]
	movs r1, #0x10
	movs r2, #0x10
	bl func_080057A0
	ldr r2, [r4, #0x00]
	movs r0, #0x00
	str r0, [r2, #0x04]
	ldrh r0, [r2, #0x34]
	ldr r1, _0801294C @ =0x0000FFFD
	ands r1, r0
	strh r1, [r2, #0x34]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _0801293C
	b _08012AA0
_0801293C:
	movs r0, #0x00
	movs r1, #0x08
	bl func_080061E8
	b _08012AA0
	.byte 0x00, 0x00
_08012948: .4byte 0x02034928
_0801294C: .4byte 0x0000FFFD
_08012950:
	ldr r0, _080129AC @ =0x02039B84
	ldr r5, [r0, #0x00]
	ldr r3, [r5, #0x68]
	ldr r4, [r5, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	adds r0, r3, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080129F4
	movs r0, #0x80
	lsls r0, r0, #0x16
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _080129B4
	movs r0, #0x02
	adds r1, r3, #0x0
	ands r1, r0
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _08012A26
	adds r0, r5, #0x0
	adds r0, #0xB2
	movs r4, #0x00
	ldsb r4, [r0, r4]
	bl func_080ABED0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bge _08012A26
	ldr r0, _080129B0 @ =0x02034928
	ldr r0, [r0, #0x00]
	adds r0, #0x4C
	movs r1, #0x00
	ldsh r0, [r0, r1]
	bl func_08012728
	b _08012A26
_080129AC: .4byte 0x02039B84
_080129B0: .4byte 0x02034928
_080129B4:
	ldr r0, _080129EC @ =0x02039B9C
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x02
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08012A26
	adds r0, r3, #0x0
	adds r0, #0xB2
	movs r4, #0x00
	ldsb r4, [r0, r4]
	bl func_080ABED0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bge _08012A26
	ldr r0, _080129F0 @ =0x02034928
	ldr r0, [r0, #0x00]
	adds r0, #0x4C
	movs r2, #0x00
	ldsh r0, [r0, r2]
	bl func_08012728
	b _08012A26
_080129EC: .4byte 0x02039B9C
_080129F0: .4byte 0x02034928
_080129F4:
	movs r0, #0x02
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _08012A26
	adds r0, r5, #0x0
	adds r0, #0xB2
	movs r4, #0x00
	ldsb r4, [r0, r4]
	bl func_080ABED0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bge _08012A26
	ldr r0, _08012A74 @ =0x02034928
	ldr r0, [r0, #0x00]
	adds r0, #0x4C
	movs r1, #0x00
	ldsh r0, [r0, r1]
	bl func_08012728
_08012A26:
	mov r4, sp
	adds r4, #0x06
	ldr r5, _08012A74 @ =0x02034928
	ldr r0, [r5, #0x00]
	ldr r2, [r0, #0x10]
	ldr r3, [r0, #0x14]
	ldr r0, [r0, #0x18]
	str r0, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	bl func_0801909C
	add r0, sp, #0x004
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	bl func_080066F4
	ldr r3, [r5, #0x00]
	ldrh r1, [r3, #0x34]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	beq _08012A7C
	adds r1, r3, #0x0
	adds r1, #0x24
	ldr r0, _08012A78 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldrb r0, [r0, #0x18]
	ldrb r1, [r1, #0x00]
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [r3, #0x1C]
	ldr r2, [r3, #0x20]
	bl func_0800675C
	b _08012AA0
_08012A74: .4byte 0x02034928
_08012A78: .4byte 0x02039B84
_08012A7C:
	ldr r0, _08012AA8 @ =0x02039B84
	ldr r4, [r0, #0x00]
	ldr r0, [r3, #0x1C]
	ldr r2, [r4, #0x24]
	adds r1, r0, #0x0
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r3, #0x20]
	muls r2, r0
	asrs r2, r2, #0x08
	adds r3, #0x24
	ldrb r0, [r4, #0x18]
	ldrb r3, [r3, #0x00]
	adds r0, r0, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl func_0800675C
_08012AA0:
	add sp, #0x008
	pop {r4, r5}
	pop {r0}
	bx r0
_08012AA8: .4byte 0x02039B84
.syntax divided
