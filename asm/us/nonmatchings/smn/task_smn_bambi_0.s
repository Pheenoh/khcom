.syntax unified
	.align 2, 0
	.global task_smn_bambi_0
	.thumb
	.thumb_func
	.type task_smn_bambi_0, %function
task_smn_bambi_0: @ 08041DF0
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x004
	adds r6, r0, #0x0
	mov r9, r1
	movs r0, #0x38
	adds r0, r0, r6
	mov r8, r0
	ldrb r1, [r1, #0x02]
	cmp r1, #0x00
	beq _08041E40
	ldr r2, _08041E30 @ =0x00000163
	adds r1, r6, r2
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _08041E34 @ =0x02039B84
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08041E38 @ =0x00200000
	ldr r3, _08041E3C @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r7, [r4, #0x7C]
	movs r3, #0x8A
	lsls r3, r3, #0x01
	adds r4, r4, r3
	ldr r0, [r4, #0x00]
	b _08041E66
_08041E30: .4byte 0x00000163
_08041E34: .4byte 0x02039B84
_08041E38: .4byte 0x00200000
_08041E3C: .4byte 0x00000000
_08041E40:
	ldr r2, _08041EE8 @ =0x00000163
	adds r0, r6, r2
	strb r1, [r0, #0x00]
	ldr r0, _08041EEC @ =0x02039B9C
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08041EF0 @ =0x00200000
	ldr r3, _08041EF4 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r7, [r4, #0x7C]
	ldr r0, _08041EF8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r3, #0x8A
	lsls r3, r3, #0x01
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
_08041E66:
	str r0, [r6, #0x00]
	bl func_080065A4
	ldr r5, _08041EF8 @ =0x02039B84
	ldr r1, [r5, #0x00]
	adds r2, r1, #0x0
	adds r2, #0xDA
	movs r3, #0x00
	ldsh r4, [r2, r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, #0xDC
	movs r2, #0x00
	ldsh r1, [r1, r2]
	subs r1, r1, r4
	adds r1, #0x01
	bl __modsi3
	adds r4, r4, r0
	lsls r4, r4, #0x08
	mov r3, r8
	str r4, [r3, #0x04]
	bl func_080065A4
	ldr r1, [r5, #0x00]
	adds r2, r1, #0x0
	adds r2, #0xDE
	movs r3, #0x00
	ldsh r4, [r2, r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, #0xE0
	movs r2, #0x00
	ldsh r1, [r1, r2]
	subs r1, r1, r4
	adds r1, #0x01
	bl __modsi3
	adds r4, r4, r0
	lsls r4, r4, #0x08
	mov r3, r8
	str r4, [r3, #0x08]
	ldr r0, [r7, #0x1C]
	str r0, [r3, #0x0C]
	ldr r0, [r7, #0x1C]
	str r0, [r3, #0x10]
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08041EFC
	movs r0, #0x00
	movs r1, #0x00
	mov r2, r8
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	movs r3, #0xAC
	lsls r3, r3, #0x01
	adds r1, r6, r3
	movs r0, #0xC0
	b _08041F0E
	.byte 0x00, 0x00
_08041EE8: .4byte 0x00000163
_08041EEC: .4byte 0x02039B9C
_08041EF0: .4byte 0x00200000
_08041EF4: .4byte 0x00000000
_08041EF8: .4byte 0x02039B84
_08041EFC:
	movs r0, #0x04
	movs r1, #0x00
	mov r2, r8
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	movs r3, #0xAC
	lsls r3, r3, #0x01
	adds r1, r6, r3
	movs r0, #0x40
_08041F0E:
	strb r0, [r1, #0x00]
	mov r1, r9
	ldrh r0, [r1, #0x00]
	movs r3, #0xB1
	lsls r3, r3, #0x01
	adds r2, r6, r3
	movs r4, #0x00
	strb r0, [r2, #0x00]
	ldr r0, _08041FC0 @ =0x09617FF8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x04]
	movs r1, #0xAE
	lsls r1, r1, #0x01
	adds r0, r6, r1
	str r4, [r0, #0x00]
	adds r5, r6, #0x0
	adds r5, #0x08
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_08005968
	ldr r0, _08041FC4 @ =0x0813E9E8
	ldr r1, [r6, #0x00]
	str r1, [sp, #0x000]
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	str r4, [r6, #0x34]
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r0, r6, r2
	movs r2, #0x00
	strh r4, [r0, #0x00]
	movs r3, #0xA5
	lsls r3, r3, #0x01
	adds r0, r6, r3
	strh r4, [r0, #0x00]
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r6, r1
	strh r4, [r0, #0x00]
	adds r3, #0x06
	adds r0, r6, r3
	str r4, [r0, #0x00]
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x0A
	str r0, [r1, #0x00]
	movs r1, #0xB2
	lsls r1, r1, #0x01
	adds r0, r6, r1
	strb r2, [r0, #0x00]
	movs r2, #0xB0
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strh r4, [r0, #0x00]
	adds r3, #0x18
	adds r0, r6, r3
	str r4, [r0, #0x00]
	adds r1, #0x08
	adds r0, r6, r1
	strh r4, [r0, #0x00]
	movs r0, #0xAB
	bl func_0811FE70
	adds r4, r6, #0x0
	adds r4, #0x20
	adds r0, r4, #0x0
	movs r1, #0x02
	bl func_08000E64
	ldr r1, _08041FC8 @ =0x09EDAE88
	adds r0, r4, #0x0
	mov r2, r8
	bl func_08000E14
	add sp, #0x004
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08041FC0: .4byte 0x09617FF8
_08041FC4: .4byte 0x0813E9E8
_08041FC8: .4byte 0x09EDAE88
.syntax divided
