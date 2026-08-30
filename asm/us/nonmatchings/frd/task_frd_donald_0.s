.syntax unified
	.align 2, 0
	.global task_frd_donald_0
	.thumb
	.thumb_func
	.type task_frd_donald_0, %function
task_frd_donald_0: @ 08045550
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x004
	adds r6, r0, #0x0
	mov r8, r1
	adds r7, r6, #0x0
	adds r7, #0x20
	ldrb r1, [r1, #0x02]
	cmp r1, #0x00
	beq _080455A0
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r5, _08045594 @ =0x02039B84
	ldr r4, [r5, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08045598 @ =0x00200000
	ldr r3, _0804559C @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r0, [r4, #0x7C]
	str r0, [r6, #0x14]
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r4, r4, r1
	ldr r0, [r4, #0x00]
	str r0, [r6, #0x18]
	b _080455CE
	.byte 0x00, 0x00
_08045594: .4byte 0x02039B84
_08045598: .4byte 0x00200000
_0804559C: .4byte 0x00000000
_080455A0:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strb r1, [r0, #0x00]
	ldr r0, _08045628 @ =0x02039B9C
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _0804562C @ =0x00200000
	ldr r3, _08045630 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r0, [r4, #0x7C]
	str r0, [r6, #0x14]
	ldr r1, _08045634 @ =0x02039B84
	ldr r0, [r1, #0x00]
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x18]
	adds r5, r1, #0x0
_080455CE:
	mov r1, r8
	ldrh r0, [r1, #0x00]
	ldr r1, _08045638 @ =0x0000014D
	adds r2, r6, r1
	movs r1, #0x00
	strb r0, [r2, #0x00]
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r0, r6, r2
	str r1, [r0, #0x00]
	adds r2, #0x06
	adds r0, r6, r2
	strh r1, [r0, #0x00]
	adds r2, #0x02
	adds r0, r6, r2
	strh r1, [r0, #0x00]
	adds r2, #0x04
	adds r0, r6, r2
	str r1, [r0, #0x00]
	ldr r3, [r6, #0x14]
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08045640
	movs r0, #0xAC
	lsls r0, r0, #0x01
	adds r1, r6, r0
	ldr r0, [r3, #0x04]
	ldr r2, _0804563C @ =0xFFFFD000
	adds r0, r0, r2
	str r0, [r1, #0x00]
	ldr r0, [r5, #0x00]
	adds r0, #0xDC
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r0, #0x30
	lsls r0, r0, #0x08
	str r0, [r7, #0x04]
	movs r0, #0x04
	movs r1, #0x00
	b _08045662
_08045628: .4byte 0x02039B9C
_0804562C: .4byte 0x00200000
_08045630: .4byte 0x00000000
_08045634: .4byte 0x02039B84
_08045638: .4byte 0x0000014D
_0804563C: .4byte 0xFFFFD000
_08045640:
	movs r2, #0xAC
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldr r0, [r3, #0x04]
	movs r2, #0xC0
	lsls r2, r2, #0x06
	adds r0, r0, r2
	str r0, [r1, #0x00]
	ldr r0, [r5, #0x00]
	adds r0, #0xDA
	movs r1, #0x00
	ldsh r0, [r0, r1]
	subs r0, #0x30
	lsls r0, r0, #0x08
	str r0, [r7, #0x04]
	movs r0, #0x00
	movs r1, #0x00
_08045662:
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldr r0, [r6, #0x14]
	ldr r0, [r0, #0x08]
	str r0, [r7, #0x08]
	ldr r0, _080456B0 @ =0xFFFFB000
	str r0, [r7, #0x0C]
	movs r0, #0x00
	str r0, [r7, #0x10]
	ldr r0, _080456B4 @ =0x09617C58
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x1C]
	movs r2, #0x98
	lsls r2, r2, #0x01
	adds r4, r6, r2
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_08005968
	ldr r0, _080456B8 @ =0x0813EB8C
	ldr r1, [r6, #0x18]
	str r1, [sp, #0x000]
	adds r1, r4, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	mov r0, r8
	ldrh r1, [r0, #0x00]
	cmp r1, #0x01
	beq _080456CA
	cmp r1, #0x01
	bgt _080456BC
	cmp r1, #0x00
	beq _080456C2
	b _080456E6
_080456B0: .4byte 0xFFFFB000
_080456B4: .4byte 0x09617C58
_080456B8: .4byte 0x0813EB8C
_080456BC:
	cmp r1, #0x02
	beq _080456D4
	b _080456E6
_080456C2:
	movs r2, #0xB0
	lsls r2, r2, #0x01
	adds r1, r6, r2
	b _080456DA
_080456CA:
	movs r2, #0xB0
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strh r1, [r0, #0x00]
	b _080456DE
_080456D4:
	movs r0, #0xB0
	lsls r0, r0, #0x01
	adds r1, r6, r0
_080456DA:
	movs r0, #0x01
	strh r0, [r1, #0x00]
_080456DE:
	movs r0, #0xB4
	bl func_0811FE70
	b _08045706
_080456E6:
	movs r0, #0xB3
	bl func_0811FE70
	movs r3, #0xC0
	lsls r3, r3, #0x01
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl func_08017260
	adds r0, r7, #0x0
	movs r1, #0x00
	movs r2, #0x08
	movs r3, #0x08
	bl func_08045494
_08045706:
	adds r0, r6, #0x0
	movs r1, #0x01
	bl func_08000E64
	ldr r1, _08045724 @ =0x09EDAE88
	adds r0, r6, #0x0
	adds r2, r7, #0x0
	bl func_08000E14
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08045724: .4byte 0x09EDAE88
.syntax divided
