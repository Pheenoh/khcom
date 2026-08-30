.syntax unified
	.align 2, 0
	.global task_btl_raid_2
	.thumb
	.thumb_func
	.type task_btl_raid_2, %function
task_btl_raid_2: @ 0804096C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	adds r0, #0x56
	ldrh r1, [r0, #0x00]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _08040A50
	ldr r0, [r6, #0x28]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r6, #0x24]
	ldr r3, [r6, #0x28]
	ldr r0, [r6, #0x2C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	ldr r0, _080409C8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x24]
	ldr r0, [r6, #0x44]
	muls r0, r1
	asrs r2, r0, #0x08
	movs r0, #0x80
	lsls r0, r0, #0x01
	mov r8, r4
	cmp r2, r0
	bne _080409CC
	movs r5, #0x00
	adds r0, r6, #0x0
	adds r0, #0x3C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080409E8
	movs r0, #0x01
	orrs r7, r0
	b _080409E8
_080409C8: .4byte 0x02039B84
_080409CC:
	adds r0, r6, #0x0
	adds r0, #0x3C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080409DC
	negs r1, r2
	movs r0, #0x00
	b _080409E0
_080409DC:
	movs r0, #0x00
	adds r1, r2, #0x0
_080409E0:
	movs r3, #0x01
	bl func_08002CB4
	adds r5, r0, #0x0
_080409E8:
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r2, [r6, #0x08]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	str r7, [sp, #0x008]
	ldr r5, [r6, #0x28]
	movs r4, #0x80
	lsls r4, r4, #0x05
	adds r5, r5, r4
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	mov r12, r5
	ldr r5, _08040A5C @ =0xFFFFEFFC
	adds r4, r5, #0x0
	mov r5, r12
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
	ldr r2, [r6, #0x24]
	ldr r3, [r6, #0x28]
	movs r5, #0x00
	str r5, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r2, _08040A60 @ =0x08B22CBC
	ldr r3, [r6, #0x60]
	ldr r4, [r6, #0x64]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	str r7, [sp, #0x008]
	ldr r4, _08040A64 @ =0x0000FFFE
	str r4, [sp, #0x00C]
	bl func_080023E0
_08040A50:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08040A5C: .4byte 0xFFFFEFFC
_08040A60: .4byte 0x08B22CBC
_08040A64: .4byte 0x0000FFFE
.syntax divided
