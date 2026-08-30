.syntax unified
	.align 2, 0
	.global task_hum_lex_tmh0_2
	.thumb
	.thumb_func
	.type task_hum_lex_tmh0_2, %function
task_hum_lex_tmh0_2: @ 08057364
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	adds r0, #0x08
	bl func_08005AFC
	mov r8, r0
	ldr r0, [r6, #0x24]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r2, [r6, #0x30]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _0805739A
	adds r0, r6, #0x0
	adds r0, #0x2C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080573A6
	movs r0, #0x01
	orrs r7, r0
	b _080573A6
_0805739A:
	adds r0, r6, #0x0
	adds r0, #0x2C
	ldrb r0, [r0, #0x00]
	negs r1, r2
	cmp r0, #0x00
	beq _080573A8
_080573A6:
	adds r1, r2, #0x0
_080573A8:
	movs r2, #0x80
	lsls r2, r2, #0x01
	movs r0, #0x00
	movs r3, #0x00
	bl func_08002CB4
	adds r5, r0, #0x0
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r6, #0x20]
	ldr r3, [r6, #0x24]
	ldr r0, [r6, #0x28]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r3, [r6, #0x00]
	ldr r2, [r6, #0x04]
	str r2, [sp, #0x000]
	str r5, [sp, #0x004]
	str r7, [sp, #0x008]
	ldr r4, [r6, #0x24]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r5, _08057404 @ =0xFFFFEFF4
	adds r2, r5, #0x0
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	mov r2, r8
	bl func_080023E0
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08057404: .4byte 0xFFFFEFF4
.syntax divided
