.syntax unified
	.align 2, 0
	.global func_0805FC04
	.thumb
	.thumb_func
	.type func_0805FC04, %function
func_0805FC04: @ 0805FC04
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r6, r0, #0x0
	mov r8, r1
	adds r7, r2, #0x0
	adds r4, r3, #0x0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	mov r0, r8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r5, sp
	movs r1, #0x64
	mov r9, r1
	adds r0, r4, #0x0
	bl _0811D754
	movs r1, #0x00
	mov r10, r1
	strb r0, [r5, #0x01]
	mov r5, sp
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl _0811D754
	mov r1, sp
	ldrb r2, [r1, #0x01]
	lsls r1, r2, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x01
	subs r0, r0, r1
	strb r0, [r5, #0x03]
	mov r3, sp
	mov r0, sp
	ldrb r0, [r0, #0x01]
	mov r2, r9
	muls r2, r0
	mov r0, sp
	ldrb r1, [r0, #0x03]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	adds r2, r2, r0
	subs r4, r4, r2
	strb r4, [r3, #0x05]
	mov r0, sp
	movs r1, #0x82
	strb r1, [r0, #0x00]
	mov r2, sp
	ldrb r0, [r0, #0x01]
	adds r0, #0x4F
	strb r0, [r2, #0x01]
	mov r0, sp
	strb r1, [r0, #0x02]
	ldrb r0, [r0, #0x03]
	adds r0, #0x4F
	strb r0, [r2, #0x03]
	mov r0, sp
	strb r1, [r0, #0x04]
	mov r1, sp
	ldrb r0, [r0, #0x05]
	adds r0, #0x4F
	strb r0, [r1, #0x05]
	mov r0, sp
	mov r1, r10
	strb r1, [r0, #0x06]
	adds r0, r6, #0x0
	mov r1, r8
	adds r2, r7, #0x0
	bl func_0805FCB0
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
