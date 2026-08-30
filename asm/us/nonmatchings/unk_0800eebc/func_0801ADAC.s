.syntax unified
	.align 2, 0
	.global func_0801ADAC
	.thumb
	.thumb_func
	.type func_0801ADAC, %function
func_0801ADAC: @ 0801ADAC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	adds r0, #0xE8
	ldr r2, [r0, #0x00]
	cmp r2, #0x02
	bne _0801AE18
	ldr r4, [r7, #0x34]
	ldr r5, [r7, #0x38]
	adds r0, r4, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	movs r1, #0xE2
	adds r1, r1, r7
	mov r12, r1
	cmp r0, #0x00
	beq _0801AE60
	ldr r0, _0801AE08 @ =0xFFFBFFFD
	adds r2, r4, #0x0
	ands r2, r0
	adds r3, r5, #0x0
	ldr r4, _0801AE0C @ =0xFFFFB7FF
	ldr r5, _0801AE10 @ =0xFFFFFADF
	adds r0, r4, #0x0
	ands r0, r2
	adds r1, r5, #0x0
	ands r1, r3
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldr r0, _0801AE14 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x76
	ldrh r1, [r1, #0x00]
	adds r0, #0x72
	strh r1, [r0, #0x00]
	movs r0, #0x1E
	mov r2, r12
	strh r0, [r2, #0x00]
	adds r1, r7, #0x0
	adds r1, #0xE0
	ldrh r0, [r7, #0x20]
	ldrh r3, [r1, #0x00]
	adds r0, r0, r3
	strh r0, [r1, #0x00]
	b _0801AE60
_0801AE08: .4byte 0xFFFBFFFD
_0801AE0C: .4byte 0xFFFFB7FF
_0801AE10: .4byte 0xFFFFFADF
_0801AE14: .4byte 0x02039B84
_0801AE18:
	adds r1, r7, #0x0
	adds r1, #0xE0
	ldrh r2, [r1, #0x00]
	movs r3, #0x00
	ldsh r0, [r1, r3]
	movs r3, #0xE2
	adds r3, r3, r7
	mov r12, r3
	cmp r0, #0x00
	ble _0801AE60
	movs r6, #0x00
	strh r2, [r7, #0x20]
	strh r6, [r1, #0x00]
	ldr r0, _0801AED4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x76
	strh r6, [r0, #0x00]
	ldr r2, [r7, #0x34]
	ldr r3, [r7, #0x38]
	ldr r0, _0801AED8 @ =0xFFFFB7FF
	ldr r1, _0801AEDC @ =0xFFFFFADF
	ands r2, r0
	ands r3, r1
	movs r4, #0x02
	movs r5, #0x00
	adds r0, r2, #0x0
	orrs r0, r4
	adds r1, r3, #0x0
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	str r6, [r7, #0x24]
	adds r0, r7, #0x0
	adds r0, #0xA8
	str r6, [r0, #0x00]
	adds r0, #0x04
	str r6, [r0, #0x00]
_0801AE60:
	mov r0, r12
	ldrh r1, [r0, #0x00]
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x00
	ble _0801AE72
	subs r0, r1, #0x1
	mov r3, r12
	strh r0, [r3, #0x00]
_0801AE72:
	movs r0, #0x82
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldrh r2, [r1, #0x00]
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r0, #0x00
	ble _0801AE86
	subs r0, r2, #0x1
	strh r0, [r1, #0x00]
_0801AE86:
	ldr r3, [r7, #0x34]
	ldr r4, [r7, #0x38]
	movs r0, #0x80
	lsls r0, r0, #0x09
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801AEEC
	ldr r2, _0801AEE0 @ =0xFFFEFFFC
	adds r0, r3, #0x0
	ands r0, r2
	adds r1, r4, #0x0
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	adds r0, r7, #0x0
	bl func_0801AF08
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	ldr r2, _0801AEE4 @ =0x00000200
	ldr r3, _0801AEE8 @ =0x00000000
	orrs r0, r2
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	adds r0, r7, #0x0
	movs r1, #0x09
	bl func_08019190
	ldr r0, _0801AED4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x72
	movs r1, #0x0C
	strh r1, [r0, #0x00]
	movs r0, #0x04
	b _0801AF02
	.byte 0x00, 0x00
_0801AED4: .4byte 0x02039B84
_0801AED8: .4byte 0xFFFFB7FF
_0801AEDC: .4byte 0xFFFFFADF
_0801AEE0: .4byte 0xFFFEFFFC
_0801AEE4: .4byte 0x00000200
_0801AEE8: .4byte 0x00000000
_0801AEEC:
	adds r0, r7, #0x0
	bl func_0801AD68
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0801AF00
	adds r0, r7, #0x0
	bl func_0801A978
	b _0801AF02
_0801AF00:
	movs r0, #0x05
_0801AF02:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
