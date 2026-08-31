.syntax unified
	.align 2, 0
	.global func_080D51D8
	.thumb
	.thumb_func
	.type func_080D51D8, %function
func_080D51D8: @ 080D51D8
	push {r4, r5, r6, r7, lr}
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D51F0
	ldr r0, _080D521C @ =0x0203C4E0
	ldr r0, [r0, #0x00]
	cmp r0, #0x03
	bne _080D51F0
	bl func_080D55E4
_080D51F0:
	ldr r0, _080D521C @ =0x0203C4E0
	ldr r1, [r0, #0x00]
	cmp r1, #0x02
	bne _080D5274
	ldr r0, _080D5220 @ =0x0203C534
	ldrh r2, [r0, #0x00]
	cmp r2, #0x06
	bls _080D522C
	ldr r0, _080D5224 @ =0x0203C4B4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xA4
	adds r1, #0xA8
	ldr r1, [r1, #0x00]
	ldr r3, _080D5228 @ =0xFFFFFE00
	adds r1, r1, r3
	subs r2, #0x07
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl func_080058FC
	b _080D5262
_080D521C: .4byte 0x0203C4E0
_080D5220: .4byte 0x0203C534
_080D5224: .4byte 0x0203C4B4
_080D5228: .4byte 0xFFFFFE00
_080D522C:
	movs r0, #0x01
	ands r0, r2
	cmp r0, #0x00
	beq _080D524C
	ldr r0, _080D5248 @ =0x0203C4B4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xA4
	adds r1, #0xA8
	ldr r1, [r1, #0x00]
	movs r2, #0x01
	bl func_080058FC
	b _080D5262
_080D5248: .4byte 0x0203C4B4
_080D524C:
	ldr r0, _080D5284 @ =0x0203C4B4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xA4
	adds r1, #0xA8
	ldr r1, [r1, #0x00]
	ldr r5, _080D5288 @ =0xFFFFFE00
	adds r1, r1, r5
	movs r2, #0x01
	bl func_080058FC
_080D5262:
	ldr r0, _080D5284 @ =0x0203C4B4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xA4
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x08
	adds r1, #0xA2
	strh r0, [r1, #0x00]
	ldr r0, _080D528C @ =0x0203C4E0
_080D5274:
	ldr r0, [r0, #0x00]
	cmp r0, #0x03
	bne _080D5290
	ldr r0, _080D5284 @ =0x0203C4B4
	ldr r0, [r0, #0x00]
	bl func_080D510C
	b _080D52DE
_080D5284: .4byte 0x0203C4B4
_080D5288: .4byte 0xFFFFFE00
_080D528C: .4byte 0x0203C4E0
_080D5290:
	ldr r1, _080D5394 @ =0x0203C540
	ldr r0, _080D5398 @ =0x0203C4B4
	ldr r2, [r0, #0x00]
	adds r3, r2, #0x0
	adds r3, #0xAC
	adds r4, r2, #0x0
	adds r4, #0xA0
	ldrh r0, [r4, #0x00]
	ldrh r6, [r3, #0x00]
	adds r0, r0, r6
	strh r0, [r1, #0x00]
	ldr r1, _080D539C @ =0x0203C53C
	movs r0, #0xAE
	adds r0, r0, r2
	mov r12, r0
	adds r5, r2, #0x0
	adds r5, #0xA2
	ldrh r0, [r5, #0x00]
	mov r2, r12
	ldrh r2, [r2, #0x00]
	adds r0, r0, r2
	strh r0, [r1, #0x00]
	ldr r2, _080D53A0 @ =0x02034E8C
	movs r6, #0x00
	ldsh r0, [r3, r6]
	movs r3, #0x00
	ldsh r1, [r4, r3]
	adds r0, r0, r1
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
	ldr r2, _080D53A4 @ =0x02034E90
	mov r6, r12
	movs r1, #0x00
	ldsh r0, [r6, r1]
	movs r3, #0x00
	ldsh r1, [r5, r3]
	adds r0, r0, r1
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
_080D52DE:
	ldr r0, _080D5394 @ =0x0203C540
	ldr r7, _080D5398 @ =0x0203C4B4
	ldr r2, [r7, #0x00]
	adds r3, r2, #0x0
	adds r3, #0xAC
	ldrh r0, [r0, #0x00]
	ldrh r1, [r3, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _080D539C @ =0x0203C53C
	adds r2, #0xAE
	ldrh r0, [r0, #0x00]
	ldrh r1, [r2, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r5, #0x00
	ldsh r1, [r3, r5]
	adds r0, r1, #0x0
	cmp r1, #0x00
	bge _080D530C
	adds r0, r1, #0x7
_080D530C:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r1, r0
	lsls r1, r4, #0x10
	asrs r5, r1, #0x10
	subs r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r0, #0x00
	ldsh r1, [r2, r0]
	adds r2, r1, #0x0
	cmp r1, #0x00
	bge _080D5328
	adds r2, r1, #0x7
_080D5328:
	asrs r2, r2, #0x03
	lsls r2, r2, #0x03
	subs r2, r1, r2
	lsls r0, r6, #0x10
	asrs r4, r0, #0x10
	subs r2, r4, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x00
	adds r1, r3, #0x0
	bl func_08005244
	ldr r2, [r7, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xAC
	movs r3, #0x00
	ldsh r1, [r0, r3]
	adds r0, r1, #0x0
	cmp r1, #0x00
	bge _080D5352
	adds r0, r1, #0x7
_080D5352:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r1, r0
	subs r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r2, #0x0
	adds r0, #0xAE
	movs r5, #0x00
	ldsh r0, [r0, r5]
	adds r2, r0, #0x0
	cmp r0, #0x00
	bge _080D536E
	adds r2, r0, #0x7
_080D536E:
	asrs r2, r2, #0x03
	lsls r2, r2, #0x03
	subs r2, r0, r2
	subs r2, r4, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x01
	bl func_08005244
	ldr r0, [r7, #0x00]
	bl TaskPoolUpdate
	ldr r0, [r7, #0x00]
	bl TaskPoolDraw
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D5394: .4byte 0x0203C540
_080D5398: .4byte 0x0203C4B4
_080D539C: .4byte 0x0203C53C
_080D53A0: .4byte 0x02034E8C
_080D53A4: .4byte 0x02034E90
.syntax divided
