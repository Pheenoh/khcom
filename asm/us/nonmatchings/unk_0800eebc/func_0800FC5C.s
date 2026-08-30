.syntax unified
	.align 2, 0
	.global func_0800FC5C
	.thumb
	.thumb_func
	.type func_0800FC5C, %function
func_0800FC5C: @ 0800FC5C
	push {r4, lr}
	adds r2, r0, #0x0
	ldr r4, _0800FC84 @ =0x02039BB0
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r4, r4, r0
	movs r0, #0x01
	movs r1, #0x00
	bl _0811D57C
	ldr r2, [r4, #0x00]
	ldr r3, [r4, #0x04]
	ands r2, r0
	ands r3, r1
	adds r0, r3, #0x0
	orrs r0, r2
	cmp r0, #0x00
	bne _0800FC88
	movs r0, #0x00
	b _0800FC8A
_0800FC84: .4byte 0x02039BB0
_0800FC88:
	movs r0, #0x01
_0800FC8A:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
