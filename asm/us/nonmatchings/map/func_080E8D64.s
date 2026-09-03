.syntax unified
	.align 2, 0
	.global func_080E8D64
	.thumb
	.thumb_func
	.type func_080E8D64, %function
func_080E8D64: @ 080E8D64
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _080E8D9C @ =0x0203C7AC
	ldr r1, [r0, #0x00]
	ldrb r0, [r1, #0x0F]
	ldrb r1, [r1, #0x10]
	bl func_080E8C38
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080E8DA4
	ldrh r0, [r4, #0x00]
	cmp r0, #0x15
	bhi _080E8DB8
	ldr r0, _080E8DA0 @ =0x0203C590
	ldrb r0, [r0, #0x06]
	bl func_080DF548
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrh r0, [r4, #0x02]
	cmp r0, #0x00
	beq _080E8E1A
	movs r2, #0x00
	cmp r0, r1
	bls _080E8E0C
	b _080E8E0A
	.byte 0x00, 0x00
_080E8D9C: .4byte 0x0203C7AC
_080E8DA0: .4byte 0x0203C590
_080E8DA4:
	movs r0, #0x00
	bl func_080E8D1C
	adds r1, r0, #0x0
	ldrb r0, [r1, #0x00]
	cmp r0, #0xFF
	beq _080E8DBC
	ldrh r2, [r4, #0x00]
	cmp r0, r2
	beq _080E8DC2
_080E8DB8:
	movs r0, #0x00
	b _080E8E1C
_080E8DBC:
	ldrh r0, [r4, #0x00]
	cmp r0, #0x15
	bhi _080E8DB8
_080E8DC2:
	ldrb r0, [r1, #0x01]
	cmp r0, #0x00
	beq _080E8DCE
	ldrh r2, [r4, #0x04]
	cmp r0, r2
	bne _080E8DB8
_080E8DCE:
	ldrb r0, [r1, #0x02]
	cmp r0, #0x02
	beq _080E8DF4
	cmp r0, #0x02
	bgt _080E8DDE
	cmp r0, #0x01
	beq _080E8DE8
	b _080E8E1A
_080E8DDE:
	cmp r0, #0x03
	beq _080E8E00
	cmp r0, #0x04
	beq _080E8E10
	b _080E8E1A
_080E8DE8:
	movs r2, #0x00
	ldrh r0, [r4, #0x02]
	ldrb r1, [r1, #0x03]
	cmp r0, r1
	bcc _080E8E0C
	b _080E8E0A
_080E8DF4:
	movs r2, #0x00
	ldrh r0, [r4, #0x02]
	ldrb r1, [r1, #0x03]
	cmp r0, r1
	bhi _080E8E0C
	b _080E8E0A
_080E8E00:
	movs r2, #0x00
	ldrh r0, [r4, #0x02]
	ldrb r1, [r1, #0x03]
	cmp r0, r1
	bne _080E8E0C
_080E8E0A:
	movs r2, #0x01
_080E8E0C:
	adds r0, r2, #0x0
	b _080E8E1C
_080E8E10:
	ldrh r1, [r4, #0x02]
	negs r0, r1
	orrs r0, r1
	lsrs r0, r0, #0x1F
	b _080E8E1C
_080E8E1A:
	movs r0, #0x01
_080E8E1C:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
