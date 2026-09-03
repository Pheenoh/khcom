.syntax unified
	.align 2, 0
	.global func_080E87EC
	.thumb
	.thumb_func
	.type func_080E87EC, %function
func_080E87EC: @ 080E87EC
	push {r4, r5, r6, lr}
	adds r4, r2, #0x0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	b _080E8856
_080E87FA:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r4, #0x00]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r4, #0x02]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080E548C
	adds r2, r0, #0x0
	ldr r1, [r2, #0x0C]
	movs r0, #0x80
	lsls r0, r0, #0x0D
	cmp r1, r0
	beq _080E8850
	ldrb r1, [r4, #0x04]
	cmp r1, #0x07
	beq _080E882E
	ldrb r0, [r2, #0x03]
	cmp r0, r1
	bne _080E8850
_080E882E:
	ldrb r0, [r2, #0x04]
	ldrb r1, [r4, #0x05]
	cmp r0, r1
	bne _080E8850
	movs r1, #0xA4
	lsls r1, r1, #0x03
	ldrh r0, [r2, #0x00]
	ands r1, r0
	cmp r1, #0x00
	bne _080E8850
	movs r1, #0x0C
	ands r1, r0
	ldrh r0, [r4, #0x08]
	bics r1, r0
	ldrh r2, [r4, #0x06]
	cmp r1, r2
	beq _080E8854
_080E8850:
	movs r0, #0x00
	b _080E885E
_080E8854:
	adds r4, #0x0C
_080E8856:
	ldrb r0, [r4, #0x04]
	cmp r0, #0xFF
	bne _080E87FA
	movs r0, #0x01
_080E885E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
