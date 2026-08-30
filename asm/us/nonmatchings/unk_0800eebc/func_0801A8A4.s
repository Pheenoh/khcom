.syntax unified
	.align 2, 0
	.global func_0801A8A4
	.thumb
	.thumb_func
	.type func_0801A8A4, %function
func_0801A8A4: @ 0801A8A4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	movs r6, #0x00
	ldr r2, _0801A91C @ =0x02039B84
	ldr r0, [r2, #0x00]
	adds r0, #0xDE
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	subs r0, r0, r3
	lsls r1, r0, #0x08
	ldr r0, [r4, #0x00]
	cmp r0, r1
	bge _0801A8CC
	str r1, [r4, #0x00]
	movs r6, #0x03
_0801A8CC:
	ldr r0, [r2, #0x00]
	adds r0, #0xE0
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r0, r0, r3
	lsls r3, r0, #0x08
	ldr r0, [r4, #0x00]
	cmp r0, r3
	ble _0801A8E2
	str r3, [r4, #0x00]
	movs r6, #0x04
_0801A8E2:
	ldr r4, [r2, #0x00]
	adds r0, r4, #0x0
	adds r0, #0xDA
	movs r2, #0x00
	ldsh r0, [r0, r2]
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	subs r0, r0, r1
	lsls r3, r0, #0x08
	ldr r0, [r5, #0x00]
	cmp r0, r3
	bge _0801A8FE
	str r3, [r5, #0x00]
	movs r6, #0x01
_0801A8FE:
	adds r0, r4, #0x0
	adds r0, #0xDC
	movs r2, #0x00
	ldsh r0, [r0, r2]
	adds r0, r0, r1
	lsls r1, r0, #0x08
	ldr r0, [r5, #0x00]
	cmp r0, r1
	ble _0801A914
	str r1, [r5, #0x00]
	movs r6, #0x02
_0801A914:
	adds r0, r6, #0x0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_0801A91C: .4byte 0x02039B84
.syntax divided
