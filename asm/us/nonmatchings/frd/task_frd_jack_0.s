.syntax unified
	.align 2, 0
	.global task_frd_jack_0
	.thumb
	.thumb_func
	.type task_frd_jack_0, %function
task_frd_jack_0: @ 080474F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x004
	adds r6, r0, #0x0
	mov r8, r1
	adds r7, r6, #0x0
	adds r7, #0x20
	movs r0, #0xB8
	bl func_0811FE70
	mov r0, r8
	ldrb r1, [r0, #0x02]
	cmp r1, #0x00
	beq _08047548
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r5, _0804753C @ =0x02039B84
	ldr r4, [r5, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08047540 @ =0x00200000
	ldr r3, _08047544 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r0, [r4, #0x7C]
	str r0, [r6, #0x14]
	movs r0, #0x8A
	lsls r0, r0, #0x01
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	str r0, [r6, #0x18]
	b _08047576
	.byte 0x00, 0x00
_0804753C: .4byte 0x02039B84
_08047540: .4byte 0x00200000
_08047544: .4byte 0x00000000
_08047548:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strb r1, [r0, #0x00]
	ldr r0, _080475D0 @ =0x02039B9C
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _080475D4 @ =0x00200000
	ldr r3, _080475D8 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r0, [r4, #0x7C]
	str r0, [r6, #0x14]
	ldr r1, _080475DC @ =0x02039B84
	ldr r0, [r1, #0x00]
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x18]
	adds r5, r1, #0x0
_08047576:
	mov r1, r8
	ldrh r0, [r1, #0x00]
	ldr r1, _080475E0 @ =0x0000014D
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
	beq _080475E8
	movs r0, #0xAC
	lsls r0, r0, #0x01
	adds r1, r6, r0
	ldr r0, [r3, #0x04]
	ldr r2, _080475E4 @ =0xFFFFD000
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
	b _0804760A
_080475D0: .4byte 0x02039B9C
_080475D4: .4byte 0x00200000
_080475D8: .4byte 0x00000000
_080475DC: .4byte 0x02039B84
_080475E0: .4byte 0x0000014D
_080475E4: .4byte 0xFFFFD000
_080475E8:
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
_0804760A:
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldr r0, [r6, #0x14]
	ldr r0, [r0, #0x08]
	str r0, [r7, #0x08]
	ldr r0, _08047668 @ =0xFFFFB000
	str r0, [r7, #0x0C]
	movs r1, #0x00
	str r1, [r7, #0x10]
	movs r2, #0xB0
	lsls r2, r2, #0x01
	adds r0, r6, r2
	str r1, [r0, #0x00]
	ldr r0, _0804766C @ =0x09617DB8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x1C]
	movs r0, #0x98
	lsls r0, r0, #0x01
	adds r4, r6, r0
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_08005968
	ldr r0, _08047670 @ =0x0813EC9C
	ldr r1, [r6, #0x18]
	str r1, [sp, #0x000]
	adds r1, r4, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	mov r2, r8
	ldrh r1, [r2, #0x00]
	cmp r1, #0x01
	beq _0804765E
	cmp r1, #0x01
	bgt _08047674
	cmp r1, #0x00
	bne _08047674
_0804765E:
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strh r1, [r0, #0x00]
	b _0804767E
_08047668: .4byte 0xFFFFB000
_0804766C: .4byte 0x09617DB8
_08047670: .4byte 0x0813EC9C
_08047674:
	movs r0, #0xB4
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x02
	strh r0, [r1, #0x00]
_0804767E:
	adds r0, r6, #0x0
	movs r1, #0x01
	bl func_08000E64
	ldr r1, _0804769C @ =0x09EDAE88
	adds r0, r6, #0x0
	adds r2, r7, #0x0
	bl func_08000E14
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0804769C: .4byte 0x09EDAE88
.syntax divided
