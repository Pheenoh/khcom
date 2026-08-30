.syntax unified
	.align 2, 0
	.global func_0811D408
	.thumb
	.thumb_func
	.type func_0811D408, %function
func_0811D408: @ 0811D408
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	mov r9, r0
	adds r5, r1, #0x0
	adds r6, r2, #0x0
	adds r7, r3, #0x0
	ldr r0, [sp, #0x020]
	mov r8, r0
	ldr r1, [sp, #0x024]
	mov r10, r1
	ldr r2, _0811D45C @ =0x0203C7F0
	mov r12, r2
	mov r3, r9
	lsls r4, r3, #0x02
	mov r0, r12
	adds r0, #0x08
	adds r0, r4, r0
	ldr r1, [r2, #0x34]
	ldr r2, [r0, #0x00]
	subs r3, r1, r2
	cmp r3, r5
	bcs _0811D460
	mov r0, r12
	adds r1, r4, r0
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r6, #0x00]
	str r3, [r7, #0x00]
	ldr r0, [r1, #0x00]
	mov r1, r8
	str r0, [r1, #0x00]
	subs r1, r5, r3
	mov r2, r10
	str r1, [r2, #0x00]
	mov r0, r12
	adds r0, #0x18
	adds r0, r4, r0
	str r1, [r0, #0x00]
	b _0811D482
_0811D45C: .4byte 0x0203C7F0
_0811D460:
	mov r3, r12
	adds r0, r4, r3
	ldr r0, [r0, #0x00]
	adds r0, r0, r2
	str r0, [r6, #0x00]
	str r5, [r7, #0x00]
	movs r0, #0x00
	mov r1, r8
	str r0, [r1, #0x00]
	mov r2, r10
	str r0, [r2, #0x00]
	mov r1, r12
	adds r1, #0x18
	adds r1, r4, r1
	ldr r0, [r1, #0x00]
	adds r0, r0, r5
	str r0, [r1, #0x00]
_0811D482:
	mov r1, r12
	adds r1, #0x20
	adds r1, r4, r1
	ldr r0, [r1, #0x00]
	adds r0, r0, r5
	str r0, [r1, #0x00]
	mov r3, r9
	lsls r1, r3, #0x02
	mov r0, r12
	adds r0, #0x18
	adds r2, r1, r0
	ldr r1, [r2, #0x00]
	mov r3, r12
	ldr r0, [r3, #0x34]
	cmp r1, r0
	bne _0811D4A6
	movs r0, #0x00
	str r0, [r2, #0x00]
_0811D4A6:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
