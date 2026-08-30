.syntax unified
	.align 2, 0
	.global func_08006120
	.thumb
	.thumb_func
	.type func_08006120, %function
func_08006120: @ 08006120
	push {r4, r5, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r0, _08006174 @ =0x03007568
	ldr r3, [r0, #0x00]
	ldr r0, _08006178 @ =0x00000594
	adds r1, r3, r0
	ldrh r2, [r1, #0x00]
	movs r0, #0x02
	ands r0, r2
	cmp r0, #0x00
	beq _08006142
	movs r0, #0x01
	ands r0, r2
	cmp r0, #0x00
	bne _0800616C
_08006142:
	movs r2, #0x00
	movs r0, #0x01
	strh r0, [r1, #0x00]
	ldr r1, _0800617C @ =0x0000058C
	adds r0, r3, r1
	strh r4, [r0, #0x00]
	movs r0, #0xB0
	lsls r0, r0, #0x03
	adds r1, r3, r0
	movs r0, #0xF8
	lsls r0, r0, #0x05
	str r0, [r1, #0x00]
	ldr r1, _08006180 @ =0x00000584
	adds r0, r3, r1
	str r2, [r0, #0x00]
	adds r1, #0x04
	adds r0, r3, r1
	str r2, [r0, #0x00]
	adds r1, #0x08
	adds r0, r3, r1
	str r5, [r0, #0x00]
_0800616C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08006174: .4byte 0x03007568
_08006178: .4byte 0x00000594
_0800617C: .4byte 0x0000058C
_08006180: .4byte 0x00000584
.syntax divided
