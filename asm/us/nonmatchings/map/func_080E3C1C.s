.syntax unified
	.align 2, 0
	.global func_080E3C1C
	.thumb
	.thumb_func
	.type func_080E3C1C, %function
func_080E3C1C: @ 080E3C1C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	mov r10, r0
	str r1, [sp, #0x000]
	str r2, [sp, #0x004]
	str r3, [sp, #0x008]
	ldr r0, [sp, #0x02C]
	ldr r1, [sp, #0x030]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	bl GetRandom
	mov r1, r9
	lsls r5, r1, #0x10
	asrs r5, r5, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, r8
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	subs r1, r4, r5
	bl __modsi3
	adds r6, r5, r0
	movs r7, #0x00
	subs r4, r4, r5
	cmp r7, r4
	bge _080E3CC2
_080E3C64:
	ldr r0, _080E3C98 @ =0x02034F2A
	ldrh r0, [r0, #0x00]
	subs r4, r0, #0x1
	cmp r4, #0x00
	blt _080E3CA6
	lsls r5, r6, #0x10
_080E3C70:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	asrs r0, r5, #0x10
	bl func_080E08BC
	ldrb r1, [r0, #0x02]
	cmp r1, r10
	bne _080E3C9C
	ldr r1, [sp, #0x000]
	strh r6, [r1, #0x00]
	ldr r2, [sp, #0x004]
	strh r4, [r2, #0x00]
	ldr r1, [r0, #0x08]
	asrs r0, r1, #0x0B
	lsrs r1, r1, #0x1F
	adds r0, r0, r1
	asrs r0, r0, #0x01
	ldr r1, [sp, #0x008]
	strh r0, [r1, #0x00]
	b _080E3CC2
_080E3C98: .4byte 0x02034F2A
_080E3C9C:
	cmp r1, #0x0B
	bne _080E3CA6
	subs r4, #0x01
	cmp r4, #0x00
	bge _080E3C70
_080E3CA6:
	adds r6, #0x01
	mov r2, r8
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	mov r2, r9
	lsls r0, r2, #0x10
	cmp r6, r1
	bne _080E3CB8
	asrs r6, r0, #0x10
_080E3CB8:
	adds r7, #0x01
	asrs r0, r0, #0x10
	subs r0, r1, r0
	cmp r7, r0
	blt _080E3C64
_080E3CC2:
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
