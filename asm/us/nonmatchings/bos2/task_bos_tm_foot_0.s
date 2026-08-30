.syntax unified
	.align 2, 0
	.global task_bos_tm_foot_0
	.thumb
	.thumb_func
	.type task_bos_tm_foot_0, %function
task_bos_tm_foot_0: @ 080BA928
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r7, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, _080BAA90 @ =0x09652E84
	movs r1, #0xEC
	lsls r1, r1, #0x05
	bl func_080026A4
	str r0, [r7, #0x08]
	movs r4, #0x88
	lsls r4, r4, #0x03
	ldr r5, _080BAA94 @ =0x09654C04
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_080028F8
	str r0, [r7, #0x0C]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_080028F8
	str r0, [r7, #0x10]
	ldr r0, _080BAA98 @ =0x096FB2A4
	movs r1, #0x60
	bl func_08002A14
	str r0, [r7, #0x14]
	ldr r0, _080BAA9C @ =0x08F69BC4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r7, #0x18]
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r2, r7, r0
	ldr r0, _080BAAA0 @ =0x09EF39DC
	ldr r1, [r0, #0x08]
	str r1, [r2, #0x00]
	movs r2, #0x91
	lsls r2, r2, #0x02
	adds r0, r7, r2
	str r1, [r0, #0x00]
	subs r4, #0xE4
	adds r1, r7, r4
	ldr r0, _080BAAA4 @ =0x09EF39BC
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, _080BAAA8 @ =0x00000474
	adds r1, r7, r0
	ldr r0, _080BAAAC @ =0x09EF39C4
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _080BAAB0 @ =0x0000047C
	adds r1, r1, r7
	mov r8, r1
	str r6, [r1, #0x00]
	adds r6, #0x42
	ldr r1, [r7, #0x0C]
	ldr r0, [r7, #0x10]
	ldrh r0, [r0, #0x08]
	ldrh r1, [r1, #0x08]
	adds r0, r0, r1
	ldrh r1, [r6, #0x00]
	adds r1, r1, r0
	movs r2, #0x00
	movs r0, #0x00
	strh r1, [r6, #0x00]
	strb r2, [r7, #0x03]
	strb r2, [r7, #0x04]
	strh r0, [r7, #0x00]
	movs r4, #0x90
	lsls r4, r4, #0x03
	adds r1, r7, r4
	ldr r0, _080BAAB4 @ =0xFFFFFF00
	str r0, [r1, #0x00]
	strb r2, [r7, #0x02]
	movs r6, #0x98
	lsls r6, r6, #0x01
	adds r0, r7, r6
	strb r2, [r0, #0x00]
	movs r1, #0x92
	lsls r1, r1, #0x02
	adds r0, r7, r1
	strb r2, [r0, #0x00]
	movs r4, #0xD8
	lsls r4, r4, #0x02
	adds r0, r7, r4
	strb r2, [r0, #0x00]
	movs r6, #0x8F
	lsls r6, r6, #0x03
	adds r0, r7, r6
	strb r2, [r0, #0x00]
	mov r0, r8
	ldr r3, [r0, #0x00]
	ldrh r1, [r3, #0x28]
	movs r0, #0x08
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	cmp r0, #0x00
	beq _080BAAB8
	adds r0, r7, #0x0
	adds r0, #0x1C
	ldrh r1, [r3, #0x00]
	adds r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r3, #0x02]
	adds r2, #0x02
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r3, [r3, #0x04]
	subs r3, #0x04
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	bl func_080BA0E4
	movs r1, #0x9A
	lsls r1, r1, #0x01
	adds r0, r7, r1
	mov r2, r8
	ldr r3, [r2, #0x00]
	ldrh r1, [r3, #0x00]
	subs r1, #0x06
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r3, #0x02]
	subs r2, #0x02
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r3, [r3, #0x04]
	subs r3, #0x04
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	bl func_080BA0E4
	movs r4, #0x93
	lsls r4, r4, #0x02
	adds r0, r7, r4
	mov r6, r8
	ldr r3, [r6, #0x00]
	ldrh r1, [r3, #0x00]
	adds r1, #0x06
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r3, #0x02]
	adds r2, #0x05
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r3, [r3, #0x04]
	adds r3, #0x28
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	bl func_080BA0E4
	movs r1, #0xD9
	lsls r1, r1, #0x02
	adds r0, r7, r1
	ldr r3, [r6, #0x00]
	ldrh r1, [r3, #0x00]
	subs r1, #0x02
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r3, #0x02]
	subs r2, #0x02
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r3, [r3, #0x04]
	adds r3, #0x2B
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	bl func_080BA0E4
	b _080BAB7E
	.byte 0x00, 0x00
_080BAA90: .4byte 0x09652E84
_080BAA94: .4byte 0x09654C04
_080BAA98: .4byte 0x096FB2A4
_080BAA9C: .4byte 0x08F69BC4
_080BAAA0: .4byte 0x09EF39DC
_080BAAA4: .4byte 0x09EF39BC
_080BAAA8: .4byte 0x00000474
_080BAAAC: .4byte 0x09EF39C4
_080BAAB0: .4byte 0x0000047C
_080BAAB4: .4byte 0xFFFFFF00
_080BAAB8:
	adds r0, r7, #0x0
	adds r0, #0x1C
	ldrh r1, [r3, #0x00]
	adds r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r3, #0x02]
	adds r2, #0x02
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r3, [r3, #0x04]
	subs r3, #0x04
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	movs r4, #0x04
	str r4, [sp, #0x000]
	movs r5, #0x20
	str r5, [sp, #0x004]
	mov r6, r9
	str r6, [sp, #0x008]
	str r4, [sp, #0x00C]
	bl func_080BA08C
	movs r1, #0x9A
	lsls r1, r1, #0x01
	adds r0, r7, r1
	mov r2, r8
	ldr r3, [r2, #0x00]
	ldrh r1, [r3, #0x00]
	subs r1, #0x06
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r3, #0x02]
	subs r2, #0x02
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r3, [r3, #0x04]
	subs r3, #0x04
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	str r6, [sp, #0x008]
	movs r4, #0x05
	str r4, [sp, #0x00C]
	bl func_080BA08C
	movs r4, #0x93
	lsls r4, r4, #0x02
	adds r0, r7, r4
	mov r6, r8
	ldr r3, [r6, #0x00]
	ldrh r1, [r3, #0x00]
	adds r1, #0x06
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r3, #0x02]
	adds r2, #0x05
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r3, [r3, #0x04]
	adds r3, #0x28
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	movs r6, #0x14
	str r6, [sp, #0x000]
	movs r5, #0x8C
	str r5, [sp, #0x004]
	mov r4, r9
	str r4, [sp, #0x008]
	movs r4, #0x06
	str r4, [sp, #0x00C]
	bl func_080BA08C
	movs r1, #0xD9
	lsls r1, r1, #0x02
	adds r0, r7, r1
	mov r2, r8
	ldr r3, [r2, #0x00]
	ldrh r1, [r3, #0x00]
	subs r1, #0x02
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r3, #0x02]
	subs r2, #0x02
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r3, [r3, #0x04]
	adds r3, #0x2B
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	str r6, [sp, #0x000]
	str r5, [sp, #0x004]
	mov r4, r9
	str r4, [sp, #0x008]
	movs r4, #0x07
	str r4, [sp, #0x00C]
	bl func_080BA08C
_080BAB7E:
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
