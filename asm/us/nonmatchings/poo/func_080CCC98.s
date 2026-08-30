.syntax unified
	.align 2, 0
	.global func_080CCC98
	.thumb
	.thumb_func
	.type func_080CCC98, %function
func_080CCC98: @ 080CCC98
	push {r4, r5, r6, lr}
	ldr r0, _080CCCEC @ =0x02034DF8
	bl func_08000C8C
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	ldr r1, _080CCCF0 @ =0x02034DF0
	movs r0, #0x00
	str r0, [r1, #0x00]
	cmp r5, #0x00
	beq _080CCCD4
	adds r6, r1, #0x0
_080CCCB0:
	adds r0, r4, #0x0
	bl func_080CCBF8
	adds r1, r0, #0x0
	ldr r0, _080CCCF4 @ =0x02034DF4
	str r1, [r0, #0x00]
	ldr r0, [r6, #0x00]
	cmp r1, r0
	ble _080CCCC6
	str r1, [r6, #0x00]
	adds r5, r4, #0x0
_080CCCC6:
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08000CD4
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _080CCCB0
_080CCCD4:
	ldr r0, _080CCCF0 @ =0x02034DF0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080CCCF8
	ldr r0, _080CCCEC @ =0x02034DF8
	bl func_08000C8C
	cmp r5, r0
	bne _080CCCF8
	movs r0, #0x00
	b _080CCCFA
	.byte 0x00, 0x00
_080CCCEC: .4byte 0x02034DF8
_080CCCF0: .4byte 0x02034DF0
_080CCCF4: .4byte 0x02034DF4
_080CCCF8:
	adds r0, r5, #0x0
_080CCCFA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
