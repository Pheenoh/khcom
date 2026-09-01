.syntax unified
	.align 2, 0
	.global func_08018724
	.thumb
	.thumb_func
	.type func_08018724, %function
func_08018724: @ 08018724
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x008
	adds r7, r0, #0x0
	mov r8, r1
	adds r6, r2, #0x0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r9, r3
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x00
	bne _08018832
	bl func_08012674
	ldr r5, _0801879C @ =0x02034928
	ldr r1, [r5, #0x00]
	str r7, [r1, #0x10]
	mov r0, r8
	str r0, [r1, #0x14]
	str r6, [r1, #0x18]
	strh r4, [r1, #0x26]
	movs r0, #0x50
	strh r0, [r1, #0x0A]
	ldr r0, [sp, #0x024]
	str r0, [r1, #0x48]
	mov r4, sp
	adds r4, #0x06
	str r6, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	adds r2, r7, #0x0
	mov r3, r8
	bl WorldToScreen
	ldr r0, _080187A0 @ =0x09EDAD08
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	mov r0, r9
	cmp r0, #0x00
	beq _080187A4
	ldr r2, [r5, #0x00]
	ldrh r0, [r2, #0x34]
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r2, #0x34]
	adds r2, #0x24
	movs r0, #0xF8
	strb r0, [r2, #0x00]
	b _080187AC
_0801879C: .4byte 0x02034928
_080187A0: .4byte 0x09EDAD08
_080187A4:
	ldr r0, [r5, #0x00]
	adds r0, #0x24
	movs r1, #0x08
	strb r1, [r0, #0x00]
_080187AC:
	ldr r0, _080187DC @ =0x02034928
	ldr r4, [r0, #0x00]
	ldrh r1, [r4, #0x34]
	movs r2, #0x01
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _080187E4
	ldr r0, _080187E0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r1, [r4, #0x10]
	ldr r0, [r0, #0x04]
	cmp r1, r0
	blt _080187F2
	subs r0, r1, r0
	lsls r0, r0, #0x08
	movs r1, #0x96
	lsls r1, r1, #0x07
	bl __divsi3
	negs r0, r0
	b _08018808
	.byte 0x00, 0x00
_080187DC: .4byte 0x02034928
_080187E0: .4byte 0x02039B84
_080187E4:
	ldr r0, _080187F8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r1, [r4, #0x10]
	ldr r0, [r0, #0x04]
	cmp r1, r0
	ble _080187FC
_080187F2:
	strh r2, [r4, #0x26]
	b _0801880A
	.byte 0x00, 0x00
_080187F8: .4byte 0x02039B84
_080187FC:
	subs r0, r0, r1
	lsls r0, r0, #0x08
	movs r1, #0x96
	lsls r1, r1, #0x07
	bl __divsi3
_08018808:
	str r0, [r4, #0x1C]
_0801880A:
	movs r0, #0x03
	bl func_08006B34
	ldr r4, _08018840 @ =0x02034928
	ldr r1, [r4, #0x00]
	ldr r0, _08018844 @ =0x080185D1
	str r0, [r1, #0x04]
	ldr r0, _08018848 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	ldr r2, [r4, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_08018832:
	add sp, #0x008
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08018840: .4byte 0x02034928
_08018844: .4byte 0x080185D1
_08018848: .4byte 0x02039B84
.syntax divided
