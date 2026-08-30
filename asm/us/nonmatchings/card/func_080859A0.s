.syntax unified
	.align 2, 0
	.global func_080859A0
	.thumb
	.thumb_func
	.type func_080859A0, %function
func_080859A0: @ 080859A0
	push {r4, r5, r6, r7, lr}
	adds r4, r1, #0x0
	movs r3, #0x00
	cmp r0, #0x00
	beq _080859B0
	cmp r0, #0x01
	beq _08085A00
	b _08085A44
_080859B0:
	movs r1, #0x00
	adds r0, r4, #0x0
	adds r0, #0xDC
	ldrh r0, [r0, #0x00]
	cmp r3, r0
	bge _08085A44
	ldr r6, _080859F8 @ =0x08F70AB0
	ldr r7, _080859FC @ =0x00000FFF
	adds r5, r0, #0x0
_080859C2:
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	lsls r0, r2, #0x01
	adds r0, r4, r0
	ldrh r1, [r0, #0x00]
	adds r0, r7, #0x0
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	adds r0, r0, r6
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bhi _080859E8
	lsls r0, r3, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r3, r0, #0x10
_080859E8:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r5
	blt _080859C2
	b _08085A44
	.byte 0x00, 0x00
_080859F8: .4byte 0x08F70AB0
_080859FC: .4byte 0x00000FFF
_08085A00:
	movs r1, #0x00
	adds r0, r4, #0x0
	adds r0, #0xDC
	ldrh r0, [r0, #0x00]
	cmp r3, r0
	bge _08085A44
	ldr r6, _08085A50 @ =0x08F70AB0
	ldr r7, _08085A54 @ =0x00000FFF
	adds r5, r0, #0x0
_08085A12:
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	lsls r0, r2, #0x01
	adds r0, r4, r0
	ldrh r1, [r0, #0x00]
	adds r0, r7, #0x0
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	adds r0, r0, r6
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _08085A38
	lsls r0, r3, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r3, r0, #0x10
_08085A38:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r5
	blt _08085A12
_08085A44:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08085A50: .4byte 0x08F70AB0
_08085A54: .4byte 0x00000FFF
.syntax divided
