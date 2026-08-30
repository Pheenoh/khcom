.syntax unified
	.align 2, 0
	.global func_080BB518
	.thumb
	.thumb_func
	.type func_080BB518, %function
func_080BB518: @ 080BB518
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r9, r0
	movs r5, #0x00
	movs r6, #0x00
	movs r4, #0x00
	ldr r0, _080BB580 @ =0x08121400
	mov r12, r0
	ldr r1, _080BB584 @ =0x0961A63C
	mov r8, r1
_080BB530:
	movs r0, #0x34
	muls r0, r4
	mov r2, r9
	adds r3, r2, r0
	str r5, [r3, #0x0C]
	str r6, [r3, #0x10]
	ldrb r1, [r3, #0x08]
	lsls r0, r1, #0x01
	add r0, r12
	movs r7, #0x00
	ldsh r2, [r0, r7]
	ldrh r0, [r3, #0x26]
	lsls r0, r0, #0x01
	add r0, r8
	ldrh r3, [r0, #0x00]
	adds r0, r2, #0x0
	muls r0, r3
	adds r5, r5, r0
	adds r1, #0x40
	lsls r1, r1, #0x01
	add r1, r12
	movs r2, #0x00
	ldsh r0, [r1, r2]
	negs r0, r0
	muls r0, r3
	adds r6, r6, r0
	adds r4, #0x01
	cmp r4, #0x02
	ble _080BB530
	mov r3, r9
	adds r3, #0x9C
	str r5, [r3, #0x0C]
	str r6, [r3, #0x10]
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080BB580: .4byte 0x08121400
_080BB584: .4byte 0x0961A63C
.syntax divided
