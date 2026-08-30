.syntax unified
	.align 2, 0
	.global func_0800F3BC
	.thumb
	.thumb_func
	.type func_0800F3BC, %function
func_0800F3BC: @ 0800F3BC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	adds r7, r2, #0x0
	adds r4, r3, #0x0
	ldr r0, [r5, #0x44]
	ldr r1, [r5, #0x48]
	adds r2, r6, #0x0
	adds r3, r7, #0x0
	bl func_0801CB6C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _0800F424 @ =0x08121400
	lsls r1, r0, #0x01
	adds r1, r1, r3
	movs r2, #0x00
	ldsh r1, [r1, r2]
	muls r1, r4
	asrs r1, r1, #0x08
	ldr r2, [r5, #0x44]
	adds r2, r2, r1
	str r2, [r5, #0x44]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	adds r1, r0, #0x0
	muls r1, r4
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x48]
	adds r0, r0, r1
	str r0, [r5, #0x48]
	subs r1, r2, r6
	cmp r1, #0x00
	bge _0800F40A
	subs r1, r6, r2
_0800F40A:
	movs r0, #0xF0
	lsls r0, r0, #0x05
	cmp r1, r0
	bgt _0800F432
	ldr r0, [r5, #0x48]
	subs r1, r0, r7
	cmp r1, #0x00
	blt _0800F428
	movs r0, #0x80
	lsls r0, r0, #0x05
	cmp r1, r0
	bgt _0800F432
	b _0800F436
_0800F424: .4byte 0x08121400
_0800F428:
	subs r1, r7, r0
	movs r0, #0x80
	lsls r0, r0, #0x05
	cmp r1, r0
	ble _0800F436
_0800F432:
	movs r0, #0x00
	b _0800F438
_0800F436:
	movs r0, #0x01
_0800F438:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
