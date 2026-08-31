.syntax unified
	.align 2, 0
	.global task_poo_wagon_2
	.thumb
	.thumb_func
	.type task_poo_wagon_2, %function
task_poo_wagon_2: @ 080D0418
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	adds r7, r0, #0x0
	movs r0, #0x00
	str r0, [sp, #0x010]
	ldrh r0, [r7, #0x3E]
	cmp r0, #0x00
	beq _080D044C
	ldr r3, _080D0448 @ =0x08121400
	adds r2, r7, #0x0
	adds r2, #0x40
	ldrh r1, [r2, #0x00]
	ldrb r0, [r2, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r4, #0x00
	ldsh r3, [r0, r4]
	adds r1, #0x10
	strh r1, [r2, #0x00]
	b _080D044E
_080D0448: .4byte 0x08121400
_080D044C:
	movs r3, #0x00
_080D044E:
	ldr r0, [r7, #0x1C]
	adds r0, r0, r3
	asrs r0, r0, #0x08
	ldr r1, _080D04B4 @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, [r7, #0x20]
	asrs r1, r1, #0x08
	ldr r2, [r7, #0x24]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	ldr r2, _080D04B8 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r2, r0, #0x10
	mov r8, r2
	asrs r0, r0, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x30
	str r2, [sp, #0x000]
	str r2, [sp, #0x004]
	movs r2, #0x20
	movs r3, #0x28
	bl func_080035CC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D04BC
	ldr r0, [r7, #0x04]
	cmp r0, #0x00
	bne _080D0494
	b _080D0674
_080D0494:
	ldr r0, [r7, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r7, #0x0C]
	bl ReleaseObjTiles
	ldr r0, [r7, #0x14]
	bl ReleaseObjTiles
	ldr r0, [r7, #0x04]
	bl ReleaseObjPalette
	movs r0, #0x00
	str r0, [r7, #0x04]
	b _080D0674
	.byte 0x00, 0x00
_080D04B4: .4byte 0x0203C40C
_080D04B8: .4byte 0x0203C3F8
_080D04BC:
	ldr r0, [r7, #0x04]
	cmp r0, #0x00
	bne _080D04F0
	movs r0, #0xAC
	lsls r0, r0, #0x03
	ldr r4, _080D0534 @ =0x09758C94
	adds r1, r4, #0x0
	bl AllocObjTiles
	str r0, [r7, #0x00]
	movs r0, #0x98
	lsls r0, r0, #0x03
	adds r1, r4, #0x0
	bl AllocObjTiles
	str r0, [r7, #0x0C]
	movs r0, #0xA0
	adds r1, r4, #0x0
	bl AllocObjTiles
	str r0, [r7, #0x14]
	ldr r0, _080D0538 @ =0x09849DD8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r7, #0x04]
_080D04F0:
	bl func_080CBB7C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r10, r0
	bl func_080CFF30
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D055C
	ldr r5, _080D053C @ =0x02034E26
	mov r0, r10
	adds r0, #0x03
	strh r0, [r5, #0x00]
	ldr r4, _080D0540 @ =0x02034E24
	subs r0, #0x04
	strh r0, [r4, #0x00]
	bl func_080C9DAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D05D6
	ldr r1, _080D0544 @ =0x0203C420
	ldr r0, _080D0548 @ =0x0203C3EC
	ldr r0, [r0, #0x00]
	ldr r1, [r1, #0x04]
	ldr r0, [r0, #0x04]
	cmp r1, r0
	blt _080D054C
	ldrh r0, [r5, #0x00]
	adds r0, #0x06
	strh r0, [r5, #0x00]
	b _080D05D6
	.byte 0x00, 0x00
_080D0534: .4byte 0x09758C94
_080D0538: .4byte 0x09849DD8
_080D053C: .4byte 0x02034E26
_080D0540: .4byte 0x02034E24
_080D0544: .4byte 0x0203C420
_080D0548: .4byte 0x0203C3EC
_080D054C:
	ldr r3, _080D0558 @ =0x0000FFFC
	adds r0, r3, #0x0
	ldrh r1, [r4, #0x00]
	adds r0, r0, r1
	strh r0, [r4, #0x00]
	b _080D05D6
_080D0558: .4byte 0x0000FFFC
_080D055C:
	ldr r1, _080D0594 @ =0x0203C420
	ldr r0, [r1, #0x00]
	ldr r1, [r1, #0x04]
	bl func_080D0210
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x010]
	cmp r0, #0x00
	bne _080D05A8
	ldr r1, [r7, #0x20]
	movs r2, #0xC0
	lsls r2, r2, #0x02
	adds r1, r1, r2
	ldr r2, _080D0598 @ =0x02034E26
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r3, _080D059C @ =0xFFFFEFFC
	adds r0, r3, #0x0
	subs r0, r0, r1
	strh r0, [r2, #0x00]
	ldr r2, _080D05A0 @ =0x02034E24
	ldr r4, _080D05A4 @ =0xFFFFEFF7
	adds r0, r4, #0x0
	subs r0, r0, r1
	strh r0, [r2, #0x00]
	b _080D05D6
	.byte 0x00, 0x00
_080D0594: .4byte 0x0203C420
_080D0598: .4byte 0x02034E26
_080D059C: .4byte 0xFFFFEFFC
_080D05A0: .4byte 0x02034E24
_080D05A4: .4byte 0xFFFFEFF7
_080D05A8:
	ldr r0, [sp, #0x010]
	cmp r0, #0x53
	beq _080D05B2
	cmp r0, #0xAD
	bne _080D05C8
_080D05B2:
	ldr r1, _080D05C0 @ =0x02034E26
	mov r0, r10
	subs r0, #0x03
	strh r0, [r1, #0x00]
	ldr r1, _080D05C4 @ =0x02034E24
	subs r0, #0x05
	b _080D05D4
_080D05C0: .4byte 0x02034E26
_080D05C4: .4byte 0x02034E24
_080D05C8:
	ldr r1, _080D0684 @ =0x02034E24
	mov r0, r10
	adds r0, #0x04
	strh r0, [r1, #0x00]
	ldr r1, _080D0688 @ =0x02034E26
	adds r0, #0x05
_080D05D4:
	strh r0, [r1, #0x00]
_080D05D6:
	mov r1, r8
	lsls r1, r1, #0x10
	str r1, [sp, #0x014]
	asrs r1, r1, #0x10
	mov r8, r1
	lsls r6, r6, #0x10
	mov r9, r6
	asrs r6, r6, #0x10
	ldr r2, [r7, #0x08]
	ldr r3, [r7, #0x00]
	ldr r0, [r7, #0x04]
	str r0, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	ldr r0, _080D0688 @ =0x02034E26
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x00C]
	mov r0, r8
	adds r1, r6, #0x0
	bl DrawSprite
	ldr r2, [r7, #0x10]
	ldr r3, [r7, #0x0C]
	ldr r0, [r7, #0x04]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r4, [sp, #0x008]
	ldr r0, _080D0684 @ =0x02034E24
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x00C]
	mov r0, r8
	adds r1, r6, #0x0
	bl DrawSprite
	ldr r0, [r7, #0x20]
	ldr r2, _080D068C @ =0xFFFFF200
	adds r0, r0, r2
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	ldr r3, _080D0690 @ =0xFFFFEFFE
	adds r1, r3, #0x0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	bl func_080CFF30
	lsls r0, r0, #0x18
	ldr r2, [sp, #0x014]
	mov r1, r9
	cmp r0, #0x00
	bne _080D0658
	cmp r10, r5
	bls _080D0658
	ldr r4, [sp, #0x010]
	cmp r4, #0x53
	beq _080D0650
	cmp r4, #0xAD
	bne _080D0658
_080D0650:
	mov r0, r10
	subs r0, #0x01
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_080D0658:
	asrs r0, r2, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x18]
	ldr r3, [r7, #0x14]
	ldr r4, [r7, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	str r5, [sp, #0x00C]
	bl DrawSprite
_080D0674:
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D0684: .4byte 0x02034E24
_080D0688: .4byte 0x02034E26
_080D068C: .4byte 0xFFFFF200
_080D0690: .4byte 0xFFFFEFFE
.syntax divided
