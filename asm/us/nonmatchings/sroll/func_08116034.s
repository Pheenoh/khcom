.syntax unified
	.align 2, 0
	.global func_08116034
	.thumb
	.thumb_func
	.type func_08116034, %function
func_08116034: @ 08116034
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x0D8
	adds r6, r0, #0x0
	movs r0, #0x00
	mov r8, r0
	add r5, sp, #0x094
	ldrh r4, [r6, #0x06]
	str r4, [r5, #0x00]
	ldrh r0, [r6, #0x02]
	str r0, [r5, #0x04]
	ldrh r0, [r6, #0x04]
	str r0, [r5, #0x08]
	ldrh r0, [r6, #0x08]
	str r0, [r5, #0x0C]
	lsls r7, r4, #0x04
	orrs r7, r4
	lsls r0, r7, #0x08
	orrs r7, r0
	lsls r0, r7, #0x10
	orrs r7, r0
	ldrh r4, [r6, #0x20]
	movs r0, #0x07
	ands r0, r4
	str r0, [sp, #0x000]
	str r3, [sp, #0x004]
	str r2, [sp, #0x008]
	str r1, [sp, #0x00C]
	str r5, [sp, #0x010]
	ldrh r4, [r6, #0x24]
	subs r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _081160A4 @ =0x0000FFFF
	cmp r4, r0
	beq _081160DA
	add r5, sp, #0x0D4
	mov r9, r0
_08116084:
	ldr r0, [sp, #0x000]
	cmp r0, #0x00
	bne _08116096
	str r7, [r5, #0x00]
	ldr r1, [sp, #0x00C]
	adds r0, r5, #0x0
	ldr r2, _081160A8 @ =0x01000008
	bl func_08117FE4
_08116096:
	ldrh r0, [r6, #0x26]
	cmp r0, #0x01
	beq _081160AC
	cmp r0, #0x02
	beq _081160B4
	b _081160BC
	.byte 0x00, 0x00
_081160A4: .4byte 0x0000FFFF
_081160A8: .4byte 0x01000008
_081160AC:
	mov r0, sp
	bl func_0811589C
	b _081160BA
_081160B4:
	mov r0, sp
	bl func_08115E24
_081160BA:
	mov r8, r0
_081160BC:
	ldrh r1, [r6, #0x26]
	lsls r1, r1, #0x03
	ldr r0, [sp, #0x008]
	adds r0, r0, r1
	str r0, [sp, #0x008]
	ldrh r1, [r6, #0x1C]
	lsls r1, r1, #0x05
	ldr r0, [sp, #0x00C]
	adds r0, r0, r1
	str r0, [sp, #0x00C]
	subs r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r9
	bne _08116084
_081160DA:
	mov r0, r8
	add sp, #0x0D8
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
