.syntax unified
	.align 2, 0
	.global func_080D54FC
	.thumb
	.thumb_func
	.type func_080D54FC, %function
func_080D54FC: @ 080D54FC
	push {r4, r5, r6, r7, lr}
	ldr r2, _080D554C @ =0x0203C4B4
	ldr r0, [r2, #0x00]
	mov r12, r0
	ldr r0, _080D5550 @ =0x0203C538
	ldrb r1, [r0, #0x00]
	lsls r1, r1, #0x02
	mov r0, r12
	adds r0, #0x14
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldr r5, [r0, #0x04]
	adds r0, r5, #0x0
	adds r0, #0x8E
	movs r3, #0x00
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	mov r1, r12
	adds r1, #0xAE
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	subs r0, #0x45
	mov r3, r12
	adds r3, #0xA2
	strh r0, [r3, #0x00]
	lsls r0, r0, #0x10
	adds r6, r2, #0x0
	cmp r0, #0x00
	blt _080D5548
	mov r2, r12
	adds r2, #0xB2
	ldrh r4, [r2, #0x00]
	movs r7, #0x00
	ldsh r0, [r2, r7]
	cmp r0, #0x9F
	bgt _080D5554
_080D5548:
	movs r0, #0x00
	b _080D5566
_080D554C: .4byte 0x0203C4B4
_080D5550: .4byte 0x0203C538
_080D5554:
	movs r0, #0x00
	ldsh r1, [r3, r0]
	movs r7, #0x00
	ldsh r0, [r2, r7]
	subs r0, #0xA0
	cmp r1, r0
	ble _080D5568
	adds r0, r4, #0x0
	subs r0, #0xA0
_080D5566:
	strh r0, [r3, #0x00]
_080D5568:
	adds r0, r5, #0x0
	adds r0, #0x8E
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r3, [r6, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xAE
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x0F
	bgt _080D5592
	adds r1, r3, #0x0
	adds r1, #0xA2
	ldrh r0, [r1, #0x00]
	subs r0, #0x10
	strh r0, [r1, #0x00]
_080D5592:
	ldr r2, [r6, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x8C
	movs r3, #0x00
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r1, r2, #0x0
	adds r1, #0xAC
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	subs r0, #0x68
	adds r3, r2, #0x0
	adds r3, #0xA0
	strh r0, [r3, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	blt _080D55C4
	adds r2, #0xB0
	ldrh r4, [r2, #0x00]
	movs r5, #0x00
	ldsh r0, [r2, r5]
	cmp r0, #0xEF
	bgt _080D55C8
_080D55C4:
	movs r0, #0x00
	b _080D55DA
_080D55C8:
	movs r7, #0x00
	ldsh r1, [r3, r7]
	movs r5, #0x00
	ldsh r0, [r2, r5]
	subs r0, #0xF0
	cmp r1, r0
	ble _080D55DC
	adds r0, r4, #0x0
	subs r0, #0xF0
_080D55DA:
	strh r0, [r3, #0x00]
_080D55DC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
