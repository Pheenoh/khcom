.syntax unified
	.align 2, 0
	.global task_bos_lst_bit_2
	.thumb
	.thumb_func
	.type task_bos_lst_bit_2, %function
task_bos_lst_bit_2: @ 0811145C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	adds r0, #0xCC
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	ble _0811151E
	adds r0, r7, #0x0
	adds r0, #0x98
	ldr r0, [r0, #0x00]
	mov r9, r0
	ldrh r1, [r7, #0x0A]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0811148E
	adds r0, r7, #0x0
	adds r0, #0x9C
	ldr r0, [r0, #0x00]
	mov r9, r0
_0811148E:
	lsls r0, r1, #0x10
	cmp r0, #0x00
	ble _08111498
	subs r0, r1, #0x1
	strh r0, [r7, #0x0A]
_08111498:
	movs r3, #0x12
	add r3, sp
	mov r8, r3
	ldr r2, [r7, #0x28]
	ldr r0, [r7, #0x34]
	adds r2, r2, r0
	ldr r3, [r7, #0x2C]
	ldr r0, [r7, #0x38]
	adds r3, r3, r0
	ldr r0, [r7, #0x30]
	ldr r1, [r7, #0x3C]
	adds r0, r0, r1
	ldr r1, [r7, #0x40]
	adds r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl func_0801909C
	ldr r0, [r7, #0x2C]
	bl func_0801AF1C
	adds r5, r0, #0x0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, [r7, #0x2C]
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	ldr r6, _08111530 @ =0xFFFFEFFC
	adds r4, r6, #0x0
	subs r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrb r0, [r7, #0x1B]
	ldr r1, [r7, #0x74]
	ldr r2, [r7, #0x78]
	movs r3, #0x00
	bl func_08002CB4
	mov r10, r0
	adds r0, r7, #0x0
	adds r0, #0x7C
	bl func_08005AFC
	adds r2, r0, #0x0
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r3, r8
	movs r6, #0x00
	ldsh r1, [r3, r6]
	adds r3, r7, #0x0
	adds r3, #0x94
	ldr r3, [r3, #0x00]
	mov r6, r9
	str r6, [sp, #0x000]
	mov r6, r10
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	str r4, [sp, #0x00C]
	bl func_080023E0
	movs r1, #0xD8
	lsls r1, r1, #0x01
	adds r0, r7, r1
	bl func_08000EE0
_0811151E:
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08111530: .4byte 0xFFFFEFFC
.syntax divided
