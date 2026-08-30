.syntax unified
	.align 2, 0
	.global func_080E7DF8
	.thumb
	.thumb_func
	.type func_080E7DF8, %function
func_080E7DF8: @ 080E7DF8
	push {r4, r5, r6, lr}
	movs r4, #0x00
	ldr r5, _080E7E28 @ =0x02034F7A
	ldr r6, _080E7E2C @ =0x02034F79
_080E7E00:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl func_080E54A0
	adds r1, r0, #0x0
	ldrb r0, [r1, #0x08]
	cmp r0, #0x00
	bne _080E7E30
	ldr r1, [r1, #0x14]
	movs r0, #0x80
	lsls r0, r0, #0x0D
	cmp r1, r0
	beq _080E7E30
	ldrh r0, [r5, #0x00]
	adds r0, #0x4C
	strh r0, [r5, #0x00]
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	strb r0, [r6, #0x00]
	b _080E7E36
_080E7E28: .4byte 0x02034F7A
_080E7E2C: .4byte 0x02034F79
_080E7E30:
	adds r4, #0x01
	cmp r4, #0x0B
	ble _080E7E00
_080E7E36:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
