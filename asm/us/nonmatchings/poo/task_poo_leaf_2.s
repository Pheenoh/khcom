.syntax unified
	.align 2, 0
	.global task_poo_leaf_2
	.thumb
	.thumb_func
	.type task_poo_leaf_2, %function
task_poo_leaf_2: @ 080CF374
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r1, [r5, #0x24]
	asrs r1, r1, #0x08
	ldr r0, _080CF3DC @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	ldr r0, [r5, #0x28]
	asrs r0, r0, #0x08
	ldr r2, _080CF3E0 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r0, r0, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	mov r8, r1
	lsls r0, r0, #0x10
	asrs r7, r0, #0x10
	movs r4, #0x00
	str r4, [sp, #0x000]
	movs r0, #0x38
	str r0, [sp, #0x004]
	mov r0, r8
	adds r1, r7, #0x0
	movs r2, #0x00
	movs r3, #0x20
	bl func_080035CC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CF3E4
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	beq _080CF474
	ldr r0, [r5, #0x00]
	bl func_080028C0
	ldr r0, [r5, #0x04]
	bl func_08002C10
	str r4, [r5, #0x04]
	adds r0, r5, #0x0
	adds r0, #0x34
	bl func_08012304
	adds r0, r5, #0x0
	adds r0, #0x90
	strb r4, [r0, #0x00]
	b _080CF474
	.byte 0x00, 0x00
_080CF3DC: .4byte 0x0203C40C
_080CF3E0: .4byte 0x0203C3F8
_080CF3E4:
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	bne _080CF410
	adds r0, r5, #0x0
	adds r0, #0x92
	ldrh r0, [r0, #0x00]
	ldr r1, _080CF454 @ =0x0975C3E2
	bl func_080028F8
	str r0, [r5, #0x00]
	ldr r0, _080CF458 @ =0x09849DF8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x04]
	adds r0, r5, #0x0
	adds r0, #0x34
	movs r1, #0x06
	movs r2, #0x1C
	movs r3, #0x00
	bl func_080122AC
_080CF410:
	adds r6, r5, #0x0
	adds r6, #0x90
	ldrb r0, [r6, #0x00]
	cmp r0, #0x00
	beq _080CF474
	adds r4, r5, #0x0
	adds r4, #0x0C
	adds r0, r4, #0x0
	bl func_08005A64
	str r0, [r5, #0x08]
	adds r0, r4, #0x0
	bl func_08005B1C
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x00
	bne _080CF460
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x00]
	ldr r0, [r5, #0x04]
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	ldr r0, _080CF45C @ =0x0000FFF1
	str r0, [sp, #0x00C]
	mov r0, r8
	adds r1, r7, #0x0
	bl func_080023E0
	b _080CF474
	.byte 0x00, 0x00
_080CF454: .4byte 0x0975C3E2
_080CF458: .4byte 0x09849DF8
_080CF45C: .4byte 0x0000FFF1
_080CF460:
	adds r0, r5, #0x0
	adds r0, #0x62
	ldrh r1, [r0, #0x00]
	movs r0, #0x02
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	bne _080CF474
	strb r0, [r6, #0x00]
_080CF474:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
