.syntax unified
	.align 2, 0
	.global func_080F7E84
	.thumb
	.thumb_func
	.type func_080F7E84, %function
func_080F7E84: @ 080F7E84
	push {r4, r5, lr}
	adds r4, r0, #0x0
	movs r0, #0x90
	lsls r0, r0, #0x01
	adds r5, r4, r0
	ldr r1, [r5, #0x00]
	adds r1, #0x4C
	str r1, [r5, #0x00]
	ldr r0, [r4, #0x0C]
	adds r0, r0, r1
	str r0, [r4, #0x0C]
	cmp r0, #0x00
	ble _080F7EBE
	ldr r1, [r5, #0x00]
	movs r0, #0xA0
	lsls r0, r0, #0x03
	cmp r1, r0
	ble _080F7EAE
	ldr r0, _080F7EDC @ =0x0000026A
	bl func_0811FE70
_080F7EAE:
	movs r0, #0x00
	str r0, [r4, #0x0C]
	ldr r0, [r5, #0x00]
	negs r0, r0
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r0, r0, #0x01
	str r0, [r5, #0x00]
_080F7EBE:
	movs r0, #0xB2
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r1, [r2, #0x00]
	cmp r1, #0x00
	ble _080F7EE0
	ldr r0, [r4, #0x04]
	adds r0, r0, r1
	str r0, [r4, #0x04]
	ldr r0, [r2, #0x00]
	subs r0, #0x11
	str r0, [r2, #0x00]
	cmp r0, #0x00
	bge _080F7EF8
	b _080F7EF4
_080F7EDC: .4byte 0x0000026A
_080F7EE0:
	cmp r1, #0x00
	bge _080F7EF8
	ldr r0, [r4, #0x04]
	adds r0, r0, r1
	str r0, [r4, #0x04]
	ldr r0, [r2, #0x00]
	adds r0, #0x11
	str r0, [r2, #0x00]
	cmp r0, #0x00
	ble _080F7EF8
_080F7EF4:
	movs r0, #0x00
	str r0, [r2, #0x00]
_080F7EF8:
	movs r0, #0xB4
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r1, [r2, #0x00]
	cmp r1, #0x00
	ble _080F7F1C
	lsrs r0, r1, #0x1F
	adds r0, r1, r0
	asrs r0, r0, #0x01
	ldr r1, [r4, #0x08]
	adds r1, r1, r0
	str r1, [r4, #0x08]
	ldr r0, [r2, #0x00]
	subs r0, #0x11
	str r0, [r2, #0x00]
	cmp r0, #0x00
	bge _080F7F3A
	b _080F7F36
_080F7F1C:
	cmp r1, #0x00
	bge _080F7F3A
	lsrs r0, r1, #0x1F
	adds r0, r1, r0
	asrs r0, r0, #0x01
	ldr r1, [r4, #0x08]
	adds r1, r1, r0
	str r1, [r4, #0x08]
	ldr r0, [r2, #0x00]
	adds r0, #0x11
	str r0, [r2, #0x00]
	cmp r0, #0x00
	ble _080F7F3A
_080F7F36:
	movs r0, #0x00
	str r0, [r2, #0x00]
_080F7F3A:
	adds r0, r4, #0x4
	adds r1, r4, #0x0
	adds r1, #0x08
	movs r2, #0x18
	negs r2, r2
	movs r3, #0x0C
	negs r3, r3
	bl func_0801A8A4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
