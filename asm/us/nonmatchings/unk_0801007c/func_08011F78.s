.syntax unified
	.align 2, 0
	.global func_08011F78
	.thumb
	.thumb_func
	.type func_08011F78, %function
func_08011F78: @ 08011F78
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x028
	str r0, [sp, #0x00C]
	str r1, [sp, #0x010]
	str r2, [sp, #0x014]
	str r3, [sp, #0x018]
	ldr r0, [sp, #0x048]
	ldr r1, [sp, #0x04C]
	ldr r2, [sp, #0x050]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r5, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r9, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r10, r2
	ldr r1, [sp, #0x00C]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _0801201C @ =0x0813400C
	adds r0, r0, r1
	str r0, [sp, #0x01C]
	movs r0, #0x00
	str r0, [sp, #0x020]
	movs r1, #0x00
	str r1, [sp, #0x024]
	ldr r2, _08012020 @ =0x02039B84
	ldr r0, [r2, #0x00]
	adds r0, #0xB4
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r2, [r2, #0x00]
	mov r12, r2
	mov r0, r12
	adds r0, #0xB8
	ldr r1, [sp, #0x010]
	str r1, [r0, #0x00]
	adds r0, #0x04
	ldr r1, [sp, #0x014]
	str r1, [r0, #0x00]
	adds r0, #0x04
	ldr r1, [sp, #0x018]
	str r1, [r0, #0x00]
	adds r0, #0x04
	strh r5, [r0, #0x00]
	adds r0, #0x02
	mov r1, r9
	strh r1, [r0, #0x00]
	adds r0, #0x02
	mov r1, r10
	strh r1, [r0, #0x00]
	mov r0, r12
	ldr r3, [r0, #0x68]
	ldr r4, [r0, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	adds r0, r3, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08012028
	movs r0, #0x80
	lsls r0, r0, #0x16
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801210C
	ldr r0, _08012024 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	ldr r4, [r0, #0x7C]
	b _08012110
_0801201C: .4byte 0x0813400C
_08012020: .4byte 0x02039B84
_08012024: .4byte 0x02039B9C
_08012028:
	movs r0, #0x80
	lsls r0, r0, #0x16
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801210C
	mov r0, r12
	adds r0, #0x80
	bl ListPoolFirst
	adds r4, r0, #0x0
	movs r1, #0x00
	mov r8, r1
	movs r7, #0x00
	movs r6, #0x00
	cmp r4, #0x00
	beq _080120C4
_08012050:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x000]
	mov r1, r9
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x004]
	mov r1, r10
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x008]
	adds r0, r4, #0x0
	ldr r1, [sp, #0x010]
	ldr r2, [sp, #0x014]
	ldr r3, [sp, #0x018]
	bl func_08011270
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080120B6
	adds r0, r4, #0x0
	ldr r1, [sp, #0x00C]
	bl func_08011398
	cmp r0, #0x01
	bne _080120AE
	ldr r0, [r4, #0x04]
	adds r6, r6, r0
	ldr r0, [r4, #0x08]
	adds r7, r7, r0
	ldr r0, [r4, #0x0C]
	add r8, r0
	ldr r1, [sp, #0x020]
	lsls r0, r1, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #0x020]
	ldr r1, [sp, #0x01C]
	ldr r0, [r1, #0x14]
	movs r1, #0x80
	lsls r1, r1, #0x04
	ands r0, r1
	cmp r0, #0x00
	bne _080120C4
	b _080120B6
_080120AE:
	cmp r0, #0x02
	bne _080120B6
	movs r0, #0x01
	str r0, [sp, #0x024]
_080120B6:
	adds r0, r4, #0x0
	adds r0, #0xB8
	bl ListPoolNext
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _08012050
_080120C4:
	ldr r1, [sp, #0x024]
	cmp r1, #0x00
	beq _080120CE
	movs r0, #0x02
	b _0801215E
_080120CE:
	ldr r1, [sp, #0x020]
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0x00
	ble _0801215C
	ldr r0, [sp, #0x01C]
	ldr r5, [r0, #0x10]
	cmp r5, #0x00
	beq _08012108
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl __divsi3
	adds r6, r0, #0x0
	adds r0, r7, #0x0
	adds r1, r4, #0x0
	bl __divsi3
	adds r7, r0, #0x0
	mov r0, r8
	adds r1, r4, #0x0
	bl __divsi3
	mov r8, r0
	adds r0, r6, #0x0
	adds r1, r7, #0x0
	mov r2, r8
	bl _call_via_r5
_08012108:
	movs r0, #0x01
	b _0801215E
_0801210C:
	mov r1, r12
	ldr r4, [r1, #0x7C]
_08012110:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x000]
	mov r1, r9
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x004]
	mov r1, r10
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x008]
	adds r0, r4, #0x0
	ldr r1, [sp, #0x010]
	ldr r2, [sp, #0x014]
	ldr r3, [sp, #0x018]
	bl func_08011270
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0801215C
	adds r0, r4, #0x0
	ldr r1, [sp, #0x00C]
	bl func_08011398
	adds r5, r0, #0x0
	cmp r5, #0x01
	bne _08012158
	ldr r0, [sp, #0x01C]
	ldr r3, [r0, #0x10]
	cmp r3, #0x00
	beq _08012158
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x08]
	ldr r2, [r4, #0x0C]
	bl _call_via_r3
_08012158:
	adds r0, r5, #0x0
	b _0801215E
_0801215C:
	movs r0, #0x00
_0801215E:
	add sp, #0x028
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
