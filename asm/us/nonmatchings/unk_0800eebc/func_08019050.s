.syntax unified
	.align 2, 0
	.global func_08019050
	.thumb
	.thumb_func
	.type func_08019050, %function
func_08019050: @ 08019050
	push {r4, lr}
	ldr r4, _08019064 @ =0x02039B84
	ldr r4, [r4, #0x00]
	str r1, [r4, #0x28]
	strh r0, [r4, #0x1A]
	str r2, [r4, #0x1C]
	str r3, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0
_08019064: .4byte 0x02039B84
.syntax divided
