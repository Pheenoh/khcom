.syntax unified
	.align 2, 0
	.global task_bos_boogie_dice_2
	.thumb
	.thumb_func
	.type task_bos_boogie_dice_2, %function
task_bos_boogie_dice_2: @ 080DA2EC
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	adds r7, r6, #0x0
	adds r7, #0x40
	bl func_080D9B28
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080DA3B2
	ldr r0, [r7, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	adds r0, r7, #0x0
	bl func_0801CA00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DA324
	ldr r0, [r6, #0x10]
	mov r8, r0
	b _080DA328
_080DA324:
	ldr r1, [r6, #0x0C]
	mov r8, r1
_080DA328:
	movs r2, #0xAE
	lsls r2, r2, #0x01
	adds r0, r6, r2
	ldr r1, [r0, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x01
	cmp r1, r3
	ble _080DA33A
	adds r1, r3, #0x0
_080DA33A:
	movs r4, #0xB0
	lsls r4, r4, #0x01
	adds r0, r6, r4
	ldr r2, [r0, #0x00]
	cmp r2, r3
	ble _080DA348
	adds r2, r3, #0x0
_080DA348:
	movs r0, #0x00
	movs r3, #0x00
	bl AllocObjAffine
	adds r5, r0, #0x0
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r7, #0x04]
	ldr r3, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	adds r0, r6, #0x0
	adds r0, #0x14
	bl AnimGetGfx
	adds r2, r0, #0x0
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r3, #0xB2
	lsls r3, r3, #0x01
	adds r1, r6, r3
	ldr r1, [r1, #0x00]
	asrs r1, r1, #0x08
	ldrh r4, [r4, #0x00]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r3, [r6, #0x08]
	mov r4, r8
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	mov r4, r9
	str r4, [sp, #0x008]
	ldr r5, [r7, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r7, _080DA3C0 @ =0xFFFFEFFC
	adds r4, r7, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	adds r0, r6, #0x0
	adds r0, #0x2C
	bl TaskPoolDraw
_080DA3B2:
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080DA3C0: .4byte 0xFFFFEFFC
.syntax divided
