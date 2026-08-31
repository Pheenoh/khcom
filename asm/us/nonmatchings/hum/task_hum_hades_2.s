.syntax unified
	.align 2, 0
	.global task_hum_hades_2
	.thumb
	.thumb_func
	.type task_hum_hades_2, %function
task_hum_hades_2: @ 0804F6D8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x020
	adds r7, r0, #0x0
	bl func_0800EFE8
	movs r1, #0xE5
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	bne _0804F6FC
	b _0804F894
_0804F6FC:
	adds r2, r7, #0x0
	adds r2, #0x40
	str r2, [sp, #0x014]
	movs r3, #0x12
	add r3, sp
	mov r10, r3
	movs r4, #0x8A
	lsls r4, r4, #0x02
	adds r4, r7, r4
	str r4, [sp, #0x01C]
	movs r0, #0x8B
	lsls r0, r0, #0x02
	adds r6, r7, r0
	movs r1, #0x01
	str r1, [sp, #0x018]
_0804F71A:
	ldr r0, [r6, #0x00]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r2, #0x9F
	lsls r2, r2, #0x02
	adds r0, r7, r2
	ldr r3, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r3, r0
	bne _0804F752
	ldr r4, [sp, #0x014]
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0804F766
	movs r0, #0x01
	mov r1, r8
	orrs r1, r0
	mov r8, r1
	b _0804F766
_0804F752:
	ldr r2, [sp, #0x014]
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	negs r1, r3
	cmp r0, #0x00
	bne _0804F768
_0804F766:
	adds r1, r3, #0x0
_0804F768:
	movs r3, #0x9F
	lsls r3, r3, #0x02
	adds r0, r7, r3
	ldr r2, [r0, #0x00]
	movs r0, #0x00
	movs r3, #0x00
	bl AllocObjAffine
	mov r9, r0
	movs r4, #0xF0
	lsls r4, r4, #0x01
	adds r0, r7, r4
	bl AnimGetGfx
	adds r5, r0, #0x0
	ldr r2, [r6, #0x04]
	ldr r3, [r6, #0x08]
	ldr r0, [r6, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r10
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r10
	movs r3, #0x00
	ldsh r1, [r2, r3]
	subs r4, #0x0C
	adds r2, r7, r4
	ldr r3, [r2, #0x00]
	ldr r4, [sp, #0x01C]
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	mov r2, r9
	str r2, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r4, [r6, #0x00]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	mov r12, r4
	ldr r4, _0804F8A4 @ =0xFFFFEFFB
	adds r2, r4, #0x0
	mov r4, r12
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	adds r2, r5, #0x0
	bl DrawSprite
	movs r1, #0xFC
	lsls r1, r1, #0x01
	adds r0, r7, r1
	bl AnimGetGfx
	adds r5, r0, #0x0
	ldr r2, [r6, #0x10]
	ldr r3, [r6, #0x14]
	ldr r0, [r6, #0x18]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r10
	bl WorldToScreen
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	mov r3, r10
	movs r4, #0x00
	ldsh r1, [r3, r4]
	movs r3, #0xEC
	lsls r3, r3, #0x01
	adds r2, r7, r3
	ldr r3, [r2, #0x00]
	ldr r4, [sp, #0x01C]
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	mov r2, r9
	str r2, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r4, [r6, #0x00]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	mov r12, r4
	ldr r4, _0804F8A8 @ =0xFFFFEFFA
	adds r2, r4, #0x0
	mov r4, r12
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	adds r2, r5, #0x0
	bl DrawSprite
	movs r1, #0x84
	lsls r1, r1, #0x02
	adds r0, r7, r1
	bl AnimGetGfx
	adds r5, r0, #0x0
	ldr r2, [r6, #0x1C]
	ldr r3, [r6, #0x20]
	ldr r0, [r6, #0x24]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r10
	bl WorldToScreen
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	mov r3, r10
	movs r4, #0x00
	ldsh r1, [r3, r4]
	movs r3, #0xEE
	lsls r3, r3, #0x01
	adds r2, r7, r3
	ldr r3, [r2, #0x00]
	ldr r4, [sp, #0x01C]
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	mov r2, r9
	str r2, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r4, [r6, #0x00]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	mov r8, r4
	ldr r4, _0804F8AC @ =0xFFFFEFF9
	adds r2, r4, #0x0
	mov r4, r8
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	adds r2, r5, #0x0
	bl DrawSprite
	adds r6, #0x28
	ldr r0, [sp, #0x018]
	subs r0, #0x01
	str r0, [sp, #0x018]
	cmp r0, #0x00
	blt _0804F894
	b _0804F71A
_0804F894:
	add sp, #0x020
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0804F8A4: .4byte 0xFFFFEFFB
_0804F8A8: .4byte 0xFFFFEFFA
_0804F8AC: .4byte 0xFFFFEFF9
.syntax divided
