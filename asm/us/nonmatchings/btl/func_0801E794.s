.syntax unified
	.align 2, 0
	.global func_0801E794
	.thumb
	.thumb_func
	.type func_0801E794, %function
func_0801E794: @ 0801E794
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
	beq _0801E7BA
	adds r0, r3, #0x0
	ands r0, r2
	cmp r0, #0x00
	bne _0801E7B6
	bics r3, r1
_0801E7B6:
	orrs r3, r2
	b _0801E7CA
_0801E7BA:
	adds r0, r3, #0x0
	ands r0, r4
	cmp r0, #0x00
	beq _0801E7CA
	bics r3, r4
	orrs r3, r1
	lsls r0, r3, #0x10
	lsrs r3, r0, #0x10
_0801E7CA:
	adds r0, r3, #0x0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
