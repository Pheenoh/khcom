.syntax unified
	.align 2, 0
	.global task_hum_lex_rock_2
	.thumb
	.thumb_func
	.type task_hum_lex_rock_2, %function
task_hum_lex_rock_2: @ 080578D0
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	adds r6, r0, #0x0
	movs r1, #0xB0
	lsls r1, r1, #0x02
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080578FC
	movs r2, #0xB3
	lsls r2, r2, #0x01
	adds r0, r6, r2
	ldrh r1, [r0, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080578FC
	b _08057A82
_080578FC:
	movs r3, #0xB2
	lsls r3, r3, #0x01
	adds r1, r6, r3
	ldrh r0, [r1, #0x00]
	cmp r0, #0x01
	bne _0805799C
	adds r0, r6, #0x0
	adds r0, #0x34
	bl func_08005AFC
	str r0, [sp, #0x014]
	movs r4, #0xB0
	lsls r4, r4, #0x01
	adds r0, r6, r4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0805792C
	movs r5, #0xAC
	lsls r5, r5, #0x01
	adds r0, r6, r5
	ldr r0, [r0, #0x00]
	bl func_0801AF1C
	b _0805793C
_0805792C:
	movs r1, #0xAC
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	bl func_0801AF1C
	movs r1, #0x01
	orrs r0, r1
_0805793C:
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r4, sp
	adds r4, #0x12
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r0, r6, r2
	ldr r2, [r0, #0x00]
	movs r3, #0xAC
	lsls r3, r3, #0x01
	adds r5, r6, r3
	ldr r3, [r5, #0x00]
	movs r1, #0xAE
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r3, #0x00
	ldsh r1, [r4, r3]
	ldr r3, [r6, #0x00]
	ldr r2, [r6, #0x30]
	str r2, [sp, #0x000]
	movs r2, #0x00
	str r2, [sp, #0x004]
	str r7, [sp, #0x008]
	ldr r4, [r5, #0x00]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r5, _08057998 @ =0xFFFFEFFA
	adds r2, r5, #0x0
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	ldr r2, [sp, #0x014]
	bl func_080023E0
	b _08057A82
	.byte 0x00, 0x00
_08057998: .4byte 0xFFFFEFFA
_0805799C:
	cmp r0, #0x0C
	bne _08057A82
	movs r0, #0x00
	mov r10, r0
	ldrh r1, [r1, #0x00]
	cmp r10, r1
	bge _08057A82
	movs r1, #0x12
	add r1, sp
	mov r8, r1
	movs r2, #0xB6
	lsls r2, r2, #0x01
	adds r5, r6, r2
	movs r3, #0x34
	adds r3, r3, r6
	mov r9, r3
_080579BC:
	mov r0, r9
	bl func_08005AFC
	str r0, [sp, #0x014]
	movs r4, #0xB0
	lsls r4, r4, #0x01
	adds r0, r6, r4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080579D8
	ldr r0, [r5, #0x04]
	bl func_0801AF1C
	b _080579E2
_080579D8:
	ldr r0, [r5, #0x04]
	bl func_0801AF1C
	movs r1, #0x01
	orrs r0, r1
_080579E2:
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r2, [r5, #0x00]
	ldr r3, [r5, #0x04]
	ldr r0, [r5, #0x08]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	mov r4, r10
	lsls r2, r4, #0x02
	adds r2, r6, r2
	ldr r3, [r2, #0x00]
	ldr r2, [r6, #0x30]
	str r2, [sp, #0x000]
	movs r2, #0x00
	str r2, [sp, #0x004]
	str r7, [sp, #0x008]
	ldr r4, [r5, #0x04]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	mov r12, r4
	ldr r4, _08057A94 @ =0xFFFFEFFA
	adds r2, r4, #0x0
	mov r4, r12
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	ldr r2, [sp, #0x014]
	bl func_080023E0
	ldr r2, [r5, #0x00]
	ldr r3, [r5, #0x04]
	movs r0, #0x00
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	movs r4, #0xAE
	lsls r4, r4, #0x02
	adds r2, r6, r4
	ldr r3, [r2, #0x00]
	adds r4, #0x04
	adds r2, r6, r4
	ldr r2, [r2, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	str r2, [sp, #0x004]
	str r7, [sp, #0x008]
	ldr r2, _08057A98 @ =0x0000FFFE
	str r2, [sp, #0x00C]
	ldr r2, _08057A9C @ =0x08B22CBC
	bl func_080023E0
	adds r5, #0x1C
	movs r3, #0x18
	add r9, r3
	movs r4, #0x01
	add r10, r4
	movs r1, #0xB2
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldrh r0, [r0, #0x00]
	cmp r10, r0
	blt _080579BC
_08057A82:
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08057A94: .4byte 0xFFFFEFFA
_08057A98: .4byte 0x0000FFFE
_08057A9C: .4byte 0x08B22CBC
.syntax divided
