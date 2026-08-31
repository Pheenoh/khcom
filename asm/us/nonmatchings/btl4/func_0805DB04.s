.syntax unified
	.align 2, 0
	.global func_0805DB04
	.thumb
	.thumb_func
	.type func_0805DB04, %function
func_0805DB04: @ 0805DB04
	push {r4, r5, lr}
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldrh r5, [r0, #0x00]
	movs r4, #0x04
	orrs r4, r5
	strh r4, [r0, #0x00]
	strh r1, [r0, #0x12]
	strh r2, [r0, #0x14]
	adds r0, #0x20
	adds r1, r3, #0x0
	movs r2, #0x01
	bl AnimStart
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
