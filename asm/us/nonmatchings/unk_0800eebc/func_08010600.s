.syntax unified
	.align 2, 0
	.global func_08010600
	.thumb
	.thumb_func
	.type func_08010600, %function
func_08010600: @ 08010600
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r2, #0x0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r6, r4, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	mov r5, r8
	movs r0, #0x00
	mov r9, r0
	adds r0, r4, #0x0
	adds r1, r7, #0x0
	bl func_08010548
	ldr r0, _08010700 @ =0x020348D4
	lsls r3, r7, #0x01
	adds r0, r3, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x02
	bne _0801063E
	ldr r0, _08010704 @ =0x020348DC
	adds r0, r3, r0
	ldrh r2, [r0, #0x00]
	ldr r1, _08010708 @ =0x0000FDFF
	ands r1, r2
	strh r1, [r0, #0x00]
_0801063E:
	ldr r0, _0801070C @ =0x020348D8
	adds r1, r3, r0
	ldrh r1, [r1, #0x00]
	ldr r2, _08010704 @ =0x020348DC
	mov r12, r2
	mov r10, r0
	cmp r1, #0x02
	bne _08010658
	adds r2, r3, r2
	ldrh r1, [r2, #0x00]
	ldr r0, _08010710 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2, #0x00]
_08010658:
	movs r1, #0x80
	lsls r1, r1, #0x02
	mov r0, r8
	ands r0, r1
	cmp r0, #0x00
	beq _0801066E
	movs r0, #0x80
	lsls r0, r0, #0x01
	ands r0, r4
	cmp r0, #0x00
	bne _0801067E
_0801066E:
	movs r0, #0x80
	lsls r0, r0, #0x01
	ands r5, r0
	cmp r5, #0x00
	beq _08010694
	ands r6, r1
	cmp r6, #0x00
	beq _08010694
_0801067E:
	lsls r3, r7, #0x01
	mov r4, r12
	adds r2, r3, r4
	ldrh r1, [r2, #0x00]
	movs r5, #0xC0
	lsls r5, r5, #0x02
	adds r0, r5, #0x0
	orrs r0, r1
	strh r0, [r2, #0x00]
	adds r0, r5, #0x0
	mov r9, r0
_08010694:
	mov r2, r12
	adds r4, r3, r2
	ldrh r2, [r4, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x02
	adds r0, r1, #0x0
	ands r0, r2
	cmp r0, #0x00
	bne _080106C2
	ldr r0, _08010714 @ =0x020348CC
	adds r0, r3, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x05
	beq _080106BA
	ldr r0, _08010700 @ =0x020348D4
	adds r0, r3, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080106C2
_080106BA:
	adds r0, r1, #0x0
	orrs r0, r2
	strh r0, [r4, #0x00]
	mov r9, r1
_080106C2:
	mov r5, r12
	adds r4, r3, r5
	ldrh r2, [r4, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r1, #0x0
	ands r0, r2
	cmp r0, #0x00
	bne _080106F0
	ldr r0, _08010718 @ =0x020348D0
	adds r0, r3, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x05
	beq _080106E8
	mov r5, r10
	adds r0, r3, r5
	ldrh r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080106F0
_080106E8:
	adds r0, r1, #0x0
	orrs r0, r2
	strh r0, [r4, #0x00]
	mov r9, r1
_080106F0:
	mov r0, r9
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08010700: .4byte 0x020348D4
_08010704: .4byte 0x020348DC
_08010708: .4byte 0x0000FDFF
_0801070C: .4byte 0x020348D8
_08010710: .4byte 0x0000FEFF
_08010714: .4byte 0x020348CC
_08010718: .4byte 0x020348D0
.syntax divided
