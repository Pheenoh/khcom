.syntax unified
	.align 2, 0
	.global func_08012330
	.thumb
	.thumb_func
	.type func_08012330, %function
func_08012330: @ 08012330
	push {r4, lr}
	bl func_08000C8C
	adds r1, r0, #0x0
	cmp r1, #0x00
	beq _08012354
	movs r4, #0x00
_0801233E:
	adds r0, r1, #0x0
	adds r0, #0x2C
	strb r4, [r0, #0x00]
	str r4, [r1, #0x58]
	strh r4, [r1, #0x2E]
	subs r0, #0x14
	bl func_08000CD4
	adds r1, r0, #0x0
	cmp r1, #0x00
	bne _0801233E
_08012354:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
