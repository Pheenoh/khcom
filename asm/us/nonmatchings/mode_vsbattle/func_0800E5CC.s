.syntax unified
	.align 2, 0
	.global func_0800E5CC
	.thumb
	.thumb_func
	.type func_0800E5CC, %function
func_0800E5CC: @ 0800E5CC
	push {r4, lr}
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _0800E5E8
	ldrh r1, [r4, #0x34]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	bne _0800E5E8
	adds r0, r4, #0x0
	adds r0, #0x10
	bl func_08005A64
	str r0, [r4, #0x38]
_0800E5E8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
