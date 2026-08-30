.syntax unified
	.align 2, 0
	.global func_08044518
	.thumb
	.thumb_func
	.type func_08044518, %function
func_08044518: @ 08044518
	push {r4, r5, r6, lr}
	mov r12, r0
	movs r0, #0xAA
	lsls r0, r0, #0x01
	add r0, r12
	ldr r6, [r0, #0x00]
	mov r4, r12
	adds r4, #0x38
	cmp r6, #0x00
	beq _08044602
	ldr r0, [r4, #0x04]
	ldr r5, [r6, #0x04]
	cmp r5, r0
	bge _08044540
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	movs r3, #0x00
	orrs r0, r2
	b _0804454A
_08044540:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x05
	negs r2, r2
	ands r0, r2
_0804454A:
	str r0, [r4, #0x34]
	str r1, [r4, #0x38]
	movs r0, #0x80
	lsls r0, r0, #0x09
	cmp r5, r0
	ble _08044560
	ldr r0, _0804455C @ =0xFFFFC900
	adds r1, r5, r0
	b _08044566
_0804455C: .4byte 0xFFFFC900
_08044560:
	movs r2, #0xDC
	lsls r2, r2, #0x06
	adds r1, r5, r2
_08044566:
	ldr r5, [r6, #0x08]
	ldr r0, [r4, #0x10]
	ldr r2, _08044588 @ =0xFFFFFE00
	adds r6, r0, r2
	ldr r0, [r4, #0x04]
	subs r0, r1, r0
	asrs r1, r0, #0x03
	movs r3, #0xB0
	lsls r3, r3, #0x01
	add r3, r12
	ldr r0, [r3, #0x00]
	cmp r1, r0
	ble _0804458C
	adds r1, r0, #0x0
	adds r0, #0x4C
	b _080445A0
	.byte 0x00, 0x00
_08044588: .4byte 0xFFFFFE00
_0804458C:
	negs r2, r0
	cmp r1, r2
	bge _08044598
	adds r1, r2, #0x0
	adds r0, #0x4C
	b _080445A0
_08044598:
	adds r0, r1, #0x0
	cmp r1, #0x00
	bge _080445A0
	negs r0, r1
_080445A0:
	str r0, [r3, #0x00]
	ldr r0, [r4, #0x04]
	adds r0, r0, r1
	str r0, [r4, #0x04]
	ldr r0, [r4, #0x08]
	subs r0, r5, r0
	asrs r1, r0, #0x03
	movs r3, #0xB2
	lsls r3, r3, #0x01
	add r3, r12
	ldr r0, [r3, #0x00]
	cmp r1, r0
	ble _080445C0
	adds r1, r0, #0x0
	adds r0, #0x4C
	b _080445D4
_080445C0:
	negs r2, r0
	cmp r1, r2
	bge _080445CC
	adds r1, r2, #0x0
	adds r0, #0x4C
	b _080445D4
_080445CC:
	adds r0, r1, #0x0
	cmp r1, #0x00
	bge _080445D4
	negs r0, r1
_080445D4:
	str r0, [r3, #0x00]
	ldr r0, [r4, #0x08]
	adds r0, r0, r1
	str r0, [r4, #0x08]
	ldr r2, _08044608 @ =0x08121400
	movs r0, #0xA4
	lsls r0, r0, #0x01
	add r0, r12
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x01
	movs r1, #0xFF
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x03
	subs r0, r6, r0
	ldr r1, [r4, #0x0C]
	subs r0, r0, r1
	asrs r0, r0, #0x03
	adds r1, r1, r0
	str r1, [r4, #0x0C]
_08044602:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08044608: .4byte 0x08121400
.syntax divided
