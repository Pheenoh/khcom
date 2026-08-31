.syntax unified
	.align 2, 0
	.global func_08004938
	.thumb
	.thumb_func
	.type func_08004938, %function
func_08004938: @ 08004938
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	ldr r0, _08004A2C @ =0x03007574
	ldr r5, [r0, #0x00]
	movs r0, #0xC0
	lsls r0, r0, #0x04
	adds r0, r5, r0
	str r0, [sp, #0x004]
	movs r1, #0x80
	lsls r1, r1, #0x05
	adds r1, r1, r5
	mov r9, r1
	movs r0, #0x83
	lsls r0, r0, #0x05
	adds r2, r5, r0
	movs r1, #0x84
	lsls r1, r1, #0x05
	adds r1, r5, r1
	str r1, [sp, #0x008]
	adds r0, #0x4C
	adds r1, r5, r0
	movs r0, #0x00
	str r0, [r1, #0x00]
	ldr r1, _08004A30 @ =0x000010A6
	adds r0, r5, r1
	ldrh r0, [r0, #0x00]
	adds r7, r0, #0x0
	cmp r7, #0x00
	beq _0800498A
	adds r6, r2, #0x0
	adds r4, r7, #0x0
_0800497E:
	ldm r6!, {r0}
	bl _call_via_r0
	subs r4, #0x01
	cmp r4, #0x00
	bne _0800497E
_0800498A:
	ldr r0, _08004A2C @ =0x03007574
	ldr r1, [r0, #0x00]
	ldr r0, _08004A30 @ =0x000010A6
	adds r2, r1, r0
	ldrh r0, [r2, #0x00]
	movs r0, #0x00
	strh r0, [r2, #0x00]
	movs r2, #0x85
	lsls r2, r2, #0x05
	adds r1, r1, r2
	ldrh r0, [r1, #0x00]
	adds r7, r0, #0x0
	cmp r7, #0x00
	beq _080049CC
	adds r4, r7, #0x0
_080049A8:
	ldr r0, [r5, #0x00]
	ldr r1, [r5, #0x04]
	ldrh r2, [r5, #0x08]
	lsrs r2, r2, #0x01
	bl CpuSet
	ldr r0, _08004A2C @ =0x03007574
	ldr r1, [r0, #0x00]
	ldr r0, _08004A34 @ =0x000010AC
	adds r1, r1, r0
	ldrh r2, [r5, #0x08]
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	adds r5, #0x0C
	subs r4, #0x01
	cmp r4, #0x00
	bne _080049A8
_080049CC:
	ldr r3, _08004A2C @ =0x03007574
	ldr r1, [r3, #0x00]
	movs r0, #0x85
	lsls r0, r0, #0x05
	adds r2, r1, r0
	ldrh r0, [r2, #0x00]
	movs r0, #0x00
	strh r0, [r2, #0x00]
	ldr r2, _08004A38 @ =0x000010A4
	adds r1, r1, r2
	ldrh r0, [r1, #0x00]
	adds r7, r0, #0x0
	movs r4, #0x00
	cmp r4, r7
	bge _08004A6C
	movs r0, #0x1F
	mov r8, r0
_080049EE:
	lsls r0, r4, #0x01
	adds r0, r0, r4
	lsls r0, r0, #0x02
	mov r2, r9
	adds r1, r0, r2
	ldrb r0, [r1, #0x0A]
	cmp r0, #0x00
	beq _08004A3C
	movs r6, #0x00
	adds r4, #0x01
	mov r10, r4
	adds r2, r1, #0x0
	ldr r4, [r2, #0x04]
	ldr r3, [r2, #0x00]
_08004A0A:
	ldrb r0, [r2, #0x09]
	adds r0, r0, r6
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #0x05
	ldrb r1, [r2, #0x08]
	adds r0, r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r4
	ldrh r1, [r3, #0x00]
	strh r1, [r0, #0x00]
	adds r3, #0x02
	adds r6, #0x01
	cmp r6, #0x1F
	ble _08004A0A
	b _08004A66
	.byte 0x00, 0x00
_08004A2C: .4byte 0x03007574
_08004A30: .4byte 0x000010A6
_08004A34: .4byte 0x000010AC
_08004A38: .4byte 0x000010A4
_08004A3C:
	movs r5, #0x00
	adds r4, #0x01
	mov r10, r4
	adds r2, r1, #0x0
	ldr r4, [r2, #0x04]
	ldr r3, [r2, #0x00]
_08004A48:
	ldrb r0, [r2, #0x08]
	adds r0, r0, r5
	mov r1, r8
	ands r0, r1
	ldrb r1, [r2, #0x09]
	lsls r1, r1, #0x05
	adds r1, r1, r0
	lsls r1, r1, #0x01
	adds r1, r1, r4
	ldrh r0, [r3, #0x00]
	strh r0, [r1, #0x00]
	adds r3, #0x02
	adds r5, #0x01
	cmp r5, #0x1F
	ble _08004A48
_08004A66:
	mov r4, r10
	cmp r4, r7
	blt _080049EE
_08004A6C:
	ldr r2, _08004A98 @ =0x03007574
	ldr r1, [r2, #0x00]
	ldr r0, _08004A9C @ =0x000010A4
	adds r2, r1, r0
	ldrh r0, [r2, #0x00]
	movs r0, #0x00
	strh r0, [r2, #0x00]
	ldr r2, _08004AA0 @ =0x000010A2
	adds r1, r1, r2
	ldrh r0, [r1, #0x00]
	adds r7, r0, #0x0
	movs r4, #0x00
	cmp r4, r7
	bge _08004B0E
_08004A88:
	movs r6, #0x00
	lsls r3, r4, #0x04
	ldr r1, [sp, #0x004]
	adds r0, r3, r1
	adds r4, #0x01
	mov r10, r4
	str r3, [sp, #0x00C]
	b _08004B02
_08004A98: .4byte 0x03007574
_08004A9C: .4byte 0x000010A4
_08004AA0: .4byte 0x000010A2
_08004AA4:
	adds r4, r3, #0x0
	ldr r2, [sp, #0x004]
	adds r0, r4, r2
	ldrb r1, [r0, #0x09]
	adds r1, r1, r6
	movs r2, #0x1F
	ands r1, r2
	lsls r1, r1, #0x05
	mov r9, r1
	ldrb r1, [r0, #0x0B]
	adds r1, r1, r6
	ands r1, r2
	lsls r1, r1, #0x05
	mov r8, r1
	movs r5, #0x00
	adds r6, #0x01
	mov r12, r6
	ldrb r0, [r0, #0x0C]
	cmp r5, r0
	bge _08004AFA
	movs r6, #0x1F
_08004ACE:
	ldr r0, [sp, #0x004]
	adds r3, r4, r0
	ldrb r0, [r3, #0x08]
	adds r0, r0, r5
	ands r0, r6
	ldrb r1, [r3, #0x0A]
	adds r1, r1, r5
	ands r1, r6
	add r1, r8
	ldr r2, [r3, #0x04]
	lsls r1, r1, #0x01
	adds r1, r1, r2
	add r0, r9
	ldr r2, [r3, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	adds r5, #0x01
	ldrb r3, [r3, #0x0C]
	cmp r5, r3
	blt _08004ACE
_08004AFA:
	mov r6, r12
	ldr r3, [sp, #0x00C]
	ldr r1, [sp, #0x004]
	adds r0, r3, r1
_08004B02:
	ldrb r0, [r0, #0x0D]
	cmp r6, r0
	blt _08004AA4
	mov r4, r10
	cmp r4, r7
	blt _08004A88
_08004B0E:
	ldr r2, _08004B7C @ =0x03007574
	ldr r1, [r2, #0x00]
	ldr r0, _08004B80 @ =0x000010A2
	adds r2, r1, r0
	ldrh r0, [r2, #0x00]
	movs r0, #0x00
	strh r0, [r2, #0x00]
	ldr r2, _08004B84 @ =0x000010A8
	adds r1, r1, r2
	ldrh r0, [r1, #0x00]
	adds r7, r0, #0x0
	cmp r7, #0x00
	beq _08004B5C
	ldr r5, [sp, #0x008]
	mov r6, sp
	adds r4, r7, #0x0
_08004B2E:
	movs r0, #0x00
	strh r0, [r6, #0x00]
	ldr r1, [r5, #0x00]
	ldrh r2, [r5, #0x04]
	lsrs r2, r2, #0x01
	movs r0, #0x80
	lsls r0, r0, #0x11
	orrs r2, r0
	mov r0, sp
	bl CpuSet
	ldr r0, _08004B7C @ =0x03007574
	ldr r1, [r0, #0x00]
	ldr r0, _08004B88 @ =0x000010AC
	adds r1, r1, r0
	ldrh r2, [r5, #0x04]
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	adds r5, #0x08
	subs r4, #0x01
	cmp r4, #0x00
	bne _08004B2E
_08004B5C:
	ldr r0, _08004B7C @ =0x03007574
	ldr r0, [r0, #0x00]
	ldr r1, _08004B84 @ =0x000010A8
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	movs r1, #0x00
	strh r1, [r0, #0x00]
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08004B7C: .4byte 0x03007574
_08004B80: .4byte 0x000010A2
_08004B84: .4byte 0x000010A8
_08004B88: .4byte 0x000010AC
.syntax divided
