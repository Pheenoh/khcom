.syntax unified
	.align 2, 0
	.global func_080054C8
	.thumb
	.thumb_func
	.type func_080054C8, %function
func_080054C8: @ 080054C8
	push {r4, r5, lr}
	movs r3, #0x0F
	ands r1, r3
	ldr r5, _080054E8 @ =0x03007528
	ldrh r4, [r5, #0x00]
	movs r2, #0xFF
	lsls r2, r2, #0x08
	ands r2, r4
	ands r3, r0
	orrs r2, r3
	lsls r1, r1, #0x04
	orrs r2, r1
	strh r2, [r5, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_080054E8: .4byte 0x03007528
.syntax divided
