.syntax unified
	.align 2, 0
	.global func_0807CD48
	.thumb
	.thumb_func
	.type func_0807CD48, %function
func_0807CD48: @ 0807CD48
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, [r4, #0x78]
	movs r0, #0x80
	lsls r0, r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	beq _0807CDFE
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	beq _0807CDA2
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0807CD9A
	ldr r0, [r4, #0x54]
	cmp r0, #0x02
	ble _0807CD7A
	subs r0, #0x40
	str r0, [r4, #0x54]
	cmp r0, #0x02
	bgt _0807CDFE
	movs r0, #0x02
	b _0807CDFC
_0807CD7A:
	movs r0, #0x02
	str r0, [r4, #0x54]
	subs r0, #0x04
	ands r0, r1
	str r0, [r4, #0x78]
	movs r5, #0x80
	ands r0, r5
	cmp r0, #0x00
	bne _0807CDFE
	adds r0, r4, #0x0
	bl func_0807C33C
	ldr r0, [r4, #0x78]
	orrs r0, r5
	str r0, [r4, #0x78]
	b _0807CDFE
_0807CD9A:
	ldr r0, [r4, #0x54]
	cmp r0, #0xFF
	ble _0807CDE8
	b _0807CDF8
_0807CDA2:
	movs r2, #0x01
	adds r0, r1, #0x0
	ands r0, r2
	cmp r0, #0x00
	bne _0807CDE2
	ldr r0, [r4, #0x54]
	cmp r0, #0x02
	ble _0807CDBE
	subs r0, #0x40
	str r0, [r4, #0x54]
	cmp r0, #0x02
	bgt _0807CDFE
	movs r0, #0x02
	b _0807CDFC
_0807CDBE:
	movs r0, #0x02
	str r0, [r4, #0x54]
	adds r0, r2, #0x0
	orrs r0, r1
	str r0, [r4, #0x78]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0x00
	beq _0807CDFE
	adds r0, r4, #0x0
	bl func_0807C39C
	ldr r0, [r4, #0x78]
	movs r1, #0x81
	negs r1, r1
	ands r0, r1
	str r0, [r4, #0x78]
	b _0807CDFE
_0807CDE2:
	ldr r0, [r4, #0x54]
	cmp r0, #0xFF
	bgt _0807CDF8
_0807CDE8:
	adds r0, #0x40
	str r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #0x01
	cmp r0, r1
	ble _0807CDFE
	str r1, [r4, #0x54]
	b _0807CDFE
_0807CDF8:
	movs r0, #0x80
	lsls r0, r0, #0x01
_0807CDFC:
	str r0, [r4, #0x54]
_0807CDFE:
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
