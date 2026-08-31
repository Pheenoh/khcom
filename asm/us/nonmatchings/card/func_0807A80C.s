.syntax unified
	.align 2, 0
	.global func_0807A80C
	.thumb
	.thumb_func
	.type func_0807A80C, %function
func_0807A80C: @ 0807A80C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x024
	adds r7, r0, #0x0
	adds r0, #0xBA
	ldrb r5, [r0, #0x00]
	movs r0, #0x00
	mov r9, r0
	add r1, sp, #0x008
	ldr r0, _0807A940 @ =0x09033FD0
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r1, _0807A944 @ =0x02039DD4
	ldr r4, [r1, #0x00]
	adds r0, r4, #0x0
	adds r0, #0xC2
	movs r2, #0x00
	ldsh r0, [r0, r2]
	mov r8, r1
	cmp r0, r5
	ble _0807A846
	cmp r5, #0x00
	beq _0807A846
	b _0807ABB2
_0807A846:
	movs r6, #0x00
	ldr r3, _0807A948 @ =0x02039B84
	ldr r0, [r3, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x90
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	mov r10, r3
	cmp r0, #0x00
	beq _0807A8D0
	ldr r0, _0807A94C @ =0x02039B9C
	ldr r1, [r0, #0x00]
	adds r1, #0xF4
	ldr r1, [r1, #0x00]
	adds r2, r0, #0x0
	cmp r1, #0x02
	bne _0807A886
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x48]
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0807A886
	adds r0, r4, #0x0
	adds r0, #0xE2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0807A886
	movs r6, #0x01
_0807A886:
	ldr r0, [r2, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x14
	bne _0807A8AA
	mov r3, r8
	ldr r1, [r3, #0x00]
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x48]
	ldr r0, [r0, #0x24]
	cmp r0, #0x16
	bne _0807A8AA
	adds r0, r1, #0x0
	adds r0, #0xE2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0807A8AA
	movs r6, #0x01
_0807A8AA:
	ldr r0, [r2, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x1D
	bne _0807A8D0
	mov r4, r8
	ldr r1, [r4, #0x00]
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x48]
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _0807A8D0
	adds r0, r1, #0x0
	adds r0, #0xE2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0807A8D0
	movs r6, #0x01
_0807A8D0:
	cmp r6, #0x00
	beq _0807A8D6
	b _0807ABB2
_0807A8D6:
	movs r3, #0x00
	mov r1, r8
	ldr r0, [r1, #0x00]
	adds r0, #0xD0
	ldrb r0, [r0, #0x00]
	cmp r3, r0
	bcs _0807A906
	mov r6, r8
	movs r4, #0x80
	lsls r4, r4, #0x0E
_0807A8EA:
	ldr r2, [r6, #0x00]
	lsls r0, r3, #0x02
	adds r0, r2, r0
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x78]
	orrs r0, r4
	str r0, [r1, #0x78]
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r2, #0xD0
	ldrb r2, [r2, #0x00]
	cmp r3, r2
	bcc _0807A8EA
_0807A906:
	mov r2, r10
	ldr r4, [r2, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _0807A950 @ =0x00800000
	ldr r3, _0807A954 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	mov r3, r8
	ldr r0, [r3, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xC2
	movs r2, #0x00
	ldsh r0, [r1, r2]
	cmp r0, r5
	bne _0807A92A
	b _0807AB68
_0807A92A:
	cmp r5, #0x00
	bne _0807A962
	ldrh r2, [r1, #0x00]
	cmp r0, #0x09
	ble _0807A958
	movs r0, #0xE5
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x09
	b _0807A97C
	.byte 0x00, 0x00
_0807A940: .4byte 0x09033FD0
_0807A944: .4byte 0x02039DD4
_0807A948: .4byte 0x02039B84
_0807A94C: .4byte 0x02039B9C
_0807A950: .4byte 0x00800000
_0807A954: .4byte 0x00000000
_0807A958:
	movs r1, #0xE5
	lsls r1, r1, #0x01
	adds r0, r4, r1
	strb r2, [r0, #0x00]
	b _0807A97E
_0807A962:
	subs r0, r5, r0
	cmp r0, #0x09
	ble _0807A972
	movs r2, #0xE5
	lsls r2, r2, #0x01
	adds r1, r4, r2
	movs r0, #0x09
	b _0807A97C
_0807A972:
	ldrb r0, [r1, #0x00]
	subs r0, r5, r0
	movs r3, #0xE5
	lsls r3, r3, #0x01
	adds r1, r4, r3
_0807A97C:
	strb r0, [r1, #0x00]
_0807A97E:
	ldr r0, _0807AA24 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x80
	lsls r1, r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _0807A9B6
	bl func_0807BA54
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0807A9B6
	ldr r0, _0807AA28 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x08
	movs r0, #0x00
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	bne _0807A9B6
	ldr r0, _0807AA2C @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xEE
	movs r1, #0x01
	strb r1, [r0, #0x00]
_0807A9B6:
	ldr r4, _0807AA28 @ =0x02039B84
	mov r8, r4
	ldr r6, [r4, #0x00]
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x6C]
	ldr r2, _0807AA30 @ =0x00000400
	ldr r3, _0807AA34 @ =0x00000000
	orrs r0, r2
	ldr r4, _0807AA38 @ =0x08000000
	ldr r5, _0807AA3C @ =0x00000000
	adds r2, r0, #0x0
	orrs r2, r4
	adds r3, r1, #0x0
	movs r0, #0x80
	movs r1, #0x00
	adds r4, r2, #0x0
	orrs r4, r0
	adds r5, r3, #0x0
	movs r2, #0x21
	negs r2, r2
	adds r0, r4, #0x0
	ands r0, r2
	adds r1, r5, #0x0
	str r0, [r6, #0x68]
	str r1, [r6, #0x6C]
	adds r0, r7, #0x0
	bl func_08079218
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0807AA40
	adds r4, r7, #0x0
	adds r4, #0x28
	adds r5, r7, #0x0
	adds r5, #0xB9
	ldrb r1, [r5, #0x00]
	adds r0, r7, #0x0
	adds r0, #0xBA
	ldrb r2, [r0, #0x00]
	add r0, sp, #0x020
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	add r3, sp, #0x008
	bl func_080AC5E8
	b _0807AA60
	.byte 0x00, 0x00
_0807AA24: .4byte 0x02039BB0
_0807AA28: .4byte 0x02039B84
_0807AA2C: .4byte 0x02039DD4
_0807AA30: .4byte 0x00000400
_0807AA34: .4byte 0x00000000
_0807AA38: .4byte 0x08000000
_0807AA3C: .4byte 0x00000000
_0807AA40:
	adds r4, r7, #0x0
	adds r4, #0x28
	adds r5, r7, #0x0
	adds r5, #0xB9
	ldrb r1, [r5, #0x00]
	adds r0, r7, #0x0
	adds r0, #0xBA
	ldrb r2, [r0, #0x00]
	add r0, sp, #0x020
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	adds r0, r4, #0x0
	add r3, sp, #0x008
	bl func_080AD144
_0807AA60:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _0807AB5C @ =0x02039DD4
	mov r8, r2
	ldr r3, _0807AB60 @ =0x02039B84
	mov r10, r3
	cmp r0, #0x34
	bne _0807AAC8
	ldr r0, [r3, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x90
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0807AAC8
	movs r3, #0x00
	mov r1, r8
	ldr r0, [r1, #0x00]
	adds r0, #0xD0
	ldrb r0, [r0, #0x00]
	cmp r3, r0
	bcs _0807AAC8
	mov r6, r8
_0807AA94:
	ldr r0, [r6, #0x00]
	lsls r2, r3, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x3C]
	ldrb r0, [r1, #0x08]
	cmp r0, #0x01
	bne _0807AAB8
	strb r0, [r1, #0x0A]
	mov r1, r8
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x78]
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #0x78]
_0807AAB8:
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, [r6, #0x00]
	adds r0, #0xD0
	ldrb r0, [r0, #0x00]
	cmp r3, r0
	bcc _0807AA94
_0807AAC8:
	movs r3, #0x00
	ldrb r0, [r5, #0x00]
	cmp r3, r0
	bcs _0807AAF0
	adds r2, r4, #0x0
	adds r1, r0, #0x0
_0807AAD4:
	lsls r0, r3, #0x02
	adds r0, r2, r0
	ldr r0, [r0, #0x00]
	adds r0, #0xA5
	ldrb r0, [r0, #0x00]
	add r0, r9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, r1
	bcc _0807AAD4
_0807AAF0:
	mov r2, r8
	ldr r0, [r2, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xC2
	mov r3, r9
	strh r3, [r1, #0x00]
	ldrb r1, [r5, #0x00]
	adds r0, #0xD0
	strb r1, [r0, #0x00]
	movs r3, #0x00
	ldrb r0, [r5, #0x00]
	cmp r3, r0
	bcs _0807AB42
_0807AB0A:
	mov r1, r8
	ldr r2, [r1, #0x00]
	lsls r1, r3, #0x02
	adds r2, r2, r1
	adds r1, r4, r1
	ldr r0, [r1, #0x00]
	str r0, [r2, #0x00]
	ldr r2, [r1, #0x00]
	ldr r0, [r2, #0x78]
	movs r1, #0x80
	lsls r1, r1, #0x06
	orrs r0, r1
	str r0, [r2, #0x78]
	ldr r0, [r2, #0x48]
	ldrh r1, [r0, #0x1E]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _0807AB36
	ldr r1, [r2, #0x3C]
	movs r0, #0x01
	strb r0, [r1, #0x0A]
_0807AB36:
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldrb r2, [r5, #0x00]
	cmp r3, r2
	bcc _0807AB0A
_0807AB42:
	mov r3, r10
	ldr r0, [r3, #0x00]
	adds r0, #0xA4
	movs r1, #0x01
	strb r1, [r0, #0x00]
	mov r4, r8
	ldr r0, [r4, #0x00]
	adds r0, #0xE1
	strb r1, [r0, #0x00]
	ldr r0, _0807AB64 @ =0x00000213
	bl m4aSongNumStart
	b _0807ABB2
_0807AB5C: .4byte 0x02039DD4
_0807AB60: .4byte 0x02039B84
_0807AB64: .4byte 0x00000213
_0807AB68:
	movs r1, #0xE5
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r6, #0x00
	strb r6, [r0, #0x00]
	adds r0, r7, #0x0
	bl func_08079218
	movs r0, #0xCC
	bl m4aSongNumStart
	mov r2, r10
	ldr r5, [r2, #0x00]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x6C]
	movs r2, #0x81
	negs r2, r2
	ands r0, r2
	movs r4, #0x21
	negs r4, r4
	adds r2, r0, #0x0
	ands r2, r4
	adds r3, r1, #0x0
	ldr r4, _0807ABC4 @ =0xFFFFFBFF
	adds r0, r2, #0x0
	ands r0, r4
	str r0, [r5, #0x68]
	str r1, [r5, #0x6C]
	mov r3, r8
	ldr r0, [r3, #0x00]
	adds r0, #0xE1
	strb r6, [r0, #0x00]
	mov r4, r10
	ldr r0, [r4, #0x00]
	adds r0, #0xA4
	movs r1, #0x01
	strb r1, [r0, #0x00]
_0807ABB2:
	add sp, #0x024
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0807ABC4: .4byte 0xFFFFFBFF
.syntax divided
