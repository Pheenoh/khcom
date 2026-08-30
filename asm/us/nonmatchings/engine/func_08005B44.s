.syntax unified
	.align 2, 0
	.global func_08005B44
	.thumb
	.thumb_func
	.type func_08005B44, %function
func_08005B44: @ 08005B44
	adds r2, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r2, #0x0C]
	cmp r1, r0
	bcs _08005B5E
	movs r0, #0x00
	strh r1, [r2, #0x0E]
	strh r0, [r2, #0x0A]
	ldrh r1, [r2, #0x08]
	ldr r0, _08005B60 @ =0x0000EFFF
	ands r0, r1
	strh r0, [r2, #0x08]
_08005B5E:
	bx lr
_08005B60: .4byte 0x0000EFFF
.syntax divided
