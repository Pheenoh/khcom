.syntax unified
	.align 2, 0
	.global func_080C84E0
	.thumb
	.thumb_func
	.type func_080C84E0, %function
func_080C84E0: @ 080C84E0
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, _080C8554 @ =0x02034DAC
	str r5, [r0, #0x00]
	cmp r5, #0x00
	bne _080C84F2
	ldr r0, _080C8558 @ =0x0203C3F0
	str r5, [r0, #0x00]
_080C84F2:
	adds r0, r5, #0x0
	subs r0, #0x26
	cmp r0, #0x01
	bhi _080C8522
	adds r1, r4, #0x0
	adds r1, #0xAC
	movs r0, #0x00
	strh r0, [r1, #0x00]
	adds r6, r4, #0x0
	adds r6, #0xC4
	ldr r0, [r6, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080C8522
	adds r0, r4, #0x0
	adds r0, #0xB0
	ldr r1, _080C855C @ =0x09EF4910
	adds r2, r4, #0x0
	adds r2, #0x28
	bl TaskCreate
	str r0, [r6, #0x00]
_080C8522:
	cmp r5, #0x1E
	beq _080C8532
	cmp r5, #0x18
	beq _080C8532
	cmp r5, #0x04
	beq _080C8532
	cmp r5, #0x0B
	bne _080C853A
_080C8532:
	adds r1, r4, #0x0
	adds r1, #0xDA
	movs r0, #0x00
	strh r0, [r1, #0x00]
_080C853A:
	cmp r5, #0x0F
	bne _080C8542
	ldr r0, _080C8560 @ =0xFFFFFED0
	str r0, [r4, #0x48]
_080C8542:
	adds r0, r5, #0x0
	subs r0, #0x24
	cmp r0, #0x01
	bhi _080C8568
	ldr r0, _080C8564 @ =0x00000149
	bl m4aSongNumStart
	b _080C859C
	.byte 0x00, 0x00
_080C8554: .4byte 0x02034DAC
_080C8558: .4byte 0x0203C3F0
_080C855C: .4byte 0x09EF4910
_080C8560: .4byte 0xFFFFFED0
_080C8564: .4byte 0x00000149
_080C8568:
	cmp r5, #0x10
	bne _080C8576
	movs r0, #0xA4
	lsls r0, r0, #0x01
	bl m4aSongNumStart
	b _080C859C
_080C8576:
	cmp r5, #0x27
	beq _080C8586
	cmp r5, #0x16
	beq _080C8586
	adds r0, r5, #0x0
	subs r0, #0x20
	cmp r0, #0x03
	bhi _080C859C
_080C8586:
	adds r0, r4, #0x0
	adds r0, #0x38
	movs r1, #0xAD
	strb r1, [r0, #0x00]
	adds r2, r4, #0x0
	adds r2, #0x3A
	strb r1, [r2, #0x00]
	ldrb r0, [r0, #0x00]
	adds r1, r4, #0x0
	adds r1, #0x3B
	strb r0, [r1, #0x00]
_080C859C:
	cmp r5, #0x23
	bls _080C85B6
	adds r0, r4, #0x0
	adds r0, #0x38
	movs r1, #0x53
	strb r1, [r0, #0x00]
	adds r2, r4, #0x0
	adds r2, #0x3A
	strb r1, [r2, #0x00]
	ldrb r0, [r0, #0x00]
	adds r1, r4, #0x0
	adds r1, #0x3B
	strb r0, [r1, #0x00]
_080C85B6:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_080C8428
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
