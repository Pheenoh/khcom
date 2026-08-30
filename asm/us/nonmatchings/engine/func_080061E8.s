.syntax unified
	.align 2, 0
	.global func_080061E8
	.thumb
	.thumb_func
	.type func_080061E8, %function
func_080061E8: @ 080061E8
	push {r4, r5, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r0, _0800622C @ =0x03007568
	ldr r2, [r0, #0x00]
	ldr r0, _08006230 @ =0x00000594
	adds r3, r2, r0
	ldrh r1, [r3, #0x00]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _0800620A
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _08006224
_0800620A:
	movs r1, #0x00
	movs r0, #0x01
	strh r0, [r3, #0x00]
	ldr r3, _08006234 @ =0x0000058C
	adds r0, r2, r3
	strh r4, [r0, #0x00]
	subs r3, #0x08
	adds r0, r2, r3
	str r1, [r0, #0x00]
	movs r1, #0xB2
	lsls r1, r1, #0x03
	adds r0, r2, r1
	str r5, [r0, #0x00]
_08006224:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800622C: .4byte 0x03007568
_08006230: .4byte 0x00000594
_08006234: .4byte 0x0000058C
.syntax divided
