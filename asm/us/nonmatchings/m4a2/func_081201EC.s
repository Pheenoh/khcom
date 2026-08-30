.syntax unified
	.align 2, 0
	.global func_081201EC
	.thumb
	.thumb_func
	.type func_081201EC, %function
func_081201EC: @ 081201EC
	push {lr}
	ldr r1, _081201FC @ =0x0203D888
	ldr r1, [r1, #0x00]
	bl _call_via_r1
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_081201FC: .4byte 0x0203D888
.syntax divided
