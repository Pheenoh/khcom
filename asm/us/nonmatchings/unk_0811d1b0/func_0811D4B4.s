.syntax unified
	.align 2, 0
	.global func_0811D4B4
	.thumb
	.thumb_func
	.type func_0811D4B4, %function
func_0811D4B4: @ 0811D4B4
	push {r4, lr}
	ldr r4, _0811D4C8 @ =0x0203C7F0
	str r0, [r4, #0x48]
	str r1, [r4, #0x4C]
	str r2, [r4, #0x50]
	str r3, [r4, #0x54]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0811D4C8: .4byte 0x0203C7F0
.syntax divided
