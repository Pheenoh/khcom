.syntax unified
	.align 2, 0
	.global func_08005920
	.thumb
	.thumb_func
	.type func_08005920, %function
func_08005920: @ 08005920
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x11
	cmp r0, #0x00
	bne _0800592A
	movs r0, #0x01
_0800592A:
	bx lr
.syntax divided
