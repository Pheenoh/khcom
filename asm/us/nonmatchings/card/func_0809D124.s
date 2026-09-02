.syntax unified
	.align 2, 0
	.global func_0809D124
	.thumb
	.thumb_func
	.type func_0809D124, %function
func_0809D124: @ 0809D124
	push {r4, r5, lr}
	ldr r5, _0809D15C @ =0x08121400
	ldr r2, [r0, #0x3C]
	movs r1, #0xFF
	ands r2, r1
	lsls r1, r2, #0x01
	adds r1, r1, r5
	movs r3, #0x00
	ldsh r1, [r1, r3]
	ldr r4, [r0, #0x40]
	asrs r4, r4, #0x08
	muls r1, r4
	ldr r3, [r0, #0x24]
	adds r1, r1, r3
	str r1, [r0, #0x30]
	adds r2, #0x40
	lsls r2, r2, #0x01
	adds r2, r2, r5
	movs r3, #0x00
	ldsh r1, [r2, r3]
	negs r1, r1
	muls r1, r4
	ldr r2, [r0, #0x28]
	adds r1, r1, r2
	str r1, [r0, #0x34]
	pop {r4, r5}
	pop {r0}
	bx r0
_0809D15C: .4byte 0x08121400
.syntax divided
