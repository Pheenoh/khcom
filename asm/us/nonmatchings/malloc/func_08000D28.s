.syntax unified
	.align 2, 0
	.global func_08000D28
	.thumb
	.thumb_func
	.type func_08000D28, %function
func_08000D28: @ 08000D28
	push {r4, lr}
	adds r4, r0, #0x0
	adds r2, r1, #0x0
	adds r1, #0x08
	adds r2, #0x0C
	bl func_08000B08
	ldrh r1, [r4, #0x0C]
	movs r0, #0x01
	orrs r0, r1
	strh r0, [r4, #0x0C]
	str r4, [r4, #0x10]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
