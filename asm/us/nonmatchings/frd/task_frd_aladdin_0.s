.syntax unified
	.align 2, 0
	.global task_frd_aladdin_0
	.thumb
	.thumb_func
	.type task_frd_aladdin_0, %function
task_frd_aladdin_0: @ 08049168
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x004
	adds r6, r0, #0x0
	mov r8, r1
	adds r7, r6, #0x0
	adds r7, #0x20
	movs r0, #0xBC
	bl func_0811FE70
	mov r0, r8
	ldrb r1, [r0, #0x02]
	cmp r1, #0x00
	beq _080491C0
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r5, _080491B4 @ =0x02039B84
	ldr r4, [r5, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _080491B8 @ =0x00200000
	ldr r3, _080491BC @ =0x00000000
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
	b _080491EE
	.byte 0x00, 0x00
_080491B4: .4byte 0x02039B84
_080491B8: .4byte 0x00200000
_080491BC: .4byte 0x00000000
_080491C0:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strb r1, [r0, #0x00]
	ldr r0, _08049248 @ =0x02039B9C
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _0804924C @ =0x00200000
	ldr r3, _08049250 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r0, [r4, #0x7C]
	str r0, [r6, #0x14]
	ldr r1, _08049254 @ =0x02039B84
	ldr r0, [r1, #0x00]
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x18]
	adds r5, r1, #0x0
_080491EE:
	mov r1, r8
	ldrh r0, [r1, #0x00]
	ldr r1, _08049258 @ =0x0000014D
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
	beq _08049260
	movs r0, #0xAC
	lsls r0, r0, #0x01
	adds r1, r6, r0
	ldr r0, [r3, #0x04]
	ldr r2, _0804925C @ =0xFFFFD000
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
	b _08049282
_08049248: .4byte 0x02039B9C
_0804924C: .4byte 0x00200000
_08049250: .4byte 0x00000000
_08049254: .4byte 0x02039B84
_08049258: .4byte 0x0000014D
_0804925C: .4byte 0xFFFFD000
_08049260:
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
_08049282:
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldr r0, [r6, #0x14]
	ldr r0, [r0, #0x08]
	str r0, [r7, #0x08]
	ldr r0, _080492EC @ =0xFFFFB000
	str r0, [r7, #0x0C]
	movs r0, #0x00
	str r0, [r7, #0x10]
	ldr r0, _080492F0 @ =0x09617D98
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
	ldr r0, _080492F4 @ =0x0813ED4C
	ldr r1, [r6, #0x18]
	str r1, [sp, #0x000]
	adds r1, r4, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	adds r0, r6, #0x0
	movs r1, #0x01
	bl func_08000E64
	ldr r1, _080492F8 @ =0x09EDAE88
	adds r0, r6, #0x0
	adds r2, r7, #0x0
	bl func_08000E14
	ldr r1, _080492FC @ =0x0000014D
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _08049300
	cmp r0, #0x01
	bgt _0804930A
	cmp r0, #0x00
	bne _0804930A
	movs r2, #0xA9
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x78
	b _08049314
_080492EC: .4byte 0xFFFFB000
_080492F0: .4byte 0x09617D98
_080492F4: .4byte 0x0813ED4C
_080492F8: .4byte 0x09EDAE88
_080492FC: .4byte 0x0000014D
_08049300:
	movs r0, #0xA9
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0xF0
	b _08049314
_0804930A:
	movs r2, #0xA9
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0xF0
	lsls r0, r0, #0x01
_08049314:
	strh r0, [r1, #0x00]
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
