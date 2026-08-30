.syntax unified
	.align 2, 0
	.global task_hum_lex_tmh_2
	.thumb
	.thumb_func
	.type task_hum_lex_tmh_2, %function
task_hum_lex_tmh_2: @ 08057184
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	adds r0, #0x08
	bl func_08005AFC
	mov r8, r0
	adds r0, r6, #0x0
	adds r0, #0x2C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080571A8
	ldr r0, [r6, #0x24]
	bl func_0801AF1C
	b _080571B2
_080571A8:
	ldr r0, [r6, #0x24]
	bl func_0801AF1C
	movs r1, #0x01
	orrs r0, r1
_080571B2:
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r5, sp
	adds r5, #0x12
	ldr r2, [r6, #0x20]
	ldr r3, [r6, #0x24]
	ldr r0, [r6, #0x28]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r5, r2]
	ldr r3, [r6, #0x00]
	ldr r2, [r6, #0x04]
	str r2, [sp, #0x000]
	movs r2, #0x00
	str r2, [sp, #0x004]
	str r7, [sp, #0x008]
	ldr r4, [r6, #0x24]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	mov r12, r4
	ldr r4, _08057208 @ =0xFFFFEFFC
	adds r2, r4, #0x0
	mov r4, r12
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	mov r2, r8
	bl func_080023E0
	ldr r1, [r6, #0x28]
	adds r4, r5, #0x0
	cmp r1, #0x00
	blt _0805720C
	movs r5, #0x00
	b _0805722E
_08057208: .4byte 0xFFFFEFFC
_0805720C:
	negs r1, r1
	cmp r1, #0x00
	bge _08057214
	adds r1, #0xFF
_08057214:
	asrs r1, r1, #0x08
	movs r0, #0x80
	lsls r0, r0, #0x01
	subs r2, r0, r1
	cmp r2, #0x4B
	bgt _08057222
	movs r2, #0x4C
_08057222:
	movs r0, #0x00
	adds r1, r2, #0x0
	movs r3, #0x00
	bl func_08002CB4
	adds r5, r0, #0x0
_0805722E:
	ldr r2, [r6, #0x20]
	ldr r3, [r6, #0x24]
	movs r0, #0x00
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, _08057268 @ =0x08B22BA8
	ldr r3, [r6, #0x40]
	ldr r4, [r6, #0x44]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	str r7, [sp, #0x008]
	ldr r4, _0805726C @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl func_080023E0
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08057268: .4byte 0x08B22BA8
_0805726C: .4byte 0x0000FFF0
.syntax divided
