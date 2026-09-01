.syntax unified
	.align 2, 0
	.global func_080E56B4
	.thumb
	.thumb_func
	.type func_080E56B4, %function
func_080E56B4: @ 080E56B4
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _080E56C0
	b _080E57EE
_080E56C0:
	ldr r0, _080E5738 @ =0x0203C7B8
	ldr r5, [r0, #0x00]
	ldrb r0, [r4, #0x00]
	cmp r0, #0xFF
	beq _080E570E
	movs r6, #0x00
_080E56CC:
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	ldr r0, [r4, #0x08]
	str r6, [sp, #0x00C]
	str r6, [sp, #0x008]
	str r0, [sp, #0x004]
	movs r0, #0x02
	strh r0, [r5, #0x00]
	ldrb r1, [r4, #0x00]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080E573C @ =0x09856FB4
	adds r0, r0, r1
	str r0, [r5, #0x14]
	adds r1, r5, #0x4
	mov r0, sp
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, _080E5740 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0x78
	ldr r1, _080E5744 @ =0x09EF6DBC
	adds r2, r5, #0x0
	bl TaskCreate
	adds r4, #0x0C
	adds r5, #0x18
	ldrb r0, [r4, #0x00]
	cmp r0, #0xFF
	bne _080E56CC
_080E570E:
	ldr r0, _080E5748 @ =0x0203C590
	ldrb r0, [r0, #0x06]
	cmp r0, #0xFE
	bne _080E57EE
	ldr r2, _080E574C @ =0x02039BB0
	ldr r0, [r2, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080E572A
	movs r0, #0x0E
	ldsb r0, [r2, r0]
	cmp r0, #0x00
	beq _080E5750
_080E572A:
	movs r0, #0xC0
	lsls r0, r0, #0x09
	str r0, [sp, #0x000]
	movs r0, #0x88
	lsls r0, r0, #0x09
	b _080E575A
	.byte 0x00, 0x00
_080E5738: .4byte 0x0203C7B8
_080E573C: .4byte 0x09856FB4
_080E5740: .4byte 0x02039BA0
_080E5744: .4byte 0x09EF6DBC
_080E5748: .4byte 0x0203C590
_080E574C: .4byte 0x02039BB0
_080E5750:
	movs r0, #0x98
	lsls r0, r0, #0x0A
	str r0, [sp, #0x000]
	movs r0, #0x90
	lsls r0, r0, #0x09
_080E575A:
	str r0, [sp, #0x004]
	movs r1, #0x00
	str r1, [sp, #0x00C]
	str r1, [sp, #0x008]
	strh r1, [r5, #0x00]
	ldr r2, _080E57B0 @ =0x0984C1CC
	str r2, [r5, #0x14]
	adds r1, r5, #0x4
	mov r0, sp
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, _080E57B4 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0x78
	ldr r1, [r2, #0x24]
	adds r2, r5, #0x0
	bl TaskCreate
	adds r5, #0x18
	bl func_080DF750
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080E57EE
	ldr r2, _080E57B8 @ =0x02039BB0
	ldr r0, [r2, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080E57A2
	movs r0, #0x0E
	ldsb r0, [r2, r0]
	cmp r0, #0x00
	beq _080E57BC
_080E57A2:
	movs r0, #0xF8
	lsls r0, r0, #0x09
	str r0, [sp, #0x000]
	movs r0, #0xA0
	lsls r0, r0, #0x09
	b _080E57C6
	.byte 0x00, 0x00
_080E57B0: .4byte 0x0984C1CC
_080E57B4: .4byte 0x02039BA0
_080E57B8: .4byte 0x02039BB0
_080E57BC:
	movs r0, #0xB4
	lsls r0, r0, #0x0A
	str r0, [sp, #0x000]
	movs r0, #0xA8
	lsls r0, r0, #0x09
_080E57C6:
	str r0, [sp, #0x004]
	movs r1, #0x00
	str r1, [sp, #0x00C]
	str r1, [sp, #0x008]
	strh r1, [r5, #0x00]
	ldr r2, _080E57F8 @ =0x0984C23C
	str r2, [r5, #0x14]
	adds r1, r5, #0x4
	mov r0, sp
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, _080E57FC @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0x78
	ldr r1, [r2, #0x24]
	adds r2, r5, #0x0
	bl TaskCreate
_080E57EE:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E57F8: .4byte 0x0984C23C
_080E57FC: .4byte 0x02039BA0
.syntax divided
