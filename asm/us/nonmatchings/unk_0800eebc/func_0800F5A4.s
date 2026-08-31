.syntax unified
	.align 2, 0
	.global func_0800F5A4
	.thumb
	.thumb_func
	.type func_0800F5A4, %function
func_0800F5A4: @ 0800F5A4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	mov r9, r0
	ldr r0, [sp, #0x02C]
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x000]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #0x004]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x008]
	ldr r0, _0800F654 @ =0x02039B84
	mov r10, r0
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x40
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800F5E2
	b _0800F838
_0800F5E2:
	ldr r0, _0800F658 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	movs r1, #0xE6
	lsls r1, r1, #0x01
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	ble _0800F5F6
	b _0800F838
_0800F5F6:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _0800F60C
	b _0800F838
_0800F60C:
	bl func_08081870
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	bl func_0807B3F8
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	bl func_0807E2BC
	adds r7, r0, #0x0
	bl func_0807E33C
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r7, #0x35
	bhi _0800F668
	cmp r7, #0x2F
	bcc _0800F668
	asrs r4, r5, #0x01
	cmp r4, #0x00
	bgt _0800F63C
	movs r4, #0x01
_0800F63C:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl __modsi3
	cmp r0, #0x00
	bne _0800F65C
	mov r1, r10
	ldr r0, [r1, #0x00]
	b _0800F82E
_0800F654: .4byte 0x02039B84
_0800F658: .4byte 0x02039B9C
_0800F65C:
	mov r1, r10
	ldr r0, [r1, #0x00]
	adds r0, #0xEF
	ldrb r2, [r0, #0x00]
	movs r1, #0x01
	b _0800F834
_0800F668:
	bl func_0807E29C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800F690
	cmp r5, #0x01
	bgt _0800F678
	b _0800F838
_0800F678:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _0800F68E
	b _0800F838
_0800F68E:
	b _0800F6FA
_0800F690:
	bl func_08081838
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x03
	bne _0800F710
	bl GetRandom
	adds r1, r4, #0x0
	ands r1, r0
	cmp r1, #0x00
	bne _0800F6F4
	cmp r5, #0x00
	bgt _0800F6CC
	movs r2, #0xAA
	lsls r2, r2, #0x01
	add r2, r9
	ldr r0, [r2, #0x00]
	movs r1, #0x10
	orrs r0, r1
	str r0, [r2, #0x00]
	ldr r0, _0800F6C8 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r1, #0xEF
	ldrb r2, [r1, #0x00]
	movs r0, #0x04
	b _0800F704
	.byte 0x00, 0x00
_0800F6C8: .4byte 0x02039B84
_0800F6CC:
	ldr r0, _0800F6F0 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r1, #0xEF
	ldrb r2, [r1, #0x00]
	movs r0, #0x20
	orrs r0, r2
	strb r0, [r1, #0x00]
	cmp r5, #0x01
	beq _0800F6E0
	b _0800F838
_0800F6E0:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	add r0, r9
	ldr r1, [r0, #0x00]
	movs r2, #0x10
	orrs r1, r2
	str r1, [r0, #0x00]
	b _0800F838
_0800F6F0: .4byte 0x02039B84
_0800F6F4:
	cmp r5, #0x01
	bgt _0800F6FA
	b _0800F838
_0800F6FA:
	ldr r0, _0800F70C @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r1, #0xEF
	ldrb r2, [r1, #0x00]
	movs r0, #0x01
_0800F704:
	orrs r0, r2
	strb r0, [r1, #0x00]
	b _0800F838
	.byte 0x00, 0x00
_0800F70C: .4byte 0x02039B84
_0800F710:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	add r0, r9
	ldr r0, [r0, #0x00]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0x00
	bne _0800F754
	ldr r0, _0800F74C @ =0x02039B9C
	ldr r0, [r0, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800F754
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x3C
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _0800F754
	ldr r0, _0800F750 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r1, #0xEF
	ldrb r2, [r1, #0x00]
	movs r0, #0x04
	b _0800F704
_0800F74C: .4byte 0x02039B9C
_0800F750: .4byte 0x02039B84
_0800F754:
	cmp r6, #0x02
	bls _0800F76E
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x06
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _0800F7C4
	b _0800F786
_0800F76E:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _0800F7C4
	cmp r5, #0x01
	bgt _0800F79C
	cmp r6, #0x00
	beq _0800F79C
_0800F786:
	ldr r0, _0800F798 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r1, #0xEF
	ldrb r2, [r1, #0x00]
	movs r0, #0x10
	orrs r0, r2
	strb r0, [r1, #0x00]
	movs r0, #0x01
	b _0800F83A
_0800F798: .4byte 0x02039B84
_0800F79C:
	mov r0, r8
	cmp r0, #0x00
	beq _0800F6FA
	movs r0, #0xC2
	lsls r0, r0, #0x01
	add r0, r9
	ldr r1, [r0, #0x00]
	lsls r0, r6, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	cmp r0, r7
	bne _0800F6FA
	ldr r0, _0800F7C0 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r1, #0xEF
	ldrb r2, [r1, #0x00]
	movs r0, #0x10
	b _0800F704
_0800F7C0: .4byte 0x02039B84
_0800F7C4:
	ldr r4, _0800F804 @ =0x02039B84
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x16
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800F816
	ldr r0, [sp, #0x000]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	mov r0, r9
	ldr r2, [sp, #0x004]
	ldr r3, [sp, #0x008]
	bl func_0800F440
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800F808
	bl func_08081848
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r8
	bls _0800F82C
	mov r1, r8
	cmp r1, #0x00
	bne _0800F838
	b _0800F82C
_0800F804: .4byte 0x02039B84
_0800F808:
	bl func_08081848
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r8
	bne _0800F838
	b _0800F82C
_0800F816:
	ldr r0, [sp, #0x000]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	mov r0, r9
	ldr r2, [sp, #0x004]
	ldr r3, [sp, #0x008]
	bl func_0800F440
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800F838
_0800F82C:
	ldr r0, [r4, #0x00]
_0800F82E:
	adds r0, #0xEF
	ldrb r2, [r0, #0x00]
	movs r1, #0x20
_0800F834:
	orrs r1, r2
	strb r1, [r0, #0x00]
_0800F838:
	movs r0, #0x00
_0800F83A:
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
