.syntax unified
	.align 2, 0
	.global func_080E7E3C
	.thumb
	.thumb_func
	.type func_080E7E3C, %function
func_080E7E3C: @ 080E7E3C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	ldr r0, _080E7E84 @ =0x0203C590
	ldrb r0, [r0, #0x06]
	bl func_080DEE18
	mov r8, r0
	ldr r0, _080E7E88 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldrb r0, [r0, #0x0D]
	cmp r0, #0x0A
	bne _080E7EEE
	ldr r7, _080E7E8C @ =0x0984C158
	ldr r4, _080E7E90 @ =0x02034F78
	movs r5, #0x01
_080E7E5E:
	ldrb r1, [r7, #0x15]
	mov r0, sp
	bl func_080E7D64
	mov r0, r8
	ldrh r1, [r0, #0x00]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _080E7E98
	ldrb r1, [r4, #0x00]
	ldr r3, _080E7E94 @ =0x0203C7B8
	ldr r2, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	movs r1, #0x0A
	b _080E7EA8
_080E7E84: .4byte 0x0203C590
_080E7E88: .4byte 0x0203C7AC
_080E7E8C: .4byte 0x0984C158
_080E7E90: .4byte 0x02034F78
_080E7E94: .4byte 0x0203C7B8
_080E7E98:
	ldrb r1, [r4, #0x00]
	ldr r3, _080E7F34 @ =0x0203C7B8
	ldr r2, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	movs r1, #0x08
_080E7EA8:
	strh r1, [r0, #0x00]
	ldrb r1, [r4, #0x00]
	ldr r2, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	str r7, [r0, #0x14]
	ldrb r0, [r4, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	adds r1, r1, r2
	adds r1, #0x04
	mov r0, sp
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _080E7F38 @ =0x02034F7A
	ldrh r0, [r7, #0x08]
	lsrs r0, r0, #0x05
	ldrh r2, [r1, #0x00]
	adds r0, r0, r2
	strh r0, [r1, #0x00]
	ldr r1, _080E7F3C @ =0x02034F79
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
	strb r0, [r4, #0x00]
	subs r5, #0x01
	cmp r5, #0x00
	bge _080E7E5E
_080E7EEE:
	ldr r0, _080E7F40 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldrb r0, [r0, #0x0D]
	cmp r0, #0x03
	beq _080E7F04
	cmp r0, #0x09
	beq _080E7F04
	cmp r0, #0x0A
	beq _080E7F04
	cmp r0, #0x16
	bne _080E7FB0
_080E7F04:
	ldr r7, _080E7F44 @ =0x0984C158
	ldrb r1, [r7, #0x15]
	mov r0, sp
	bl func_080E7D64
	mov r3, r8
	ldrh r1, [r3, #0x00]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x00
	beq _080E7F4C
	ldr r4, _080E7F48 @ =0x02034F78
	ldrb r1, [r4, #0x00]
	ldr r3, _080E7F34 @ =0x0203C7B8
	ldr r2, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	movs r1, #0x02
	strh r1, [r0, #0x00]
	b _080E7F5E
_080E7F34: .4byte 0x0203C7B8
_080E7F38: .4byte 0x02034F7A
_080E7F3C: .4byte 0x02034F79
_080E7F40: .4byte 0x0203C7AC
_080E7F44: .4byte 0x0984C158
_080E7F48: .4byte 0x02034F78
_080E7F4C:
	ldr r4, _080E7FBC @ =0x02034F78
	ldrb r1, [r4, #0x00]
	ldr r3, _080E7FC0 @ =0x0203C7B8
	ldr r2, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	strh r5, [r0, #0x00]
_080E7F5E:
	ldrb r1, [r4, #0x00]
	ldr r2, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	str r7, [r0, #0x14]
	ldrb r0, [r4, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	adds r1, r1, r2
	adds r1, #0x04
	mov r0, sp
	ldm r0!, {r2, r5, r6}
	stm r1!, {r2, r5, r6}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _080E7FC4 @ =0x02034F7A
	ldrh r0, [r7, #0x08]
	lsrs r0, r0, #0x05
	ldrh r3, [r1, #0x00]
	adds r0, r0, r3
	strh r0, [r1, #0x00]
	ldr r1, _080E7FC8 @ =0x02034F79
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
	strb r0, [r4, #0x00]
	ldr r0, [sp, #0x000]
	ldr r1, [sp, #0x004]
	ldr r2, [sp, #0x008]
	adds r1, r1, r2
	bl func_080E67D4
	ldrh r2, [r0, #0x00]
	movs r1, #0x80
	orrs r1, r2
	strh r1, [r0, #0x00]
_080E7FB0:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080E7FBC: .4byte 0x02034F78
_080E7FC0: .4byte 0x0203C7B8
_080E7FC4: .4byte 0x02034F7A
_080E7FC8: .4byte 0x02034F79
.syntax divided
