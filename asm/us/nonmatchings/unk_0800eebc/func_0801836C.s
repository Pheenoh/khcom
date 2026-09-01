.syntax unified
	.align 2, 0
	.global func_0801836C
	.thumb
	.thumb_func
	.type func_0801836C, %function
func_0801836C: @ 0801836C
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x008
	adds r6, r0, #0x0
	mov r9, r1
	mov r8, r2
	adds r5, r3, #0x0
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08018466
	bl func_08012674
	ldr r0, _080183B4 @ =0x02034928
	ldr r2, [r0, #0x00]
	ldr r0, [sp, #0x024]
	str r0, [r2, #0x48]
	cmp r5, #0x00
	ble _080183C0
	ldr r0, _080183B8 @ =0xFFFFFE80
	str r0, [r2, #0x1C]
	ldrh r1, [r2, #0x34]
	movs r0, #0x01
	orrs r0, r1
	strh r0, [r2, #0x34]
	ldr r0, _080183BC @ =0xFFFFC000
	adds r6, r6, r0
	movs r2, #0x80
	lsls r2, r2, #0x07
	adds r5, r5, r2
	b _080183D0
	.byte 0x00, 0x00
_080183B4: .4byte 0x02034928
_080183B8: .4byte 0xFFFFFE80
_080183BC: .4byte 0xFFFFC000
_080183C0:
	movs r0, #0xC0
	lsls r0, r0, #0x01
	str r0, [r2, #0x1C]
	movs r3, #0x80
	lsls r3, r3, #0x07
	adds r6, r6, r3
	ldr r0, _08018474 @ =0xFFFFC000
	adds r5, r5, r0
_080183D0:
	ldr r7, _08018478 @ =0x02034928
	ldr r4, [r7, #0x00]
	str r6, [r4, #0x28]
	mov r2, r8
	str r2, [r4, #0x30]
	adds r3, r5, #0x0
	cmp r3, #0x00
	bge _080183E2
	negs r3, r3
_080183E2:
	str r3, [r4, #0x3C]
	ldr r1, _0801847C @ =0x08121400
	movs r2, #0x00
	ldsh r0, [r1, r2]
	muls r0, r3
	asrs r0, r0, #0x08
	adds r0, r6, r0
	str r0, [r4, #0x10]
	adds r1, #0x80
	movs r2, #0x00
	ldsh r0, [r1, r2]
	negs r0, r0
	muls r0, r3
	asrs r0, r0, #0x08
	add r0, r8
	str r0, [r4, #0x18]
	mov r3, r9
	str r3, [r4, #0x14]
	movs r0, #0xC0
	lsls r0, r0, #0x01
	str r0, [r4, #0x20]
	movs r0, #0x10
	movs r1, #0x00
	bl SetBlendAlpha
	movs r0, #0xAB
	lsls r0, r0, #0x02
	bl m4aSongNumStart
	mov r4, sp
	adds r4, #0x06
	ldr r0, [r7, #0x00]
	ldr r2, [r0, #0x10]
	ldr r3, [r0, #0x14]
	ldr r0, [r0, #0x18]
	str r0, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	bl WorldToScreen
	ldr r0, _08018480 @ =0x09EDACD8
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	ldr r1, [r7, #0x00]
	movs r0, #0x00
	strh r0, [r1, #0x26]
	ldr r0, _08018484 @ =0x08018241
	str r0, [r1, #0x04]
	ldr r0, _08018488 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	ldr r2, [r7, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_08018466:
	add sp, #0x008
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08018474: .4byte 0xFFFFC000
_08018478: .4byte 0x02034928
_0801847C: .4byte 0x08121400
_08018480: .4byte 0x09EDACD8
_08018484: .4byte 0x08018241
_08018488: .4byte 0x02039B84
.syntax divided
