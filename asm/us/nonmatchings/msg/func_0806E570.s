.syntax unified
	.align 2, 0
	.global func_0806E570
	.thumb
	.thumb_func
	.type func_0806E570, %function
func_0806E570: @ 0806E570
	push {r4, r5, r6, r7, lr}
	add sp, #-0x00C
	adds r5, r0, #0x0
	movs r0, #0xD0
	lsls r0, r0, #0x01
	adds r6, r5, r0
	ldr r2, [r6, #0x00]
	lsls r0, r2, #0x03
	adds r0, r0, r2
	lsls r0, r0, #0x02
	ldr r3, [r5, #0x00]
	adds r1, r0, r3
	ldr r0, _0806E66C @ =0x02039DC8
	ldr r0, [r0, #0x00]
	adds r4, r0, #0x0
	adds r4, #0x6C
	ldrh r0, [r1, #0x04]
	ldrh r7, [r4, #0x00]
	cmp r0, r7
	bls _0806E59A
	b _0806E792
_0806E59A:
	ldr r0, [r1, #0x18]
	movs r1, #0x80
	lsls r1, r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _0806E5A8
	b _0806E792
_0806E5A8:
	adds r1, r2, #0x1
	str r1, [r6, #0x00]
	movs r0, #0xD2
	lsls r0, r0, #0x01
	adds r2, r5, r0
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r3
	ldrh r0, [r0, #0x04]
	ldrh r1, [r4, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	movs r1, #0xBE
	lsls r1, r1, #0x01
	adds r2, r5, r1
	ldr r1, [r6, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	ldr r1, [r6, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r4, r0, r3
	ldr r0, [r4, #0x18]
	movs r1, #0x80
	lsls r1, r1, #0x07
	ands r0, r1
	adds r7, r5, #0x0
	adds r7, #0x28
	cmp r0, #0x00
	beq _0806E61E
	adds r0, r5, #0x0
	adds r0, #0x10
	adds r1, r5, #0x0
	adds r1, #0x26
	ldrb r2, [r1, #0x00]
	ldr r3, [r4, #0x00]
	ldr r1, [r4, #0x08]
	str r1, [sp, #0x000]
	ldr r1, [r4, #0x0C]
	str r1, [sp, #0x004]
	ldr r1, [r4, #0x10]
	str r1, [sp, #0x008]
	adds r1, r7, #0x0
	bl func_0801CD98
	movs r2, #0xDA
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x01
	strb r0, [r1, #0x00]
	adds r0, r5, #0x0
	bl _08072C34
_0806E61E:
	ldr r1, [r6, #0x00]
	ldr r2, [r5, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x18]
	movs r1, #0x80
	lsls r1, r1, #0x09
	ands r0, r1
	cmp r0, #0x00
	beq _0806E63E
	ldr r0, _0806E670 @ =0x000001B5
	adds r1, r5, r0
	movs r0, #0x01
	strb r0, [r1, #0x00]
_0806E63E:
	ldr r1, [r6, #0x00]
	ldr r2, [r5, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r1, r0, r2
	ldr r0, [r1, #0x18]
	movs r2, #0x80
	lsls r2, r2, #0x04
	ands r0, r2
	cmp r0, #0x00
	beq _0806E67C
	ldr r0, _0806E674 @ =0x096149D8
	adds r1, r5, #0x0
	adds r1, #0x44
	ldrh r1, [r1, #0x00]
	lsls r1, r1, #0x05
	ldr r2, _0806E678 @ =0x05000200
	adds r1, r1, r2
	movs r2, #0x20
	bl LoadPalette
	b _0806E6AA
_0806E66C: .4byte 0x02039DC8
_0806E670: .4byte 0x000001B5
_0806E674: .4byte 0x096149D8
_0806E678: .4byte 0x05000200
_0806E67C:
	adds r0, r1, #0x0
	subs r0, #0x24
	ldr r0, [r0, #0x18]
	ands r0, r2
	cmp r0, #0x00
	beq _0806E6AA
	ldr r1, _0806E6E0 @ =0x0813B09C
	adds r0, r5, #0x0
	adds r0, #0x26
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x04
	adds r1, #0x08
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x44
	ldrh r1, [r1, #0x00]
	lsls r1, r1, #0x05
	ldr r2, _0806E6E4 @ =0x05000200
	adds r1, r1, r2
	movs r2, #0x20
	bl LoadPalette
_0806E6AA:
	movs r1, #0xD0
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r1, [r0, #0x00]
	ldr r2, [r5, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r4, [r0, #0x18]
	movs r0, #0x80
	lsls r0, r0, #0x0D
	ands r4, r0
	cmp r4, #0x00
	beq _0806E6EC
	ldr r1, _0806E6E8 @ =0x03007554
	movs r2, #0xF4
	lsls r2, r2, #0x04
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldrh r1, [r5, #0x3E]
	movs r0, #0x04
	orrs r1, r0
	adds r0, r7, #0x0
	bl func_0801CE00
	b _0806E700
_0806E6E0: .4byte 0x0813B09C
_0806E6E4: .4byte 0x05000200
_0806E6E8: .4byte 0x03007554
_0806E6EC:
	ldrh r1, [r5, #0x3E]
	ldr r0, _0806E74C @ =0x0000FFFB
	ands r1, r0
	adds r0, r7, #0x0
	bl func_0801CE00
	movs r1, #0xDC
	lsls r1, r1, #0x01
	adds r0, r5, r1
	strh r4, [r0, #0x00]
_0806E700:
	movs r2, #0xDA
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0806E750
	movs r1, #0xD0
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r1, [r0, #0x00]
	ldr r2, [r5, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r3, r0, r2
	ldr r0, [r3, #0x18]
	movs r1, #0x0F
	ands r0, r1
	cmp r0, #0x02
	bne _0806E734
	ldr r1, [r3, #0x08]
	ldr r2, [r3, #0x0C]
	ldr r3, [r3, #0x10]
	adds r0, r7, #0x0
	bl func_0801CD8C
_0806E734:
	movs r2, #0xBE
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldr r1, [r0, #0x00]
	adds r0, r7, #0x0
	bl func_0801CD74
	adds r0, r5, #0x0
	bl func_0806F94C
	movs r0, #0x01
	b _0806E794
_0806E74C: .4byte 0x0000FFFB
_0806E750:
	movs r7, #0xD0
	lsls r7, r7, #0x01
	adds r4, r5, r7
	ldr r1, [r4, #0x00]
	ldr r2, [r5, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r1, [r0, #0x00]
	ldr r0, _0806E79C @ =0x000003AF
	cmp r1, r0
	bne _0806E774
	ldr r0, _0806E7A0 @ =0x02039DC8
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x40]
	bl func_0810B350
_0806E774:
	ldr r1, [r4, #0x00]
	ldr r2, [r5, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r1, [r0, #0x00]
	ldr r0, _0806E7A4 @ =0x000003AB
	cmp r1, r0
	bne _0806E792
	ldr r0, _0806E7A0 @ =0x02039DC8
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x40]
	bl func_0810C2C4
_0806E792:
	movs r0, #0x00
_0806E794:
	add sp, #0x00C
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_0806E79C: .4byte 0x000003AF
_0806E7A0: .4byte 0x02039DC8
_0806E7A4: .4byte 0x000003AB
.syntax divided
