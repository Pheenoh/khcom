.syntax unified
	.align 2, 0
	.global func_080609AC
	.thumb
	.thumb_func
	.type func_080609AC, %function
func_080609AC: @ 080609AC
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080609D4
	ldr r2, _080609CC @ =0x08F70AB0
	ldr r0, _080609D0 @ =0x00000FFF
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	adds r0, r0, r2
	b _08060A20
	.byte 0x00, 0x00
_080609CC: .4byte 0x08F70AB0
_080609D0: .4byte 0x00000FFF
_080609D4:
	ldr r2, _08060A0C @ =0x00000FFF
	ands r2, r1
	ldr r0, _08060A10 @ =0x000001C1
	cmp r2, r0
	bhi _08060A18
	movs r0, #0x34
	adds r1, r2, #0x0
	muls r1, r0
	ldr r0, _08060A14 @ =0x08F70ACC
	adds r0, r1, r0
	ldrb r5, [r0, #0x04]
	cmp r5, #0x00
	bne _080609F0
	movs r5, #0x0A
_080609F0:
	subs r5, #0x01
	ldrh r4, [r0, #0x10]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl _0811D754
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	muls r0, r5
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0x0
	b _08060A22
_08060A0C: .4byte 0x00000FFF
_08060A10: .4byte 0x000001C1
_08060A14: .4byte 0x08F70ACC
_08060A18:
	ldr r1, _08060A28 @ =0x08F70AB0
	movs r0, #0x34
	muls r0, r2
	adds r0, r0, r1
_08060A20:
	ldrh r0, [r0, #0x2C]
_08060A22:
	pop {r4, r5}
	pop {r1}
	bx r1
_08060A28: .4byte 0x08F70AB0
.syntax divided
