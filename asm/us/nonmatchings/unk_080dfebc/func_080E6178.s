.syntax unified
	.align 2, 0
	.global func_080E6178
	.thumb
	.thumb_func
	.type func_080E6178, %function
func_080E6178: @ 080E6178
	push {r4, r5, r6, r7, lr}
	add sp, #-0x020
	ldr r0, _080E61A0 @ =0x02034F40
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r0, _080E61A4 @ =0x02034F41
	strb r1, [r0, #0x00]
	ldr r1, _080E61A8 @ =0x02034F42
	movs r0, #0x2E
	strb r0, [r1, #0x00]
	ldr r1, _080E61AC @ =0x02039BB0
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080E6228
	adds r0, r1, #0x0
	adds r0, #0xE8
	bl func_08000C8C
	b _080E61E4
	.byte 0x00, 0x00
_080E61A0: .4byte 0x02034F40
_080E61A4: .4byte 0x02034F41
_080E61A8: .4byte 0x02034F42
_080E61AC: .4byte 0x02039BB0
_080E61B0:
	ldr r2, [r4, #0x30]
	str r2, [sp, #0x000]
	ldr r0, [r4, #0x34]
	str r0, [sp, #0x004]
	add r1, sp, #0x008
	adds r0, r4, #0x0
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	mov r1, sp
	ldrb r0, [r4, #0x10]
	strb r0, [r1, #0x18]
	ldr r0, [r4, #0x14]
	str r0, [sp, #0x01C]
	ldr r0, _080E621C @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0xB4
	ldr r1, [r2, #0x10]
	mov r2, sp
	bl func_08000E14
	adds r0, r4, #0x0
	adds r0, #0x1C
	bl func_08000CD4
_080E61E4:
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _080E61B0
	ldr r2, _080E6220 @ =0x02039BB0
	ldr r1, [r2, #0x08]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080E622C
	movs r0, #0x03
	negs r0, r0
	ands r0, r1
	str r0, [r2, #0x08]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0x00
	bne _080E622C
	ldr r0, _080E6224 @ =0x0203C590
	ldrb r0, [r0, #0x06]
	bl func_080DEE18
	adds r1, r0, #0x0
	ldrb r0, [r1, #0x0B]
	cmp r0, #0x00
	beq _080E622C
	subs r0, #0x01
	strb r0, [r1, #0x0B]
	b _080E622C
_080E621C: .4byte 0x02039BA0
_080E6220: .4byte 0x02039BB0
_080E6224: .4byte 0x0203C590
_080E6228:
	bl func_080E6100
_080E622C:
	ldr r4, _080E6260 @ =0x02039C98
	adds r0, r4, #0x0
	bl func_08000BA4
	adds r7, r4, #0x0
	subs r7, #0x8C
	adds r5, r4, #0x0
	subs r5, #0xA8
	adds r4, r7, #0x0
	movs r6, #0x02
_080E6240:
	adds r0, r4, #0x0
	adds r1, r7, #0x0
	adds r1, #0x8C
	adds r2, r5, #0x0
	bl func_08000BB0
	adds r5, #0x38
	adds r4, #0x38
	subs r6, #0x01
	cmp r6, #0x00
	bge _080E6240
	add sp, #0x020
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E6260: .4byte 0x02039C98
.syntax divided
