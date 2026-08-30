.syntax unified
	.align 2, 0
	.global task_frd_ariel_0
	.thumb
	.thumb_func
	.type task_frd_ariel_0, %function
task_frd_ariel_0: @ 08046E50
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x004
	adds r6, r0, #0x0
	mov r8, r1
	adds r7, r6, #0x0
	adds r7, #0x20
	movs r0, #0xBB
	bl func_0811FE70
	mov r0, r8
	ldrb r1, [r0, #0x02]
	cmp r1, #0x00
	beq _08046EA8
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r5, _08046E9C @ =0x02039B84
	ldr r4, [r5, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08046EA0 @ =0x00200000
	ldr r3, _08046EA4 @ =0x00000000
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
	b _08046ED6
	.byte 0x00, 0x00
_08046E9C: .4byte 0x02039B84
_08046EA0: .4byte 0x00200000
_08046EA4: .4byte 0x00000000
_08046EA8:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strb r1, [r0, #0x00]
	ldr r0, _08046F18 @ =0x02039B9C
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08046F1C @ =0x00200000
	ldr r3, _08046F20 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r0, [r4, #0x7C]
	str r0, [r6, #0x14]
	ldr r1, _08046F24 @ =0x02039B84
	ldr r0, [r1, #0x00]
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x18]
	adds r5, r1, #0x0
_08046ED6:
	mov r1, r8
	ldrh r0, [r1, #0x00]
	ldr r1, _08046F28 @ =0x0000014D
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
	ldr r0, [r6, #0x14]
	ldr r1, [r0, #0x38]
	ldr r0, [r0, #0x34]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08046F2C
	ldr r0, [r5, #0x00]
	adds r0, #0xDC
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r0, #0x30
	lsls r0, r0, #0x08
	str r0, [r7, #0x04]
	movs r0, #0x04
	movs r1, #0x00
	b _08046F3E
	.byte 0x00, 0x00
_08046F18: .4byte 0x02039B9C
_08046F1C: .4byte 0x00200000
_08046F20: .4byte 0x00000000
_08046F24: .4byte 0x02039B84
_08046F28: .4byte 0x0000014D
_08046F2C:
	ldr r0, [r5, #0x00]
	adds r0, #0xDA
	movs r2, #0x00
	ldsh r0, [r0, r2]
	subs r0, #0x30
	lsls r0, r0, #0x08
	str r0, [r7, #0x04]
	movs r0, #0x00
	movs r1, #0x00
_08046F3E:
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldr r0, [r6, #0x14]
	ldr r0, [r0, #0x08]
	str r0, [r7, #0x08]
	movs r0, #0x00
	str r0, [r7, #0x10]
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r1, r6, r0
	ldr r0, _08046FB0 @ =0xFFFFF000
	str r0, [r1, #0x00]
	str r0, [r7, #0x0C]
	ldr r0, _08046FB4 @ =0x09617DF8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x1C]
	movs r1, #0x98
	lsls r1, r1, #0x01
	adds r4, r6, r1
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_08005968
	ldr r0, _08046FB8 @ =0x0813EC5C
	ldr r1, [r6, #0x18]
	str r1, [sp, #0x000]
	adds r1, r4, #0x0
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
	adds r0, r6, #0x0
	movs r1, #0x01
	bl func_08000E64
	ldr r1, _08046FBC @ =0x09EDAE88
	adds r0, r6, #0x0
	adds r2, r7, #0x0
	bl func_08000E14
	mov r0, r8
	ldrh r2, [r0, #0x00]
	cmp r2, #0x01
	beq _08046FC0
	cmp r2, #0x01
	bgt _08046FD6
	cmp r2, #0x00
	bne _08046FD6
	movs r1, #0xAE
	lsls r1, r1, #0x01
	adds r0, r6, r1
	movs r1, #0xA0
	lsls r1, r1, #0x03
	b _08046FCA
_08046FB0: .4byte 0xFFFFF000
_08046FB4: .4byte 0x09617DF8
_08046FB8: .4byte 0x0813EC5C
_08046FBC: .4byte 0x09EDAE88
_08046FC0:
	movs r1, #0xAE
	lsls r1, r1, #0x01
	adds r0, r6, r1
	movs r1, #0x80
	lsls r1, r1, #0x04
_08046FCA:
	str r1, [r0, #0x00]
	movs r1, #0xAC
	lsls r1, r1, #0x01
	adds r0, r6, r1
	strh r2, [r0, #0x00]
	b _08046FEC
_08046FD6:
	movs r2, #0xAE
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0xC0
	lsls r0, r0, #0x04
	str r0, [r1, #0x00]
	movs r0, #0xAC
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x04
	strh r0, [r1, #0x00]
_08046FEC:
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
