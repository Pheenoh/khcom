.syntax unified
	.align 2, 0
	.global func_08005244
	.thumb
	.thumb_func
	.type func_08005244, %function
func_08005244: @ 08005244
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x02C
	adds r6, r0, #0x0
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	mov r10, r0
	lsls r5, r2, #0x10
	lsrs r1, r5, #0x10
	str r1, [sp, #0x010]
	ldr r0, _080052C0 @ =0x030074D4
	lsls r1, r6, #0x04
	ldr r0, [r0, #0x00]
	adds r4, r0, r1
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	bne _0800526E
	b _08005448
_0800526E:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _080052B2
	lsrs r2, r3, #0x13
	ldrh r0, [r4, #0x0A]
	lsrs r0, r0, #0x03
	subs r2, r2, r0
	lsls r2, r2, #0x18
	lsrs r1, r5, #0x13
	ldrh r0, [r4, #0x0C]
	lsrs r0, r0, #0x03
	subs r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r9, r1
	lsrs r3, r2, #0x18
	mov r8, r3
	asrs r7, r2, #0x18
	adds r0, r7, #0x0
	cmp r7, #0x00
	bge _0800529A
	negs r0, r7
_0800529A:
	cmp r0, #0x1D
	bgt _080052B2
	mov r5, r9
	lsls r0, r5, #0x18
	asrs r5, r0, #0x18
	adds r1, r5, #0x0
	str r0, [sp, #0x028]
	cmp r5, #0x00
	bge _080052AE
	negs r1, r5
_080052AE:
	cmp r1, #0x13
	ble _080052C4
_080052B2:
	adds r0, r6, #0x0
	mov r1, r10
	ldr r2, [sp, #0x010]
	bl func_080051C4
	b _08005448
	.byte 0x00, 0x00
_080052C0: .4byte 0x030074D4
_080052C4:
	adds r0, r6, #0x0
	bl func_08005550
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x014]
	adds r0, r6, #0x0
	bl func_0800558C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x018]
	ldrh r1, [r4, #0x0A]
	mov r0, r10
	subs r1, r0, r1
	ldr r3, [sp, #0x014]
	adds r1, r3, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r2, [r4, #0x0C]
	ldr r0, [sp, #0x010]
	subs r2, r0, r2
	ldr r3, [sp, #0x018]
	adds r2, r3, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0x0
	bl SetBgScroll
	cmp r7, #0x00
	bne _08005308
	cmp r5, #0x00
	bne _08005308
	b _0800543E
_08005308:
	ldr r1, _0800537C @ =0x09ECEB30
	lsls r0, r6, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldrh r1, [r0, #0x00]
	movs r0, #0xF8
	lsls r0, r0, #0x05
	ands r0, r1
	lsls r0, r0, #0x03
	movs r1, #0xC0
	lsls r1, r1, #0x13
	adds r7, r0, r1
	ldr r0, [sp, #0x014]
	lsrs r5, r0, #0x03
	str r5, [sp, #0x01C]
	ldr r1, [sp, #0x018]
	lsrs r1, r1, #0x03
	str r1, [sp, #0x020]
	adds r0, r6, #0x0
	bl func_08005550
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1B
	str r0, [sp, #0x024]
	adds r0, r6, #0x0
	bl func_0800558C
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x1B
	adds r3, r2, #0x0
	mov r6, r8
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	ble _08005380
	cmp r0, #0x1F
	ble _08005356
	movs r0, #0x1F
	mov r8, r0
_08005356:
	ldrh r0, [r4, #0x0A]
	adds r0, #0xF8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0x0
	adds r1, #0x1F
	str r1, [sp, #0x000]
	str r2, [sp, #0x004]
	mov r1, r8
	str r1, [sp, #0x008]
	movs r1, #0x15
	str r1, [sp, #0x00C]
	ldr r1, [sp, #0x010]
	adds r2, r4, #0x0
	adds r3, r7, #0x0
	bl func_08004C20
	b _080053C4
	.byte 0x00, 0x00
_0800537C: .4byte 0x09ECEB30
_08005380:
	cmp r0, #0x00
	bge _080053C4
	negs r0, r0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r8, r5
	asrs r0, r0, #0x18
	cmp r0, #0x1F
	ble _08005396
	movs r6, #0x1F
	mov r8, r6
_08005396:
	mov r0, r8
	lsls r2, r0, #0x18
	asrs r1, r2, #0x15
	ldrh r0, [r4, #0x0A]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, [sp, #0x01C]
	mov r6, r8
	subs r1, r5, r6
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x000]
	str r3, [sp, #0x004]
	lsrs r2, r2, #0x18
	str r2, [sp, #0x008]
	movs r1, #0x15
	str r1, [sp, #0x00C]
	ldr r1, [sp, #0x010]
	adds r2, r4, #0x0
	adds r3, r7, #0x0
	bl func_08004C20
_080053C4:
	ldr r1, [sp, #0x028]
	asrs r0, r1, #0x18
	cmp r0, #0x00
	ble _080053FA
	cmp r0, #0x15
	ble _080053D4
	movs r3, #0x15
	mov r9, r3
_080053D4:
	ldrh r1, [r4, #0x0C]
	adds r1, #0xA8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r5, [sp, #0x024]
	str r5, [sp, #0x000]
	ldr r0, [sp, #0x020]
	adds r0, #0x15
	str r0, [sp, #0x004]
	movs r0, #0x1F
	str r0, [sp, #0x008]
	mov r6, r9
	str r6, [sp, #0x00C]
	mov r0, r10
	adds r2, r4, #0x0
	adds r3, r7, #0x0
	bl func_08004C20
	b _0800543E
_080053FA:
	cmp r0, #0x00
	bge _0800543E
	negs r0, r0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	mov r9, r1
	asrs r0, r0, #0x18
	cmp r0, #0x15
	ble _08005410
	movs r3, #0x15
	mov r9, r3
_08005410:
	mov r5, r9
	lsls r2, r5, #0x18
	asrs r0, r2, #0x15
	ldrh r1, [r4, #0x0C]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r6, [sp, #0x024]
	str r6, [sp, #0x000]
	ldr r3, [sp, #0x020]
	subs r0, r3, r5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x004]
	movs r0, #0x1F
	str r0, [sp, #0x008]
	lsrs r2, r2, #0x18
	str r2, [sp, #0x00C]
	mov r0, r10
	adds r2, r4, #0x0
	adds r3, r7, #0x0
	bl func_08004C20
_0800543E:
	mov r5, r10
	strh r5, [r4, #0x0A]
	mov r6, sp
	ldrh r6, [r6, #0x10]
	strh r6, [r4, #0x0C]
_08005448:
	add sp, #0x02C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x04, 0x49, 0x00, 0x01, 0x09, 0x68, 0x09, 0x18, 0x48, 0x68, 0x00, 0x28, 0x04, 0xD0, 0x48, 0x89
	.byte 0x03, 0xE0, 0x00, 0x00, 0xD4, 0x74, 0x00, 0x03, 0x00, 0x20, 0x70, 0x47, 0x04, 0x49, 0x00, 0x01
	.byte 0x09, 0x68, 0x09, 0x18, 0x48, 0x68, 0x00, 0x28, 0x04, 0xD0, 0x88, 0x89, 0x03, 0xE0, 0x00, 0x00
	.byte 0xD4, 0x74, 0x00, 0x03, 0x00, 0x20, 0x70, 0x47
.syntax divided
