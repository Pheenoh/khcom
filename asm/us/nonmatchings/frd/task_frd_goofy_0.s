.syntax unified
	.align 2, 0
	.global task_frd_goofy_0
	.thumb
	.thumb_func
	.type task_frd_goofy_0, %function
task_frd_goofy_0: @ 08046638
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x004
	adds r6, r0, #0x0
	mov r8, r1
	adds r7, r6, #0x0
	adds r7, #0x20
	movs r0, #0xAE
	bl m4aSongNumStart
	mov r0, r8
	ldrb r1, [r0, #0x02]
	cmp r1, #0x00
	beq _08046690
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r5, _08046684 @ =0x02039B84
	ldr r4, [r5, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08046688 @ =0x00200000
	ldr r3, _0804668C @ =0x00000000
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
	b _080466BE
	.byte 0x00, 0x00
_08046684: .4byte 0x02039B84
_08046688: .4byte 0x00200000
_0804668C: .4byte 0x00000000
_08046690:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strb r1, [r0, #0x00]
	ldr r0, _08046718 @ =0x02039B9C
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _0804671C @ =0x00200000
	ldr r3, _08046720 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r0, [r4, #0x7C]
	str r0, [r6, #0x14]
	ldr r1, _08046724 @ =0x02039B84
	ldr r0, [r1, #0x00]
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x18]
	adds r5, r1, #0x0
_080466BE:
	mov r1, r8
	ldrh r0, [r1, #0x00]
	ldr r1, _08046728 @ =0x0000014D
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
	beq _08046730
	movs r0, #0xAC
	lsls r0, r0, #0x01
	adds r1, r6, r0
	ldr r0, [r3, #0x04]
	ldr r2, _0804672C @ =0xFFFFD000
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
	b _08046752
_08046718: .4byte 0x02039B9C
_0804671C: .4byte 0x00200000
_08046720: .4byte 0x00000000
_08046724: .4byte 0x02039B84
_08046728: .4byte 0x0000014D
_0804672C: .4byte 0xFFFFD000
_08046730:
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
_08046752:
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldr r0, [r6, #0x14]
	ldr r0, [r0, #0x08]
	str r0, [r7, #0x08]
	ldr r0, _080467AC @ =0xFFFFB000
	str r0, [r7, #0x0C]
	movs r0, #0x00
	str r0, [r7, #0x10]
	ldr r0, _080467B0 @ =0x08F68384
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x1C]
	movs r2, #0x98
	lsls r2, r2, #0x01
	adds r4, r6, r2
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimInit
	ldr r0, _080467B4 @ =0x0813EBFC
	ldr r1, [r6, #0x18]
	str r1, [sp, #0x000]
	adds r1, r4, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	adds r0, r6, #0x0
	movs r1, #0x01
	bl TaskPoolInit
	ldr r1, _080467B8 @ =0x09EDAE88
	adds r0, r6, #0x0
	adds r2, r7, #0x0
	bl TaskCreate
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080467AC: .4byte 0xFFFFB000
_080467B0: .4byte 0x08F68384
_080467B4: .4byte 0x0813EBFC
_080467B8: .4byte 0x09EDAE88
.syntax divided
