.syntax unified
	.align 2, 0
	.global func_080140C0
	.thumb
	.thumb_func
	.type func_080140C0, %function
func_080140C0: @ 080140C0
	push {r4, r5, lr}
	ldr r5, _080140DC @ =0x02034928
	ldr r4, [r5, #0x00]
	ldr r3, [r4, #0x10]
	str r3, [r0, #0x00]
	ldr r0, [r4, #0x14]
	str r0, [r1, #0x00]
	ldr r0, [r5, #0x00]
	ldr r0, [r0, #0x18]
	str r0, [r2, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080140DC: .4byte 0x02034928
.syntax divided
