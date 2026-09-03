.syntax unified
	.align 2, 0
	.global func_0806CBAC
	.thumb
	.thumb_func
	.type func_0806CBAC, %function
func_0806CBAC: @ 0806CBAC
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x0B
	ldr r0, _0806CBC4 @ =0x06014000
	adds r6, r2, r0
	movs r3, #0x00
	ldr r0, _0806CBC8 @ =0x02034A90
	strb r3, [r0, #0x00]
	strh r3, [r4, #0x00]
	b _0806CD1A
_0806CBC4: .4byte 0x06014000
_0806CBC8: .4byte 0x02034A90
_0806CBCC:
	movs r2, #0x00
	cmp r0, #0x0A
	bne _0806CBD6
	strh r2, [r4, #0x00]
	b _0806CD18
_0806CBD6:
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xDF
	bhi _0806CBE4
	ldrh r2, [r5, #0x00]
	b _0806CCC6
_0806CBE4:
	ldrh r1, [r5, #0x00]
	movs r0, #0x99
	lsls r0, r0, #0x06
	cmp r1, r0
	beq _0806CCB8
	cmp r1, r0
	bgt _0806CC40
	ldr r0, _0806CC10 @ =0x00002192
	cmp r1, r0
	beq _0806CC98
	cmp r1, r0
	bgt _0806CC18
	subs r0, #0x02
	cmp r1, r0
	beq _0806CC94
	cmp r1, r0
	bgt _0806CC8C
	ldr r0, _0806CC14 @ =0x0000203B
	cmp r1, r0
	beq _0806CCAC
	b _0806CCC4
	.byte 0x00, 0x00
_0806CC10: .4byte 0x00002192
_0806CC14: .4byte 0x0000203B
_0806CC18:
	ldr r0, _0806CC2C @ =0x000025A0
	cmp r1, r0
	beq _0806CCC0
	cmp r1, r0
	bgt _0806CC34
	ldr r0, _0806CC30 @ =0x00002193
	cmp r1, r0
	beq _0806CC90
	b _0806CCC4
	.byte 0x00, 0x00
_0806CC2C: .4byte 0x000025A0
_0806CC30: .4byte 0x00002193
_0806CC34:
	ldr r0, _0806CC3C @ =0x00002605
	cmp r1, r0
	beq _0806CCBC
	b _0806CCC4
_0806CC3C: .4byte 0x00002605
_0806CC40:
	ldr r0, _0806CC5C @ =0x0000300D
	cmp r1, r0
	beq _0806CCA0
	cmp r1, r0
	bgt _0806CC70
	ldr r0, _0806CC60 @ =0x0000266A
	cmp r1, r0
	beq _0806CCB0
	cmp r1, r0
	bgt _0806CC64
	subs r0, #0x28
	cmp r1, r0
	beq _0806CCB4
	b _0806CCC4
_0806CC5C: .4byte 0x0000300D
_0806CC60: .4byte 0x0000266A
_0806CC64:
	ldr r0, _0806CC6C @ =0x0000300C
	cmp r1, r0
	beq _0806CC9C
	b _0806CCC4
_0806CC6C: .4byte 0x0000300C
_0806CC70:
	ldr r0, _0806CC88 @ =0x0000300F
	cmp r1, r0
	beq _0806CCA8
	cmp r1, r0
	blt _0806CCA4
	movs r0, #0xE0
	lsls r0, r0, #0x08
	cmp r1, r0
	bne _0806CCC4
	movs r2, #0x19
	b _0806CCC6
	.byte 0x00, 0x00
_0806CC88: .4byte 0x0000300F
_0806CC8C:
	movs r2, #0x0A
	b _0806CCC6
_0806CC90:
	movs r2, #0x0B
	b _0806CCC6
_0806CC94:
	movs r2, #0x0C
	b _0806CCC6
_0806CC98:
	movs r2, #0x0D
	b _0806CCC6
_0806CC9C:
	movs r2, #0x01
	b _0806CCC6
_0806CCA0:
	movs r2, #0x02
	b _0806CCC6
_0806CCA4:
	movs r2, #0x03
	b _0806CCC6
_0806CCA8:
	movs r2, #0x04
	b _0806CCC6
_0806CCAC:
	movs r2, #0x06
	b _0806CCC6
_0806CCB0:
	movs r2, #0x12
	b _0806CCC6
_0806CCB4:
	movs r2, #0x08
	b _0806CCC6
_0806CCB8:
	movs r2, #0x09
	b _0806CCC6
_0806CCBC:
	movs r2, #0x15
	b _0806CCC6
_0806CCC0:
	movs r2, #0x11
	b _0806CCC6
_0806CCC4:
	movs r2, #0x00
_0806CCC6:
	cmp r2, #0x20
	beq _0806CD0C
	ldr r1, _0806CCFC @ =0x08F7D438
	lsls r0, r2, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	strh r0, [r4, #0x00]
	ldr r1, _0806CD00 @ =0x09EEC134
	lsls r0, r2, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldrh r2, [r0, #0x06]
	lsls r0, r2, #0x05
	ldr r1, _0806CD04 @ =0x090CBFB2
	adds r0, r0, r1
	adds r1, r6, #0x0
	movs r2, #0x40
	bl CpuSet
	adds r6, #0x80
	ldr r1, _0806CD08 @ =0x02034A90
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	adds r4, #0x02
	movs r3, #0x01
	b _0806CD18
_0806CCFC: .4byte 0x08F7D438
_0806CD00: .4byte 0x09EEC134
_0806CD04: .4byte 0x090CBFB2
_0806CD08: .4byte 0x02034A90
_0806CD0C:
	cmp r3, #0x00
	beq _0806CD18
	subs r1, r4, #0x2
	ldrh r0, [r1, #0x00]
	adds r0, #0x03
	strh r0, [r1, #0x00]
_0806CD18:
	adds r5, #0x02
_0806CD1A:
	ldrh r0, [r5, #0x00]
	cmp r0, #0x00
	beq _0806CD22
	b _0806CBCC
_0806CD22:
	ldr r0, _0806CD2C @ =0x02034A90
	ldrb r0, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_0806CD2C: .4byte 0x02034A90
.syntax divided
