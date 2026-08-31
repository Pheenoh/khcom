.syntax unified
	.align 2, 0
	.global func_080784BC
	.thumb
	.thumb_func
	.type func_080784BC, %function
func_080784BC: @ 080784BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	ldr r0, _080784DC @ =0x09041FA0
	adds r0, #0xDC
	ldrh r0, [r0, #0x00]
	mov r8, r0
	cmp r7, #0x00
	beq _080784E0
	cmp r7, #0x01
	beq _0807857A
	b _0807859E
	.byte 0x00, 0x00
_080784DC: .4byte 0x09041FA0
_080784E0:
	mov r5, r8
	adds r5, #0x0F
	lsls r4, r5, #0x01
	adds r4, r4, r5
	lsls r0, r4, #0x02
	bl EwramAlloc
	adds r1, r0, #0x0
	str r1, [r6, #0x44]
	str r7, [sp, #0x000]
	movs r2, #0xA0
	lsls r2, r2, #0x13
	orrs r2, r4
	mov r0, sp
	bl CpuSet
	movs r2, #0x00
	mov r4, r8
	adds r4, #0x01
	adds r7, r4, #0x0
	movs r0, #0x94
	adds r0, r0, r6
	mov r8, r0
	cmp r2, r7
	bge _0807853C
	movs r3, #0x00
_08078514:
	ldr r0, [r6, #0x44]
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x02
	adds r0, r1, r0
	strb r3, [r0, #0x06]
	ldr r0, [r6, #0x44]
	adds r0, r1, r0
	strb r3, [r0, #0x07]
	ldr r0, [r6, #0x44]
	adds r0, r1, r0
	strb r3, [r0, #0x0A]
	ldr r0, [r6, #0x44]
	adds r1, r1, r0
	strb r3, [r1, #0x08]
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r4
	blt _08078514
_0807853C:
	lsls r0, r7, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r5
	bge _0807856E
	movs r3, #0x01
_08078546:
	ldr r0, [r6, #0x44]
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x02
	adds r0, r1, r0
	strb r3, [r0, #0x06]
	ldr r0, [r6, #0x44]
	adds r0, r1, r0
	strb r3, [r0, #0x07]
	ldr r0, [r6, #0x44]
	adds r0, r1, r0
	strb r3, [r0, #0x0A]
	ldr r0, [r6, #0x44]
	adds r1, r1, r0
	strb r3, [r1, #0x08]
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r5
	blt _08078546
_0807856E:
	ldr r0, [r6, #0x44]
	bl func_080783C0
	movs r0, #0x00
	mov r1, r8
	b _0807859C
_0807857A:
	movs r0, #0x0C
	bl EwramAlloc
	adds r1, r0, #0x0
	str r1, [r6, #0x50]
	movs r0, #0x00
	str r0, [sp, #0x004]
	add r0, sp, #0x004
	ldr r2, _080785AC @ =0x05000003
	bl CpuSet
	ldr r1, [r6, #0x50]
	ldr r0, _080785B0 @ =0x000030FF
	str r0, [r1, #0x00]
	adds r1, r6, #0x0
	adds r1, #0x9A
	ldr r0, _080785B4 @ =0x0000FFFF
_0807859C:
	strh r0, [r1, #0x00]
_0807859E:
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080785AC: .4byte 0x05000003
_080785B0: .4byte 0x000030FF
_080785B4: .4byte 0x0000FFFF
.syntax divided
