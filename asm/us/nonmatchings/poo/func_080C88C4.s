.syntax unified
	.align 2, 0
	.global func_080C88C4
	.thumb
	.thumb_func
	.type func_080C88C4, %function
func_080C88C4: @ 080C88C4
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	cmp r5, #0x00
	beq _080C899C
	bl func_080CBA4C
	lsls r0, r0, #0x18
	adds r3, r4, #0x0
	adds r3, #0xDC
	cmp r0, #0x00
	beq _080C891C
	ldrh r0, [r3, #0x00]
	cmp r0, #0x00
	bne _080C88F0
	adds r0, r4, #0x0
	adds r0, #0xD0
	ldr r1, _080C8914 @ =0x0203C410
	ldr r2, [r0, #0x00]
	ldr r0, [r1, #0x00]
	cmp r2, r0
	bne _080C8918
_080C88F0:
	adds r1, r4, #0x0
	adds r1, #0xF8
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	movs r2, #0x00
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x0A
	bls _080C89AC
	strh r2, [r3, #0x00]
	strh r2, [r1, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x1D
	bl func_080C84E0
	b _080C89AC
	.byte 0x00, 0x00
_080C8914: .4byte 0x0203C410
_080C8918:
	movs r0, #0x5A
	strh r0, [r3, #0x00]
_080C891C:
	ldrh r0, [r3, #0x00]
	cmp r0, #0x00
	beq _080C892A
	subs r0, #0x01
	strh r0, [r3, #0x00]
	ldr r0, _080C8978 @ =0x0203C410
	ldr r5, [r0, #0x00]
_080C892A:
	adds r0, r4, #0x0
	adds r0, #0xD0
	ldr r1, [r0, #0x00]
	adds r2, r0, #0x0
	adds r3, r4, #0x0
	adds r3, #0xD4
	cmp r1, r5
	beq _080C897C
	ldrh r0, [r3, #0x00]
	cmp r0, #0x3B
	bhi _080C897C
	adds r1, r4, #0x0
	adds r1, #0x38
	ldrb r0, [r1, #0x00]
	adds r2, r4, #0x0
	adds r2, #0x3A
	strb r0, [r2, #0x00]
	ldrb r0, [r1, #0x00]
	adds r1, #0x03
	strb r0, [r1, #0x00]
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x2C]
	ldr r3, [r5, #0x08]
	ldr r2, [r3, #0x00]
	ldr r3, [r3, #0x04]
	bl GetAngle
	adds r1, r4, #0x0
	adds r1, #0x39
	strb r0, [r1, #0x00]
	ldr r0, [r4, #0x28]
	str r0, [r4, #0x40]
	ldr r0, [r4, #0x2C]
	str r0, [r4, #0x44]
	adds r0, r4, #0x0
	movs r1, #0x09
	bl func_080C84E0
	b _080C89AC
_080C8978: .4byte 0x0203C410
_080C897C:
	str r5, [r2, #0x00]
	movs r0, #0x00
	strh r0, [r3, #0x00]
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x08]
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x40]
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x08]
	ldr r0, [r0, #0x04]
	str r0, [r4, #0x44]
	adds r0, r4, #0x0
	movs r1, #0x03
	bl func_080C84E0
	b _080C89AC
_080C899C:
	ldr r0, [r4, #0x28]
	str r0, [r4, #0x40]
	ldr r0, [r4, #0x2C]
	str r0, [r4, #0x44]
	adds r0, r4, #0x0
	movs r1, #0x17
	bl func_080C84E0
_080C89AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
