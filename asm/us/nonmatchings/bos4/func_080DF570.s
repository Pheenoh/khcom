.syntax unified
	.align 2, 0
	.global func_080DF570
	.thumb
	.thumb_func
	.type func_080DF570, %function
func_080DF570: @ 080DF570
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r5, #0x0
	bl func_080DEE18
	adds r4, r0, #0x0
	movs r0, #0x00
	bl func_080DEDD8
	adds r2, r0, #0x0
	ldrb r1, [r2, #0x00]
	cmp r1, #0x05
	beq _080DF5B2
	ldr r6, _080DF5CC @ =0x0203C590
	movs r3, #0x00
	movs r7, #0x08
_080DF592:
	ldrb r0, [r2, #0x02]
	cmp r0, r5
	bne _080DF5AA
	cmp r1, #0x02
	beq _080DF5D4
	ldrh r0, [r6, #0x02]
	orrs r0, r7
	strh r0, [r6, #0x02]
	strb r3, [r4, #0x0A]
	movs r0, #0x1A
	strb r0, [r4, #0x08]
	strb r3, [r4, #0x09]
_080DF5AA:
	adds r2, #0x08
	ldrb r1, [r2, #0x00]
	cmp r1, #0x05
	bne _080DF592
_080DF5B2:
	ldr r0, _080DF5D0 @ =0x02039BB0
	ldrb r0, [r0, #0x0E]
	bl func_080DED64
	ldrb r0, [r0, #0x01]
	cmp r0, r5
	beq _080DF5E0
	movs r1, #0x00
	strb r1, [r4, #0x0A]
	movs r0, #0x1A
	strb r0, [r4, #0x08]
	strb r1, [r4, #0x09]
	b _080DF5EC
_080DF5CC: .4byte 0x0203C590
_080DF5D0: .4byte 0x02039BB0
_080DF5D4:
	movs r0, #0x00
	strb r0, [r4, #0x0A]
	movs r0, #0x1B
	strb r0, [r4, #0x08]
	movs r0, #0x16
	b _080DF5EA
_080DF5E0:
	movs r0, #0x00
	strb r0, [r4, #0x0A]
	movs r0, #0x05
	strb r0, [r4, #0x08]
	movs r0, #0x17
_080DF5EA:
	strb r0, [r4, #0x09]
_080DF5EC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
