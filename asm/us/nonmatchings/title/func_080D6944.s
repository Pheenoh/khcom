.syntax unified
	.align 2, 0
	.global func_080D6944
	.thumb
	.thumb_func
	.type func_080D6944, %function
func_080D6944: @ 080D6944
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	ldr r0, _080D6980 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x20
	ands r0, r1
	movs r6, #0x01
	cmp r0, #0x00
	beq _080D6958
	movs r6, #0x02
_080D6958:
	bl GetKeysPressed
	movs r1, #0x40
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	cmp r5, #0x00
	beq _080D6984
	movs r0, #0x65
	bl m4aSongNumStart
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bge _080D69A6
	strh r6, [r4, #0x00]
	b _080D69A6
	.byte 0x00, 0x00
_080D6980: .4byte 0x02039BB0
_080D6984:
	bl GetKeysPressed
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _080D69A6
	movs r0, #0x65
	bl m4aSongNumStart
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r6
	ble _080D69A6
	strh r5, [r4, #0x00]
_080D69A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
