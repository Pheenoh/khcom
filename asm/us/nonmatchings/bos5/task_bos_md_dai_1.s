.syntax unified
	.align 2, 0
	.global task_bos_md_dai_1
	.thumb
	.thumb_func
	.type task_bos_md_dai_1, %function
task_bos_md_dai_1: @ 080FD4BC
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x00C
	adds r5, r0, #0x0
	movs r0, #0x01
	mov r9, r0
	adds r6, r5, #0x0
	adds r6, #0x7E
	ldrh r0, [r6, #0x00]
	cmp r0, #0x01
	beq _080FD538
	cmp r0, #0x01
	bgt _080FD4E0
	cmp r0, #0x00
	beq _080FD4EC
	b _080FD686
_080FD4E0:
	cmp r0, #0x02
	beq _080FD590
	cmp r0, #0x03
	bne _080FD4EA
	b _080FD5E4
_080FD4EA:
	b _080FD686
_080FD4EC:
	adds r0, r5, #0x0
	adds r0, #0x0C
	ldrh r2, [r5, #0x10]
	movs r1, #0x00
	bl ApproachValue
	ldrh r0, [r5, #0x10]
	subs r0, #0x01
	strh r0, [r5, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	ble _080FD506
	b _080FD686
_080FD506:
	adds r4, r5, #0x0
	adds r4, #0x1C
	adds r0, r4, #0x0
	movs r1, #0x00
	bl func_08012614
	adds r0, r4, #0x0
	movs r1, #0x08
	bl func_08012658
	ldr r0, [r5, #0x08]
	ldr r1, _080FD534 @ =0xFFFF6000
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	movs r0, #0xAA
	lsls r0, r0, #0x02
	bl m4aSongNumStart
	adds r0, r5, #0x0
	adds r0, #0x7C
	mov r1, r9
	b _080FD57C
	.byte 0x00, 0x00
_080FD534: .4byte 0xFFFF6000
_080FD538:
	adds r0, r5, #0x0
	adds r0, #0x0C
	ldr r1, _080FD588 @ =0xFFFFF200
	ldrh r2, [r5, #0x10]
	bl ApproachValue
	ldrh r0, [r5, #0x10]
	subs r0, #0x01
	strh r0, [r5, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	ble _080FD552
	b _080FD686
_080FD552:
	adds r4, r5, #0x0
	adds r4, #0x1C
	adds r0, r4, #0x0
	movs r1, #0x00
	bl func_08012614
	adds r0, r4, #0x0
	movs r1, #0x10
	bl func_08012658
	ldr r0, [r5, #0x08]
	ldr r1, _080FD58C @ =0xFFFF6000
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	movs r0, #0xAA
	lsls r0, r0, #0x02
	bl m4aSongNumStart
	adds r0, r5, #0x0
	adds r0, #0x7C
	movs r1, #0x02
_080FD57C:
	strh r1, [r0, #0x00]
	movs r0, #0x14
	strh r0, [r5, #0x10]
	strh r1, [r6, #0x00]
	b _080FD686
	.byte 0x00, 0x00
_080FD588: .4byte 0xFFFFF200
_080FD58C: .4byte 0xFFFF6000
_080FD590:
	adds r0, r5, #0x0
	adds r0, #0x0C
	ldr r1, _080FD5DC @ =0xFFFFE400
	ldrh r2, [r5, #0x10]
	bl ApproachValue
	ldrh r0, [r5, #0x10]
	subs r0, #0x01
	strh r0, [r5, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bgt _080FD686
	adds r4, r5, #0x0
	adds r4, #0x1C
	adds r0, r4, #0x0
	movs r1, #0x00
	bl func_08012614
	adds r0, r4, #0x0
	movs r1, #0x18
	bl func_08012658
	movs r0, #0xAA
	lsls r0, r0, #0x02
	bl m4aSongNumStart
	adds r0, r5, #0x0
	adds r0, #0x7C
	movs r3, #0x03
	strh r3, [r0, #0x00]
	ldr r2, [r5, #0x78]
	ldrh r1, [r2, #0x00]
	ldr r0, _080FD5E0 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2, #0x00]
	strh r3, [r6, #0x00]
	b _080FD686
	.byte 0x00, 0x00
_080FD5DC: .4byte 0xFFFFE400
_080FD5E0: .4byte 0x0000FFFE
_080FD5E4:
	ldr r2, [r5, #0x78]
	ldrh r1, [r2, #0x00]
	mov r0, r9
	ands r0, r1
	cmp r0, #0x00
	beq _080FD686
	ldr r0, _080FD670 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r0, [r5, #0x00]
	str r0, [sp, #0x000]
	ldr r0, [r5, #0x04]
	str r0, [sp, #0x004]
	adds r4, r5, #0x0
	adds r4, #0x7C
	movs r0, #0x00
	ldsh r1, [r4, r0]
	subs r1, #0x01
	lsls r0, r1, #0x03
	subs r0, r0, r1
	lsls r0, r0, #0x09
	negs r0, r0
	str r0, [sp, #0x008]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x03
	bl __umodsi3
	adds r0, #0x03
	movs r6, #0x00
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x1C
	adds r1, r1, r5
	mov r8, r1
	adds r7, r4, #0x0
	cmp r6, r0
	bge _080FD654
	adds r4, r0, #0x0
_080FD636:
	adds r0, r5, #0x0
	adds r0, #0x80
	ldr r0, [r0, #0x00]
	ldr r1, _080FD674 @ =0x09EF8F0C
	mov r2, sp
	bl TaskCreate
	lsls r0, r6, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r4
	blt _080FD636
_080FD654:
	adds r1, r7, #0x0
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bgt _080FD678
	mov r0, r8
	movs r1, #0x01
	bl func_08012614
	movs r0, #0x00
	mov r9, r0
	b _080FD686
_080FD670: .4byte 0x0000FFFE
_080FD674: .4byte 0x09EF8F0C
_080FD678:
	movs r0, #0x00
	ldsh r1, [r7, r0]
	lsls r1, r1, #0x13
	lsrs r1, r1, #0x10
	mov r0, r8
	bl func_08012658
_080FD686:
	mov r0, r9
	add sp, #0x00C
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
