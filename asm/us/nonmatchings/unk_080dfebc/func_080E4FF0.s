.syntax unified
	.align 2, 0
	.global func_080E4FF0
	.thumb
	.thumb_func
	.type func_080E4FF0, %function
func_080E4FF0: @ 080E4FF0
	push {r4, r5, r6, lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4, r5, r6}
	add sp, #-0x004
	mov r8, r0
	adds r3, r1, #0x0
	lsls r3, r3, #0x10
	lsls r2, r2, #0x10
	movs r0, #0x40
	add r0, r8
	mov r9, r0
	movs r0, #0x80
	add r0, r8
	mov r10, r0
	lsrs r5, r3, #0x10
	asrs r3, r3, #0x10
	lsrs r4, r2, #0x10
	asrs r2, r2, #0x10
	str r2, [sp, #0x000]
	mov r0, r8
	mov r1, r9
	mov r2, r10
	bl func_080E4EB0
	movs r0, #0x03
	bl func_0800514C
	adds r1, r0, #0x0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r6, #0x01
	str r6, [sp, #0x000]
	mov r0, r8
	adds r2, r5, #0x0
	adds r3, r4, #0x0
	bl func_080045AC
	movs r0, #0x02
	bl func_0800514C
	adds r1, r0, #0x0
	str r6, [sp, #0x000]
	mov r0, r9
	adds r2, r5, #0x0
	adds r3, r4, #0x0
	bl func_080045AC
	movs r0, #0x01
	bl func_0800514C
	adds r1, r0, #0x0
	str r6, [sp, #0x000]
	mov r0, r10
	adds r2, r5, #0x0
	adds r3, r4, #0x0
	bl func_080045AC
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
