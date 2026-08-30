.syntax unified
	.align 2, 0
	.global func_08006954
	.thumb
	.thumb_func
	.type func_08006954, %function
func_08006954: @ 08006954
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	ldr r0, _08006988 @ =0x02034040
	ldr r1, [r0, #0x00]
	cmp r1, #0x00
	bne _08006966
	b _08006B06
_08006966:
	ldr r2, _0800698C @ =0x02034046
	ldrh r0, [r2, #0x00]
	ldrh r1, [r1, #0x14]
	cmp r0, r1
	bcc _0800699E
	ldr r0, _08006990 @ =0x02034066
	ldrh r1, [r0, #0x00]
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r0, #0x00
	blt _08006998
	strh r1, [r2, #0x00]
	ldr r1, _08006994 @ =0x02034044
	movs r0, #0x00
	strh r0, [r1, #0x00]
	b _08006B06
	.byte 0x00, 0x00
_08006988: .4byte 0x02034040
_0800698C: .4byte 0x02034046
_08006990: .4byte 0x02034066
_08006994: .4byte 0x02034044
_08006998:
	bl func_08006B4C
	b _08006B06
_0800699E:
	ldr r0, _080069CC @ =0x02034058
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080069E8
	ldr r0, _080069D0 @ =0x02034048
	ldr r0, [r0, #0x00]
	ldr r1, _080069D4 @ =0x02034064
	ldrb r1, [r1, #0x00]
	ldr r2, _080069D8 @ =0x0203405C
	ldr r2, [r2, #0x00]
	ldr r3, _080069DC @ =0x02034060
	ldr r3, [r3, #0x00]
	ldr r4, _080069E0 @ =0x02034050
	movs r5, #0x00
	ldsh r4, [r4, r5]
	str r4, [sp, #0x000]
	ldr r4, _080069E4 @ =0x02034052
	movs r5, #0x00
	ldsh r4, [r4, r5]
	str r4, [sp, #0x004]
	bl func_0800685C
	b _08006A1C
_080069CC: .4byte 0x02034058
_080069D0: .4byte 0x02034048
_080069D4: .4byte 0x02034064
_080069D8: .4byte 0x0203405C
_080069DC: .4byte 0x02034060
_080069E0: .4byte 0x02034050
_080069E4: .4byte 0x02034052
_080069E8:
	ldr r0, _08006A9C @ =0x02034048
	ldr r0, [r0, #0x00]
	ldr r4, _08006AA0 @ =0x02034050
	ldrh r1, [r4, #0x00]
	ldr r5, _08006AA4 @ =0x02034052
	ldrh r2, [r5, #0x00]
	bl func_080054EC
	ldrh r0, [r4, #0x00]
	adds r0, #0xFF
	lsls r0, r0, #0x10
	movs r1, #0xBF
	lsls r1, r1, #0x11
	movs r2, #0x00
	cmp r0, r1
	bhi _08006A18
	movs r0, #0x00
	ldsh r1, [r5, r0]
	cmp r1, #0x7F
	bgt _08006A18
	ldr r0, _08006AA8 @ =0xFFFFFF00
	cmp r1, r0
	ble _08006A18
	movs r2, #0x01
_08006A18:
	cmp r2, #0x00
	beq _08006AD4
_08006A1C:
	ldr r7, _08006A9C @ =0x02034048
	ldr r0, [r7, #0x00]
	bl func_08004FC8
	ldr r0, _08006AAC @ =0x02034044
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08006ADC
	ldr r0, _08006AB0 @ =0x02034046
	ldr r1, _08006AB4 @ =0x0203404E
	ldrh r5, [r0, #0x00]
	ldrh r6, [r1, #0x00]
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl _0811D754
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl func_0811D7CC
	ldr r1, _08006AB8 @ =0x0203404C
	mov r8, r1
	ldrh r2, [r1, #0x00]
	muls r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08006ABC @ =0x02034040
	ldr r1, [r1, #0x00]
	ldr r1, [r1, #0x00]
	lsls r4, r4, #0x03
	adds r4, r4, r1
	ldr r1, [r4, #0x00]
	adds r6, r1, r0
	adds r0, r0, r2
	ldrh r1, [r4, #0x04]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r5, r0, #0x10
	cmp r5, #0x00
	ble _08006AC0
	subs r4, r2, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, [r7, #0x00]
	bl func_08005130
	adds r1, r0, #0x0
	adds r0, r6, #0x0
	adds r2, r4, #0x0
	bl func_080043B4
	ldr r0, [r7, #0x00]
	bl func_08005130
	adds r0, r0, r4
	lsrs r1, r5, #0x10
	bl func_0800443C
	b _08006ADC
	.byte 0x00, 0x00
_08006A9C: .4byte 0x02034048
_08006AA0: .4byte 0x02034050
_08006AA4: .4byte 0x02034052
_08006AA8: .4byte 0xFFFFFF00
_08006AAC: .4byte 0x02034044
_08006AB0: .4byte 0x02034046
_08006AB4: .4byte 0x0203404E
_08006AB8: .4byte 0x0203404C
_08006ABC: .4byte 0x02034040
_08006AC0:
	ldr r0, [r7, #0x00]
	bl func_08005130
	adds r1, r0, #0x0
	mov r3, r8
	ldrh r2, [r3, #0x00]
	adds r0, r6, #0x0
	bl func_080043B4
	b _08006ADC
_08006AD4:
	ldr r0, _08006B14 @ =0x02034048
	ldr r0, [r0, #0x00]
	bl func_0800501C
_08006ADC:
	ldr r2, _08006B18 @ =0x02034044
	ldrh r0, [r2, #0x00]
	adds r0, #0x01
	strh r0, [r2, #0x00]
	ldr r1, _08006B1C @ =0x0203406A
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1, #0x00]
	cmp r0, r1
	bcc _08006B06
	movs r0, #0x00
	strh r0, [r2, #0x00]
	ldr r2, _08006B20 @ =0x02034046
	ldrh r1, [r2, #0x00]
	ldr r0, _08006B24 @ =0x02034068
	movs r5, #0x00
	ldsh r0, [r0, r5]
	cmp r1, r0
	beq _08006B06
	adds r0, r1, #0x1
	strh r0, [r2, #0x00]
_08006B06:
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08006B14: .4byte 0x02034048
_08006B18: .4byte 0x02034044
_08006B1C: .4byte 0x0203406A
_08006B20: .4byte 0x02034046
_08006B24: .4byte 0x02034068
	.byte 0x01, 0x49, 0x08, 0x80, 0x70, 0x47, 0x00, 0x00, 0x6A, 0x40, 0x03, 0x02
.syntax divided
