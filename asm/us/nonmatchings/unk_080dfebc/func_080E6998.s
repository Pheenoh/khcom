.syntax unified
	.align 2, 0
	.global func_080E6998
	.thumb
	.thumb_func
	.type func_080E6998, %function
func_080E6998: @ 080E6998
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r9, r2
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	movs r2, #0x00
	cmp r2, r9
	bge _080E6A02
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x000]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	mov r10, r0
_080E69C8:
	movs r5, #0x00
	adds r0, r2, #0x1
	mov r8, r0
	cmp r5, r7
	bge _080E69FC
	mov r1, r10
	adds r0, r1, r2
	lsls r6, r0, #0x10
	ldr r3, [sp, #0x000]
	lsls r4, r3, #0x10
_080E69DC:
	asrs r1, r4, #0x10
	asrs r0, r6, #0x10
	bl func_080E548C
	ldrh r2, [r0, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x01
	adds r1, r3, #0x0
	orrs r1, r2
	strh r1, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x09
	adds r4, r4, r0
	adds r5, #0x01
	cmp r5, r7
	blt _080E69DC
_080E69FC:
	mov r2, r8
	cmp r2, r9
	blt _080E69C8
_080E6A02:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
