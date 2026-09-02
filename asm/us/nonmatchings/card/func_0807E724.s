.syntax unified
	.align 2, 0
	.global func_0807E724
	.thumb
	.thumb_func
	.type func_0807E724, %function
func_0807E724: @ 0807E724
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	mov r8, r0
	lsls r1, r1, #0x18
	mov r10, r1
	asrs r6, r1, #0x18
	lsls r5, r6, #0x01
	movs r0, #0xA8
	add r0, r8
	mov r9, r0
	adds r0, r0, r5
	ldrh r7, [r0, #0x00]
	cmp r7, #0x00
	bne _0807E74A
	b _0807E8A8
_0807E74A:
	cmp r6, #0x00
	bne _0807E814
	adds r5, r7, #0x0
	adds r5, #0x0F
	lsls r4, r5, #0x01
	adds r4, r4, r5
	lsls r0, r4, #0x02
	bl EwramAlloc
	adds r1, r0, #0x0
	mov r3, r8
	str r1, [r3, #0x44]
	str r6, [sp, #0x000]
	movs r2, #0xA0
	lsls r2, r2, #0x13
	orrs r2, r4
	mov r0, sp
	bl CpuSet
	movs r4, #0x00
	mov r0, r9
	str r0, [sp, #0x014]
	str r5, [sp, #0x00C]
	movs r1, #0x44
	add r1, r8
	mov r9, r1
	lsls r3, r7, #0x18
	mov r12, r3
	mov r0, r8
	adds r0, #0x94
	str r0, [sp, #0x010]
	cmp r6, r7
	bcs _0807E7C4
	mov r3, r8
	adds r3, #0x44
	movs r5, #0x00
_0807E792:
	ldr r0, [r3, #0x00]
	lsls r2, r4, #0x01
	adds r2, r2, r4
	lsls r2, r2, #0x02
	adds r0, r2, r0
	strb r5, [r0, #0x06]
	ldr r1, [r3, #0x00]
	adds r1, r2, r1
	ldr r0, _0807E810 @ =0x0000FFFF
	str r0, [r1, #0x00]
	strb r5, [r1, #0x07]
	ldr r0, [r3, #0x00]
	adds r0, r2, r0
	strb r5, [r0, #0x0A]
	ldr r0, [r3, #0x00]
	adds r0, r2, r0
	strb r5, [r0, #0x08]
	ldr r0, [r3, #0x00]
	adds r2, r2, r0
	strb r5, [r2, #0x09]
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r7
	bcc _0807E792
_0807E7C4:
	mov r1, r12
	lsrs r4, r1, #0x18
	ldr r5, [sp, #0x00C]
	cmp r4, r5
	bge _0807E882
	mov r3, r10
	asrs r0, r3, #0x16
	mov r1, r9
	adds r2, r1, r0
	movs r7, #0x00
	movs r3, #0x01
	ldr r6, _0807E810 @ =0x0000FFFF
_0807E7DC:
	ldr r0, [r2, #0x00]
	lsls r1, r4, #0x01
	adds r1, r1, r4
	lsls r1, r1, #0x02
	adds r0, r1, r0
	strb r3, [r0, #0x06]
	ldr r0, [r2, #0x00]
	adds r0, r1, r0
	str r6, [r0, #0x00]
	strb r3, [r0, #0x07]
	ldr r0, [r2, #0x00]
	adds r0, r1, r0
	strb r3, [r0, #0x0A]
	ldr r0, [r2, #0x00]
	adds r0, r1, r0
	strb r3, [r0, #0x08]
	ldr r0, [r2, #0x00]
	adds r1, r1, r0
	strb r7, [r1, #0x09]
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r5
	blt _0807E7DC
	b _0807E882
	.byte 0x00, 0x00
_0807E810: .4byte 0x0000FFFF
_0807E814:
	lsls r4, r7, #0x01
	adds r4, r4, r7
	lsls r0, r4, #0x02
	bl EwramAlloc
	adds r1, r0, #0x0
	lsls r0, r6, #0x02
	mov r5, r8
	adds r5, #0x44
	adds r6, r5, r0
	str r1, [r6, #0x00]
	movs r0, #0x00
	str r0, [sp, #0x004]
	add r0, sp, #0x004
	movs r2, #0xA0
	lsls r2, r2, #0x13
	orrs r2, r4
	bl CpuSet
	movs r4, #0x00
	mov r3, r9
	str r3, [sp, #0x014]
	mov r9, r5
	mov r0, r8
	adds r0, #0x94
	str r0, [sp, #0x010]
	cmp r4, r7
	bcs _0807E882
	adds r5, r6, #0x0
	movs r3, #0x00
_0807E850:
	ldr r0, [r5, #0x00]
	lsls r2, r4, #0x01
	adds r2, r2, r4
	lsls r2, r2, #0x02
	adds r0, r2, r0
	strb r3, [r0, #0x06]
	ldr r1, [r5, #0x00]
	adds r1, r2, r1
	ldr r0, _0807E8A4 @ =0x0000FFFF
	str r0, [r1, #0x00]
	strb r3, [r1, #0x07]
	ldr r0, [r5, #0x00]
	adds r0, r2, r0
	strb r3, [r0, #0x0A]
	ldr r0, [r5, #0x00]
	adds r0, r2, r0
	strb r3, [r0, #0x08]
	ldr r0, [r5, #0x00]
	adds r2, r2, r0
	strb r3, [r2, #0x09]
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r7
	bcc _0807E850
_0807E882:
	mov r1, r10
	asrs r2, r1, #0x18
	lsls r0, r2, #0x02
	add r0, r9
	ldr r1, [r0, #0x00]
	lsls r4, r2, #0x01
	ldr r3, [sp, #0x014]
	adds r0, r3, r4
	ldrh r3, [r0, #0x00]
	mov r0, r8
	bl sub_0807E4C8
	ldr r0, [sp, #0x010]
	adds r4, r0, r4
	movs r0, #0x00
	strh r0, [r4, #0x00]
	b _0807E8DA
_0807E8A4: .4byte 0x0000FFFF
_0807E8A8:
	movs r0, #0x0C
	bl EwramAlloc
	adds r1, r0, #0x0
	lsls r0, r6, #0x02
	mov r4, r8
	adds r4, #0x44
	adds r4, r4, r0
	str r1, [r4, #0x00]
	str r7, [sp, #0x008]
	add r0, sp, #0x008
	ldr r2, _0807E8EC @ =0x05000003
	bl CpuSet
	ldr r2, [r4, #0x00]
	lsls r0, r6, #0x0C
	movs r1, #0xFF
	orrs r0, r1
	str r0, [r2, #0x00]
	strb r7, [r2, #0x09]
	mov r0, r8
	adds r0, #0x94
	adds r0, r0, r5
	ldr r1, _0807E8F0 @ =0x0000FFFF
	strh r1, [r0, #0x00]
_0807E8DA:
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0807E8EC: .4byte 0x05000003
_0807E8F0: .4byte 0x0000FFFF
.syntax divided
