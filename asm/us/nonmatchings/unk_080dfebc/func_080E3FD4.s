.syntax unified
	.align 2, 0
	.global func_080E3FD4
	.thumb
	.thumb_func
	.type func_080E3FD4, %function
func_080E3FD4: @ 080E3FD4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080E414C @ =0x02034F28
	mov r9, r1
	ldrh r1, [r1, #0x00]
	subs r1, #0x07
	bl __modsi3
	adds r4, r0, #0x0
	adds r4, #0x04
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	subs r1, r1, r4
	subs r1, #0x03
	bl __modsi3
	adds r0, #0x02
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r1, sp, #0x008
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r4
	mov r7, sp
	adds r7, #0x0E
	strh r0, [r7, #0x00]
	ldr r0, _080E4150 @ =0x02034F2A
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x02
	mov r5, sp
	adds r5, #0x0A
	strh r0, [r5, #0x00]
	adds r0, r1, #0x0
	ldrh r1, [r0, #0x00]
	ldrh r2, [r7, #0x00]
	movs r0, #0x00
	movs r3, #0x00
	bl func_080E3060
	add r0, sp, #0x008
	movs r3, #0x00
	ldsh r1, [r0, r3]
	movs r0, #0x00
	ldsh r2, [r7, r0]
	movs r0, #0x00
	ldsh r3, [r5, r0]
	movs r0, #0x00
	mov r10, r0
	str r0, [sp, #0x000]
	bl func_080E309C
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bhi _080E4158
	add r6, sp, #0x00C
	mov r1, r10
	str r1, [sp, #0x000]
	mov r2, r9
	movs r3, #0x00
	ldsh r0, [r2, r3]
	str r0, [sp, #0x004]
	movs r0, #0x03
	add r1, sp, #0x008
	adds r2, r5, #0x0
	adds r3, r6, #0x0
	bl func_080E3C1C
	bl GetRandom
	ldr r1, _080E4154 @ =0x0203C7B0
	mov r8, r1
	ldrb r4, [r1, #0x03]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r1, #0x04]
	subs r1, r1, r4
	adds r1, #0x01
	bl __modsi3
	adds r4, r4, r0
	add r0, sp, #0x008
	ldrh r1, [r0, #0x00]
	mov r3, r9
	ldrh r2, [r3, #0x00]
	ldrh r3, [r6, #0x00]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r3, r4, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	movs r0, #0x01
	bl func_080E3060
	add r0, sp, #0x008
	movs r2, #0x00
	ldsh r1, [r0, r2]
	mov r3, r9
	movs r0, #0x00
	ldsh r2, [r3, r0]
	ldrh r0, [r5, #0x00]
	adds r4, r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r3, r10
	str r3, [sp, #0x000]
	movs r0, #0x01
	adds r3, r4, #0x0
	bl func_080E309C
	mov r0, r10
	str r0, [sp, #0x000]
	mov r1, r9
	movs r2, #0x00
	ldsh r0, [r1, r2]
	str r0, [sp, #0x004]
	movs r0, #0x05
	adds r1, r7, #0x0
	adds r2, r5, #0x0
	adds r3, r6, #0x0
	bl func_080E3CD4
	bl GetRandom
	mov r3, r8
	ldrb r4, [r3, #0x03]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r3, #0x04]
	subs r1, r1, r4
	adds r1, #0x01
	bl __modsi3
	adds r4, r4, r0
	ldrh r2, [r7, #0x00]
	adds r2, #0x01
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldrh r3, [r6, #0x00]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r3, r4, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	movs r0, #0x02
	movs r1, #0x00
	bl func_080E3060
	ldrh r2, [r7, #0x00]
	adds r2, #0x01
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r0, [r5, #0x00]
	adds r4, r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r0, r10
	str r0, [sp, #0x000]
	movs r0, #0x02
	movs r1, #0x00
	adds r3, r4, #0x0
	bl func_080E3400
	b _080E4230
_080E414C: .4byte 0x02034F28
_080E4150: .4byte 0x02034F2A
_080E4154: .4byte 0x0203C7B0
_080E4158:
	add r6, sp, #0x00C
	mov r1, r10
	str r1, [sp, #0x000]
	mov r2, r9
	movs r3, #0x00
	ldsh r0, [r2, r3]
	str r0, [sp, #0x004]
	movs r0, #0x05
	adds r1, r7, #0x0
	adds r2, r5, #0x0
	adds r3, r6, #0x0
	bl func_080E3CD4
	bl GetRandom
	ldr r1, _080E4240 @ =0x0203C7B0
	mov r8, r1
	ldrb r4, [r1, #0x03]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r1, #0x04]
	subs r1, r1, r4
	adds r1, #0x01
	bl __modsi3
	adds r4, r4, r0
	ldrh r2, [r7, #0x00]
	adds r2, #0x01
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldrh r3, [r6, #0x00]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r3, r4, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	movs r0, #0x01
	movs r1, #0x00
	bl func_080E3060
	ldrh r2, [r7, #0x00]
	adds r2, #0x01
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r0, [r5, #0x00]
	adds r4, r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r3, r10
	str r3, [sp, #0x000]
	movs r0, #0x01
	movs r1, #0x00
	adds r3, r4, #0x0
	bl func_080E3400
	mov r0, r10
	str r0, [sp, #0x000]
	mov r1, r9
	movs r2, #0x00
	ldsh r0, [r1, r2]
	str r0, [sp, #0x004]
	movs r0, #0x03
	add r1, sp, #0x008
	adds r2, r5, #0x0
	adds r3, r6, #0x0
	bl func_080E3C1C
	bl GetRandom
	mov r3, r8
	ldrb r4, [r3, #0x03]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r3, #0x04]
	subs r1, r1, r4
	adds r1, #0x01
	bl __modsi3
	adds r4, r4, r0
	add r0, sp, #0x008
	ldrh r1, [r0, #0x00]
	mov r0, r9
	ldrh r2, [r0, #0x00]
	ldrh r3, [r6, #0x00]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r3, r4, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	movs r0, #0x02
	bl func_080E3060
	add r0, sp, #0x008
	movs r2, #0x00
	ldsh r1, [r0, r2]
	mov r3, r9
	movs r0, #0x00
	ldsh r2, [r3, r0]
	ldrh r0, [r5, #0x00]
	adds r4, r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r3, r10
	str r3, [sp, #0x000]
	movs r0, #0x02
	adds r3, r4, #0x0
	bl func_080E309C
_080E4230:
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080E4240: .4byte 0x0203C7B0
.syntax divided
