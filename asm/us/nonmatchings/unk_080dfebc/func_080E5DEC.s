.syntax unified
	.align 2, 0
	.global func_080E5DEC
	.thumb
	.thumb_func
	.type func_080E5DEC, %function
func_080E5DEC: @ 080E5DEC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	ldr r7, _080E5E14 @ =0x02039BA0
	ldr r0, [r7, #0x00]
	ldr r0, [r0, #0x70]
	movs r6, #0x80
	lsls r6, r6, #0x09
	ands r0, r6
	cmp r0, #0x00
	beq _080E5E18
	adds r4, r5, #0x0
	adds r4, #0xA4
	adds r0, r4, #0x0
	bl func_08005AC4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080E5E3C
	b _080E5E30
	.byte 0x00, 0x00
_080E5E14: .4byte 0x02039BA0
_080E5E18:
	adds r4, r5, #0x0
	adds r4, #0xA4
	adds r0, r4, #0x0
	bl func_08005AC4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080E5E30
	ldr r1, [r7, #0x00]
	ldr r0, [r1, #0x70]
	orrs r0, r6
	str r0, [r1, #0x70]
_080E5E30:
	adds r0, r4, #0x0
	bl AnimUpdate
	adds r1, r5, #0x0
	adds r1, #0xC4
	str r0, [r1, #0x00]
_080E5E3C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
