.syntax unified
	.align 2, 0
	.global func_08011270
	.thumb
	.thumb_func
	.type func_08011270, %function
func_08011270: @ 08011270
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	mov r12, r0
	mov r8, r1
	mov r9, r2
	str r3, [sp, #0x000]
	ldr r0, [sp, #0x028]
	ldr r1, [sp, #0x02C]
	ldr r2, [sp, #0x030]
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r10, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x004]
	mov r0, r12
	adds r0, #0xD8
	ldr r6, [r0, #0x00]
	cmp r6, #0x00
	beq _080112B4
	ldr r2, [r6, #0x34]
	ldr r3, [r6, #0x38]
	mov r4, r12
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	adds r4, r2, #0x0
	orrs r4, r0
	b _080112BC
_080112B4:
	mov r0, r12
	ldr r4, [r0, #0x34]
	ldr r5, [r0, #0x38]
	mov r6, r12
_080112BC:
	ldr r0, _0801134C @ =0x01000180
	adds r1, r4, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _08011350
	lsls r0, r7, #0x10
	asrs r4, r0, #0x08
	mov r2, r8
	subs r1, r2, r4
	mov r0, r12
	adds r0, #0x9E
	ldrh r0, [r0, #0x00]
	lsls r3, r0, #0x08
	mov r0, r12
	ldr r2, [r0, #0x04]
	adds r0, r2, r3
	cmp r1, r0
	bgt _08011350
	mov r0, r8
	adds r1, r0, r4
	subs r0, r2, r3
	cmp r1, r0
	blt _08011350
	mov r1, r10
	lsls r0, r1, #0x10
	asrs r2, r0, #0x08
	mov r4, r9
	subs r1, r4, r2
	mov r0, r12
	adds r0, #0xA0
	ldrh r0, [r0, #0x00]
	lsls r4, r0, #0x08
	mov r0, r12
	ldr r3, [r0, #0x08]
	adds r0, r3, r4
	cmp r1, r0
	bgt _08011350
	mov r0, r9
	adds r1, r0, r2
	subs r0, r3, r4
	cmp r1, r0
	blt _08011350
	ldr r1, [sp, #0x004]
	lsls r0, r1, #0x10
	asrs r1, r0, #0x08
	ldr r2, [sp, #0x000]
	subs r0, r2, r1
	mov r2, r12
	ldr r4, [r2, #0x0C]
	cmp r0, r4
	bgt _08011350
	ldr r0, [sp, #0x000]
	adds r1, r0, r1
	mov r0, r12
	adds r0, #0x9C
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x08
	subs r0, r4, r0
	cmp r1, r0
	blt _08011350
	adds r0, r6, #0x0
	adds r0, #0xE2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	bgt _08011350
	movs r0, #0x01
	b _08011352
	.byte 0x00, 0x00
_0801134C: .4byte 0x01000180
_08011350:
	movs r0, #0x00
_08011352:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
