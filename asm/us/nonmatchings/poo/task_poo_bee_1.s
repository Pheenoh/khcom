.syntax unified
	.align 2, 0
	.global task_poo_bee_1
	.thumb
	.thumb_func
	.type task_poo_bee_1, %function
task_poo_bee_1: @ 080D0AE8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	adds r6, r0, #0x0
	bl func_080CFCC0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D0B02
	b _080D0CCE
_080D0B02:
	adds r1, r6, #0x0
	adds r1, #0xC8
	ldrb r0, [r1, #0x00]
	movs r2, #0xA4
	adds r2, r2, r6
	mov r8, r2
	movs r3, #0xA8
	adds r3, r3, r6
	mov r9, r3
	adds r2, r6, #0x0
	adds r2, #0x0C
	str r2, [sp, #0x00C]
	cmp r0, #0x00
	beq _080D0B9C
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r5, #0x00
	adds r3, r6, #0x0
	adds r3, #0x24
	str r3, [sp, #0x010]
	adds r0, r6, #0x0
	adds r0, #0x28
	str r0, [sp, #0x014]
	subs r1, #0x9C
	str r1, [sp, #0x000]
	adds r2, #0xA0
	str r2, [sp, #0x008]
	adds r3, #0x10
	str r3, [sp, #0x004]
	movs r0, #0x38
	adds r0, r0, r6
	mov r10, r0
	movs r1, #0x80
	lsls r1, r1, #0x06
	mov r12, r1
	ldr r7, _080D0C30 @ =0x096FD730
_080D0B4A:
	lsls r2, r5, #0x05
	ldr r3, [sp, #0x010]
	adds r1, r3, r2
	mov r3, r8
	ldr r0, [r3, #0x00]
	ldr r3, _080D0C34 @ =0xFFFFFB00
	adds r0, r0, r3
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x014]
	adds r1, r0, r2
	mov r3, r9
	ldr r0, [r3, #0x00]
	movs r3, #0xA0
	lsls r3, r3, #0x03
	adds r0, r0, r3
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x000]
	adds r1, r0, r2
	ldr r3, [sp, #0x008]
	ldr r0, [r3, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x004]
	adds r3, r0, r2
	ldr r1, _080D0C38 @ =0x0203C3EC
	ldr r4, [r1, #0x00]
	ldr r1, [r7, #0x00]
	add r1, r12
	ldr r0, [r4, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	add r2, r10
	ldr r1, [r7, #0x04]
	mov r3, r12
	subs r1, r1, r3
	ldr r0, [r4, #0x04]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r7, #0x08
	adds r5, #0x01
	cmp r5, #0x03
	ble _080D0B4A
_080D0B9C:
	ldr r0, _080D0C3C @ =0x02034E2C
	ldr r2, [r0, #0x00]
	cmp r2, #0x03
	bhi _080D0C44
	lsls r2, r2, #0x05
	adds r0, r2, #0x0
	adds r0, #0x24
	adds r0, r6, r0
	adds r1, r6, #0x0
	adds r1, #0x34
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	adds r4, r6, #0x0
	adds r4, #0xC6
	ldrh r2, [r4, #0x00]
	bl func_080058FC
	ldr r1, _080D0C3C @ =0x02034E2C
	ldr r2, [r1, #0x00]
	lsls r2, r2, #0x05
	adds r0, r2, r6
	adds r0, #0x28
	adds r1, r6, #0x0
	adds r1, #0x38
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	ldrh r2, [r4, #0x00]
	bl func_080058FC
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x00
	bne _080D0C1A
	movs r0, #0x08
	strh r0, [r4, #0x00]
	ldr r3, _080D0C3C @ =0x02034E2C
	ldr r0, [r3, #0x00]
	adds r0, #0x01
	str r0, [r3, #0x00]
	cmp r0, #0x03
	bls _080D0C1A
	ldr r0, _080D0C38 @ =0x0203C3EC
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x06
	adds r0, r0, r3
	mov r3, r8
	str r0, [r3, #0x00]
	ldr r0, [r1, #0x04]
	ldr r1, _080D0C40 @ =0xFFFFE000
	adds r0, r0, r1
	mov r3, r9
	str r0, [r3, #0x00]
	adds r1, r6, #0x0
	adds r1, #0xB4
	adds r0, r6, #0x0
	adds r0, #0xB8
	str r2, [r0, #0x00]
	str r2, [r1, #0x00]
_080D0C1A:
	mov r1, r8
	ldr r0, [r1, #0x00]
	adds r2, r6, #0x0
	adds r2, #0xAC
	mov r3, r9
	ldr r1, [r3, #0x00]
	ldr r2, [r2, #0x00]
	adds r1, r1, r2
	bl func_080C9FA8
	b _080D0CC6
_080D0C30: .4byte 0x096FD730
_080D0C34: .4byte 0xFFFFFB00
_080D0C38: .4byte 0x0203C3EC
_080D0C3C: .4byte 0x02034E2C
_080D0C40: .4byte 0xFFFFE000
_080D0C44:
	adds r4, r6, #0x0
	adds r4, #0xB4
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r2, _080D0CE0 @ =0xFFFFE000
	adds r0, r0, r2
	ldr r1, _080D0CE4 @ =0x0203C3EC
	ldr r3, [r1, #0x00]
	ldr r1, [r3, #0x00]
	subs r0, r0, r1
	str r0, [r4, #0x00]
	adds r2, r6, #0x0
	adds r2, #0xB8
	mov r1, r9
	ldr r0, [r1, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x06
	adds r0, r0, r1
	ldr r1, [r3, #0x04]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	mov r3, r8
	ldr r0, [r3, #0x00]
	ldr r1, [r4, #0x00]
	subs r0, r0, r1
	str r0, [r3, #0x00]
	mov r1, r9
	ldr r0, [r1, #0x00]
	ldr r1, [r2, #0x00]
	subs r0, r0, r1
	mov r3, r9
	str r0, [r3, #0x00]
	adds r7, r2, #0x0
	subs r2, #0x90
	adds r3, r6, #0x0
	adds r3, #0x24
	movs r5, #0x03
_080D0C8E:
	ldr r0, [r3, #0x00]
	ldr r1, [r4, #0x00]
	subs r0, r0, r1
	str r0, [r3, #0x00]
	ldr r0, [r2, #0x00]
	ldr r1, [r7, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	adds r2, #0x20
	adds r3, #0x20
	subs r5, #0x01
	cmp r5, #0x00
	bge _080D0C8E
	bl func_080C9D84
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D0CC6
	mov r1, r8
	ldr r0, [r1, #0x00]
	adds r2, r6, #0x0
	adds r2, #0xAC
	mov r3, r9
	ldr r1, [r3, #0x00]
	ldr r2, [r2, #0x00]
	adds r1, r1, r2
	bl func_080C9FA8
_080D0CC6:
	ldr r0, [sp, #0x00C]
	bl AnimUpdate
	str r0, [r6, #0x08]
_080D0CCE:
	movs r0, #0x01
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080D0CE0: .4byte 0xFFFFE000
_080D0CE4: .4byte 0x0203C3EC
.syntax divided
