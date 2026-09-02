.syntax unified
	.align 2, 0
	.global func_080A09C0
	.thumb
	.thumb_func
	.type func_080A09C0, %function
func_080A09C0: @ 080A09C0
	push {r4, r5, r6, lr}
	mov r6, r9
	mov r5, r8
	push {r5, r6}
	adds r6, r0, #0x0
	mov r8, r1
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	movs r1, #0xFA
	lsls r1, r1, #0x02
	adds r0, r6, #0x0
	bl __udivsi3
	adds r5, r0, #0x0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	movs r0, #0x64
	mov r9, r0
	adds r0, r6, #0x0
	movs r1, #0x64
	bl __udivsi3
	adds r4, r0, #0x0
	lsls r0, r5, #0x02
	adds r0, r0, r5
	lsls r0, r0, #0x01
	subs r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r6, #0x0
	movs r1, #0x0A
	bl __udivsi3
	lsls r1, r4, #0x02
	adds r1, r1, r4
	lsls r1, r1, #0x01
	subs r0, r0, r1
	mov r1, r9
	muls r1, r5
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r5, #0x05
	subs r1, r1, r5
	lsls r1, r1, #0x02
	adds r1, r1, r5
	lsls r1, r1, #0x03
	subs r6, r6, r1
	mov r1, r9
	muls r1, r4
	subs r6, r6, r1
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x01
	subs r6, r6, r1
	mov r1, r8
	strh r5, [r1, #0x00]
	strh r4, [r1, #0x02]
	strh r0, [r1, #0x04]
	strh r6, [r1, #0x06]
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
