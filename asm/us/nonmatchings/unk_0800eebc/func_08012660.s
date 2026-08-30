.syntax unified
	.align 2, 0
	.global func_08012660
	.thumb
	.thumb_func
	.type func_08012660, %function
func_08012660: @ 08012660
	movs r2, #0x01
	lsls r2, r1
	ldr r0, [r0, #0x58]
	ands r0, r2
	cmp r0, #0x00
	bne _08012670
	movs r0, #0x00
	b _08012672
_08012670:
	movs r0, #0x01
_08012672:
	bx lr
.syntax divided
