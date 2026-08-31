.syntax unified
	.align 2, 0
	.global task_frd_pan_0
	.thumb
	.thumb_func
	.type task_frd_pan_0, %function
task_frd_pan_0: @ 08048794
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x004
	adds r6, r0, #0x0
	mov r8, r1
	adds r7, r6, #0x0
	adds r7, #0x20
	movs r0, #0xB9
	bl m4aSongNumStart
	mov r0, r8
	ldrb r1, [r0, #0x02]
	cmp r1, #0x00
	beq _080487EC
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r5, _080487E0 @ =0x02039B84
	ldr r4, [r5, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _080487E4 @ =0x00200000
	ldr r3, _080487E8 @ =0x00000000
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
	b _0804881A
	.byte 0x00, 0x00
_080487E0: .4byte 0x02039B84
_080487E4: .4byte 0x00200000
_080487E8: .4byte 0x00000000
_080487EC:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strb r1, [r0, #0x00]
	ldr r0, _0804887C @ =0x02039B9C
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08048880 @ =0x00200000
	ldr r3, _08048884 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r0, [r4, #0x7C]
	str r0, [r6, #0x14]
	ldr r1, _08048888 @ =0x02039B84
	ldr r0, [r1, #0x00]
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x18]
	adds r5, r1, #0x0
_0804881A:
	mov r1, r8
	ldrh r0, [r1, #0x00]
	ldr r1, _0804888C @ =0x0000014D
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
	adds r2, #0x08
	adds r0, r6, r2
	str r1, [r0, #0x00]
	ldr r0, [r6, #0x14]
	ldr r1, [r0, #0x38]
	ldr r0, [r0, #0x34]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0804889C
	ldr r0, [r5, #0x00]
	adds r0, #0xDC
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r0, #0x30
	lsls r0, r0, #0x08
	str r0, [r7, #0x04]
	ldr r0, _08048890 @ =0x00020004
	ldr r1, _08048894 @ =0x00000000
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldr r0, _08048898 @ =0xFFFFF800
	str r0, [r1, #0x00]
	movs r0, #0xB6
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x00
	b _080488C6
_0804887C: .4byte 0x02039B9C
_08048880: .4byte 0x00200000
_08048884: .4byte 0x00000000
_08048888: .4byte 0x02039B84
_0804888C: .4byte 0x0000014D
_08048890: .4byte 0x00020004
_08048894: .4byte 0x00000000
_08048898: .4byte 0xFFFFF800
_0804889C:
	ldr r0, [r5, #0x00]
	adds r0, #0xDA
	movs r1, #0x00
	ldsh r0, [r0, r1]
	subs r0, #0x30
	lsls r0, r0, #0x08
	str r0, [r7, #0x04]
	ldr r1, _08048948 @ =0x00000000
	ldr r0, _08048944 @ =0x00020000
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [r1, #0x00]
	movs r0, #0xB6
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x01
_080488C6:
	strb r0, [r1, #0x00]
	movs r2, #0xAE
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x80
	lsls r0, r0, #0x09
	str r0, [r1, #0x00]
	ldr r0, [r6, #0x14]
	ldr r0, [r0, #0x08]
	str r0, [r7, #0x08]
	movs r0, #0x00
	str r0, [r7, #0x10]
	movs r0, #0xB2
	lsls r0, r0, #0x01
	adds r1, r6, r0
	ldr r0, _0804894C @ =0xFFFFE000
	str r0, [r1, #0x00]
	str r0, [r7, #0x0C]
	ldr r0, _08048950 @ =0x09617DD8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x1C]
	movs r1, #0x98
	lsls r1, r1, #0x01
	adds r4, r6, r1
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimInit
	ldr r0, _08048954 @ =0x0813ECFC
	ldr r1, [r6, #0x18]
	str r1, [sp, #0x000]
	adds r1, r4, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	adds r0, r6, #0x0
	movs r1, #0x0F
	bl TaskPoolInit
	ldr r1, _08048958 @ =0x09EDAE88
	adds r0, r6, #0x0
	adds r2, r7, #0x0
	bl TaskCreate
	ldr r2, _0804895C @ =0x0000014D
	adds r0, r6, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _08048960
	cmp r0, #0x01
	bgt _0804896A
	cmp r0, #0x00
	bne _0804896A
	movs r0, #0xA9
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x78
	b _08048972
	.byte 0x00, 0x00
_08048944: .4byte 0x00020000
_08048948: .4byte 0x00000000
_0804894C: .4byte 0xFFFFE000
_08048950: .4byte 0x09617DD8
_08048954: .4byte 0x0813ECFC
_08048958: .4byte 0x09EDAE88
_0804895C: .4byte 0x0000014D
_08048960:
	movs r2, #0xA9
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0xF0
	b _08048972
_0804896A:
	movs r0, #0xA9
	lsls r0, r0, #0x01
	adds r1, r6, r0
	adds r0, #0x8E
_08048972:
	strh r0, [r1, #0x00]
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
