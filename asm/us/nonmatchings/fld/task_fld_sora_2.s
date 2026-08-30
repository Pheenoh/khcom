.syntax unified
	.align 2, 0
	.global task_fld_sora_2
	.thumb
	.thumb_func
	.type task_fld_sora_2, %function
task_fld_sora_2: @ 080341E8
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r0, _08034244 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r4, r0, #0x0
	adds r4, #0x18
	adds r0, r5, #0x0
	adds r0, #0xA4
	ldrh r2, [r0, #0x00]
	movs r0, #0x02
	ands r0, r2
	movs r7, #0x80
	lsls r7, r7, #0x04
	cmp r0, #0x00
	beq _0803420A
	adds r7, #0x01
_0803420A:
	adds r0, r5, #0x0
	adds r0, #0xBC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08034252
	adds r0, r5, #0x0
	adds r0, #0x80
	ldr r1, [r0, #0x00]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r2, _08034248 @ =0xFFFFEFFA
	adds r0, r2, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r5, #0x0
	adds r0, #0x84
	ldr r1, [r0, #0x00]
	ldr r0, [r5, #0x48]
	cmp r1, r0
	bgt _0803424C
	movs r0, #0x00
	strh r0, [r4, #0x3A]
	adds r0, r4, #0x0
	bl func_080DFF1C
	str r0, [r4, #0x3C]
	b _0803428C
	.byte 0x00, 0x00
_08034244: .4byte 0x02039BA0
_08034248: .4byte 0xFFFFEFFA
_0803424C:
	ldr r0, [r5, #0x78]
	str r0, [r4, #0x3C]
	b _08034288
_08034252:
	ldr r0, [r4, #0x04]
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	ldr r3, _08034270 @ =0xFFFFEFFC
	adds r1, r3, #0x0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0x00
	beq _08034274
	ldr r0, [r4, #0x0C]
	b _0803427A
	.byte 0x00, 0x00
_08034270: .4byte 0xFFFFEFFC
_08034274:
	adds r0, r4, #0x0
	bl func_080DFF1C
_0803427A:
	str r0, [r4, #0x3C]
	ldr r1, [r4, #0x3C]
	ldr r0, [r4, #0x0C]
	cmp r1, r0
	beq _08034288
	movs r0, #0x00
	b _0803428A
_08034288:
	adds r0, r6, #0x1
_0803428A:
	strh r0, [r4, #0x3A]
_0803428C:
	ldr r0, [r4, #0x00]
	asrs r0, r0, #0x08
	ldr r1, _080342D8 @ =0x02039BA0
	ldr r3, [r1, #0x00]
	ldr r1, [r3, #0x00]
	asrs r1, r1, #0x08
	subs r0, r0, r1
	ldr r1, [r4, #0x04]
	asrs r1, r1, #0x08
	ldr r2, [r4, #0x08]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	ldr r2, [r3, #0x04]
	asrs r2, r2, #0x08
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x20]
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r7, [sp, #0x008]
	str r6, [sp, #0x00C]
	bl func_080023E0
	adds r0, r5, #0x0
	adds r0, #0x24
	bl func_08000EE0
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080342D8: .4byte 0x02039BA0
.syntax divided
