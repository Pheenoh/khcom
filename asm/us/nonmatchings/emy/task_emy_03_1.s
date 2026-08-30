.syntax unified
	.align 2, 0
	.global task_emy_03_1
	.thumb
	.thumb_func
	.type task_emy_03_1, %function
task_emy_03_1: @ 0803776C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x018
	adds r7, r0, #0x0
	adds r4, r7, #0x0
	movs r0, #0x3C
	adds r0, r0, r7
	mov r8, r0
	adds r0, r7, #0x0
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080377B4
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _080377A0
	cmp r1, #0x01
	beq _080377AA
	b _080377B4
_080377A0:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0x12
	b _080377B2
_080377AA:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0x13
_080377B2:
	str r0, [r1, #0x00]
_080377B4:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x12
	beq _080377C6
	cmp r0, #0x13
	beq _08037844
	b _080378EC
_080377C6:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r7, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	bne _080377FC
	movs r0, #0xB4
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldr r0, _080377F4 @ =0xFFFFFB80
	str r0, [r1, #0x00]
	ldr r0, _080377F8 @ =0x0813D544
	adds r1, r4, #0x0
	adds r1, #0x10
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	b _0803780C
	.byte 0x00, 0x00
_080377F4: .4byte 0xFFFFFB80
_080377F8: .4byte 0x0813D544
_080377FC:
	cmp r0, #0x01
	bne _0803780C
	mov r0, r8
	bl func_080141FC
	ldr r0, _0803783C @ =0x00000246
	bl func_0811FE70
_0803780C:
	movs r0, #0xAB
	str r0, [sp, #0x000]
	movs r0, #0x50
	str r0, [sp, #0x004]
	ldr r0, _08037840 @ =0x00000247
	str r0, [sp, #0x008]
	movs r0, #0x00
	str r0, [sp, #0x00C]
	str r0, [sp, #0x010]
	movs r0, #0x0A
	str r0, [sp, #0x014]
	adds r0, r7, #0x0
	movs r1, #0x11
	movs r2, #0x17
	movs r3, #0x0A
	bl func_0800C980
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x02
	bne _080378EC
	bl func_08006B4C
	b _080378EC
_0803783C: .4byte 0x00000246
_08037840: .4byte 0x00000247
_08037844:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r7, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	bne _0803786C
	ldr r0, _08037868 @ =0x0813D544
	adds r1, r4, #0x0
	adds r1, #0x10
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
	b _080378B2
	.byte 0x00, 0x00
_08037868: .4byte 0x0813D544
_0803786C:
	cmp r0, #0x01
	bne _080378B2
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r5, r4, r0
	movs r1, #0xC4
	lsls r1, r1, #0x01
	adds r6, r4, r1
	mov r0, r8
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	movs r3, #0x00
	bl func_0801C700
	movs r1, #0xC6
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r4, #0x00
	str r4, [r0, #0x00]
	mov r0, r8
	ldr r1, [r0, #0x04]
	ldr r2, [r0, #0x08]
	ldr r3, [r0, #0x0C]
	ldr r0, _080378DC @ =0xFFFFF000
	adds r3, r3, r0
	ldr r0, [r5, #0x00]
	str r0, [sp, #0x000]
	ldr r0, [r6, #0x00]
	str r0, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r0, #0xAC
	str r0, [sp, #0x00C]
	movs r0, #0x00
	bl func_08015834
_080378B2:
	movs r0, #0xB4
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0x00
	str r0, [r1, #0x00]
	adds r0, r7, #0x0
	adds r0, #0x10
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080378E0
	bl func_080128EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080378E0
	adds r0, r7, #0x0
	bl func_0800CB4C
	b _080378EC
_080378DC: .4byte 0xFFFFF000
_080378E0:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_080378EC:
	adds r0, r7, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x018
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
