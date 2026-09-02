.syntax unified
	.align 2, 0
	.global func_08064B80
	.thumb
	.thumb_func
	.type func_08064B80, %function
func_08064B80: @ 08064B80
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0x0
	ldr r4, _08064BC4 @ =0x02034A84
	movs r0, #0xC0
	lsls r0, r0, #0x04
	bl EwramAlloc
	str r0, [r4, #0x00]
	adds r7, r4, #0x0
	movs r6, #0x00
	movs r4, #0x00
	movs r0, #0x7F
	mov r8, r0
_08064B9E:
	ldr r0, [r7, #0x00]
	adds r0, r4, r0
	str r6, [r0, #0x00]
	str r6, [r0, #0x04]
	str r6, [r0, #0x08]
	str r6, [r0, #0x0C]
	str r6, [r0, #0x10]
	strb r6, [r0, #0x15]
	ldr r0, [r7, #0x00]
	adds r0, r4, r0
	strb r6, [r0, #0x14]
	cmp r5, #0x01
	beq _08064BD8
	cmp r5, #0x01
	bgt _08064BC8
	cmp r5, #0x00
	beq _08064BCE
	b _08064BEE
	.byte 0x00, 0x00
_08064BC4: .4byte 0x02034A84
_08064BC8:
	cmp r5, #0x02
	beq _08064BE0
	b _08064BEE
_08064BCE:
	ldr r0, _08064BD4 @ =0x09614758
	b _08064BE2
	.byte 0x00, 0x00
_08064BD4: .4byte 0x09614758
_08064BD8:
	ldr r0, _08064BDC @ =0x09614718
	b _08064BE2
_08064BDC: .4byte 0x09614718
_08064BE0:
	ldr r0, _08064C28 @ =0x09614738
_08064BE2:
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, [r7, #0x00]
	adds r1, r4, r1
	str r0, [r1, #0x0C]
_08064BEE:
	ldr r0, [r7, #0x00]
	adds r0, r4, r0
	ldr r0, [r0, #0x0C]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	adds r4, #0x18
	movs r0, #0x01
	negs r0, r0
	add r8, r0
	mov r0, r8
	cmp r0, #0x00
	bge _08064B9E
	movs r1, #0x00
	ldr r0, _08064C2C @ =0x02034A90
	strb r1, [r0, #0x00]
	ldr r0, _08064C30 @ =0x02034A84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x0C]
	ldrh r0, [r0, #0x06]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08064C28: .4byte 0x09614738
_08064C2C: .4byte 0x02034A90
_08064C30: .4byte 0x02034A84
.syntax divided
