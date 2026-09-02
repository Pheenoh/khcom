.syntax unified
	.align 2, 0
	.global func_0807CC2C
	.thumb
	.thumb_func
	.type func_0807CC2C, %function
func_0807CC2C: @ 0807CC2C
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0x0
	adds r0, #0x94
	adds r1, r7, #0x0
	adds r1, #0x98
	ldr r1, [r1, #0x00]
	adds r4, r7, #0x0
	adds r4, #0xA3
	ldrb r2, [r4, #0x00]
	bl ApproachValue
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _0807CC52
	subs r0, #0x01
	strb r0, [r4, #0x00]
_0807CC52:
	adds r2, r7, #0x0
	adds r2, #0x84
	adds r0, r7, #0x0
	adds r0, #0x88
	ldr r0, [r0, #0x00]
	ldr r1, [r2, #0x00]
	subs r0, r0, r1
	asrs r0, r0, #0x01
	adds r1, r1, r0
	str r1, [r2, #0x00]
	adds r4, r7, #0x0
	adds r4, #0x9C
	movs r1, #0x00
	ldsh r0, [r4, r1]
	mov r9, r2
	cmp r0, #0x00
	ble _0807CCA4
	adds r0, r7, #0x0
	adds r0, #0x7C
	adds r1, r7, #0x0
	adds r1, #0x80
	ldr r1, [r1, #0x00]
	ldrh r2, [r4, #0x00]
	bl ApproachValue
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	movs r2, #0x00
	strh r0, [r4, #0x00]
	ldr r0, [r7, #0x78]
	movs r1, #0x41
	negs r1, r1
	ands r0, r1
	str r0, [r7, #0x78]
	ldr r0, _0807CCA0 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xE7
	strb r2, [r0, #0x00]
	b _0807CCAC
_0807CCA0: .4byte 0x02039DD4
_0807CCA4:
	ldr r0, [r7, #0x78]
	movs r1, #0x40
	orrs r0, r1
	str r0, [r7, #0x78]
_0807CCAC:
	movs r2, #0x8C
	adds r2, r2, r7
	mov r8, r2
	ldr r3, _0807CD40 @ =0x08121400
	adds r4, r7, #0x0
	adds r4, #0x94
	ldr r0, [r4, #0x00]
	asrs r0, r0, #0x08
	movs r2, #0xFF
	ands r0, r2
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r5, #0x00
	ldsh r1, [r0, r5]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r5, _0807CD44 @ =0x09033FF4
	ldr r1, [r5, #0x00]
	adds r0, r0, r1
	mov r1, r8
	str r0, [r1, #0x00]
	adds r6, r7, #0x0
	adds r6, #0x90
	ldr r0, [r4, #0x00]
	asrs r0, r0, #0x08
	ands r0, r2
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r4, #0x00
	ldsh r1, [r0, r4]
	negs r1, r1
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, [r5, #0x04]
	adds r0, r0, r1
	str r0, [r6, #0x00]
	ldr r1, [r7, #0x7C]
	asrs r1, r1, #0x08
	adds r1, #0x20
	ands r1, r2
	lsls r0, r1, #0x01
	adds r0, r0, r3
	movs r5, #0x00
	ldsh r2, [r0, r5]
	mov r4, r9
	ldr r0, [r4, #0x00]
	asrs r0, r0, #0x08
	muls r0, r2
	mov r5, r8
	ldr r2, [r5, #0x00]
	adds r0, r0, r2
	str r0, [r7, #0x4C]
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r3
	movs r0, #0x00
	ldsh r1, [r1, r0]
	negs r1, r1
	ldr r0, [r4, #0x00]
	asrs r0, r0, #0x08
	muls r0, r1
	ldr r1, [r6, #0x00]
	adds r0, r0, r1
	str r0, [r7, #0x50]
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0807CD40: .4byte 0x08121400
_0807CD44: .4byte 0x09033FF4
.syntax divided
