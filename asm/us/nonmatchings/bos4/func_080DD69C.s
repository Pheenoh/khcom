.syntax unified
	.align 2, 0
	.global func_080DD69C
	.thumb
	.thumb_func
	.type func_080DD69C, %function
func_080DD69C: @ 080DD69C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r5, _080DD6D0 @ =0x02034F10
	ldr r0, [r5, #0x00]
	ldr r0, [r0, #0x24]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DD6E4
	ldr r0, [r5, #0x00]
	ldr r0, [r0, #0x24]
	bl func_08000F84
	ldr r1, _080DD6D4 @ =0x096FE2F4
	bl strcmp
	cmp r0, #0x00
	bne _080DD6D8
	ldr r0, [r5, #0x00]
	ldr r0, [r0, #0x24]
	ldr r0, [r0, #0x04]
	bl func_080DD9B0
	b _080DD6E4
	.byte 0x00, 0x00
_080DD6D0: .4byte 0x02034F10
_080DD6D4: .4byte 0x096FE2F4
_080DD6D8:
	ldr r1, [r5, #0x00]
	adds r0, r1, #0x0
	adds r0, #0x10
	ldr r1, [r1, #0x24]
	bl func_08000DE8
_080DD6E4:
	cmp r4, #0x03
	bne _080DD704
	ldr r4, _080DD6FC @ =0x02034F10
	ldr r0, [r4, #0x00]
	adds r0, #0x10
	ldr r1, _080DD700 @ =0x09EF5280
	movs r2, #0x00
	bl TaskCreate
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x24]
	b _080DD746
_080DD6FC: .4byte 0x02034F10
_080DD700: .4byte 0x09EF5280
_080DD704:
	ldr r5, _080DD728 @ =0x02034F10
	ldr r2, [r5, #0x00]
	ldr r0, [r2, #0x0C]
	cmp r0, r4
	beq _080DD746
	str r4, [r2, #0x0C]
	cmp r4, #0x00
	bne _080DD730
	ldr r1, _080DD72C @ =0x096FE2C0
	adds r0, r2, #0x0
	bl func_080DDDDC
	ldr r0, [r5, #0x00]
	adds r0, #0x28
	movs r1, #0x01
	strb r1, [r0, #0x00]
	b _080DD746
	.byte 0x00, 0x00
_080DD728: .4byte 0x02034F10
_080DD72C: .4byte 0x096FE2C0
_080DD730:
	ldr r1, _080DD74C @ =0x096FE278
	adds r0, r2, #0x0
	bl func_080DDDDC
	ldr r0, [r5, #0x00]
	adds r0, #0x28
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r0, _080DD750 @ =0x00000111
	bl m4aSongNumStart
_080DD746:
	pop {r4, r5}
	pop {r0}
	bx r0
_080DD74C: .4byte 0x096FE278
_080DD750: .4byte 0x00000111
.syntax divided
