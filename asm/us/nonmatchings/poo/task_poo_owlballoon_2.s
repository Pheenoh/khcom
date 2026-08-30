.syntax unified
	.align 2, 0
	.global task_poo_owlballoon_2
	.thumb
	.thumb_func
	.type task_poo_owlballoon_2, %function
task_poo_owlballoon_2: @ 080CCA58
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	adds r0, #0x0C
	bl func_08005A64
	str r0, [r4, #0x08]
	ldr r1, [r4, #0x24]
	ldr r0, _080CCAC8 @ =0xFFFFF800
	adds r1, r1, r0
	asrs r1, r1, #0x08
	ldr r0, _080CCACC @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	ldr r0, [r4, #0x28]
	movs r2, #0x80
	lsls r2, r2, #0x05
	adds r0, r0, r2
	asrs r0, r0, #0x08
	ldr r2, _080CCAD0 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r0, r0, r2
	lsls r1, r1, #0x10
	asrs r7, r1, #0x10
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	movs r0, #0x18
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	movs r2, #0x40
	movs r3, #0x08
	bl func_080035CC
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x00
	beq _080CCAD4
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CCB38
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	movs r0, #0x00
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x34
	bl func_08012304
	b _080CCB38
	.byte 0x00, 0x00
_080CCAC8: .4byte 0xFFFFF800
_080CCACC: .4byte 0x0203C40C
_080CCAD0: .4byte 0x0203C3F8
_080CCAD4:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	bne _080CCB00
	adds r0, r4, #0x0
	adds r0, #0xC8
	ldrh r0, [r0, #0x00]
	ldr r1, _080CCB40 @ =0x0974B4D8
	bl func_080028F8
	str r0, [r4, #0x00]
	ldr r0, _080CCB44 @ =0x09849C98
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x34
	movs r1, #0x0A
	movs r2, #0x08
	movs r3, #0x10
	bl func_080122AC
_080CCB00:
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	ldr r1, [r4, #0x28]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r5, _080CCB48 @ =0xFFFFEFFD
	adds r0, r5, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	bl func_080023E0
	adds r4, #0xB0
	adds r0, r4, #0x0
	bl func_08000EA4
	adds r0, r4, #0x0
	bl func_08000EE0
_080CCB38:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CCB40: .4byte 0x0974B4D8
_080CCB44: .4byte 0x09849C98
_080CCB48: .4byte 0xFFFFEFFD
.syntax divided
