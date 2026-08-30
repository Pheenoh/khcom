.syntax unified
	.align 2, 0
	.global func_080E5968
	.thumb
	.thumb_func
	.type func_080E5968, %function
func_080E5968: @ 080E5968
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	adds r4, #0x08
	adds r1, r5, #0x0
	adds r1, #0x0C
	adds r0, r4, #0x0
	bl func_080E524C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080E59D0
	movs r0, #0x00
	str r0, [r4, #0x08]
	adds r0, r4, #0x0
	bl func_080DFF30
	str r0, [r4, #0x0C]
	str r0, [r4, #0x08]
	ldr r1, [r4, #0x04]
	subs r1, r1, r0
	str r1, [r4, #0x04]
	movs r3, #0x00
	ldr r0, _080E59C8 @ =0x02034F40
	ldrb r1, [r0, #0x00]
	cmp r3, r1
	bge _080E59C2
	ldr r0, [r5, #0x08]
	asrs r6, r0, #0x08
	adds r5, r1, #0x0
	ldr r2, _080E59CC @ =0x02034F48
_080E59A6:
	ldr r0, [r2, #0x00]
	asrs r0, r0, #0x08
	cmp r0, r6
	bne _080E59BA
	ldr r1, [r2, #0x04]
	asrs r1, r1, #0x08
	ldr r0, [r4, #0x04]
	asrs r0, r0, #0x08
	cmp r1, r0
	beq _080E59D0
_080E59BA:
	adds r2, #0x10
	adds r3, #0x01
	cmp r3, r5
	blt _080E59A6
_080E59C2:
	movs r0, #0x01
	b _080E59D2
	.byte 0x00, 0x00
_080E59C8: .4byte 0x02034F40
_080E59CC: .4byte 0x02034F48
_080E59D0:
	movs r0, #0x00
_080E59D2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
