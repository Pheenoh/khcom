.syntax unified
	.align 2, 0
	.global func_080175BC
	.thumb
	.thumb_func
	.type func_080175BC, %function
func_080175BC: @ 080175BC
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r4, r0, #0x0
	adds r6, r1, #0x0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r9, r2
	lsls r3, r3, #0x18
	cmp r3, #0x00
	beq _080175F2
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x08]
	ldr r2, [r6, #0x04]
	ldr r3, [r6, #0x08]
	bl GetAngle
	adds r1, r6, #0x0
	adds r1, #0xB0
	movs r2, #0x00
	strb r0, [r1, #0x00]
	adds r0, r6, #0x0
	adds r0, #0xA8
	str r2, [r0, #0x00]
_080175F2:
	ldr r0, _0801760C @ =0x02034928
	ldr r1, [r0, #0x00]
	ldr r2, [r6, #0x04]
	ldr r1, [r1, #0x10]
	subs r3, r2, r1
	mov r12, r2
	adds r5, r0, #0x0
	cmp r3, #0x00
	blt _08017614
	ldr r0, _08017610 @ =0x00004FFF
	cmp r3, r0
	ble _08017620
	b _08017716
_0801760C: .4byte 0x02034928
_08017610: .4byte 0x00004FFF
_08017614:
	mov r0, r12
	subs r1, r1, r0
	ldr r0, _08017638 @ =0x00004FFF
	cmp r1, r0
	ble _08017620
	b _08017716
_08017620:
	ldr r0, [r5, #0x00]
	ldr r1, [r6, #0x08]
	ldr r0, [r0, #0x14]
	subs r2, r1, r0
	mov r10, r1
	cmp r2, #0x00
	blt _08017640
	ldr r0, _0801763C @ =0x000027FF
	cmp r2, r0
	ble _0801764A
	b _08017716
	.byte 0x00, 0x00
_08017638: .4byte 0x00004FFF
_0801763C: .4byte 0x000027FF
_08017640:
	mov r2, r10
	subs r1, r0, r2
	ldr r0, _08017668 @ =0x000027FF
	cmp r1, r0
	bgt _08017716
_0801764A:
	ldr r2, [r5, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0801766C
	adds r0, r6, #0x0
	adds r0, #0xA8
	ldr r1, [r2, #0x10]
	mov r3, r12
	subs r1, r1, r3
	asrs r1, r1, #0x01
	ldr r2, [r0, #0x00]
	subs r7, r2, r1
	b _0801767C
_08017668: .4byte 0x000027FF
_0801766C:
	adds r0, r6, #0x0
	adds r0, #0xA8
	ldr r1, [r2, #0x10]
	mov r2, r12
	subs r1, r1, r2
	asrs r1, r1, #0x01
	ldr r2, [r0, #0x00]
	adds r7, r2, r1
_0801767C:
	mov r8, r0
	cmp r7, #0x00
	ble _08017684
	movs r7, #0x00
_08017684:
	asrs r2, r7, #0x09
	negs r2, r2
	str r2, [sp, #0x000]
	ldr r5, [r5, #0x00]
	ldr r4, _080176DC @ =0x08121400
	adds r0, r6, #0x0
	adds r0, #0xB0
	ldrb r1, [r0, #0x00]
	add r1, r9
	movs r0, #0xFF
	ands r1, r0
	lsls r0, r1, #0x01
	adds r0, r0, r4
	movs r2, #0x00
	ldsh r3, [r0, r2]
	mov r9, r3
	ldr r3, [sp, #0x000]
	lsls r2, r3, #0x10
	asrs r0, r2, #0x10
	mov r3, r9
	muls r3, r0
	ldr r0, [r5, #0x10]
	adds r0, r0, r3
	mov r9, r0
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r4
	movs r3, #0x00
	ldsh r0, [r1, r3]
	negs r0, r0
	asrs r2, r2, #0x11
	adds r1, r0, #0x0
	muls r1, r2
	ldr r0, [r5, #0x14]
	adds r5, r0, r1
	cmp r12, r9
	bge _080176E0
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x05
	negs r2, r2
	ands r0, r2
	b _080176EA
	.byte 0x00, 0x00
_080176DC: .4byte 0x08121400
_080176E0:
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	movs r3, #0x00
	orrs r0, r2
_080176EA:
	str r0, [r6, #0x34]
	str r1, [r6, #0x38]
	mov r1, r9
	mov r2, r12
	subs r0, r1, r2
	asrs r0, r0, #0x03
	add r0, r12
	str r0, [r6, #0x04]
	mov r3, r10
	subs r0, r5, r3
	asrs r0, r0, #0x03
	add r0, r10
	str r0, [r6, #0x08]
	ldr r1, [r6, #0x0C]
	subs r0, r7, r1
	asrs r0, r0, #0x02
	adds r1, r1, r0
	str r1, [r6, #0x0C]
	mov r1, r8
	ldr r0, [r1, #0x00]
	subs r0, #0x6E
	str r0, [r1, #0x00]
_08017716:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
