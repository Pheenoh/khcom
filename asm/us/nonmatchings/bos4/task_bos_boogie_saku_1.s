.syntax unified
	.align 2, 0
	.global task_bos_boogie_saku_1
	.thumb
	.thumb_func
	.type task_bos_boogie_saku_1, %function
task_bos_boogie_saku_1: @ 080DA7C0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0x0
	ldr r6, _080DA828 @ =0x0203C560
	ldrh r0, [r6, #0x00]
	cmp r0, #0x02
	bls _080DA87C
	adds r4, r5, #0x0
	adds r4, #0x08
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	adds r7, r4, #0x0
	movs r1, #0x28
	adds r1, r1, r5
	mov r8, r1
	cmp r0, #0x00
	beq _080DA874
	ldr r3, _080DA82C @ =0x0203C554
	ldrh r0, [r5, #0x20]
	ldrh r1, [r3, #0x00]
	cmp r0, r1
	bcs _080DA83C
	cmp r0, #0x00
	bne _080DA7FA
	bl func_0802F1E8
_080DA7FA:
	ldrh r0, [r5, #0x20]
	adds r0, #0x01
	strh r0, [r5, #0x20]
	movs r1, #0xB8
	lsls r1, r1, #0x01
	movs r2, #0x8A
	lsls r2, r2, #0x02
	movs r3, #0x9E
	lsls r3, r3, #0x02
	movs r0, #0x80
	bl func_0801A920
	bl func_080DA73C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DA830
	ldr r0, [r5, #0x24]
	adds r0, #0x40
	movs r1, #0x00
	bl func_0801C2DC
	b _080DA874
_080DA828: .4byte 0x0203C560
_080DA82C: .4byte 0x0203C554
_080DA830:
	ldr r0, [r5, #0x24]
	adds r0, #0x40
	movs r1, #0x01
	bl func_0801C2DC
	b _080DA874
_080DA83C:
	ldr r0, [r5, #0x24]
	ldr r0, [r0, #0x00]
	cmp r0, #0x04
	beq _080DA874
	adds r2, r5, #0x0
	adds r2, #0x40
	movs r1, #0x00
	movs r0, #0x01
	strb r0, [r2, #0x00]
	strh r1, [r6, #0x00]
	strh r1, [r5, #0x20]
	strh r1, [r3, #0x00]
	ldr r0, [r5, #0x24]
	adds r0, #0x40
	movs r1, #0x01
	bl func_0801C2DC
	bl func_080DA73C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DA874
	ldr r1, _080DA8B8 @ =0x09EF5040
	ldr r2, [r5, #0x24]
	mov r0, r8
	bl TaskCreate
	str r0, [r5, #0x3C]
_080DA874:
	ldr r0, _080DA8BC @ =0x0203C560
	ldrh r0, [r0, #0x00]
	cmp r0, #0x02
	bhi _080DA8D6
_080DA87C:
	ldr r0, [r5, #0x3C]
	bl func_08000F48
	lsls r0, r0, #0x18
	adds r7, r5, #0x0
	adds r7, #0x08
	movs r1, #0x28
	adds r1, r1, r5
	mov r8, r1
	cmp r0, #0x00
	bne _080DA8D6
	movs r1, #0xB8
	lsls r1, r1, #0x01
	movs r2, #0x90
	lsls r2, r2, #0x02
	movs r3, #0x9E
	lsls r3, r3, #0x02
	movs r0, #0x80
	bl func_0801A920
	ldr r0, _080DA8BC @ =0x0203C560
	ldrh r6, [r0, #0x00]
	cmp r6, #0x00
	beq _080DA8C0
	adds r1, r6, #0x0
	adds r0, r7, #0x0
	movs r2, #0x00
	bl AnimChange
	b _080DA8D6
_080DA8B8: .4byte 0x09EF5040
_080DA8BC: .4byte 0x0203C560
_080DA8C0:
	adds r4, r5, #0x0
	adds r4, #0x40
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080DA8D6
	adds r0, r7, #0x0
	movs r1, #0x03
	movs r2, #0x00
	bl AnimChange
	strb r6, [r4, #0x00]
_080DA8D6:
	adds r0, r7, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080DA94C @ =0x0203C560
	ldrh r0, [r0, #0x00]
	cmp r0, #0x02
	bhi _080DA906
	cmp r0, #0x00
	bne _080DA90C
	adds r0, r7, #0x0
	bl func_08005B30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x03
	bne _080DA90C
	ldr r0, [r5, #0x3C]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080DA90C
_080DA906:
	adds r0, r7, #0x0
	bl AnimUpdate
_080DA90C:
	cmp r4, #0x00
	bne _080DA93A
	adds r0, r7, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DA93A
	ldr r0, _080DA950 @ =0x00000255
	bl m4aSongNumStart
	adds r0, r7, #0x0
	bl func_08005B30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x03
	bne _080DA93A
	adds r0, r7, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimChange
_080DA93A:
	mov r0, r8
	bl TaskPoolUpdate
	movs r0, #0x01
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080DA94C: .4byte 0x0203C560
_080DA950: .4byte 0x00000255
.syntax divided
