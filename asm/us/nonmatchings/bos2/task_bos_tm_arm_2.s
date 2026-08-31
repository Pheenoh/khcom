.syntax unified
	.align 2, 0
	.global task_bos_tm_arm_2
	.thumb
	.thumb_func
	.type task_bos_tm_arm_2, %function
task_bos_tm_arm_2: @ 080BC940
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x020
	adds r7, r0, #0x0
	ldr r0, _080BC960 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080BC964
	ldr r0, [r7, #0x04]
	mov r9, r0
	b _080BC98C
_080BC960: .4byte 0x02039B84
_080BC964:
	ldr r0, [r7, #0x0C]
	ldr r0, [r0, #0x18]
	ldrh r1, [r0, #0x28]
	movs r2, #0x01
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _080BC988
	ldr r0, _080BC984 @ =0x03007480
	ldr r0, [r0, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _080BC988
	ldr r1, [r7, #0x08]
	mov r9, r1
	b _080BC98C
_080BC984: .4byte 0x03007480
_080BC988:
	ldr r2, [r7, #0x04]
	mov r9, r2
_080BC98C:
	movs r3, #0x00
	str r3, [sp, #0x014]
	mov r4, sp
	adds r4, #0x12
	str r4, [sp, #0x018]
	adds r5, r7, #0x0
	adds r5, #0xAC
	str r5, [sp, #0x01C]
	movs r6, #0x80
	lsls r6, r6, #0x01
	mov r10, r6
	mov r8, r4
_080BC9A4:
	movs r0, #0x34
	ldr r1, [sp, #0x014]
	adds r5, r1, #0x0
	muls r5, r0
	adds r0, r5, #0x0
	adds r0, #0xE0
	adds r4, r7, r0
	ldrb r0, [r4, #0x08]
	mov r1, r10
	mov r2, r10
	movs r3, #0x00
	bl AllocObjAffine
	adds r6, r0, #0x0
	ldr r1, [r7, #0x0C]
	ldr r2, [r1, #0x00]
	ldr r0, [r4, #0x00]
	adds r2, r2, r0
	ldr r3, [r1, #0x04]
	ldr r0, [r1, #0x08]
	ldr r1, [r4, #0x04]
	adds r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	mov r3, r8
	movs r2, #0x00
	ldsh r1, [r3, r2]
	ldr r2, [r4, #0x30]
	ldr r3, [r7, #0x00]
	mov r4, r9
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	movs r6, #0x80
	lsls r6, r6, #0x04
	str r6, [sp, #0x008]
	ldr r4, [r7, #0x0C]
	ldr r4, [r4, #0x04]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r6, _080BCB68 @ =0xFFFFEFFC
	subs r4, r6, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	adds r5, #0x10
	adds r4, r7, r5
	ldrb r0, [r4, #0x08]
	mov r1, r10
	mov r2, r10
	movs r3, #0x00
	bl AllocObjAffine
	adds r6, r0, #0x0
	ldr r1, [r7, #0x0C]
	ldr r2, [r1, #0x0C]
	ldr r0, [r4, #0x00]
	adds r2, r2, r0
	ldr r3, [r1, #0x10]
	ldr r0, [r1, #0x14]
	ldr r1, [r4, #0x04]
	adds r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r2, [r4, #0x30]
	ldr r3, [r7, #0x00]
	mov r4, r9
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	movs r5, #0x80
	lsls r5, r5, #0x04
	str r5, [sp, #0x008]
	ldr r4, [r7, #0x0C]
	ldr r4, [r4, #0x10]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r6, _080BCB68 @ =0xFFFFEFFC
	subs r4, r6, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	ldr r0, [sp, #0x014]
	adds r0, #0x01
	str r0, [sp, #0x014]
	cmp r0, #0x02
	ble _080BC9A4
	ldr r0, [r7, #0x0C]
	ldr r0, [r0, #0x18]
	ldrh r1, [r0, #0x28]
	movs r0, #0x20
	ands r0, r1
	ldr r1, _080BCB6C @ =0xFFFFFF00
	mov r10, r1
	cmp r0, #0x00
	beq _080BCA8C
	movs r2, #0x80
	lsls r2, r2, #0x01
	mov r10, r2
_080BCA8C:
	movs r3, #0xBE
	lsls r3, r3, #0x01
	adds r4, r7, r3
	ldrb r0, [r4, #0x08]
	movs r5, #0x80
	lsls r5, r5, #0x01
	mov r8, r5
	mov r1, r10
	mov r2, r8
	movs r3, #0x00
	bl AllocObjAffine
	adds r6, r0, #0x0
	ldr r1, [r7, #0x0C]
	ldr r2, [r1, #0x00]
	ldr r0, [r4, #0x00]
	adds r2, r2, r0
	ldr r3, [r1, #0x04]
	ldr r0, [r1, #0x08]
	ldr r1, [r4, #0x04]
	adds r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	ldr r1, [sp, #0x018]
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, [sp, #0x018]
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r2, [r4, #0x30]
	ldr r3, [r7, #0x00]
	mov r4, r9
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	movs r5, #0x80
	lsls r5, r5, #0x04
	str r5, [sp, #0x008]
	ldr r4, [r7, #0x0C]
	ldr r4, [r4, #0x04]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r6, _080BCB68 @ =0xFFFFEFFC
	adds r5, r6, #0x0
	subs r4, r5, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	ldr r4, [sp, #0x01C]
	ldrb r0, [r4, #0x08]
	mov r1, r10
	mov r2, r8
	movs r3, #0x00
	bl AllocObjAffine
	adds r6, r0, #0x0
	ldr r1, [r7, #0x0C]
	ldr r2, [r1, #0x0C]
	ldr r0, [r4, #0x00]
	adds r2, r2, r0
	ldr r3, [r1, #0x10]
	ldr r0, [r1, #0x14]
	ldr r1, [r4, #0x04]
	adds r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	ldr r1, [sp, #0x018]
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, [sp, #0x018]
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r2, [r4, #0x30]
	ldr r3, [r7, #0x00]
	mov r4, r9
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	movs r6, #0x80
	lsls r6, r6, #0x04
	str r6, [sp, #0x008]
	ldr r4, [r7, #0x0C]
	ldr r4, [r4, #0x10]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	subs r5, r5, r4
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r5, [sp, #0x00C]
	bl DrawSprite
	movs r1, #0xDA
	lsls r1, r1, #0x01
	adds r0, r7, r1
	bl TaskPoolDraw
	add sp, #0x020
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080BCB68: .4byte 0xFFFFEFFC
_080BCB6C: .4byte 0xFFFFFF00
.syntax divided
