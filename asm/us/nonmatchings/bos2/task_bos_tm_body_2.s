.syntax unified
	.align 2, 0
	.global task_bos_tm_body_2
	.thumb
	.thumb_func
	.type task_bos_tm_body_2, %function
task_bos_tm_body_2: @ 080B9D50
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x024
	adds r7, r0, #0x0
	ldr r0, [r7, #0x00]
	ldrh r1, [r0, #0x28]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	beq _080B9D9E
	movs r1, #0x94
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x01
	adds r1, r4, #0x0
	adds r2, r4, #0x0
	movs r3, #0x01
	bl AllocObjAffine
	str r0, [sp, #0x018]
	movs r2, #0x91
	lsls r2, r2, #0x02
	adds r0, r7, r2
	ldrb r0, [r0, #0x00]
	adds r1, r4, #0x0
	adds r2, r4, #0x0
	movs r3, #0x01
	bl AllocObjAffine
	str r0, [sp, #0x01C]
	movs r3, #0x80
	lsls r3, r3, #0x04
	str r3, [sp, #0x020]
	b _080B9DD0
_080B9D9E:
	movs r4, #0x94
	lsls r4, r4, #0x01
	adds r0, r7, r4
	ldrb r0, [r0, #0x00]
	ldr r4, _080B9DE4 @ =0xFFFFFF00
	movs r5, #0x80
	lsls r5, r5, #0x01
	adds r1, r4, #0x0
	adds r2, r5, #0x0
	movs r3, #0x01
	bl AllocObjAffine
	str r0, [sp, #0x018]
	movs r6, #0x91
	lsls r6, r6, #0x02
	adds r0, r7, r6
	ldrb r0, [r0, #0x00]
	adds r1, r4, #0x0
	adds r2, r5, #0x0
	movs r3, #0x01
	bl AllocObjAffine
	str r0, [sp, #0x01C]
	ldr r0, _080B9DE8 @ =0x00000801
	str r0, [sp, #0x020]
_080B9DD0:
	ldr r0, _080B9DEC @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080B9DF0
	ldr r1, [r7, #0x08]
	mov r10, r1
	b _080B9E1E
	.byte 0x00, 0x00
_080B9DE4: .4byte 0xFFFFFF00
_080B9DE8: .4byte 0x00000801
_080B9DEC: .4byte 0x02039B84
_080B9DF0:
	ldr r0, [r7, #0x00]
	ldrh r1, [r0, #0x28]
	movs r2, #0x01
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _080B9E1A
	ldr r0, _080B9E10 @ =0x03007480
	ldr r0, [r0, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _080B9E14
	ldr r2, [r7, #0x0C]
	mov r10, r2
	b _080B9E1E
	.byte 0x00, 0x00
_080B9E10: .4byte 0x03007480
_080B9E14:
	ldr r3, [r7, #0x08]
	mov r10, r3
	b _080B9E1E
_080B9E1A:
	ldr r4, [r7, #0x08]
	mov r10, r4
_080B9E1E:
	adds r4, r7, #0x0
	adds r4, #0x10
	movs r5, #0x96
	lsls r5, r5, #0x01
	adds r5, r5, r7
	mov r8, r5
	movs r6, #0x92
	lsls r6, r6, #0x02
	adds r6, r6, r7
	mov r9, r6
	movs r0, #0xD9
	lsls r0, r0, #0x02
	adds r0, r7, r0
	str r0, [sp, #0x014]
	mov r6, sp
	adds r6, #0x12
	ldr r2, [r4, #0x04]
	ldr r3, [r4, #0x08]
	ldr r0, [r4, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	movs r3, #0x92
	lsls r3, r3, #0x01
	adds r2, r7, r3
	ldr r2, [r2, #0x00]
	ldr r3, [r7, #0x04]
	mov r5, r10
	str r5, [sp, #0x000]
	ldr r5, [sp, #0x018]
	str r5, [sp, #0x004]
	movs r5, #0x80
	lsls r5, r5, #0x04
	str r5, [sp, #0x008]
	ldr r5, [r4, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	mov r12, r5
	ldr r5, _080B9F84 @ =0xFFFFEFFB
	adds r4, r5, #0x0
	mov r5, r12
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	mov r0, r8
	ldr r2, [r0, #0x04]
	ldr r3, [r0, #0x08]
	ldr r0, [r0, #0x0C]
	ldr r1, _080B9F88 @ =0xFFFFE700
	adds r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r3, #0x00
	ldsh r1, [r6, r3]
	movs r4, #0x90
	lsls r4, r4, #0x02
	adds r2, r7, r4
	ldr r2, [r2, #0x00]
	ldr r3, [r7, #0x04]
	mov r5, r10
	str r5, [sp, #0x000]
	ldr r4, [sp, #0x01C]
	str r4, [sp, #0x004]
	movs r5, #0x80
	lsls r5, r5, #0x04
	str r5, [sp, #0x008]
	mov r5, r8
	ldr r4, [r5, #0x08]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	mov r8, r4
	ldr r4, _080B9F8C @ =0xFFFFEFFC
	adds r5, r4, #0x0
	mov r4, r8
	subs r4, r5, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	mov r0, r9
	ldr r2, [r0, #0x04]
	ldr r3, [r0, #0x08]
	ldr r0, [r0, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	movs r3, #0xD7
	lsls r3, r3, #0x02
	adds r2, r7, r3
	ldr r2, [r2, #0x00]
	ldr r4, [r7, #0x04]
	mov r12, r4
	mov r3, r10
	str r3, [sp, #0x000]
	movs r4, #0x00
	mov r8, r4
	str r4, [sp, #0x004]
	ldr r3, [sp, #0x020]
	str r3, [sp, #0x008]
	mov r4, r9
	ldr r4, [r4, #0x08]
	mov r9, r4
	mov r3, r9
	asrs r3, r3, #0x08
	lsls r4, r3, #0x02
	subs r4, r5, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	mov r3, r12
	bl DrawSprite
	ldr r4, [sp, #0x014]
	ldr r2, [r4, #0x04]
	ldr r3, [r4, #0x08]
	ldr r0, [r4, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	movs r3, #0x8F
	lsls r3, r3, #0x03
	adds r2, r7, r3
	ldr r2, [r2, #0x00]
	ldr r3, [r7, #0x04]
	mov r4, r10
	str r4, [sp, #0x000]
	mov r6, r8
	str r6, [sp, #0x004]
	ldr r4, [sp, #0x020]
	str r4, [sp, #0x008]
	ldr r6, [sp, #0x014]
	ldr r4, [r6, #0x08]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	subs r5, r5, r4
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r5, [sp, #0x00C]
	bl DrawSprite
	add sp, #0x024
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080B9F84: .4byte 0xFFFFEFFB
_080B9F88: .4byte 0xFFFFE700
_080B9F8C: .4byte 0xFFFFEFFC
.syntax divided
