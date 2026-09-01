.syntax unified
	.align 2, 0
	.global func_080B06D4
	.thumb
	.thumb_func
	.type func_080B06D4, %function
func_080B06D4: @ 080B06D4
	push {r4, r5, r6, r7, lr}
	ldr r2, _080B070C @ =0x02039810
	ldrb r0, [r2, #0x08]
	movs r1, #0x0F
	adds r5, r1, #0x0
	ands r5, r0
	adds r7, r5, #0x0
	ldrb r0, [r2, #0x0A]
	ands r1, r0
	adds r6, r1, #0x0
	adds r3, r5, #0x0
	cmp r3, #0x00
	bne _080B06F2
	cmp r1, #0x00
	beq _080B0748
_080B06F2:
	cmp r3, #0x0C
	bgt _080B0748
	adds r2, r1, #0x0
	cmp r2, #0x0C
	bgt _080B0748
	ldr r1, _080B0710 @ =0x0203AA90
	ldr r4, _080B0714 @ =0x0203AA00
	ldrb r0, [r4, #0x00]
	strb r0, [r1, #0x00]
	cmp r3, r2
	ble _080B0718
	strb r5, [r4, #0x00]
	b _080B0722
_080B070C: .4byte 0x02039810
_080B0710: .4byte 0x0203AA90
_080B0714: .4byte 0x0203AA00
_080B0718:
	cmp r3, r2
	bge _080B0720
	strb r6, [r4, #0x00]
	b _080B0722
_080B0720:
	strb r7, [r4, #0x00]
_080B0722:
	ldr r2, _080B0750 @ =0x02034B40
	ldr r0, [r2, #0x00]
	movs r3, #0x00
	movs r1, #0x00
	strh r1, [r0, #0x06]
	strh r1, [r0, #0x04]
	movs r1, #0x82
	lsls r1, r1, #0x03
	adds r0, r0, r1
	strb r3, [r0, #0x00]
	ldr r1, [r2, #0x00]
	ldrb r0, [r1, #0x02]
	strb r0, [r1, #0x01]
	ldr r1, [r2, #0x00]
	movs r0, #0x08
	strb r0, [r1, #0x02]
	movs r0, #0x67
	bl m4aSongNumStart
_080B0748:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B0750: .4byte 0x02034B40
.syntax divided
