.syntax unified
	.align 2, 0
	.global func_080E47E8
	.thumb
	.thumb_func
	.type func_080E47E8, %function
func_080E47E8: @ 080E47E8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x00C]
	lsrs r6, r0, #0x18
	cmp r6, r1
	bge _080E48EA
	mov r7, sp
	adds r7, #0x06
	add r0, sp, #0x008
	mov r10, r0
	movs r1, #0x0A
	add r1, sp
	mov r9, r1
	add r2, sp, #0x004
	mov r8, r2
_080E4814:
	add r0, sp, #0x004
	adds r1, r7, #0x0
	mov r2, r10
	mov r3, r9
	bl func_080E3D80
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080E482E
	cmp r0, #0x02
	beq _080E488C
	b _080E48EA
_080E482E:
	bl GetRandom
	ldr r3, _080E4888 @ =0x0203C7B0
	ldrb r4, [r3, #0x03]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r3, #0x04]
	subs r1, r1, r4
	adds r1, #0x01
	bl __modsi3
	adds r4, r4, r0
	lsls r5, r6, #0x18
	lsrs r5, r5, #0x18
	mov r0, r8
	ldrh r1, [r0, #0x00]
	ldrh r2, [r7, #0x00]
	mov r0, r9
	ldrh r3, [r0, #0x00]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r3, r4, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r0, r5, #0x0
	bl func_080E3060
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	movs r0, #0x00
	ldsh r2, [r7, r0]
	mov r3, r10
	ldrh r0, [r3, #0x00]
	adds r4, r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	movs r0, #0x00
	str r0, [sp, #0x000]
	adds r0, r5, #0x0
	adds r3, r4, #0x0
	bl func_080E309C
	b _080E48E2
	.byte 0x00, 0x00
_080E4888: .4byte 0x0203C7B0
_080E488C:
	bl GetRandom
	ldr r1, _080E48FC @ =0x0203C7B0
	ldrb r4, [r1, #0x03]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r1, #0x04]
	subs r1, r1, r4
	adds r1, #0x01
	bl __modsi3
	adds r4, r4, r0
	lsls r5, r6, #0x18
	lsrs r5, r5, #0x18
	mov r2, r8
	ldrh r1, [r2, #0x00]
	ldrh r2, [r7, #0x00]
	mov r0, r9
	ldrh r3, [r0, #0x00]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r3, r4, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r0, r5, #0x0
	bl func_080E3060
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	movs r0, #0x00
	ldsh r2, [r7, r0]
	mov r3, r10
	ldrh r0, [r3, #0x00]
	adds r4, r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	movs r0, #0x00
	str r0, [sp, #0x000]
	adds r0, r5, #0x0
	adds r3, r4, #0x0
	bl func_080E3400
_080E48E2:
	adds r6, #0x01
	ldr r0, [sp, #0x00C]
	cmp r6, r0
	blt _080E4814
_080E48EA:
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E48FC: .4byte 0x0203C7B0
.syntax divided
