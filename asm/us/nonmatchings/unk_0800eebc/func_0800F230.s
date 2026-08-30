.syntax unified
	.align 2, 0
	.global func_0800F230
	.thumb
	.thumb_func
	.type func_0800F230, %function
func_0800F230: @ 0800F230
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r0, _0800F274 @ =0x02039B9C
	ldr r3, [r0, #0x00]
	ldr r4, [r3, #0x7C]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x11
	ands r0, r2
	movs r1, #0x00
	orrs r1, r0
	cmp r1, #0x00
	beq _0800F252
	b _0800F358
_0800F252:
	movs r0, #0xE6
	lsls r0, r0, #0x01
	adds r2, r3, r0
	ldrh r3, [r2, #0x00]
	movs r5, #0x00
	ldsh r0, [r2, r5]
	cmp r0, #0x00
	ble _0800F278
	subs r0, r3, #0x1
	strh r0, [r2, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _0800F358
	bl func_0807E260
	b _0800F358
	.byte 0x00, 0x00
_0800F274: .4byte 0x02039B9C
_0800F278:
	ldr r0, _0800F320 @ =0x02039B84
	mov r8, r0
	ldr r0, [r0, #0x00]
	adds r0, #0xEF
	ldrb r5, [r0, #0x00]
	strb r1, [r0, #0x00]
	movs r0, #0x01
	ands r0, r5
	cmp r0, #0x00
	beq _0800F290
	bl func_0807E1F4
_0800F290:
	movs r1, #0x02
	mov r9, r1
	adds r0, r5, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _0800F2A0
	bl func_0807E200
_0800F2A0:
	movs r0, #0x04
	ands r0, r5
	cmp r0, #0x00
	beq _0800F2AC
	bl func_0807E260
_0800F2AC:
	ldr r6, [r4, #0x34]
	ldr r7, [r4, #0x38]
	movs r0, #0x80
	lsls r0, r0, #0x02
	adds r1, r6, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _0800F358
	mov r2, r8
	ldr r0, [r2, #0x00]
	ldr r3, [r0, #0x68]
	ldr r4, [r0, #0x6C]
	movs r2, #0x40
	adds r0, r3, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0800F358
	movs r0, #0x80
	lsls r0, r0, #0x15
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _0800F358
	movs r0, #0x80
	lsls r0, r0, #0x10
	adds r1, r3, #0x0
	ands r1, r0
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _0800F358
	mov r0, r9
	ands r0, r6
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0800F358
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0x00
	beq _0800F328
	bl func_0807B3F8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _0800F324
	bl func_0807E224
	b _0800F328
_0800F320: .4byte 0x02039B84
_0800F324:
	bl func_0807E218
_0800F328:
	movs r0, #0x20
	ands r5, r0
	cmp r5, #0x00
	beq _0800F358
	bl func_0807E20C
	bl func_08081838
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x03
	bne _0800F358
	bl func_0807E34C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0800F358
	ldr r0, _0800F364 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	movs r5, #0xE6
	lsls r5, r5, #0x01
	adds r0, r0, r5
	movs r1, #0x0F
	strh r1, [r0, #0x00]
_0800F358:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0800F364: .4byte 0x02039B9C
.syntax divided
