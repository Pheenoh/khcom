.syntax unified
	.align 2, 0
	.global func_08028428
	.thumb
	.thumb_func
	.type func_08028428, %function
func_08028428: @ 08028428
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r4, r2, #0x0
	adds r0, r3, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _0802844E
	adds r0, r3, #0x0
	ands r0, r2
	cmp r0, #0x00
	bne _0802844A
	bics r3, r1
_0802844A:
	orrs r3, r2
	b _0802845E
_0802844E:
	adds r0, r3, #0x0
	ands r0, r4
	cmp r0, #0x00
	beq _0802845E
	bics r3, r4
	orrs r3, r1
	lsls r0, r3, #0x10
	lsrs r3, r0, #0x10
_0802845E:
	adds r0, r3, #0x0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
