.syntax unified
	.align 2, 0
	.global task_emy_01_1
	.thumb
	.thumb_func
	.type task_emy_01_1, %function
task_emy_01_1: @ 08037304
	push {r4, r5, r6, r7, lr}
	add sp, #-0x014
	adds r4, r0, #0x0
	adds r6, r4, #0x0
	adds r5, r4, #0x0
	adds r5, #0x3C
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08037344
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _08037330
	cmp r1, #0x01
	beq _0803733A
	b _08037344
_08037330:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x12
	b _08037342
_0803733A:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r4, r2
	movs r0, #0x13
_08037342:
	str r0, [r1, #0x00]
_08037344:
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r0, r4, r3
	ldr r0, [r0, #0x00]
	cmp r0, #0x12
	beq _08037356
	cmp r0, #0x13
	beq _08037418
	b _080374EC
_08037356:
	ldr r0, _080373C0 @ =0x0813D434
	adds r1, r6, #0x0
	adds r1, #0x10
	ldr r2, [r6, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	movs r1, #0xB4
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r7, #0x00
	str r7, [r0, #0x00]
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r0, r4, r2
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r0, #0x00
	beq _080373F8
	cmp r0, #0x16
	bne _080373F8
	ldr r6, [r5, #0x08]
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	adds r2, r1, #0x0
	orrs r2, r0
	cmp r2, #0x00
	beq _080373D0
	ldr r1, [r5, #0x04]
	ldr r2, _080373C4 @ =0xFFFF9C00
	adds r0, r1, r2
	ldr r3, _080373C8 @ =0xFFFFDA00
	adds r1, r1, r3
	ldr r3, [r5, #0x0C]
	ldr r5, _080373CC @ =0xFFFFF400
	adds r3, r3, r5
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	str r7, [sp, #0x008]
	movs r0, #0x01
	str r0, [sp, #0x00C]
	movs r0, #0xA7
	str r0, [sp, #0x010]
	movs r0, #0x00
	adds r2, r6, #0x0
	bl func_08012E44
	b _080373F8
_080373C0: .4byte 0x0813D434
_080373C4: .4byte 0xFFFF9C00
_080373C8: .4byte 0xFFFFDA00
_080373CC: .4byte 0xFFFFF400
_080373D0:
	ldr r1, [r5, #0x04]
	movs r3, #0xC8
	lsls r3, r3, #0x07
	adds r0, r1, r3
	movs r3, #0x98
	lsls r3, r3, #0x06
	adds r1, r1, r3
	ldr r3, [r5, #0x0C]
	ldr r5, _08037414 @ =0xFFFFF400
	adds r3, r3, r5
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	str r2, [sp, #0x008]
	str r2, [sp, #0x00C]
	movs r0, #0xA7
	str r0, [sp, #0x010]
	movs r0, #0x00
	adds r2, r6, #0x0
	bl func_08012E44
_080373F8:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x15
	ble _080374E0
	bl func_080128EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080374D4
	b _080374E0
	.byte 0x00, 0x00
_08037414: .4byte 0xFFFFF400
_08037418:
	ldr r0, _08037484 @ =0x0813D434
	adds r1, r6, #0x0
	adds r1, #0x10
	ldr r2, [r6, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
	movs r1, #0xB4
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r7, #0x00
	str r7, [r0, #0x00]
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r0, r4, r2
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r0, #0x00
	beq _080374BC
	cmp r0, #0x16
	bne _080374BC
	ldr r6, [r5, #0x08]
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	adds r2, r1, #0x0
	orrs r2, r0
	cmp r2, #0x00
	beq _08037494
	ldr r1, [r5, #0x04]
	ldr r2, _08037488 @ =0xFFFF9C00
	adds r0, r1, r2
	ldr r3, _0803748C @ =0xFFFFDA00
	adds r1, r1, r3
	ldr r3, [r5, #0x0C]
	ldr r5, _08037490 @ =0xFFFFF400
	adds r3, r3, r5
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	str r7, [sp, #0x008]
	movs r0, #0x01
	str r0, [sp, #0x00C]
	movs r0, #0xA8
	str r0, [sp, #0x010]
	movs r0, #0x01
	adds r2, r6, #0x0
	bl func_08012E44
	b _080374BC
	.byte 0x00, 0x00
_08037484: .4byte 0x0813D434
_08037488: .4byte 0xFFFF9C00
_0803748C: .4byte 0xFFFFDA00
_08037490: .4byte 0xFFFFF400
_08037494:
	ldr r1, [r5, #0x04]
	movs r3, #0xC8
	lsls r3, r3, #0x07
	adds r0, r1, r3
	movs r3, #0x98
	lsls r3, r3, #0x06
	adds r1, r1, r3
	ldr r3, [r5, #0x0C]
	ldr r5, _080374DC @ =0xFFFFF400
	adds r3, r3, r5
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	str r2, [sp, #0x008]
	str r2, [sp, #0x00C]
	movs r0, #0xA8
	str r0, [sp, #0x010]
	movs r0, #0x01
	adds r2, r6, #0x0
	bl func_08012E44
_080374BC:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x15
	ble _080374E0
	bl func_080128EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080374E0
_080374D4:
	adds r0, r4, #0x0
	bl func_0800CB4C
	b _080374EC
_080374DC: .4byte 0xFFFFF400
_080374E0:
	movs r3, #0xAA
	lsls r3, r3, #0x01
	adds r1, r4, r3
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_080374EC:
	adds r0, r4, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x014
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
