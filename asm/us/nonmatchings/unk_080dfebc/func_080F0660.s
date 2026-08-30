.syntax unified
	.align 2, 0
	.global func_080F0660
	.thumb
	.thumb_func
	.type func_080F0660, %function
func_080F0660: @ 080F0660
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r5, r4, #0x0
	adds r5, #0x08
	ldr r7, [r5, #0x08]
	cmp r1, #0x00
	beq _080F069C
	cmp r1, #0x01
	bne _080F069C
	adds r3, r4, #0x0
	adds r3, #0xDC
	ldr r2, _080F0694 @ =0x08121400
	ldr r0, _080F0698 @ =0x03007480
	ldr r0, [r0, #0x00]
	movs r1, #0xFF
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	b _080F06BA
_080F0694: .4byte 0x08121400
_080F0698: .4byte 0x03007480
_080F069C:
	adds r3, r4, #0x0
	adds r3, #0xDC
	ldr r2, _080F06DC @ =0x08121400
	ldr r0, _080F06E0 @ =0x03007480
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x01
	movs r1, #0xFF
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
_080F06BA:
	ldr r1, [r3, #0x00]
	adds r2, r1, r0
	adds r6, r3, #0x0
	ldrh r1, [r4, #0x04]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _080F06E4
	ldr r4, [r5, #0x08]
	subs r0, r2, r4
	movs r1, #0x50
	bl __divsi3
	adds r4, r4, r0
	str r4, [r5, #0x08]
	b _080F06EE
	.byte 0x00, 0x00
_080F06DC: .4byte 0x08121400
_080F06E0: .4byte 0x03007480
_080F06E4:
	ldr r1, [r5, #0x08]
	subs r0, r2, r1
	asrs r0, r0, #0x04
	adds r1, r1, r0
	str r1, [r5, #0x08]
_080F06EE:
	ldr r1, [r5, #0x0C]
	ldr r0, [r5, #0x08]
	cmp r1, r0
	bge _080F06FE
	str r7, [r5, #0x08]
	ldr r1, _080F0704 @ =0xFFFFE400
	adds r0, r7, r1
	str r0, [r6, #0x00]
_080F06FE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080F0704: .4byte 0xFFFFE400
.syntax divided
