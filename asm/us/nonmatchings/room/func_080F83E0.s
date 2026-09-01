.syntax unified
	.align 2, 0
	.global func_080F83E0
	.thumb
	.thumb_func
	.type func_080F83E0, %function
func_080F83E0: @ 080F83E0
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x024
	adds r7, r0, #0x0
	adds r5, r1, #0x0
	movs r1, #0xAD
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _080F8402
	b _080F852E
_080F8402:
	movs r2, #0x89
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	movs r1, #0x01
	bl func_08002C28
	str r0, [sp, #0x014]
	mov r8, r5
	ldr r0, [r5, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	ldr r0, [r7, #0x18]
	cmp r0, #0x01
	bne _080F842E
	movs r0, #0x01
	mov r3, r9
	orrs r3, r0
	mov r9, r3
_080F842E:
	adds r0, r5, #0x0
	bl func_0801CA00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080F8444
	ldr r4, _080F8440 @ =0x00000A34
	adds r0, r7, r4
	b _080F844A
_080F8440: .4byte 0x00000A34
_080F8444:
	movs r6, #0xA3
	lsls r6, r6, #0x04
	adds r0, r7, r6
_080F844A:
	ldr r0, [r0, #0x00]
	mov r10, r0
	mov r6, sp
	adds r6, #0x12
	mov r0, r8
	ldr r2, [r0, #0x04]
	ldr r3, [r0, #0x08]
	ldr r0, [r0, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl WorldToScreen
	add r1, sp, #0x010
	movs r2, #0xAF
	lsls r2, r2, #0x01
	adds r2, r5, r2
	str r2, [sp, #0x018]
	ldrh r0, [r2, #0x00]
	ldrh r1, [r1, #0x00]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #0xB0
	lsls r3, r3, #0x01
	adds r3, r5, r3
	str r3, [sp, #0x01C]
	ldrh r1, [r3, #0x00]
	ldrh r4, [r6, #0x00]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r3, #0xCE
	lsls r3, r3, #0x01
	adds r2, r5, r3
	ldr r2, [r2, #0x00]
	movs r4, #0xCC
	lsls r4, r4, #0x01
	adds r3, r5, r4
	ldr r3, [r3, #0x00]
	mov r12, r3
	mov r3, r10
	str r3, [sp, #0x000]
	ldr r4, [sp, #0x014]
	str r4, [sp, #0x004]
	mov r3, r9
	str r3, [sp, #0x008]
	mov r4, r8
	ldr r4, [r4, #0x08]
	asrs r4, r4, #0x08
	str r4, [sp, #0x020]
	lsls r4, r4, #0x02
	ldr r3, _080F8540 @ =0xFFFFEFFC
	subs r4, r3, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	mov r3, r12
	bl DrawSprite
	movs r4, #0xD0
	lsls r4, r4, #0x01
	adds r0, r5, r4
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080F8524
	ldr r0, [r7, #0x00]
	cmp r0, #0x07
	beq _080F8524
	cmp r0, #0x08
	beq _080F8524
	cmp r0, #0x09
	beq _080F8524
	add r1, sp, #0x010
	ldr r2, [sp, #0x018]
	ldrh r0, [r2, #0x00]
	ldrh r1, [r1, #0x00]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r3, [sp, #0x01C]
	ldrh r1, [r3, #0x00]
	ldrh r6, [r6, #0x00]
	adds r1, r1, r6
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r4, _080F8544 @ =0x00000A2C
	adds r2, r7, r4
	ldr r2, [r2, #0x00]
	ldr r6, _080F8548 @ =0x00000A28
	adds r3, r7, r6
	ldr r3, [r3, #0x00]
	mov r4, r10
	str r4, [sp, #0x000]
	ldr r6, [sp, #0x014]
	str r6, [sp, #0x004]
	mov r4, r9
	str r4, [sp, #0x008]
	mov r6, r8
	ldr r4, [r6, #0x08]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r6, _080F8540 @ =0xFFFFEFFC
	subs r4, r6, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
_080F8524:
	movs r1, #0xB6
	lsls r1, r1, #0x01
	adds r0, r5, r1
	bl TaskPoolDraw
_080F852E:
	add sp, #0x024
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080F8540: .4byte 0xFFFFEFFC
_080F8544: .4byte 0x00000A2C
_080F8548: .4byte 0x00000A28
.syntax divided
