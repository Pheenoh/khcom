.syntax unified
	.align 2, 0
	.global func_0800FC14
	.thumb
	.thumb_func
	.type func_0800FC14, %function
func_0800FC14: @ 0800FC14
	push {r4, lr}
	adds r2, r0, #0x0
	cmp r2, #0x3A
	bne _0800FC34
	ldr r2, _0800FC30 @ =0x02039BB0
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r2, r2, r0
	movs r0, #0x01
	negs r0, r0
	asrs r1, r0, #0x1F
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	b _0800FC50
_0800FC30: .4byte 0x02039BB0
_0800FC34:
	ldr r4, _0800FC58 @ =0x02039BB0
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r4, r4, r0
	movs r0, #0x01
	movs r1, #0x00
	bl _0811D57C
	ldr r2, [r4, #0x00]
	ldr r3, [r4, #0x04]
	orrs r2, r0
	orrs r3, r1
	str r2, [r4, #0x00]
	str r3, [r4, #0x04]
_0800FC50:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800FC58: .4byte 0x02039BB0
.syntax divided
