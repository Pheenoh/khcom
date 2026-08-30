.syntax unified
	.align 2, 0
	.global func_081161EC
	.thumb
	.thumb_func
	.type func_081161EC, %function
func_081161EC: @ 081161EC
	ldrh r3, [r0, #0x28]
	lsls r3, r3, #0x01
	adds r2, r0, #0x0
	adds r2, #0x58
	adds r2, r2, r3
	strh r1, [r2, #0x00]
	ldrh r1, [r0, #0x28]
	adds r1, #0x01
	movs r2, #0xFF
	ands r1, r2
	strh r1, [r0, #0x28]
	bx lr
.syntax divided
