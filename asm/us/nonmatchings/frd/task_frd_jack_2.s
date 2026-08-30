.syntax unified
	.align 2, 0
	.global task_frd_jack_2
	.thumb
	.thumb_func
	.type task_frd_jack_2, %function
task_frd_jack_2: @ 08048594
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	mov r9, r0
	mov r7, r9
	adds r7, #0x20
	movs r0, #0x98
	lsls r0, r0, #0x01
	add r0, r9
	bl func_08005AFC
	str r0, [sp, #0x014]
	ldr r0, [r7, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r10, r0
	movs r0, #0xB0
	lsls r0, r0, #0x01
	add r0, r9
	ldrb r0, [r0, #0x00]
	mov r8, r0
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080485E8
	ldr r0, _080485E4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r5, [r0, #0x24]
	adds r6, r5, #0x0
	b _08048618
	.byte 0x00, 0x00
_080485E4: .4byte 0x02039B84
_080485E8:
	ldr r1, _0804860C @ =0x02039B84
	mov r0, r8
	cmp r0, #0x00
	bne _08048610
	ldr r0, [r1, #0x00]
	ldr r2, [r0, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _08048610
	adds r5, r2, #0x0
	adds r6, r5, #0x0
	movs r0, #0x01
	mov r1, r10
	orrs r1, r0
	mov r10, r1
	b _08048618
	.byte 0x00, 0x00
_0804860C: .4byte 0x02039B84
_08048610:
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x24]
	negs r6, r0
	adds r5, r0, #0x0
_08048618:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r7, #0x04]
	ldr r3, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	mov r2, r8
	cmp r2, #0x00
	beq _08048636
	mov r0, r8
	b _0804865C
_08048636:
	ldr r0, _08048648 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	bne _0804864C
	movs r6, #0x00
	b _08048668
_08048648: .4byte 0x02039B84
_0804864C:
	cmp r1, #0xFF
	bgt _0804865A
	movs r0, #0x00
	adds r1, r6, #0x0
	adds r2, r5, #0x0
	movs r3, #0x00
	b _08048662
_0804865A:
	movs r0, #0x00
_0804865C:
	adds r1, r6, #0x0
	adds r2, r5, #0x0
	movs r3, #0x01
_08048662:
	bl func_08002CB4
	adds r6, r0, #0x0
_08048668:
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080486A8
	add r3, sp, #0x010
	mov r12, r3
	add r4, sp, #0x010
	ldr r2, _080486A4 @ =0x08121400
	mov r3, r8
	adds r3, #0x80
	movs r1, #0xFF
	adds r0, r3, #0x0
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r5, #0x00
	ldsh r1, [r0, r5]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	asrs r0, r0, #0x05
	ldrh r4, [r4, #0x00]
	adds r0, r0, r4
	mov r1, r12
	strh r0, [r1, #0x00]
	b _080486CC
	.byte 0x00, 0x00
_080486A4: .4byte 0x08121400
_080486A8:
	add r5, sp, #0x010
	adds r4, r5, #0x0
	ldr r2, _08048748 @ =0x08121400
	mov r3, r8
	adds r3, #0x80
	movs r1, #0xFF
	adds r0, r3, #0x0
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r1, r0, #0x02
	adds r1, r1, r0
	asrs r1, r1, #0x05
	ldrh r0, [r4, #0x00]
	subs r0, r0, r1
	strh r0, [r5, #0x00]
_080486CC:
	movs r0, #0xFF
	ands r3, r0
	adds r0, r3, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r2, #0x00
	ldsh r1, [r0, r2]
	negs r1, r1
	lsls r0, r1, #0x02
	adds r0, r0, r1
	asrs r0, r0, #0x05
	mov r3, sp
	ldrh r3, [r3, #0x12]
	adds r0, r0, r3
	subs r0, #0x28
	mov r4, sp
	strh r0, [r4, #0x12]
	add r0, sp, #0x010
	movs r5, #0x00
	ldsh r0, [r0, r5]
	movs r2, #0x12
	ldsh r1, [r4, r2]
	mov r4, r9
	ldr r3, [r4, #0x18]
	ldr r2, [r4, #0x1C]
	str r2, [sp, #0x000]
	str r6, [sp, #0x004]
	mov r5, r10
	str r5, [sp, #0x008]
	ldr r2, [r7, #0x08]
	asrs r2, r2, #0x08
	lsls r2, r2, #0x02
	ldr r5, _0804874C @ =0xFFFFEFFC
	adds r4, r5, #0x0
	subs r2, r4, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	ldr r2, [sp, #0x014]
	bl func_080023E0
	ldr r0, [r7, #0x08]
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	subs r4, r4, r0
	movs r0, #0x02
	adds r1, r7, #0x0
	adds r1, #0xCC
	orrs r4, r0
	strh r4, [r1, #0x00]
	mov r0, r9
	bl func_08000EE0
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08048748: .4byte 0x08121400
_0804874C: .4byte 0xFFFFEFFC
.syntax divided
