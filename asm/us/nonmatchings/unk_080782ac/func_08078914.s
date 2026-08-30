.syntax unified
	.align 2, 0
	.global func_08078914
	.thumb
	.thumb_func
	.type func_08078914, %function
func_08078914: @ 08078914
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	ldr r0, _08078994 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _0807899C
	movs r5, #0x00
	lsls r0, r2, #0x01
	adds r1, r3, #0x0
	adds r1, #0xA8
	adds r6, r1, r0
	movs r1, #0x00
	ldsh r0, [r6, r1]
	cmp r5, r0
	bge _080789DC
	lsls r1, r2, #0x02
	adds r0, r3, #0x0
	adds r0, #0x44
	adds r4, r0, r1
	movs r7, #0x80
	lsls r7, r7, #0x08
_08078946:
	ldr r1, [r4, #0x00]
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsls r3, r0, #0x02
	adds r0, r3, r1
	ldrb r1, [r0, #0x07]
	cmp r1, #0x00
	bne _0807895E
	strb r1, [r0, #0x08]
	ldr r0, [r4, #0x00]
	adds r0, r3, r0
	strb r1, [r0, #0x06]
_0807895E:
	ldr r0, _08078998 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r0, #0x00
	ands r1, r7
	orrs r1, r0
	cmp r1, #0x00
	bne _08078982
	ldr r0, [r4, #0x00]
	adds r2, r3, r0
	ldrb r0, [r2, #0x09]
	cmp r0, #0x01
	bne _08078982
	strb r1, [r2, #0x0A]
	ldr r0, [r4, #0x00]
	adds r0, r3, r0
	strb r1, [r0, #0x09]
_08078982:
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r1, #0x00
	ldsh r0, [r6, r1]
	cmp r5, r0
	blt _08078946
	b _080789DC
	.byte 0x00, 0x00
_08078994: .4byte 0x02039BB0
_08078998: .4byte 0x02039B84
_0807899C:
	movs r5, #0x00
	lsls r0, r2, #0x01
	adds r1, r3, #0x0
	adds r1, #0xA8
	adds r4, r1, r0
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r5, r0
	bge _080789DC
	lsls r1, r2, #0x02
	adds r0, r3, #0x0
	adds r0, #0x44
	adds r3, r0, r1
_080789B6:
	ldr r1, [r3, #0x00]
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsls r2, r0, #0x02
	adds r0, r2, r1
	ldrb r1, [r0, #0x07]
	cmp r1, #0x00
	bne _080789CE
	strb r1, [r0, #0x08]
	ldr r0, [r3, #0x00]
	adds r0, r2, r0
	strb r1, [r0, #0x06]
_080789CE:
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r5, r0
	blt _080789B6
_080789DC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
