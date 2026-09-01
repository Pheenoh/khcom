.syntax unified
	.align 2, 0
	.global func_08012674
	.thumb
	.thumb_func
	.type func_08012674, %function
func_08012674: @ 08012674
	push {r4, lr}
	ldr r0, _08012698 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080126A0
	ldr r0, _0801269C @ =0x02034928
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	bl SetBgPriority
	b _080126AC
	.byte 0x00, 0x00
_08012698: .4byte 0x02039B84
_0801269C: .4byte 0x02034928
_080126A0:
	ldr r0, _080126E0 @ =0x02034928
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	movs r1, #0x01
	bl SetBgPriority
_080126AC:
	ldr r4, _080126E0 @ =0x02034928
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x00]
	movs r1, #0x10
	movs r2, #0x10
	bl SetBgBlend
	ldr r0, [r4, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x01
	str r1, [r0, #0x1C]
	str r1, [r0, #0x20]
	adds r0, #0x24
	movs r2, #0x00
	strb r2, [r0, #0x00]
	ldr r0, [r4, #0x00]
	str r2, [r0, #0x04]
	strh r2, [r0, #0x08]
	str r2, [r0, #0x18]
	movs r1, #0x02
	strh r1, [r0, #0x34]
	adds r0, #0x4C
	strh r2, [r0, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_080126E0: .4byte 0x02034928
.syntax divided
