.syntax unified
	.align 2, 0
	.global func_0801475C
	.thumb
	.thumb_func
	.type func_0801475C, %function
func_0801475C: @ 0801475C
	push {r4, lr}
	ldr r3, _0801477C @ =0x02034928
	ldr r4, [r3, #0x00]
	ldr r3, [r4, #0x10]
	adds r3, r3, r0
	str r3, [r4, #0x10]
	ldr r0, [r4, #0x14]
	adds r0, r0, r1
	str r0, [r4, #0x14]
	ldr r0, [r4, #0x18]
	adds r0, r0, r2
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801477C: .4byte 0x02034928
.syntax divided
