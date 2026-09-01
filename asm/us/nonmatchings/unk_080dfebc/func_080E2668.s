.syntax unified
	.align 2, 0
	.global func_080E2668
	.thumb
	.thumb_func
	.type func_080E2668, %function
func_080E2668: @ 080E2668
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x000]
	adds r0, r1, #0x0
	bl func_080DFB7C
	mov r10, r0
	ldrh r1, [r0, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _080E2690
	b _080E2AF6
_080E2690:
	ldrh r0, [r5, #0x02]
	ldrh r1, [r5, #0x00]
	subs r0, r0, r1
	lsls r6, r0, #0x10
	lsrs r0, r6, #0x10
	str r0, [sp, #0x004]
	ldr r1, [sp, #0x000]
	cmp r1, #0x00
	bne _080E2786
	bl GetRandom
	adds r1, r0, #0x0
	ldr r2, [sp, #0x004]
	lsls r0, r2, #0x02
	adds r0, r0, r2
	lsrs r4, r0, #0x03
	ldrh r0, [r5, #0x00]
	adds r4, r4, r0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	lsrs r1, r6, #0x12
	bl __umodsi3
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r1, #0x00
	mov r8, r1
	ldr r2, [sp, #0x004]
	cmp r8, r2
	bge _080E2786
_080E26CE:
	ldr r0, _080E2748 @ =0x02034F2C
	ldrh r6, [r0, #0x00]
	ldr r0, _080E274C @ =0x02034F2E
	ldrh r0, [r0, #0x00]
	cmp r6, r0
	bhi _080E2762
	lsls r0, r4, #0x10
	asrs r7, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x04
	mov r9, r0
_080E26E4:
	lsls r0, r6, #0x10
	asrs r3, r0, #0x10
	adds r0, r7, #0x0
	adds r1, r3, #0x0
	str r3, [sp, #0x008]
	bl func_080E08BC
	adds r2, r0, #0x0
	ldrb r0, [r2, #0x02]
	ldr r3, [sp, #0x008]
	cmp r0, #0x06
	bne _080E2754
	ldr r1, [r2, #0x0C]
	ldr r0, [r5, #0x04]
	cmp r1, r0
	bne _080E2754
	ldr r1, [r2, #0x08]
	ldr r0, _080E2750 @ =0xFFF00000
	cmp r1, r0
	bne _080E2754
	ldrh r1, [r2, #0x00]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	bne _080E2754
	mov r1, r10
	strh r4, [r1, #0x02]
	strh r6, [r1, #0x04]
	ldrh r0, [r2, #0x00]
	mov r1, r9
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x03
	orrs r0, r1
	strh r0, [r2, #0x00]
	adds r5, r6, #0x1
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	adds r0, r7, #0x0
	adds r1, r5, #0x0
	str r3, [sp, #0x008]
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	mov r2, r9
	orrs r1, r2
	strh r1, [r0, #0x00]
	subs r4, #0x01
	b _080E2A4E
	.byte 0x00, 0x00
_080E2748: .4byte 0x02034F2C
_080E274C: .4byte 0x02034F2E
_080E2750: .4byte 0xFFF00000
_080E2754:
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _080E2774 @ =0x02034F2E
	ldrh r0, [r0, #0x00]
	cmp r6, r0
	bls _080E26E4
_080E2762:
	ldrh r0, [r5, #0x02]
	subs r0, #0x01
	cmp r4, r0
	bge _080E2778
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _080E277A
	.byte 0x00, 0x00
_080E2774: .4byte 0x02034F2E
_080E2778:
	ldrh r0, [r5, #0x00]
_080E277A:
	adds r4, r0, #0x0
	movs r0, #0x01
	add r8, r0
	ldr r1, [sp, #0x004]
	cmp r8, r1
	blt _080E26CE
_080E2786:
	ldr r2, [sp, #0x000]
	cmp r2, #0x02
	beq _080E278E
	b _080E2892
_080E278E:
	bl GetRandom
	adds r1, r0, #0x0
	ldr r2, [sp, #0x004]
	lsls r0, r2, #0x02
	adds r0, r0, r2
	lsrs r4, r0, #0x03
	ldrh r0, [r5, #0x00]
	adds r4, r4, r0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x004]
	lsrs r1, r2, #0x02
	bl __umodsi3
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0x00
	mov r8, r0
	b _080E288C
_080E27B8:
	ldr r0, _080E2858 @ =0x02034F2C
	ldrh r6, [r0, #0x00]
	ldr r0, _080E285C @ =0x02034F2E
	ldrh r0, [r0, #0x00]
	cmp r6, r0
	bhi _080E286E
	lsls r0, r4, #0x10
	asrs r3, r0, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x04
	mov r9, r2
_080E27CE:
	lsls r0, r6, #0x10
	asrs r7, r0, #0x10
	adds r0, r3, #0x0
	adds r1, r7, #0x0
	str r3, [sp, #0x008]
	bl func_080E08BC
	adds r2, r0, #0x0
	ldrb r0, [r2, #0x02]
	ldr r3, [sp, #0x008]
	cmp r0, #0x03
	bne _080E2860
	ldr r1, [r2, #0x08]
	ldr r0, [r5, #0x04]
	cmp r1, r0
	bne _080E2860
	ldr r1, [r2, #0x0C]
	movs r0, #0x80
	lsls r0, r0, #0x0D
	cmp r1, r0
	bne _080E2860
	ldrh r1, [r2, #0x00]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	bne _080E2860
	mov r0, r10
	strh r4, [r0, #0x02]
	strh r6, [r0, #0x04]
	adds r0, r3, #0x0
	adds r1, r7, #0x0
	str r3, [sp, #0x008]
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	mov r2, r9
	orrs r1, r2
	strh r1, [r0, #0x00]
	subs r5, r6, #0x1
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	ldr r3, [sp, #0x008]
	adds r0, r3, #0x0
	adds r1, r5, #0x0
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	mov r2, r9
	orrs r1, r2
	strh r1, [r0, #0x00]
	subs r4, #0x01
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0x0
	adds r1, r7, #0x0
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	mov r2, r9
	orrs r1, r2
	strh r1, [r0, #0x00]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	mov r2, r9
	b _080E2AB2
	.byte 0x00, 0x00
_080E2858: .4byte 0x02034F2C
_080E285C: .4byte 0x02034F2E
_080E2860:
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _080E2880 @ =0x02034F2E
	ldrh r0, [r0, #0x00]
	cmp r6, r0
	bls _080E27CE
_080E286E:
	ldrh r0, [r5, #0x02]
	subs r0, #0x01
	cmp r4, r0
	bge _080E2884
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _080E2886
	.byte 0x00, 0x00
_080E2880: .4byte 0x02034F2E
_080E2884:
	ldrh r0, [r5, #0x00]
_080E2886:
	adds r4, r0, #0x0
	movs r0, #0x01
	add r8, r0
_080E288C:
	ldr r1, [sp, #0x004]
	cmp r8, r1
	blt _080E27B8
_080E2892:
	ldr r2, [sp, #0x000]
	cmp r2, #0x01
	beq _080E289A
	b _080E29A0
_080E289A:
	bl GetRandom
	adds r1, r0, #0x0
	ldr r2, [sp, #0x004]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsrs r4, r0, #0x03
	ldrh r0, [r5, #0x00]
	adds r4, r4, r0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x004]
	lsrs r1, r2, #0x02
	bl __umodsi3
	subs r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0x00
	mov r8, r0
	ldr r1, [sp, #0x004]
	cmp r8, r1
	bge _080E29A0
_080E28C8:
	ldr r0, _080E2968 @ =0x02034F2C
	ldrh r6, [r0, #0x00]
	ldr r0, _080E296C @ =0x02034F2E
	ldrh r0, [r0, #0x00]
	cmp r6, r0
	bhi _080E297E
	lsls r0, r4, #0x10
	asrs r3, r0, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x04
	mov r9, r2
_080E28DE:
	lsls r0, r6, #0x10
	asrs r7, r0, #0x10
	adds r0, r3, #0x0
	adds r1, r7, #0x0
	str r3, [sp, #0x008]
	bl func_080E08BC
	adds r2, r0, #0x0
	ldrb r0, [r2, #0x02]
	ldr r3, [sp, #0x008]
	cmp r0, #0x05
	bne _080E2970
	ldr r1, [r2, #0x08]
	ldr r0, [r5, #0x04]
	cmp r1, r0
	bne _080E2970
	ldr r1, [r2, #0x0C]
	movs r0, #0x80
	lsls r0, r0, #0x0D
	cmp r1, r0
	bne _080E2970
	ldrh r1, [r2, #0x00]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	bne _080E2970
	mov r0, r10
	strh r4, [r0, #0x02]
	strh r6, [r0, #0x04]
	adds r0, r3, #0x0
	adds r1, r7, #0x0
	str r3, [sp, #0x008]
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	mov r2, r9
	orrs r1, r2
	strh r1, [r0, #0x00]
	subs r5, r6, #0x1
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	ldr r3, [sp, #0x008]
	adds r0, r3, #0x0
	adds r1, r5, #0x0
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	mov r2, r9
	orrs r1, r2
	strh r1, [r0, #0x00]
	adds r4, #0x01
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0x0
	adds r1, r7, #0x0
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	mov r2, r9
	orrs r1, r2
	strh r1, [r0, #0x00]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	mov r2, r9
	b _080E2AB2
	.byte 0x00, 0x00
_080E2968: .4byte 0x02034F2C
_080E296C: .4byte 0x02034F2E
_080E2970:
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _080E2988 @ =0x02034F2E
	ldrh r0, [r0, #0x00]
	cmp r6, r0
	bls _080E28DE
_080E297E:
	ldrh r0, [r5, #0x00]
	cmp r4, r0
	bls _080E298C
	subs r0, r4, #0x1
	b _080E2990
_080E2988: .4byte 0x02034F2E
_080E298C:
	ldrh r0, [r5, #0x02]
	subs r0, #0x01
_080E2990:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r0, #0x0
	movs r1, #0x01
	add r8, r1
	ldr r2, [sp, #0x004]
	cmp r8, r2
	blt _080E28C8
_080E29A0:
	ldr r0, [sp, #0x000]
	cmp r0, #0x03
	beq _080E29A8
	b _080E2AF6
_080E29A8:
	bl GetRandom
	adds r1, r0, #0x0
	ldr r2, [sp, #0x004]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsrs r4, r0, #0x03
	ldrh r0, [r5, #0x00]
	adds r4, r4, r0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x004]
	lsrs r1, r2, #0x02
	bl __umodsi3
	subs r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0x00
	mov r8, r0
	ldr r1, [sp, #0x004]
	cmp r8, r1
	blt _080E29D8
	b _080E2AF6
_080E29D8:
	ldr r0, _080E2AB8 @ =0x02034F2C
	ldrh r6, [r0, #0x00]
	ldr r0, _080E2ABC @ =0x02034F2E
	ldrh r0, [r0, #0x00]
	cmp r6, r0
	bhi _080E2AD2
	lsls r0, r4, #0x10
	asrs r7, r0, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x04
	mov r9, r2
_080E29EE:
	lsls r0, r6, #0x10
	asrs r3, r0, #0x10
	adds r0, r7, #0x0
	adds r1, r3, #0x0
	str r3, [sp, #0x008]
	bl func_080E08BC
	adds r2, r0, #0x0
	ldrb r0, [r2, #0x02]
	ldr r3, [sp, #0x008]
	cmp r0, #0x04
	bne _080E2AC4
	ldr r1, [r2, #0x0C]
	ldr r0, [r5, #0x04]
	cmp r1, r0
	bne _080E2AC4
	ldr r1, [r2, #0x08]
	ldr r0, _080E2AC0 @ =0xFFF00000
	cmp r1, r0
	bne _080E2AC4
	ldrh r1, [r2, #0x00]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	bne _080E2AC4
	mov r0, r10
	strh r4, [r0, #0x02]
	strh r6, [r0, #0x04]
	ldrh r0, [r2, #0x00]
	mov r1, r9
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x03
	orrs r0, r1
	strh r0, [r2, #0x00]
	adds r5, r6, #0x1
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	adds r0, r7, #0x0
	adds r1, r5, #0x0
	str r3, [sp, #0x008]
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	mov r2, r9
	orrs r1, r2
	strh r1, [r0, #0x00]
	adds r4, #0x01
_080E2A4E:
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0x0
	ldr r3, [sp, #0x008]
	adds r1, r3, #0x0
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	mov r2, r9
	orrs r1, r2
	strh r1, [r0, #0x00]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	mov r2, r9
	orrs r1, r2
	strh r1, [r0, #0x00]
	subs r1, r6, #0x1
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r7, #0x0
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x03
	orrs r1, r2
	strh r1, [r0, #0x00]
	subs r1, r6, #0x2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r7, #0x0
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x03
	orrs r1, r2
	strh r1, [r0, #0x00]
	subs r1, r6, #0x3
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r7, #0x0
	bl func_080E08BC
	ldrh r1, [r0, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x03
_080E2AB2:
	orrs r1, r2
	strh r1, [r0, #0x00]
	b _080E2AF6
_080E2AB8: .4byte 0x02034F2C
_080E2ABC: .4byte 0x02034F2E
_080E2AC0: .4byte 0xFFF00000
_080E2AC4:
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _080E2ADC @ =0x02034F2E
	ldrh r0, [r0, #0x00]
	cmp r6, r0
	bls _080E29EE
_080E2AD2:
	ldrh r0, [r5, #0x00]
	cmp r4, r0
	bls _080E2AE0
	subs r0, r4, #0x1
	b _080E2AE4
_080E2ADC: .4byte 0x02034F2E
_080E2AE0:
	ldrh r0, [r5, #0x02]
	subs r0, #0x01
_080E2AE4:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r0, #0x0
	movs r1, #0x01
	add r8, r1
	ldr r2, [sp, #0x004]
	cmp r8, r2
	bge _080E2AF6
	b _080E29D8
_080E2AF6:
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
