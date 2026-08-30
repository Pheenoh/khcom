.syntax unified
	.align 2, 0
	.global func_0811FDA8
	.thumb
	.thumb_func
	.type func_0811FDA8, %function
func_0811FDA8: @ 0811FDA8
	push {lr}
	adds r2, r0, #0x0
	ldr r3, [r2, #0x34]
	ldr r0, _0811FDC0 @ =0x68736D53
	cmp r3, r0
	bne _0811FDBC
	ldr r0, [r2, #0x04]
	ldr r1, _0811FDC4 @ =0x7FFFFFFF
	ands r0, r1
	str r0, [r2, #0x04]
_0811FDBC:
	pop {r0}
	bx r0
_0811FDC0: .4byte 0x68736D53
_0811FDC4: .4byte 0x7FFFFFFF
.syntax divided
