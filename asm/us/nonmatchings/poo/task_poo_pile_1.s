.syntax unified
	.align 2, 0
	.global task_poo_pile_1
	.thumb
	.thumb_func
	.type task_poo_pile_1, %function
task_poo_pile_1: @ 080CD298
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	adds r6, r0, #0x0
	adds r7, r6, #0x0
	adds r7, #0xB0
	ldrh r0, [r7, #0x00]
	cmp r0, #0x07
	beq _080CD396
	movs r0, #0xCC
	adds r0, r0, r6
	mov r10, r0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080CD396
	movs r1, #0x34
	adds r1, r1, r6
	mov r8, r1
	mov r0, r8
	movs r1, #0x09
	bl func_08012660
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CD2D6
	ldr r1, _080CD378 @ =0x0203C3F0
	movs r0, #0x05
	str r0, [r1, #0x00]
_080CD2D6:
	ldr r0, _080CD37C @ =0x0203C3D8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080CD396
	mov r0, r8
	bl func_080C76B0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CD396
	movs r2, #0x0C
	adds r2, r2, r6
	mov r9, r2
	mov r0, r9
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CD396
	mov r1, sp
	adds r0, r6, #0x0
	adds r0, #0x24
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldrh r0, [r7, #0x00]
	bl func_080CD1F8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r1, [sp, #0x008]
	subs r1, r1, r0
	str r1, [sp, #0x008]
	adds r4, r6, #0x0
	adds r4, #0xC8
	ldr r0, [r4, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	adds r5, r6, #0x0
	adds r5, #0xB4
	cmp r0, #0x00
	beq _080CD336
	ldr r1, [r4, #0x00]
	adds r0, r5, #0x0
	bl func_08000DE8
_080CD336:
	ldr r1, _080CD380 @ =0x09EF4BC8
	adds r0, r5, #0x0
	mov r2, sp
	bl func_08000E14
	str r0, [r4, #0x00]
	ldrh r0, [r7, #0x00]
	bl func_080CD1DC
	strh r0, [r7, #0x00]
	ldrh r1, [r7, #0x00]
	mov r0, r9
	movs r2, #0x00
	bl func_080059A4
	movs r0, #0xA3
	lsls r0, r0, #0x01
	bl func_0811FE70
	ldrh r0, [r7, #0x00]
	cmp r0, #0x07
	bne _080CD384
	mov r0, r8
	bl func_08012304
	movs r0, #0x00
	mov r3, r10
	strb r0, [r3, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x90
	bl func_080CCBD4
	b _080CD396
_080CD378: .4byte 0x0203C3F0
_080CD37C: .4byte 0x0203C3D8
_080CD380: .4byte 0x09EF4BC8
_080CD384:
	ldrh r0, [r7, #0x00]
	bl func_080CD1F8
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r0, r8
	bl func_08012658
_080CD396:
	movs r0, #0x01
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
