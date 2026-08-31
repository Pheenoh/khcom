.syntax unified
	.align 2, 0
	.global func_0806BA74
	.thumb
	.thumb_func
	.type func_0806BA74, %function
func_0806BA74: @ 0806BA74
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0x0
	mov r8, r1
	ldr r4, _0806BAB0 @ =0x02034A88
	movs r0, #0xC0
	lsls r0, r0, #0x04
	bl EwramAlloc
	str r0, [r4, #0x00]
	adds r5, r4, #0x0
	movs r4, #0x00
	movs r7, #0x7F
_0806BA90:
	ldr r0, [r5, #0x00]
	adds r0, r4, r0
	movs r1, #0x00
	str r1, [r0, #0x00]
	str r1, [r0, #0x04]
	str r1, [r0, #0x08]
	str r1, [r0, #0x0C]
	str r1, [r0, #0x10]
	strb r1, [r0, #0x15]
	cmp r6, #0x01
	beq _0806BAC4
	cmp r6, #0x01
	bgt _0806BAB4
	cmp r6, #0x00
	beq _0806BABA
	b _0806BADA
_0806BAB0: .4byte 0x02034A88
_0806BAB4:
	cmp r6, #0x02
	beq _0806BACC
	b _0806BADA
_0806BABA:
	ldr r0, _0806BAC0 @ =0x09614758
	b _0806BACE
	.byte 0x00, 0x00
_0806BAC0: .4byte 0x09614758
_0806BAC4:
	ldr r0, _0806BAC8 @ =0x09614718
	b _0806BACE
_0806BAC8: .4byte 0x09614718
_0806BACC:
	ldr r0, _0806BAE4 @ =0x09614738
_0806BACE:
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, [r5, #0x00]
	adds r1, r4, r1
	str r0, [r1, #0x0C]
_0806BADA:
	mov r0, r8
	cmp r0, #0x00
	bne _0806BAE8
	movs r0, #0x03
	b _0806BAEA
_0806BAE4: .4byte 0x09614738
_0806BAE8:
	movs r0, #0x05
_0806BAEA:
	bl _08066468
	ldr r1, [r5, #0x00]
	adds r1, r4, r1
	str r0, [r1, #0x10]
	ldr r0, [r5, #0x00]
	adds r0, r4, r0
	ldr r0, [r0, #0x0C]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, [r5, #0x00]
	adds r0, r4, r0
	ldr r0, [r0, #0x10]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	adds r4, #0x18
	subs r7, #0x01
	cmp r7, #0x00
	bge _0806BA90
	movs r1, #0x00
	ldr r0, _0806BB3C @ =0x02034A90
	strb r1, [r0, #0x00]
	ldr r0, _0806BB40 @ =0x02034A88
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x0C]
	ldrh r0, [r0, #0x06]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_0806BB3C: .4byte 0x02034A90
_0806BB40: .4byte 0x02034A88
.syntax divided
