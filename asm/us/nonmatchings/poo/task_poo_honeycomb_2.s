.syntax unified
	.align 2, 0
	.global task_poo_honeycomb_2
	.thumb
	.thumb_func
	.type task_poo_honeycomb_2, %function
task_poo_honeycomb_2: @ 080CFBA0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r4, r0, #0x0
	adds r0, #0x98
	ldr r2, [r4, #0x24]
	ldr r0, [r0, #0x00]
	adds r2, r2, r0
	asrs r2, r2, #0x08
	ldr r0, _080CFC1C @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r2, r2, r0
	ldr r1, [r4, #0x28]
	asrs r1, r1, #0x08
	ldr r0, [r4, #0x2C]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	ldr r0, _080CFC20 @ =0x0203C3F8
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	mov r8, r2
	lsls r1, r1, #0x10
	asrs r7, r1, #0x10
	movs r0, #0x10
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	mov r0, r8
	adds r1, r7, #0x0
	movs r2, #0x10
	movs r3, #0x10
	bl func_080035CC
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x00
	beq _080CFC24
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CFC02
	bl func_08002C10
	ldr r0, [r4, #0x00]
	bl func_080028C0
	movs r0, #0x00
	str r0, [r4, #0x04]
_080CFC02:
	adds r5, r4, #0x0
	adds r5, #0x9C
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080CFC76
	adds r0, r4, #0x0
	adds r0, #0x38
	bl func_08012304
	movs r0, #0x00
	strb r0, [r5, #0x00]
	b _080CFC76
	.byte 0x00, 0x00
_080CFC1C: .4byte 0x0203C40C
_080CFC20: .4byte 0x0203C3F8
_080CFC24:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	bne _080CFC3E
	ldr r0, _080CFC84 @ =0x09849D78
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	ldrh r0, [r4, #0x34]
	ldr r1, _080CFC88 @ =0x09756810
	bl func_080028F8
	str r0, [r4, #0x00]
_080CFC3E:
	adds r5, r4, #0x0
	adds r5, #0x9C
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	bne _080CFC5A
	adds r0, r4, #0x0
	adds r0, #0x38
	movs r1, #0x06
	movs r2, #0x40
	movs r3, #0x00
	bl func_080122AC
	movs r0, #0x01
	strb r0, [r5, #0x00]
_080CFC5A:
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	movs r0, #0xC0
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	ldr r0, _080CFC8C @ =0x0000FFF0
	str r0, [sp, #0x00C]
	mov r0, r8
	adds r1, r7, #0x0
	bl func_080023E0
_080CFC76:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CFC84: .4byte 0x09849D78
_080CFC88: .4byte 0x09756810
_080CFC8C: .4byte 0x0000FFF0
.syntax divided
