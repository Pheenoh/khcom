.syntax unified
	.align 2, 0
	.global func_0801CD74
	.thumb
	.thumb_func
	.type func_0801CD74, %function
func_0801CD74: @ 0801CD74
	ldrh r3, [r0, #0x14]
	movs r2, #0x01
	orrs r2, r3
	strh r2, [r0, #0x14]
	lsls r1, r1, #0x04
	ldr r2, _0801CD88 @ =0x0813766C
	adds r1, r1, r2
	str r1, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_0801CD88: .4byte 0x0813766C
.syntax divided
