.syntax unified
	.align 2, 0
	.global func_0801C700
	.thumb
	.thumb_func
	.type func_0801C700, %function
func_0801C700: @ 0801C700
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	adds r6, r2, #0x0
	adds r7, r3, #0x0
	adds r0, #0xE8
	ldr r0, [r0, #0x00]
	cmp r0, #0x03
	bne _0801C7B8
	cmp r5, #0x00
	beq _0801C722
	adds r0, r4, #0x0
	adds r0, #0xF0
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x00]
_0801C722:
	cmp r6, #0x00
	beq _0801C72E
	adds r0, r4, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x00]
_0801C72E:
	cmp r7, #0x00
	beq _0801C73A
	adds r0, r4, #0x0
	adds r0, #0xF8
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x00]
_0801C73A:
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x06
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #0x00
	bne _0801C7EE
	cmp r5, #0x00
	beq _0801C77E
	bl func_080065A4
	ldr r1, _0801C7B4 @ =0x02039B84
	ldr r1, [r1, #0x00]
	adds r2, r1, #0x0
	adds r2, #0xDA
	movs r3, #0x00
	ldsh r4, [r2, r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, #0xDC
	movs r2, #0x00
	ldsh r1, [r1, r2]
	subs r1, r1, r4
	adds r1, #0x01
	bl func_0811D684
	adds r4, r4, r0
	lsls r4, r4, #0x08
	str r4, [r5, #0x00]
_0801C77E:
	cmp r6, #0x00
	beq _0801C7AA
	bl func_080065A4
	ldr r1, _0801C7B4 @ =0x02039B84
	ldr r1, [r1, #0x00]
	adds r2, r1, #0x0
	adds r2, #0xDE
	movs r3, #0x00
	ldsh r4, [r2, r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, #0xE0
	movs r2, #0x00
	ldsh r1, [r1, r2]
	subs r1, r1, r4
	adds r1, #0x01
	bl func_0811D684
	adds r4, r4, r0
	lsls r4, r4, #0x08
	str r4, [r6, #0x00]
_0801C7AA:
	cmp r7, #0x00
	beq _0801C7EE
	mov r3, r8
	str r3, [r7, #0x00]
	b _0801C7EE
_0801C7B4: .4byte 0x02039B84
_0801C7B8:
	cmp r5, #0x00
	beq _0801C7CA
	ldr r0, _0801C7F8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r1, #0x98
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x00]
_0801C7CA:
	cmp r6, #0x00
	beq _0801C7DC
	ldr r0, _0801C7F8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r2, #0x9A
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x00]
_0801C7DC:
	cmp r7, #0x00
	beq _0801C7EE
	ldr r0, _0801C7F8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r3, #0x9C
	lsls r3, r3, #0x01
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x00]
_0801C7EE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0801C7F8: .4byte 0x02039B84
.syntax divided
