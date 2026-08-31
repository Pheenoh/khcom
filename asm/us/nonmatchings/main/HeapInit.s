.syntax unified
	.align 2, 0
	.global HeapInit
	.thumb
	.thumb_func
	.type HeapInit, %function
HeapInit: @ 08000800
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	movs r3, #0x20
	negs r3, r3
	ands r1, r3
	adds r4, r1, #0x0
	subs r4, #0x20
	adds r5, r0, r4
	str r0, [r2, #0x00]
	str r5, [r2, #0x04]
	adds r4, r0, #0x0
	adds r4, #0x20
	str r3, [r0, #0x00]
	movs r6, #0x00
	str r6, [r0, #0x04]
	str r4, [r0, #0x08]
	str r6, [r0, #0x0C]
	str r4, [r0, #0x10]
	ldr r3, [r2, #0x0C]
	mov r8, r3
	str r3, [r0, #0x18]
	str r0, [r0, #0x1C]
	movs r3, #0x01
	negs r3, r3
	str r3, [r5, #0x00]
	str r4, [r5, #0x04]
	str r6, [r5, #0x08]
	str r4, [r5, #0x0C]
	str r6, [r5, #0x10]
	mov r3, r8
	str r3, [r5, #0x18]
	str r5, [r5, #0x1C]
	subs r1, #0x40
	str r1, [r0, #0x20]
	str r0, [r4, #0x04]
	str r5, [r4, #0x08]
	str r0, [r4, #0x0C]
	str r5, [r4, #0x10]
	str r3, [r4, #0x18]
	str r4, [r4, #0x1C]
	strb r6, [r2, #0x08]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
