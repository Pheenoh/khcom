.syntax unified
	.align 2, 0
	.global func_08000BC8
	.thumb
	.thumb_func
	.type func_08000BC8, %function
func_08000BC8: @ 08000BC8
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	adds r2, r4, #0x4
	bl func_08000B6C
	adds r1, r4, #0x0
	adds r1, #0x08
	adds r4, #0x0C
	adds r0, r5, #0x0
	adds r2, r4, #0x0
	bl func_08000B08
	ldrh r1, [r5, #0x0C]
	movs r0, #0x01
	orrs r0, r1
	strh r0, [r5, #0x0C]
	str r5, [r5, #0x10]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
