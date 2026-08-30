.syntax unified
	.align 2, 0
	.global func_08005810
	.thumb
	.thumb_func
	.type func_08005810, %function
func_08005810: @ 08005810
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08005820 @ =0x03007564
	lsrs r0, r0, #0x08
	orrs r1, r0
	strh r1, [r2, #0x00]
	bx lr
_08005820: .4byte 0x03007564
.syntax divided
