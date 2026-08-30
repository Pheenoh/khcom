.syntax unified
	.align 2, 0
	.global func_080CCBF8
	.thumb
	.thumb_func
	.type func_080CCBF8, %function
func_080CCBF8: @ 080CCBF8
	push {r4, r5, r6, r7, lr}
	ldr r1, _080CCC40 @ =0x0203C3EC
	ldr r3, [r1, #0x00]
	ldr r4, [r0, #0x08]
	ldr r1, [r3, #0x00]
	ldr r2, [r4, #0x00]
	subs r1, r1, r2
	lsls r1, r1, #0x08
	lsrs r6, r1, #0x10
	ldr r1, [r3, #0x04]
	ldr r2, [r4, #0x04]
	subs r1, r1, r2
	lsls r1, r1, #0x08
	lsrs r5, r1, #0x10
	bl func_080CCB80
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0x0
	muls r1, r0
	movs r0, #0xE1
	lsls r0, r0, #0x06
	cmp r1, r0
	ble _080CCC44
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0x0
	muls r1, r0
	movs r0, #0xC8
	lsls r0, r0, #0x05
	cmp r1, r0
	ble _080CCC44
	movs r0, #0x00
	b _080CCC92
_080CCC40: .4byte 0x0203C3EC
_080CCC44:
	lsls r3, r6, #0x10
	asrs r0, r3, #0x10
	adds r2, r0, #0x0
	muls r2, r0
	lsls r1, r5, #0x10
	asrs r0, r1, #0x10
	adds r5, r0, #0x0
	muls r5, r0
	adds r0, r5, #0x0
	adds r2, r2, r0
	adds r6, r3, #0x0
	adds r7, r1, #0x0
	cmp r2, #0x00
	bne _080CCC64
	lsls r0, r4, #0x08
	b _080CCC92
_080CCC64:
	lsls r5, r4, #0x08
	cmp r4, #0x00
	beq _080CCC7A
	lsls r1, r2, #0x08
	adds r0, r5, #0x0
	bl __divsi3
	cmp r0, #0x00
	bne _080CCC7A
	movs r0, #0x01
	b _080CCC92
_080CCC7A:
	asrs r0, r6, #0x10
	adds r1, r0, #0x0
	muls r1, r0
	asrs r0, r7, #0x10
	adds r2, r0, #0x0
	muls r2, r0
	adds r0, r2, #0x0
	adds r1, r1, r0
	lsls r1, r1, #0x08
	adds r0, r5, #0x0
	bl __divsi3
_080CCC92:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
