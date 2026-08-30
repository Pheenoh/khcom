.syntax unified
	.align 2, 0
	.global task_poo_eeyore_2
	.thumb
	.thumb_func
	.type task_poo_eeyore_2, %function
task_poo_eeyore_2: @ 080CDEB4
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r1, [r4, #0x24]
	asrs r1, r1, #0x08
	ldr r0, _080CDF34 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	ldr r0, [r4, #0x28]
	asrs r0, r0, #0x08
	ldr r2, _080CDF38 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r0, r0, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	mov r9, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	movs r0, #0x18
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	mov r0, r9
	mov r1, r8
	movs r2, #0x18
	movs r3, #0x0A
	bl func_080035CC
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0x00
	beq _080CDF3C
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CDF0E
	bl func_08002C10
	movs r0, #0x00
	str r0, [r4, #0x04]
	ldr r0, [r4, #0x00]
	bl func_080028C0
_080CDF0E:
	adds r5, r4, #0x0
	adds r5, #0xAC
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080CDFD2
	adds r0, r4, #0x0
	adds r0, #0x34
	bl func_08012304
	adds r0, r4, #0x0
	adds r0, #0xAE
	ldrh r0, [r0, #0x00]
	movs r1, #0x00
	bl func_080D2E70
	movs r0, #0x00
	strb r0, [r5, #0x00]
	b _080CDFD2
	.byte 0x00, 0x00
_080CDF34: .4byte 0x0203C40C
_080CDF38: .4byte 0x0203C3F8
_080CDF3C:
	adds r5, r4, #0x0
	adds r5, #0xAC
	ldrb r0, [r5, #0x00]
	adds r6, r4, #0x0
	adds r6, #0x34
	cmp r0, #0x00
	bne _080CDF66
	adds r0, r6, #0x0
	movs r1, #0x0A
	movs r2, #0x10
	movs r3, #0x10
	bl func_080122AC
	adds r0, r4, #0x0
	adds r0, #0xAE
	ldrh r0, [r0, #0x00]
	movs r1, #0x01
	bl func_080D2E70
	movs r0, #0x01
	strb r0, [r5, #0x00]
_080CDF66:
	ldr r1, [r4, #0x24]
	ldr r2, [r4, #0x28]
	ldr r3, [r4, #0x2C]
	adds r0, r6, #0x0
	bl func_08012324
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08005A64
	str r0, [r4, #0x08]
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	bne _080CDF9A
	ldr r0, _080CDFE0 @ =0x09849C58
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0xA8
	ldrh r0, [r0, #0x00]
	ldr r1, _080CDFE4 @ =0x097448BA
	bl func_080028F8
	str r0, [r4, #0x00]
_080CDF9A:
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	str r7, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	ldr r1, [r4, #0x28]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r5, _080CDFE8 @ =0xFFFFEFFC
	adds r0, r5, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	mov r0, r9
	mov r1, r8
	bl func_080023E0
	adds r4, #0x90
	adds r0, r4, #0x0
	bl func_08000EA4
	adds r0, r4, #0x0
	bl func_08000EE0
_080CDFD2:
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CDFE0: .4byte 0x09849C58
_080CDFE4: .4byte 0x097448BA
_080CDFE8: .4byte 0xFFFFEFFC
.syntax divided
