.syntax unified
	.align 2, 0
	.global task_poo_eeyoretail_2
	.thumb
	.thumb_func
	.type task_poo_eeyoretail_2, %function
task_poo_eeyoretail_2: @ 080CF96C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r0, [r5, #0x0C]
	asrs r0, r0, #0x08
	ldr r1, _080CF9C8 @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, [r5, #0x10]
	asrs r1, r1, #0x08
	ldr r2, [r5, #0x14]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	ldr r2, _080CF9CC @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r2, r0, #0x10
	mov r8, r2
	asrs r0, r0, #0x10
	lsrs r4, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x08
	str r2, [sp, #0x000]
	str r2, [sp, #0x004]
	movs r3, #0x08
	bl func_080035CC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CF9D0
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	beq _080CFA3E
	ldr r0, [r5, #0x00]
	bl func_080028C0
	ldr r0, [r5, #0x04]
	bl func_08002C10
	movs r0, #0x00
	str r0, [r5, #0x04]
	b _080CFA3E
_080CF9C8: .4byte 0x0203C40C
_080CF9CC: .4byte 0x0203C3F8
_080CF9D0:
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	bne _080CF9EA
	ldrh r0, [r5, #0x1C]
	ldr r1, _080CF9FC @ =0x097448BA
	bl func_080028F8
	str r0, [r5, #0x00]
	ldr r0, _080CFA00 @ =0x09849C58
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x04]
_080CF9EA:
	bl func_080CFA70
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CFA08
	movs r7, #0x80
	lsls r7, r7, #0x04
	ldr r6, _080CFA04 @ =0x0000FFEF
	b _080CFA0E
_080CF9FC: .4byte 0x097448BA
_080CFA00: .4byte 0x09849C58
_080CFA04: .4byte 0x0000FFEF
_080CFA08:
	movs r7, #0x80
	lsls r7, r7, #0x03
	movs r6, #0x0A
_080CFA0E:
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r7, [sp, #0x008]
	str r6, [sp, #0x00C]
	bl func_080023E0
	bl func_080C9D84
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CFA3E
	adds r0, r5, #0x0
	adds r0, #0x24
	bl func_08000EE0
_080CFA3E:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
