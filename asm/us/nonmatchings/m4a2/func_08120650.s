.syntax unified
	.align 2, 0
	.global func_08120650
	.thumb
	.thumb_func
	.type func_08120650, %function
func_08120650: @ 08120650
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0x0
	adds r7, r1, #0x0
	ldr r1, [r5, #0x34]
	ldr r0, _08120730 @ =0x68736D53
	cmp r1, r0
	bne _08120724
	adds r0, r1, #0x1
	str r0, [r5, #0x34]
	ldrb r0, [r5, #0x0B]
	ldrb r2, [r7, #0x02]
	cmp r0, #0x00
	beq _08120696
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	beq _08120680
	ldr r0, [r5, #0x2C]
	ldrb r1, [r0, #0x00]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0x00
	bne _0812068C
_08120680:
	ldr r1, [r5, #0x04]
	ldrh r0, [r5, #0x04]
	cmp r0, #0x00
	beq _08120696
	cmp r1, #0x00
	blt _08120696
_0812068C:
	ldrb r0, [r7, #0x02]
	ldrb r1, [r5, #0x09]
	adds r2, r0, #0x0
	cmp r1, r2
	bhi _08120720
_08120696:
	movs r1, #0x00
	str r1, [r5, #0x04]
	str r7, [r5, #0x00]
	ldr r0, [r7, #0x04]
	str r0, [r5, #0x30]
	strb r2, [r5, #0x09]
	str r1, [r5, #0x0C]
	movs r0, #0x96
	strh r0, [r5, #0x1C]
	strh r0, [r5, #0x20]
	adds r0, #0x6A
	strh r0, [r5, #0x1E]
	strh r1, [r5, #0x22]
	strh r1, [r5, #0x24]
	movs r6, #0x00
	ldr r4, [r5, #0x2C]
	ldrb r0, [r7, #0x00]
	cmp r6, r0
	bge _081206F0
	ldrb r0, [r5, #0x08]
	cmp r6, r0
	bge _08120710
	mov r8, r6
_081206C4:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_0811FA28
	movs r0, #0xC0
	strb r0, [r4, #0x00]
	mov r0, r8
	str r0, [r4, #0x20]
	lsls r1, r6, #0x02
	adds r0, r7, #0x0
	adds r0, #0x08
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x40]
	adds r6, #0x01
	adds r4, #0x50
	ldrb r0, [r7, #0x00]
	cmp r6, r0
	bge _081206F0
	ldrb r0, [r5, #0x08]
	cmp r6, r0
	blt _081206C4
_081206F0:
	ldrb r0, [r5, #0x08]
	cmp r6, r0
	bge _08120710
	movs r0, #0x00
	mov r8, r0
_081206FA:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_0811FA28
	mov r0, r8
	strb r0, [r4, #0x00]
	adds r6, #0x01
	adds r4, #0x50
	ldrb r0, [r5, #0x08]
	cmp r6, r0
	blt _081206FA
_08120710:
	ldrb r1, [r7, #0x03]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0x00
	beq _08120720
	ldrb r0, [r7, #0x03]
	bl func_08120378
_08120720:
	ldr r0, _08120730 @ =0x68736D53
	str r0, [r5, #0x34]
_08120724:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08120730: .4byte 0x68736D53
.syntax divided
