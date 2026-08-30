.syntax unified
	.align 2, 0
	.global func_08012614
	.thumb
	.thumb_func
	.type func_08012614, %function
func_08012614: @ 08012614
	push {r4, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	cmp r1, #0x00
	beq _08012634
	ldrh r1, [r4, #0x24]
	movs r0, #0x02
	movs r2, #0x00
	movs r3, #0x00
	orrs r0, r1
	strh r0, [r4, #0x24]
	adds r0, r4, #0x0
	adds r0, #0x2C
	strb r2, [r0, #0x00]
	strh r3, [r4, #0x2E]
	b _0801263C
_08012634:
	ldrh r1, [r4, #0x24]
	ldr r0, _08012644 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r4, #0x24]
_0801263C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08012644: .4byte 0x0000FFFD
	.byte 0x2C, 0x30, 0x00, 0x78, 0x70, 0x47, 0x00, 0x00
.syntax divided
