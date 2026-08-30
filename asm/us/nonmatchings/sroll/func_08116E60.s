.syntax unified
	.align 2, 0
	.global func_08116E60
	.thumb
	.thumb_func
	.type func_08116E60, %function
func_08116E60: @ 08116E60
	push {r4, lr}
	ldr r3, _08116E7C @ =0x02036028
	ldr r1, [r3, #0x0C]
	movs r4, #0x01
	eors r1, r4
	lsls r1, r1, #0x02
	adds r2, r3, #0x0
	adds r2, #0x10
	adds r1, r1, r2
	str r0, [r1, #0x00]
	strb r4, [r3, #0x01]
	pop {r4}
	pop {r0}
	bx r0
_08116E7C: .4byte 0x02036028
.syntax divided
