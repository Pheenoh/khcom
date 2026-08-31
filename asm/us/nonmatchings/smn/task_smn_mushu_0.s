.syntax unified
	.align 2, 0
	.global task_smn_mushu_0
	.thumb
	.thumb_func
	.type task_smn_mushu_0, %function
task_smn_mushu_0: @ 08043710
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	adds r5, r6, #0x0
	adds r5, #0x38
	ldrb r1, [r7, #0x02]
	cmp r1, #0x00
	beq _08043758
	ldr r0, _08043748 @ =0x00000153
	adds r1, r6, r0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _0804374C @ =0x02039B84
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08043750 @ =0x00200000
	ldr r3, _08043754 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r1, [r4, #0x7C]
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r4, r4, r2
	ldr r0, [r4, #0x00]
	b _0804377E
_08043748: .4byte 0x00000153
_0804374C: .4byte 0x02039B84
_08043750: .4byte 0x00200000
_08043754: .4byte 0x00000000
_08043758:
	ldr r2, _080437AC @ =0x00000153
	adds r0, r6, r2
	strb r1, [r0, #0x00]
	ldr r0, _080437B0 @ =0x02039B9C
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _080437B4 @ =0x00200000
	ldr r3, _080437B8 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r1, [r4, #0x7C]
	ldr r0, _080437BC @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
_0804377E:
	str r0, [r6, #0x00]
	ldr r0, [r1, #0x04]
	str r0, [r5, #0x04]
	ldr r0, [r1, #0x08]
	str r0, [r5, #0x08]
	ldr r0, [r1, #0x0C]
	ldr r2, _080437C0 @ =0xFFFFDE00
	adds r0, r0, r2
	str r0, [r5, #0x0C]
	ldr r0, [r1, #0x10]
	str r0, [r5, #0x10]
	ldr r0, [r1, #0x34]
	ldr r1, [r1, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080437C4
	movs r0, #0x04
	movs r1, #0x00
	b _080437C8
	.byte 0x00, 0x00
_080437AC: .4byte 0x00000153
_080437B0: .4byte 0x02039B9C
_080437B4: .4byte 0x00200000
_080437B8: .4byte 0x00000000
_080437BC: .4byte 0x02039B84
_080437C0: .4byte 0xFFFFDE00
_080437C4:
	movs r0, #0x00
	movs r1, #0x00
_080437C8:
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
	ldrh r0, [r7, #0x00]
	movs r1, #0xA9
	lsls r1, r1, #0x01
	adds r2, r6, r1
	movs r5, #0x00
	strb r0, [r2, #0x00]
	ldr r0, _08043840 @ =0x09618038
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x04]
	adds r4, r6, #0x0
	adds r4, #0x08
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimInit
	ldr r0, _08043844 @ =0x0813EA7C
	ldr r1, [r6, #0x00]
	str r1, [sp, #0x000]
	adds r1, r4, #0x0
	movs r2, #0x00
	movs r3, #0x01
	bl func_08019068
	str r5, [r6, #0x34]
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r0, r6, r2
	movs r2, #0x00
	strh r5, [r0, #0x00]
	movs r1, #0xA5
	lsls r1, r1, #0x01
	adds r0, r6, r1
	strh r5, [r0, #0x00]
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x0A
	str r0, [r1, #0x00]
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	strb r2, [r0, #0x00]
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strh r5, [r0, #0x00]
	subs r1, #0x01
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0804384C
	adds r2, #0x08
	adds r1, r6, r2
	ldr r0, _08043848 @ =0x02039B84
	b _08043854
_08043840: .4byte 0x09618038
_08043844: .4byte 0x0813EA7C
_08043848: .4byte 0x02039B84
_0804384C:
	movs r0, #0xAC
	lsls r0, r0, #0x01
	adds r1, r6, r0
	ldr r0, _08043874 @ =0x02039B9C
_08043854:
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x7C]
	str r0, [r1, #0x00]
	movs r0, #0xAB
	bl m4aSongNumStart
	adds r0, r6, #0x0
	adds r0, #0x20
	movs r1, #0x03
	bl TaskPoolInit
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08043874: .4byte 0x02039B9C
.syntax divided
