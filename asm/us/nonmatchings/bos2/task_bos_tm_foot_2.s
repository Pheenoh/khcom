.syntax unified
	.align 2, 0
	.global task_bos_tm_foot_2
	.thumb
	.thumb_func
	.type task_bos_tm_foot_2, %function
task_bos_tm_foot_2: @ 080BAFA4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x01C
	adds r7, r0, #0x0
	ldr r1, _080BAFE0 @ =0x0000047C
	adds r0, r7, r1
	ldr r0, [r0, #0x00]
	ldrh r1, [r0, #0x28]
	movs r0, #0x20
	ands r0, r1
	ldr r2, _080BAFE4 @ =0x00000801
	str r2, [sp, #0x018]
	cmp r0, #0x00
	beq _080BAFCC
	movs r3, #0x80
	lsls r3, r3, #0x04
	str r3, [sp, #0x018]
_080BAFCC:
	ldr r0, _080BAFE8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080BAFEC
	ldr r4, [r7, #0x14]
	mov r10, r4
	b _080BB010
	.byte 0x00, 0x00
_080BAFE0: .4byte 0x0000047C
_080BAFE4: .4byte 0x00000801
_080BAFE8: .4byte 0x02039B84
_080BAFEC:
	movs r2, #0x01
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _080BB00C
	ldr r0, _080BB008 @ =0x03007480
	ldr r0, [r0, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _080BB00C
	ldr r5, [r7, #0x18]
	mov r10, r5
	b _080BB010
	.byte 0x00, 0x00
_080BB008: .4byte 0x03007480
_080BB00C:
	ldr r6, [r7, #0x14]
	mov r10, r6
_080BB010:
	adds r4, r7, #0x0
	adds r4, #0x1C
	movs r0, #0x9A
	lsls r0, r0, #0x01
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0x93
	lsls r1, r1, #0x02
	adds r1, r1, r7
	mov r9, r1
	movs r2, #0xD9
	lsls r2, r2, #0x02
	adds r2, r7, r2
	str r2, [sp, #0x014]
	mov r6, sp
	adds r6, #0x12
	ldr r2, [r4, #0x04]
	ldr r3, [r4, #0x08]
	ldr r0, [r4, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r3, #0x00
	ldsh r0, [r0, r3]
	movs r5, #0x00
	ldsh r1, [r6, r5]
	movs r3, #0x96
	lsls r3, r3, #0x01
	adds r2, r7, r3
	ldr r2, [r2, #0x00]
	ldr r3, [r7, #0x0C]
	mov r5, r10
	str r5, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	ldr r5, [sp, #0x018]
	str r5, [sp, #0x008]
	ldr r4, [r4, #0x08]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	mov r12, r4
	ldr r4, _080BB16C @ =0xFFFFEFFC
	adds r5, r4, #0x0
	mov r4, r12
	subs r4, r5, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
	mov r0, r8
	ldr r2, [r0, #0x04]
	ldr r3, [r0, #0x08]
	ldr r0, [r0, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	movs r3, #0x91
	lsls r3, r3, #0x02
	adds r2, r7, r3
	ldr r2, [r2, #0x00]
	ldr r4, [r7, #0x10]
	mov r12, r4
	mov r3, r10
	str r3, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	ldr r3, [sp, #0x018]
	str r3, [sp, #0x008]
	mov r4, r8
	ldr r4, [r4, #0x08]
	mov r8, r4
	mov r3, r8
	asrs r3, r3, #0x08
	lsls r4, r3, #0x02
	subs r4, r5, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	mov r3, r12
	bl func_080023E0
	mov r4, r9
	ldr r2, [r4, #0x04]
	ldr r3, [r4, #0x08]
	ldr r0, [r4, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	movs r3, #0xD7
	lsls r3, r3, #0x02
	adds r2, r7, r3
	ldr r2, [r2, #0x00]
	ldr r4, [r7, #0x08]
	mov r12, r4
	mov r3, r10
	str r3, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	ldr r3, [sp, #0x018]
	str r3, [sp, #0x008]
	mov r4, r9
	ldr r4, [r4, #0x08]
	mov r8, r4
	mov r3, r8
	asrs r3, r3, #0x08
	lsls r4, r3, #0x02
	subs r4, r5, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	mov r3, r12
	bl func_080023E0
	ldr r4, [sp, #0x014]
	ldr r2, [r4, #0x04]
	ldr r3, [r4, #0x08]
	ldr r0, [r4, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	ldr r3, _080BB170 @ =0x00000474
	adds r2, r7, r3
	ldr r2, [r2, #0x00]
	ldr r3, [r7, #0x08]
	mov r4, r10
	str r4, [sp, #0x000]
	movs r6, #0x00
	str r6, [sp, #0x004]
	ldr r4, [sp, #0x018]
	str r4, [sp, #0x008]
	ldr r6, [sp, #0x014]
	ldr r4, [r6, #0x08]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	subs r5, r5, r4
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r5, [sp, #0x00C]
	bl func_080023E0
	add sp, #0x01C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080BB16C: .4byte 0xFFFFEFFC
_080BB170: .4byte 0x00000474
.syntax divided
