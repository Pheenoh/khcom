.syntax unified
	.align 2, 0
	.global func_080DFCDC
	.thumb
	.thumb_func
	.type func_080DFCDC, %function
func_080DFCDC: @ 080DFCDC
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0x0
	movs r7, #0x00
	ldr r0, _080DFD0C @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	blt _080DFD08
	ldr r0, _080DFD10 @ =0x02039BB0
	movs r1, #0xBD
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080DFD08
	ldr r1, [r2, #0x08]
	ldr r0, [r2, #0x0C]
	cmp r1, r0
	beq _080DFD2C
_080DFD08:
	movs r0, #0x00
	b _080DFD7C
_080DFD0C: .4byte 0x0203C7AC
_080DFD10: .4byte 0x02039BB0
_080DFD14:
	ldr r2, _080DFD28 @ =0x0203C7AC
	ldr r1, [r2, #0x00]
	ldrb r0, [r3, #0x07]
	strb r0, [r1, #0x0F]
	ldr r1, [r2, #0x00]
	ldrb r0, [r3, #0x06]
	strb r0, [r1, #0x10]
	movs r7, #0x01
	b _080DFD7A
	.byte 0x00, 0x00
_080DFD28: .4byte 0x0203C7AC
_080DFD2C:
	ldr r0, [r2, #0x00]
	asrs r0, r0, #0x08
	cmp r0, #0x00
	bge _080DFD36
	adds r0, #0x1F
_080DFD36:
	lsls r0, r0, #0x0B
	lsrs r6, r0, #0x10
	ldr r0, [r2, #0x04]
	adds r0, r0, r1
	asrs r0, r0, #0x08
	cmp r0, #0x00
	bge _080DFD46
	adds r0, #0x0F
_080DFD46:
	lsls r0, r0, #0x0C
	lsrs r5, r0, #0x10
	movs r4, #0x00
_080DFD4C:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl func_080DFB7C
	adds r3, r0, #0x0
	ldrh r1, [r3, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080DFD74
	movs r0, #0x0A
	ands r0, r1
	cmp r0, #0x02
	bne _080DFD74
	ldrh r0, [r3, #0x02]
	cmp r0, r6
	bne _080DFD74
	ldrh r0, [r3, #0x04]
	cmp r0, r5
	beq _080DFD14
_080DFD74:
	adds r4, #0x01
	cmp r4, #0x03
	ble _080DFD4C
_080DFD7A:
	adds r0, r7, #0x0
_080DFD7C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
