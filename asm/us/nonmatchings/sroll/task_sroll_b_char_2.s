.syntax unified
	.align 2, 0
	.global task_sroll_b_char_2
	.thumb
	.thumb_func
	.type task_sroll_b_char_2, %function
task_sroll_b_char_2: @ 08114B84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r6, r0, #0x0
	ldr r7, [r6, #0x08]
	ldrh r1, [r7, #0x14]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	bne _08114BF0
	ldr r5, [r7, #0x04]
	lsls r5, r5, #0x08
	lsrs r5, r5, #0x10
	ldr r4, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	adds r4, r4, r0
	lsls r4, r4, #0x08
	lsrs r4, r4, #0x10
	adds r0, r6, #0x0
	adds r0, #0x14
	bl AnimGetGfx
	mov r8, r0
	adds r0, r7, #0x0
	adds r0, #0x28
	ldrb r0, [r0, #0x00]
	ldr r1, [r7, #0x20]
	ldr r2, [r7, #0x24]
	movs r3, #0x01
	bl AllocObjAffine
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r3, [r6, #0x0C]
	ldr r1, [r6, #0x10]
	str r1, [sp, #0x000]
	str r0, [sp, #0x004]
	ldrh r0, [r7, #0x16]
	str r0, [sp, #0x008]
	movs r0, #0xFF
	lsls r0, r0, #0x04
	str r0, [sp, #0x00C]
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	mov r2, r8
	bl DrawSprite
	adds r0, r6, #0x0
	adds r0, #0x2C
	bl TaskPoolDraw
_08114BF0:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
