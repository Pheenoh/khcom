.syntax unified
	.align 2, 0
	.global task_btl_exp_1
	.thumb
	.thumb_func
	.type task_btl_exp_1, %function
task_btl_exp_1: @ 0805CF9C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0x0
	ldr r0, _0805CFC0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x06
	ands r0, r2
	movs r1, #0x00
	adds r6, r1, #0x0
	orrs r6, r0
	cmp r6, #0x00
	beq _0805CFC4
	movs r0, #0x00
	b _0805D0DC
_0805CFC0: .4byte 0x02039B84
_0805CFC4:
	adds r7, r4, #0x0
	adds r7, #0x3E
	ldr r0, _0805D064 @ =0x02039BB0
	mov r8, r0
	movs r5, #0x84
	lsls r5, r5, #0x01
	add r5, r8
	ldrb r0, [r7, #0x00]
	ldrb r1, [r5, #0x00]
	cmp r0, r1
	bcs _0805CFF6
	ldrb r1, [r5, #0x00]
	adds r0, r4, #0x0
	bl func_0805CE60
	ldr r0, _0805D068 @ =0x08B25E40
	str r0, [r4, #0x20]
	strh r6, [r4, #0x3C]
	movs r0, #0x03
	str r0, [r4, #0x48]
	ldrb r0, [r5, #0x00]
	strb r0, [r7, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x40
	strh r6, [r0, #0x00]
_0805CFF6:
	ldr r0, [r4, #0x48]
	cmp r0, #0x03
	beq _0805D02C
	movs r5, #0x80
	lsls r5, r5, #0x01
	add r5, r8
	ldr r2, [r4, #0x44]
	ldr r0, [r5, #0x00]
	cmp r2, r0
	bcs _0805D02C
	adds r1, r4, #0x0
	adds r1, #0x40
	subs r0, r0, r2
	ldrh r2, [r1, #0x00]
	adds r0, r0, r2
	strh r0, [r1, #0x00]
	ldrh r1, [r1, #0x00]
	adds r0, r4, #0x0
	bl func_0805CE60
	ldr r0, _0805D06C @ =0x08B25E54
	str r0, [r4, #0x20]
	strh r6, [r4, #0x3C]
	movs r0, #0x01
	str r0, [r4, #0x48]
	ldr r0, [r5, #0x00]
	str r0, [r4, #0x44]
_0805D02C:
	ldr r0, [r4, #0x48]
	cmp r0, #0x01
	beq _0805D070
	cmp r0, #0x01
	bcc _0805D0DA
	cmp r0, #0x02
	beq _0805D0C4
	cmp r0, #0x03
	bne _0805D0DA
	ldrh r1, [r4, #0x3C]
	movs r3, #0x3C
	ldsh r0, [r4, r3]
	cmp r0, #0x64
	ble _0805D0D6
	ldr r1, _0805D064 @ =0x02039BB0
	movs r2, #0x84
	lsls r2, r2, #0x01
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x62
	bhi _0805D088
	movs r0, #0x02
	str r0, [r4, #0x48]
	movs r3, #0x82
	lsls r3, r3, #0x01
	adds r0, r1, r3
	subs r3, #0x04
	b _0805D0A2
_0805D064: .4byte 0x02039BB0
_0805D068: .4byte 0x08B25E40
_0805D06C: .4byte 0x08B25E54
_0805D070:
	ldrh r1, [r4, #0x3C]
	movs r2, #0x3C
	ldsh r0, [r4, r2]
	cmp r0, #0x3C
	ble _0805D0D6
	ldr r1, _0805D090 @ =0x02039BB0
	movs r3, #0x84
	lsls r3, r3, #0x01
	adds r0, r1, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x62
	bls _0805D094
_0805D088:
	movs r0, #0x00
	str r0, [r4, #0x48]
	b _0805D0B4
	.byte 0x00, 0x00
_0805D090: .4byte 0x02039BB0
_0805D094:
	movs r0, #0x02
	str r0, [r4, #0x48]
	movs r2, #0x82
	lsls r2, r2, #0x01
	adds r0, r1, r2
	movs r3, #0x80
	lsls r3, r3, #0x01
_0805D0A2:
	adds r2, r1, r3
	ldr r1, [r0, #0x00]
	ldr r0, [r2, #0x00]
	subs r1, r1, r0
	adds r0, r4, #0x0
	bl func_0805CE60
	ldr r0, _0805D0C0 @ =0x08B25E5E
	str r0, [r4, #0x20]
_0805D0B4:
	movs r1, #0x00
	strh r1, [r4, #0x3C]
	adds r0, r4, #0x0
	adds r0, #0x40
	strh r1, [r0, #0x00]
	b _0805D0DA
_0805D0C0: .4byte 0x08B25E5E
_0805D0C4:
	ldrh r1, [r4, #0x3C]
	movs r2, #0x3C
	ldsh r0, [r4, r2]
	cmp r0, #0x64
	ble _0805D0D6
	movs r0, #0x00
	strh r0, [r4, #0x3C]
	str r0, [r4, #0x48]
	b _0805D0DA
_0805D0D6:
	adds r0, r1, #0x1
	strh r0, [r4, #0x3C]
_0805D0DA:
	movs r0, #0x01
_0805D0DC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
