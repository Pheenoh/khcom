.syntax unified
	.align 2, 0
	.global task_bos_lst_lsr_2
	.thumb
	.thumb_func
	.type task_bos_lst_lsr_2, %function
task_bos_lst_lsr_2: @ 08111870
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x020
	adds r7, r0, #0x0
	movs r1, #0x00
	ldsh r0, [r7, r1]
	cmp r0, #0x02
	beq _0811188C
	cmp r0, #0x03
	beq _08111950
	b _081119CA
_0811188C:
	mov r2, sp
	adds r2, #0x12
	str r2, [sp, #0x01C]
	ldr r2, [r7, #0x30]
	ldr r3, [r7, #0x34]
	ldr r0, [r7, #0x38]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	ldr r1, [sp, #0x01C]
	bl func_0801909C
	ldr r0, [r7, #0x34]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	ldr r1, [r7, #0x34]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r3, _08111948 @ =0xFFFFEFFC
	adds r0, r3, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x018]
	add r4, sp, #0x014
	movs r5, #0x16
	add r5, sp
	mov r8, r5
	ldr r2, [r7, #0x24]
	ldr r3, [r7, #0x28]
	ldr r0, [r7, #0x2C]
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	mov r1, r8
	bl func_0801909C
	ldrb r0, [r7, #0x02]
	movs r1, #0x01
	bl func_08002C28
	mov r10, r0
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x10
	ldsh r5, [r7, r3]
	muls r0, r5
	movs r1, #0x14
	ldsh r6, [r7, r1]
	adds r1, r6, #0x0
	bl func_0811D5EC
	ldrh r4, [r4, #0x00]
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r2, [sp, #0x01C]
	movs r3, #0x00
	ldsh r0, [r2, r3]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	subs r0, r0, r1
	muls r0, r5
	adds r1, r6, #0x0
	bl func_0811D5EC
	mov r5, r8
	ldrh r1, [r5, #0x00]
	adds r1, r1, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r0, _0811194C @ =0x09EFBEC4
	ldr r2, [r0, #0x34]
	ldr r3, [r7, #0x3C]
	ldr r0, [r7, #0x40]
	str r0, [sp, #0x000]
	mov r0, r10
	str r0, [sp, #0x004]
	mov r5, r9
	str r5, [sp, #0x008]
	ldr r0, [sp, #0x018]
	str r0, [sp, #0x00C]
	adds r0, r4, #0x0
	bl func_080023E0
	b _081119CA
_08111948: .4byte 0xFFFFEFFC
_0811194C: .4byte 0x09EFBEC4
_08111950:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r7, #0x30]
	ldr r3, [r7, #0x34]
	ldr r0, [r7, #0x38]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	ldr r0, [r7, #0x34]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	ldr r1, [r7, #0x34]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r2, _081119DC @ =0xFFFFEFFC
	adds r0, r2, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x018]
	movs r3, #0x10
	ldsh r2, [r7, r3]
	lsls r1, r2, #0x03
	movs r0, #0x80
	lsls r0, r0, #0x01
	subs r1, r0, r1
	lsls r2, r2, #0x04
	adds r2, r2, r0
	movs r0, #0x00
	movs r3, #0x01
	bl func_08002CB4
	mov r10, r0
	adds r0, r7, #0x0
	adds r0, #0x44
	bl func_08005AFC
	adds r2, r0, #0x0
	add r0, sp, #0x010
	movs r5, #0x00
	ldsh r0, [r0, r5]
	movs r3, #0x00
	ldsh r1, [r4, r3]
	ldr r3, [r7, #0x3C]
	ldr r4, [r7, #0x40]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	movs r4, #0x04
	mov r5, r9
	orrs r5, r4
	str r5, [sp, #0x008]
	ldr r4, [sp, #0x018]
	str r4, [sp, #0x00C]
	bl func_080023E0
_081119CA:
	add sp, #0x020
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_081119DC: .4byte 0xFFFFEFFC
.syntax divided
