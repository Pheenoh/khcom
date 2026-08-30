.syntax unified
	.align 2, 0
	.global func_08006238
	.thumb
	.thumb_func
	.type func_08006238, %function
func_08006238: @ 08006238
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	ldr r0, _08006280 @ =0x03007568
	ldr r3, [r0, #0x00]
	ldr r0, _08006284 @ =0x00000594
	adds r2, r3, r0
	ldrh r1, [r2, #0x00]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _0800625E
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _08006278
_0800625E:
	movs r0, #0x01
	strh r0, [r2, #0x00]
	ldr r1, _08006288 @ =0x0000058C
	adds r0, r3, r1
	strh r4, [r0, #0x00]
	ldr r0, _0800628C @ =0x00000584
	adds r1, r3, r0
	lsls r0, r5, #0x08
	str r0, [r1, #0x00]
	movs r1, #0xB2
	lsls r1, r1, #0x03
	adds r0, r3, r1
	str r6, [r0, #0x00]
_08006278:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08006280: .4byte 0x03007568
_08006284: .4byte 0x00000594
_08006288: .4byte 0x0000058C
_0800628C: .4byte 0x00000584
.syntax divided
