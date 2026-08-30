.syntax unified
	.align 2, 0
	.global func_080A096C
	.thumb
	.thumb_func
	.type func_080A096C, %function
func_080A096C: @ 080A096C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	movs r0, #0x64
	mov r8, r0
	adds r0, r5, #0x0
	movs r1, #0x64
	bl _0811D754
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl _0811D754
	lsls r1, r4, #0x02
	adds r1, r1, r4
	lsls r1, r1, #0x01
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, r8
	muls r1, r4
	subs r5, r5, r1
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x01
	subs r5, r5, r1
	strh r4, [r6, #0x00]
	strh r0, [r6, #0x02]
	strh r5, [r6, #0x04]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
