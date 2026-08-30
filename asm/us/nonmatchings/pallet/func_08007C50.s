.syntax unified
	.align 2, 0
	.global func_08007C50
	.thumb
	.thumb_func
	.type func_08007C50, %function
func_08007C50: @ 08007C50
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	str r0, [sp, #0x008]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	movs r3, #0xFB
	lsls r3, r3, #0x18
	adds r0, r1, r3
	asrs r0, r0, #0x01
	mov r9, r0
	lsrs r2, r2, #0x11
	mov r10, r2
	movs r7, #0x00
	cmp r7, r10
	bcs _08007D1E
	movs r4, #0xF8
	lsls r4, r4, #0x05
	mov r12, r4
_08007C86:
	lsls r0, r7, #0x01
	ldr r6, [sp, #0x000]
	adds r0, r0, r6
	ldrh r1, [r0, #0x00]
	movs r6, #0x1F
	ands r6, r1
	movs r0, #0xF8
	lsls r0, r0, #0x02
	ands r0, r1
	lsrs r3, r0, #0x05
	movs r0, #0x1F
	ands r3, r0
	movs r0, #0xF8
	lsls r0, r0, #0x07
	ands r0, r1
	lsrs r1, r0, #0x0A
	movs r4, #0x1F
	ands r1, r4
	lsls r2, r6, #0x08
	lsls r4, r3, #0x08
	lsls r5, r1, #0x08
	lsls r0, r6, #0x02
	ldr r6, _08007D40 @ =0x08121694
	adds r0, r0, r6
	ldr r0, [r0, #0x00]
	mov r6, r8
	muls r6, r0
	adds r0, r6, #0x0
	adds r2, r2, r0
	lsls r0, r3, #0x02
	ldr r3, _08007D40 @ =0x08121694
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	mov r6, r8
	muls r6, r0
	adds r0, r6, #0x0
	adds r4, r4, r0
	lsls r0, r1, #0x02
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	mov r1, r8
	muls r1, r0
	adds r0, r1, #0x0
	adds r5, r5, r0
	cmp r2, r12
	ble _08007CE6
	movs r2, #0xF8
	lsls r2, r2, #0x05
_08007CE6:
	cmp r4, r12
	ble _08007CEC
	mov r4, r12
_08007CEC:
	cmp r5, r12
	ble _08007CF2
	mov r5, r12
_08007CF2:
	lsls r0, r2, #0x08
	lsrs r6, r0, #0x10
	lsls r0, r4, #0x08
	lsrs r3, r0, #0x10
	lsls r0, r5, #0x08
	lsrs r1, r0, #0x10
	ldr r4, _08007D44 @ =0x0300756C
	ldr r2, [r4, #0x00]
	mov r4, r9
	adds r0, r7, r4
	lsls r0, r0, #0x01
	adds r2, r2, r0
	lsls r0, r1, #0x0A
	lsls r1, r3, #0x05
	orrs r0, r1
	orrs r6, r0
	strh r6, [r2, #0x00]
	adds r0, r7, #0x1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, r10
	bcc _08007C86
_08007D1E:
	mov r6, r9
	cmp r6, #0x00
	bne _08007D48
	ldr r0, _08007D44 @ =0x0300756C
	ldr r0, [r0, #0x00]
	adds r0, #0x02
	ldr r1, [sp, #0x004]
	adds r1, #0x02
	ldr r2, [sp, #0x008]
	subs r2, #0x02
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl func_080043B4
	movs r4, #0x00
	b _08007D5A
	.byte 0x00, 0x00
_08007D40: .4byte 0x08121694
_08007D44: .4byte 0x0300756C
_08007D48:
	ldr r0, _08007D70 @ =0x0300756C
	mov r1, r9
	lsls r4, r1, #0x01
	ldr r0, [r0, #0x00]
	adds r0, r0, r4
	ldr r1, [sp, #0x004]
	ldr r2, [sp, #0x008]
	bl func_080043B4
_08007D5A:
	ldr r0, _08007D70 @ =0x0300756C
	ldr r0, [r0, #0x00]
	adds r0, r0, r4
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08007D70: .4byte 0x0300756C
.syntax divided
