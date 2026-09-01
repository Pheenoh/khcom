.syntax unified
	.align 2, 0
	.global func_080C8B60
	.thumb
	.thumb_func
	.type func_080C8B60, %function
func_080C8B60: @ 080C8B60
	push {r4, r5, lr}
	adds r4, r0, #0x0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r0, [r4, #0x3C]
	adds r0, #0x06
	str r0, [r4, #0x3C]
	cmp r0, r1
	ble _080C8B74
	str r1, [r4, #0x3C]
_080C8B74:
	adds r5, r4, #0x0
	adds r5, #0x38
	cmp r2, #0x00
	beq _080C8B96
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x2C]
	ldr r2, [r4, #0x40]
	ldr r3, [r4, #0x44]
	bl GetAngle
	strb r0, [r5, #0x00]
	adds r1, r4, #0x0
	adds r1, #0x3A
	strb r0, [r1, #0x00]
	ldrb r0, [r5, #0x00]
	adds r1, #0x01
	strb r0, [r1, #0x00]
_080C8B96:
	ldr r3, _080C8BD0 @ =0x08121400
	ldrb r0, [r5, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, [r4, #0x3C]
	adds r1, r0, #0x0
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r4, #0x28]
	adds r0, r0, r1
	str r0, [r4, #0x28]
	ldrb r0, [r5, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	adds r1, r0, #0x0
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r4, #0x2C]
	adds r0, r0, r1
	str r0, [r4, #0x2C]
	pop {r4, r5}
	pop {r0}
	bx r0
_080C8BD0: .4byte 0x08121400
.syntax divided
