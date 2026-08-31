.syntax unified
	.align 2, 0
	.global task_emy_26_1
	.thumb
	.thumb_func
	.type task_emy_26_1, %function
task_emy_26_1: @ 0803AA30
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x018
	adds r5, r0, #0x0
	mov r8, r5
	adds r7, r5, #0x0
	adds r7, #0x3C
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803AA76
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0803AA62
	cmp r1, #0x01
	beq _0803AA6C
	b _0803AA76
_0803AA62:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x12
	b _0803AA74
_0803AA6C:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x13
_0803AA74:
	str r0, [r1, #0x00]
_0803AA76:
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r0, r5, r3
	ldr r0, [r0, #0x00]
	cmp r0, #0x12
	beq _0803AA88
	cmp r0, #0x13
	beq _0803AB20
	b _0803AC3E
_0803AA88:
	ldr r0, _0803AAC8 @ =0x0813DDF4
	mov r1, r8
	adds r1, #0x10
	mov r4, r8
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	adds r0, r5, #0x0
	adds r0, #0x10
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	blt _0803AAF2
	cmp r0, #0x02
	ble _0803AACC
	cmp r0, #0x03
	bne _0803AAF2
	ldrh r0, [r5, #0x1A]
	cmp r0, #0x00
	bne _0803AAF2
	movs r0, #0xB4
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0xC0
	lsls r0, r0, #0x02
	str r0, [r1, #0x00]
	b _0803AAF2
_0803AAC8: .4byte 0x0813DDF4
_0803AACC:
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x00
	str r0, [r1, #0x00]
	ldr r0, _0803AB18 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r3, #0x9C
	lsls r3, r3, #0x01
	adds r0, r0, r3
	ldr r1, [r7, #0x0C]
	movs r4, #0xF0
	lsls r4, r4, #0x06
	adds r2, r1, r4
	ldr r0, [r0, #0x00]
	subs r0, r0, r2
	asrs r0, r0, #0x03
	adds r1, r1, r0
	str r1, [r7, #0x0C]
_0803AAF2:
	movs r0, #0xC5
	str r0, [sp, #0x000]
	movs r0, #0x28
	str r0, [sp, #0x004]
	ldr r0, _0803AB1C @ =0x00000242
	str r0, [sp, #0x008]
	movs r0, #0x14
	str r0, [sp, #0x00C]
	movs r0, #0x0A
	str r0, [sp, #0x010]
	str r0, [sp, #0x014]
	adds r0, r5, #0x0
	movs r1, #0x20
	movs r2, #0x0C
	movs r3, #0x14
	bl func_0800C980
	b _0803AC3E
	.byte 0x00, 0x00
_0803AB18: .4byte 0x02039B84
_0803AB1C: .4byte 0x00000242
_0803AB20:
	movs r1, #0xB4
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r2, #0x00
	mov r9, r2
	str r2, [r0, #0x00]
	movs r3, #0xAA
	lsls r3, r3, #0x01
	adds r6, r5, r3
	movs r0, #0x00
	ldsh r4, [r6, r0]
	cmp r4, #0x01
	beq _0803AB68
	cmp r4, #0x01
	bgt _0803AB44
	cmp r4, #0x00
	beq _0803AB4E
	b _0803AC3E
_0803AB44:
	cmp r4, #0x02
	beq _0803ABFC
	cmp r4, #0x03
	beq _0803AC1E
	b _0803AC3E
_0803AB4E:
	ldr r0, _0803AB64 @ =0x0813DDF4
	mov r1, r8
	adds r1, #0x10
	mov r3, r8
	ldr r2, [r3, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
	b _0803AC16
_0803AB64: .4byte 0x0813DDF4
_0803AB68:
	adds r0, r5, #0x0
	adds r0, #0x10
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803AC3E
	ldr r6, [r7, #0x08]
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	adds r2, r1, #0x0
	orrs r2, r0
	cmp r2, #0x00
	beq _0803ABC0
	ldr r1, [r7, #0x04]
	ldr r2, _0803ABB4 @ =0xFFFF9C00
	adds r0, r1, r2
	ldr r3, _0803ABB8 @ =0xFFFFDA00
	adds r1, r1, r3
	ldr r3, [r7, #0x0C]
	ldr r2, _0803ABBC @ =0xFFFFE000
	adds r3, r3, r2
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	mov r0, r9
	str r0, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0xC6
	str r0, [sp, #0x010]
	movs r0, #0x01
	adds r2, r6, #0x0
	bl func_08012E44
	b _0803ABE8
	.byte 0x00, 0x00
_0803ABB4: .4byte 0xFFFF9C00
_0803ABB8: .4byte 0xFFFFDA00
_0803ABBC: .4byte 0xFFFFE000
_0803ABC0:
	ldr r1, [r7, #0x04]
	movs r3, #0xC8
	lsls r3, r3, #0x07
	adds r0, r1, r3
	movs r4, #0x98
	lsls r4, r4, #0x06
	adds r1, r1, r4
	ldr r3, [r7, #0x0C]
	ldr r4, _0803ABF8 @ =0xFFFFE000
	adds r3, r3, r4
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	str r2, [sp, #0x008]
	str r2, [sp, #0x00C]
	movs r0, #0xC6
	str r0, [sp, #0x010]
	movs r0, #0x01
	adds r2, r6, #0x0
	bl func_08012E44
_0803ABE8:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	b _0803AC3E
	.byte 0x00, 0x00
_0803ABF8: .4byte 0xFFFFE000
_0803ABFC:
	adds r4, r5, #0x0
	adds r4, #0x10
	adds r0, r4, #0x0
	movs r1, #0x01
	movs r2, #0x00
	bl AnimChange
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803AC3E
_0803AC16:
	ldrh r0, [r6, #0x00]
	adds r0, #0x01
	strh r0, [r6, #0x00]
	b _0803AC3E
_0803AC1E:
	adds r4, r5, #0x0
	adds r4, #0x10
	adds r0, r4, #0x0
	movs r1, #0x01
	movs r2, #0x00
	bl AnimChange
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803AC3E
	adds r0, r5, #0x0
	bl func_0800CB4C
_0803AC3E:
	adds r0, r5, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x018
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
