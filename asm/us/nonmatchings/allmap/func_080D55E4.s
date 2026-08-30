.syntax unified
	.align 2, 0
	.global func_080D55E4
	.thumb
	.thumb_func
	.type func_080D55E4, %function
func_080D55E4: @ 080D55E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r6, #0x00
	ldr r0, _080D5610 @ =0x0203C4B4
	ldr r0, [r0, #0x00]
	adds r0, #0x94
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x04]
	mov r8, r0
	ldr r4, [r0, #0x30]
	bl func_0800139C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	beq _080D5638
	cmp r0, #0x20
	bgt _080D5614
	cmp r0, #0x10
	beq _080D5634
	b _080D566A
_080D5610: .4byte 0x0203C4B4
_080D5614:
	cmp r0, #0x40
	beq _080D561E
	cmp r0, #0x80
	beq _080D5650
	b _080D566A
_080D561E:
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D5630 @ =0xFFFF0000
	ands r4, r1
	orrs r4, r0
	lsrs r0, r4, #0x10
	subs r0, #0x01
	b _080D5660
_080D5630: .4byte 0xFFFF0000
_080D5634:
	adds r0, r4, #0x1
	b _080D5652
_080D5638:
	subs r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D564C @ =0xFFFF0000
	ands r4, r1
	orrs r4, r0
	lsrs r0, r4, #0x10
	subs r0, #0x01
	b _080D5660
	.byte 0x00, 0x00
_080D564C: .4byte 0xFFFF0000
_080D5650:
	subs r0, r4, #0x1
_080D5652:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D56FC @ =0xFFFF0000
	ands r4, r1
	orrs r4, r0
	lsrs r0, r4, #0x10
	adds r0, #0x01
_080D5660:
	lsls r0, r0, #0x10
	ldr r1, _080D5700 @ =0x0000FFFF
	ands r4, r1
	orrs r4, r0
	movs r6, #0x01
_080D566A:
	adds r0, r4, #0x0
	bl func_080D5494
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r5, r1, #0x0
	cmp r1, #0xFF
	beq _080D575A
	mov r0, r8
	str r4, [r0, #0x30]
	ldr r7, _080D5704 @ =0x0203C4B4
	ldr r0, [r7, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xC0
	ldrb r0, [r2, #0x00]
	cmp r0, r1
	beq _080D575A
	strb r1, [r2, #0x00]
	ldr r0, _080D5708 @ =0x0203C538
	strb r1, [r0, #0x00]
	cmp r6, #0x00
	beq _080D56A0
	movs r0, #0x65
	bl func_0811FE70
	bl func_080D54FC
_080D56A0:
	ldr r0, [r7, #0x00]
	adds r0, #0x98
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D56BC
	ldr r0, [r7, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x98
	ldr r1, [r1, #0x00]
	bl func_08000DE8
_080D56BC:
	adds r0, r5, #0x0
	bl func_080DEE18
	adds r4, r0, #0x0
	ldrb r0, [r4, #0x08]
	cmp r0, #0x1A
	beq _080D5710
	adds r0, r5, #0x0
	movs r1, #0x02
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D56E6
	adds r0, r5, #0x0
	movs r1, #0x08
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D5710
_080D56E6:
	ldr r0, [r7, #0x00]
	ldr r1, _080D570C @ =0x09EF4DF0
	adds r2, r4, #0x0
	adds r2, #0x08
	bl func_08000E14
	ldr r1, [r7, #0x00]
	adds r1, #0x98
	str r0, [r1, #0x00]
	b _080D571E
	.byte 0x00, 0x00
_080D56FC: .4byte 0xFFFF0000
_080D5700: .4byte 0x0000FFFF
_080D5704: .4byte 0x0203C4B4
_080D5708: .4byte 0x0203C538
_080D570C: .4byte 0x09EF4DF0
_080D5710:
	ldr r0, _080D5764 @ =0x0203C4B4
	ldr r0, [r0, #0x00]
	adds r0, #0x98
	movs r1, #0x00
	str r1, [r0, #0x00]
	bl func_080D3ED0
_080D571E:
	ldr r4, _080D5764 @ =0x0203C4B4
	ldr r0, [r4, #0x00]
	adds r0, #0x9C
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D573C
	ldr r0, [r4, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x9C
	ldr r1, [r1, #0x00]
	bl func_08000DE8
_080D573C:
	mov r1, r8
	ldr r0, [r1, #0x30]
	bl func_080D422C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D575A
	ldr r0, [r4, #0x00]
	ldr r1, _080D5768 @ =0x09EF4E38
	mov r2, r8
	bl func_08000E14
	ldr r1, [r4, #0x00]
	adds r1, #0x9C
	str r0, [r1, #0x00]
_080D575A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D5764: .4byte 0x0203C4B4
_080D5768: .4byte 0x09EF4E38
.syntax divided
