.syntax unified
	.align 2, 0
	.global task_bos_jf_borderline_2
	.thumb
	.thumb_func
	.type task_bos_jf_borderline_2, %function
task_bos_jf_borderline_2: @ 080C15BC
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	mov r4, sp
	adds r4, #0x12
	adds r0, #0x98
	ldr r2, [r0, #0x00]
	adds r0, #0x04
	ldr r3, [r0, #0x00]
	adds r0, #0x04
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	adds r0, r7, #0x0
	adds r0, #0xB5
	ldrb r6, [r0, #0x00]
	mov r9, r4
	cmp r6, #0x00
	beq _080C15F8
	cmp r6, #0x01
	bne _080C15F6
	b _080C1770
_080C15F6:
	b _080C19EA
_080C15F8:
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	subs r0, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	subs r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x0C]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	movs r5, #0x80
	lsls r5, r5, #0x03
	str r5, [sp, #0x008]
	ldr r4, _080C1768 @ =0x0000FFF0
	mov r10, r4
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	subs r0, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	subs r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	mov r4, r10
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	mov r4, r10
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	adds r0, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	subs r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	mov r4, r10
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	adds r0, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	subs r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x10]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	mov r4, r10
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	subs r0, #0x08
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x04
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x0C]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	mov r4, r10
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	subs r0, #0x08
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x04
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _080C176C @ =0x0000FF60
	mov r8, r4
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	adds r0, #0x08
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x04
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	mov r4, r8
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	adds r0, #0x08
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x04
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x10]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	mov r4, r10
	str r4, [sp, #0x00C]
	bl DrawSprite
	b _080C19EA
	.byte 0x00, 0x00
_080C1768: .4byte 0x0000FFF0
_080C176C: .4byte 0x0000FF60
_080C1770:
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	subs r0, #0x28
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	subs r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x0C]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	movs r4, #0x00
	mov r10, r4
	str r4, [sp, #0x004]
	movs r5, #0x80
	lsls r5, r5, #0x03
	str r5, [sp, #0x008]
	ldr r4, _080C1A28 @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	subs r0, #0x28
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	subs r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _080C1A28 @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	subs r0, #0x18
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _080C1A28 @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	subs r0, #0x08
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x02
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _080C1A28 @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	adds r0, #0x08
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x02
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _080C1A28 @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	adds r0, #0x18
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _080C1A28 @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	adds r0, #0x28
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	subs r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _080C1A28 @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	adds r0, #0x28
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	subs r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x10]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _080C1A28 @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	subs r0, #0x20
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x04
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x0C]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _080C1A28 @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	subs r0, #0x20
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x04
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _080C1A2C @ =0x0000FF60
	mov r8, r4
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	subs r0, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x06
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	mov r4, r8
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x07
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	mov r4, r8
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	adds r0, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x06
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	mov r4, r8
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	adds r0, #0x20
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x04
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	mov r4, r8
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	adds r0, #0x20
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	subs r1, #0x04
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x10]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _080C1A28 @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl DrawSprite
_080C19EA:
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r9
	ldrh r1, [r2, #0x00]
	subs r1, #0x08
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x7C]
	ldr r3, [r7, #0x04]
	ldr r4, [r7, #0x08]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x03
	str r4, [sp, #0x008]
	movs r4, #0xFF
	lsls r4, r4, #0x08
	str r4, [sp, #0x00C]
	bl DrawSprite
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C1A28: .4byte 0x0000FFF0
_080C1A2C: .4byte 0x0000FF60
.syntax divided
