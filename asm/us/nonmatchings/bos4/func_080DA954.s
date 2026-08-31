.syntax unified
	.align 2, 0
	.global func_080DA954
	.thumb
	.thumb_func
	.type func_080DA954, %function
func_080DA954: @ 080DA954
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	add sp, #-0x014
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	lsls r6, r2, #0x10
	lsrs r6, r6, #0x10
	movs r0, #0x12
	add r0, sp
	mov r8, r0
	ldr r3, _080DA9C0 @ =0x00023F00
	ldr r0, _080DA9C4 @ =0xFFFFE000
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	adds r2, r4, #0x0
	bl WorldToScreen
	adds r0, r5, #0x0
	adds r0, #0x08
	bl AnimGetGfx
	adds r2, r0, #0x0
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r3, r8
	ldrh r1, [r3, #0x00]
	adds r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r6, [sp, #0x008]
	movs r4, #0xE7
	lsls r4, r4, #0x08
	str r4, [sp, #0x00C]
	bl DrawSprite
	adds r5, #0x28
	adds r0, r5, #0x0
	bl TaskPoolDraw
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DA9C0: .4byte 0x00023F00
_080DA9C4: .4byte 0xFFFFE000
.syntax divided
