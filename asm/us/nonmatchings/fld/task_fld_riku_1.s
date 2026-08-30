.syntax unified
	.align 2, 0
	.global task_fld_riku_1
	.thumb
	.thumb_func
	.type task_fld_riku_1, %function
task_fld_riku_1: @ 08036360
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x060
	adds r7, r0, #0x0
	mov r10, r1
	ldr r0, _080363AC @ =0x02039BA0
	mov r9, r0
	ldr r1, [r0, #0x00]
	mov r8, r1
	mov r6, r8
	adds r6, #0x18
	adds r5, r7, #0x0
	adds r5, #0xA4
	ldrh r1, [r5, #0x00]
	movs r0, #0x08
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x00
	beq _08036430
	ldr r0, _080363B0 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r5, #0x00]
	adds r1, r7, #0x0
	adds r1, #0x94
	ldr r0, [r1, #0x00]
	subs r0, #0x02
	mov r8, r1
	cmp r0, #0x0A
	bhi _08036428
	lsls r0, r0, #0x02
	ldr r1, _080363B4 @ =0x080363B8
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
_080363AC: .4byte 0x02039BA0
_080363B0: .4byte 0x0000FFF7
_080363B4: .4byte 0x080363B8
	.byte 0xEA, 0x63, 0x03, 0x08, 0xEA, 0x63, 0x03, 0x08, 0xEA, 0x63, 0x03, 0x08, 0xEA, 0x63, 0x03, 0x08
	.byte 0xF4, 0x63, 0x03, 0x08, 0xF4, 0x63, 0x03, 0x08, 0x18, 0x64, 0x03, 0x08, 0x18, 0x64, 0x03, 0x08
	.byte 0x18, 0x64, 0x03, 0x08, 0x28, 0x64, 0x03, 0x08, 0xE4, 0x63, 0x03, 0x08, 0x03, 0x20, 0x42, 0x46
	.byte 0x10, 0x60, 0x01, 0x49, 0x15, 0xE0, 0x00, 0x00, 0x89, 0x4C, 0x03, 0x08, 0x06, 0x49, 0x50, 0x46
	.byte 0xCA, 0xF7, 0xC8, 0xFD, 0x05, 0x48, 0x01, 0x68, 0x00, 0x20, 0x88, 0x66, 0x39, 0x1C, 0x98, 0x31
	.byte 0x01, 0x20, 0x08, 0x80, 0x8C, 0xE2, 0x00, 0x00, 0xDD, 0x53, 0x03, 0x08, 0xA0, 0x9B, 0x03, 0x02
	.byte 0x02, 0x49, 0x50, 0x46, 0xCA, 0xF7, 0xB6, 0xFD, 0x7E, 0xE2, 0x00, 0x00, 0xF1, 0x58, 0x03, 0x08
_08036428:
	movs r0, #0x00
	mov r3, r8
	str r0, [r3, #0x00]
	b _08036928
_08036430:
	bl func_080DFC24
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x00
	beq _08036478
	adds r0, r7, #0x0
	adds r0, #0x98
	strh r4, [r0, #0x00]
	ldr r1, _08036474 @ =0x08035AD5
	mov r0, r10
	bl func_08000F8C
	adds r0, r7, #0x0
	adds r0, #0x24
	bl func_08000EA4
	adds r1, r7, #0x0
	adds r1, #0x94
	movs r0, #0x0F
	str r0, [r1, #0x00]
	bl func_080DFC24
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _08036468
	b _08036954
_08036468:
	ldrh r0, [r5, #0x00]
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r5, #0x00]
	b _08036954
	.byte 0x00, 0x00
_08036474: .4byte 0x08035AD5
_08036478:
	mov r4, r9
	ldr r0, [r4, #0x00]
	ldr r2, [r0, #0x70]
	movs r4, #0x80
	lsls r4, r4, #0x0B
	ands r4, r2
	cmp r4, #0x00
	beq _0803649C
	adds r0, r7, #0x0
	adds r0, #0x98
	strh r1, [r0, #0x00]
	ldr r1, _08036498 @ =0x08034A0D
	mov r0, r10
	bl func_08000F8C
	b _0803694C
_08036498: .4byte 0x08034A0D
_0803649C:
	mov r0, r8
	ldr r5, [r0, #0x18]
	ldr r1, [r6, #0x04]
	str r1, [sp, #0x040]
	adds r0, r7, #0x0
	adds r0, #0x94
	ldr r1, [r0, #0x00]
	mov r8, r0
	cmp r1, #0x01
	bls _080364B2
	b _080365F0
_080364B2:
	movs r4, #0x80
	lsls r4, r4, #0x07
	ands r2, r4
	cmp r2, #0x00
	bne _08036524
	adds r0, r6, #0x0
	bl func_08034704
	mov r2, r9
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x70]
	ands r0, r4
	cmp r0, #0x00
	bne _08036524
	bl func_08001384
	movs r1, #0xF0
	ands r1, r0
	cmp r1, #0x00
	beq _08036524
	ldr r0, [r6, #0x10]
	adds r0, #0x80
	str r0, [r6, #0x10]
	adds r0, r7, #0x0
	movs r1, #0x02
	movs r2, #0x01
	bl func_0803473C
	ldr r0, [r6, #0x10]
	movs r1, #0xC0
	lsls r1, r1, #0x02
	cmp r0, r1
	ble _080364F6
	str r1, [r6, #0x10]
_080364F6:
	ldrh r0, [r7, #0x12]
	cmp r0, #0x00
	bne _0803653C
	ldrh r0, [r7, #0x16]
	cmp r0, #0x03
	beq _08036508
	cmp r0, #0x07
	beq _08036516
	b _0803653C
_08036508:
	adds r0, r7, #0x0
	adds r0, #0xAC
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x00]
	bl func_0811FE70
	b _0803653C
_08036516:
	adds r0, r7, #0x0
	adds r0, #0xAC
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x02]
	bl func_0811FE70
	b _0803653C
_08036524:
	adds r0, r7, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_0803473C
	ldr r0, [r6, #0x10]
	subs r0, #0x80
	str r0, [r6, #0x10]
	cmp r0, #0x00
	bge _0803653C
	movs r0, #0x00
	str r0, [r6, #0x10]
_0803653C:
	ldr r3, _080365B4 @ =0x08121400
	ldrb r0, [r6, #0x14]
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r4, #0x00
	ldsh r0, [r0, r4]
	ldr r2, [r6, #0x10]
	adds r1, r0, #0x0
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r6, #0x00]
	adds r0, r0, r1
	str r0, [r6, #0x00]
	ldrb r0, [r6, #0x14]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	adds r1, r0, #0x0
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r6, #0x04]
	adds r0, r0, r1
	str r0, [r6, #0x04]
	bl func_08001390
	movs r3, #0x02
	adds r1, r3, #0x0
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	cmp r4, #0x00
	beq _080365C0
	ldr r0, _080365B8 @ =0x02039BA0
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x70]
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r2, #0x70]
	movs r1, #0x00
	str r1, [r2, #0x68]
	adds r0, r7, #0x0
	adds r0, #0x98
	strh r1, [r0, #0x00]
	mov r2, r8
	str r3, [r2, #0x00]
	ldr r1, _080365BC @ =0x08034C89
	mov r0, r10
	bl func_08000F8C
	adds r0, r7, #0x0
	adds r0, #0xAC
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x04]
	bl func_0811FE70
	b _08036602
_080365B4: .4byte 0x08121400
_080365B8: .4byte 0x02039BA0
_080365BC: .4byte 0x08034C89
_080365C0:
	bl func_08001390
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _08036602
	adds r0, r7, #0x0
	adds r0, #0x98
	strh r4, [r0, #0x00]
	ldr r0, _080365E8 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	str r4, [r0, #0x68]
	movs r0, #0x0B
	mov r3, r8
	str r0, [r3, #0x00]
	ldr r1, _080365EC @ =0x08035DFD
	mov r0, r10
	bl func_08000F8C
	b _08036602
_080365E8: .4byte 0x02039BA0
_080365EC: .4byte 0x08035DFD
_080365F0:
	adds r0, r7, #0x0
	adds r0, #0x08
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08036602
	mov r0, r8
	str r4, [r0, #0x00]
_08036602:
	adds r0, r7, #0x0
	adds r0, #0x64
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08036648
	ldr r0, [r7, #0x6C]
	cmp r0, #0x05
	beq _08036648
	cmp r0, #0x05
	bhi _0803661C
	cmp r0, #0x03
	beq _08036648
	b _08036620
_0803661C:
	cmp r0, #0x0B
	beq _08036648
_08036620:
	adds r0, r7, #0x0
	adds r0, #0x66
	ldrh r1, [r0, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _08036648
	ldr r1, [r6, #0x10]
	movs r0, #0xE6
	muls r0, r1
	asrs r0, r0, #0x08
	str r0, [r6, #0x10]
	ldr r0, [r6, #0x00]
	ldr r1, [r7, #0x70]
	adds r0, r0, r1
	str r0, [r6, #0x00]
	ldr r0, [r6, #0x04]
	ldr r1, [r7, #0x74]
	adds r0, r0, r1
	str r0, [r6, #0x04]
_08036648:
	adds r0, r6, #0x0
	bl func_08034518
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08036656
	b _080368C2
_08036656:
	str r5, [r6, #0x00]
	ldr r1, [sp, #0x040]
	str r1, [r6, #0x04]
	adds r0, r6, #0x0
	adds r1, r7, #0x0
	bl func_080345EC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x00
	beq _080366B4
	cmp r0, #0x01
	beq _08036688
	cmp r0, #0x02
	beq _08036676
	b _080368C2
_08036676:
	adds r0, r7, #0x0
	adds r0, #0x98
	movs r1, #0x00
	strh r1, [r0, #0x00]
	movs r0, #0x06
	mov r2, r8
	str r0, [r2, #0x00]
	movs r0, #0xD3
	b _08036698
_08036688:
	adds r0, r7, #0x0
	adds r0, #0x98
	movs r1, #0x00
	strh r1, [r0, #0x00]
	movs r0, #0x06
	mov r3, r8
	str r0, [r3, #0x00]
	movs r0, #0x2D
_08036698:
	strb r0, [r6, #0x14]
	ldr r0, _080366AC @ =0x02039BA0
	ldr r0, [r0, #0x00]
	str r1, [r0, #0x68]
	ldr r1, _080366B0 @ =0x080353DD
	mov r0, r10
	bl func_08000F8C
	b _080368C2
	.byte 0x00, 0x00
_080366AC: .4byte 0x02039BA0
_080366B0: .4byte 0x080353DD
_080366B4:
	adds r0, r6, #0x0
	bl func_08034668
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080366E4
	ldr r0, [r7, #0x04]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, _080366E0 @ =0x02039BA0
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x70]
	movs r1, #0x10
	orrs r0, r1
	str r0, [r2, #0x70]
	b _08036954
	.byte 0x00, 0x00
_080366E0: .4byte 0x02039BA0
_080366E4:
	ldrb r0, [r6, #0x14]
	cmp r0, #0x53
	beq _08036730
	cmp r0, #0x53
	bgt _08036702
	cmp r0, #0x2D
	beq _08036758
	cmp r0, #0x2D
	bgt _080366FC
	cmp r0, #0x00
	beq _08036784
	b _080367D0
_080366FC:
	cmp r0, #0x40
	beq _0803679C
	b _080367D0
_08036702:
	cmp r0, #0xAD
	beq _0803671A
	cmp r0, #0xAD
	bgt _08036710
	cmp r0, #0x80
	beq _0803676C
	b _080367D0
_08036710:
	cmp r0, #0xC0
	beq _080367B4
	cmp r0, #0xD3
	beq _08036742
	b _080367D0
_0803671A:
	ldr r2, _0803672C @ =0xFFFFFF00
	movs r4, #0x00
	str r4, [sp, #0x044]
	mov r9, r4
	movs r5, #0xC0
	lsls r5, r5, #0x01
	str r5, [sp, #0x05C]
	b _080367DC
	.byte 0x00, 0x00
_0803672C: .4byte 0xFFFFFF00
_08036730:
	movs r2, #0x80
	lsls r2, r2, #0x01
	movs r0, #0x00
	str r0, [sp, #0x044]
	mov r9, r0
	movs r1, #0xC0
	lsls r1, r1, #0x01
	str r1, [sp, #0x05C]
	b _080367DC
_08036742:
	ldr r2, _08036750 @ =0xFFFFFF00
	movs r3, #0x00
	str r3, [sp, #0x044]
	mov r9, r3
	ldr r4, _08036754 @ =0xFFFFFE80
	str r4, [sp, #0x05C]
	b _080367DC
_08036750: .4byte 0xFFFFFF00
_08036754: .4byte 0xFFFFFE80
_08036758:
	movs r2, #0x80
	lsls r2, r2, #0x01
	movs r5, #0x00
	str r5, [sp, #0x044]
	mov r9, r5
	ldr r0, _08036768 @ =0xFFFFFE80
	str r0, [sp, #0x05C]
	b _080367DC
_08036768: .4byte 0xFFFFFE80
_0803676C:
	ldr r2, _08036780 @ =0xFFFFFE00
	movs r1, #0xC0
	str r1, [sp, #0x044]
	movs r3, #0x80
	lsls r3, r3, #0x02
	mov r9, r3
	movs r4, #0xC0
	str r4, [sp, #0x05C]
	b _080367DC
	.byte 0x00, 0x00
_08036780: .4byte 0xFFFFFE00
_08036784:
	ldr r2, _08036798 @ =0xFFFFFE00
	movs r5, #0xC0
	negs r5, r5
	str r5, [sp, #0x044]
	movs r0, #0x80
	lsls r0, r0, #0x02
	mov r9, r0
	str r5, [sp, #0x05C]
	b _080367DC
	.byte 0x00, 0x00
_08036798: .4byte 0xFFFFFE00
_0803679C:
	movs r2, #0xC0
	lsls r2, r2, #0x01
	ldr r1, _080367AC @ =0xFFFFFECD
	str r1, [sp, #0x044]
	mov r9, r2
	ldr r3, _080367B0 @ =0x00000133
	str r3, [sp, #0x05C]
	b _080367DC
_080367AC: .4byte 0xFFFFFECD
_080367B0: .4byte 0x00000133
_080367B4:
	ldr r2, _080367C4 @ =0xFFFFFE80
	ldr r4, _080367C8 @ =0xFFFFFECD
	str r4, [sp, #0x044]
	mov r9, r2
	ldr r5, _080367CC @ =0x00000133
	str r5, [sp, #0x05C]
	b _080367DC
	.byte 0x00, 0x00
_080367C4: .4byte 0xFFFFFE80
_080367C8: .4byte 0xFFFFFECD
_080367CC: .4byte 0x00000133
_080367D0:
	movs r0, #0x00
	str r0, [sp, #0x05C]
	mov r9, r0
	movs r1, #0x00
	str r1, [sp, #0x044]
	movs r2, #0x00
_080367DC:
	mov r3, sp
	adds r3, #0x10
	str r3, [sp, #0x050]
	mov r12, r3
	str r6, [sp, #0x058]
	mov r4, r12
	adds r5, r6, #0x0
	ldm r5!, {r0, r1, r3}
	stm r4!, {r0, r1, r3}
	ldr r0, [r5, #0x00]
	str r0, [r4, #0x00]
	mov r12, sp
	ldr r4, [sp, #0x050]
	str r4, [sp, #0x058]
	mov r5, r12
	adds r0, r4, #0x0
	ldm r0!, {r1, r3, r4}
	stm r5!, {r1, r3, r4}
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x00]
	ldr r0, [sp, #0x000]
	adds r0, r0, r2
	str r0, [sp, #0x000]
	ldr r0, [sp, #0x004]
	ldr r5, [sp, #0x044]
	adds r0, r0, r5
	str r0, [sp, #0x004]
	ldr r0, [sp, #0x010]
	add r0, r9
	str r0, [sp, #0x010]
	ldr r1, [sp, #0x050]
	ldr r0, [r1, #0x04]
	ldr r3, [sp, #0x05C]
	adds r0, r0, r3
	str r0, [r1, #0x04]
	mov r0, sp
	str r2, [sp, #0x048]
	bl func_08034518
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, [sp, #0x050]
	bl func_08034518
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, [sp, #0x048]
	cmp r4, #0x00
	beq _0803687E
	cmp r0, #0x00
	bne _080368BE
	mov r4, sp
	adds r4, #0x20
	str r4, [sp, #0x054]
	adds r1, r4, #0x0
	adds r0, r6, #0x0
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x020]
	add r0, r9
	str r0, [sp, #0x020]
	ldr r0, [r4, #0x04]
	ldr r4, [sp, #0x05C]
	adds r0, r0, r4
	ldr r5, [sp, #0x054]
	str r0, [r5, #0x04]
	ldr r0, [sp, #0x054]
	bl func_0803459C
	str r0, [r5, #0x0C]
	ldr r1, [r5, #0x08]
	cmp r0, r1
	blt _080368BE
	adds r0, r6, #0x0
	ldr r1, [sp, #0x054]
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	b _080368BA
_0803687E:
	cmp r0, #0x00
	beq _080368BE
	add r5, sp, #0x030
	mov r9, r5
	mov r1, r9
	adds r0, r6, #0x0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x030]
	adds r0, r0, r2
	str r0, [sp, #0x030]
	mov r1, r9
	ldr r0, [r1, #0x04]
	ldr r2, [sp, #0x044]
	adds r0, r0, r2
	str r0, [r1, #0x04]
	mov r0, r9
	bl func_0803459C
	mov r3, r9
	str r0, [r3, #0x0C]
	ldr r1, [r3, #0x08]
	cmp r0, r1
	blt _080368BE
	adds r0, r6, #0x0
	mov r1, r9
	ldm r1!, {r2, r4, r5}
	stm r0!, {r2, r4, r5}
_080368BA:
	ldr r1, [r1, #0x00]
	str r1, [r0, #0x00]
_080368BE:
	movs r0, #0x00
	str r0, [r6, #0x10]
_080368C2:
	adds r0, r7, #0x0
	bl func_080346C0
	adds r2, r0, #0x0
	ldr r1, [r6, #0x0C]
	movs r0, #0x80
	lsls r0, r0, #0x0D
	cmp r1, r0
	bne _080368DA
	ldr r0, [r6, #0x08]
	str r0, [r6, #0x0C]
	b _08036928
_080368DA:
	ldr r0, [r6, #0x08]
	cmp r2, r0
	beq _0803691C
	ldr r0, [r6, #0x10]
	asrs r0, r0, #0x02
	str r0, [r6, #0x10]
	adds r0, r7, #0x0
	adds r0, #0xA0
	movs r1, #0x00
	str r1, [r0, #0x00]
	subs r0, #0x08
	strh r1, [r0, #0x00]
	ldr r0, _08036914 @ =0x02039BA0
	ldr r2, [r0, #0x00]
	str r1, [r2, #0x68]
	ldr r0, [r2, #0x70]
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r2, #0x70]
	movs r0, #0x04
	mov r3, r8
	str r0, [r3, #0x00]
	ldr r1, _08036918 @ =0x08034C89
	mov r0, r10
	bl func_08000F8C
	b _08036928
	.byte 0x00, 0x00
_08036914: .4byte 0x02039BA0
_08036918: .4byte 0x08034C89
_0803691C:
	cmp r2, r1
	beq _08036928
	ldr r0, _08036968 @ =0x02039BA0
	ldr r1, [r0, #0x00]
	movs r0, #0x00
	str r0, [r1, #0x68]
_08036928:
	adds r0, r7, #0x0
	adds r0, #0x38
	ldr r1, [r6, #0x00]
	ldr r2, [r6, #0x04]
	ldr r3, [r6, #0x08]
	bl func_08012324
	ldr r0, [r6, #0x00]
	ldr r1, [r6, #0x04]
	ldr r2, [r6, #0x08]
	adds r1, r1, r2
	bl func_080E0298
	adds r0, r7, #0x0
	adds r0, #0x08
	bl func_08005A64
	str r0, [r7, #0x20]
_0803694C:
	adds r0, r7, #0x0
	adds r0, #0x24
	bl func_08000EA4
_08036954:
	movs r0, #0x01
	add sp, #0x060
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08036968: .4byte 0x02039BA0
.syntax divided
