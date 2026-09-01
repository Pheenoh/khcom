.syntax unified
	.align 2, 0
	.global func_08000BB0
	.thumb
	.thumb_func
	.type func_08000BB0, %function
func_08000BB0: @ 08000BB0
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r2, #0x0
	adds r2, r1, #0x4
	bl func_08000B08
	str r5, [r4, #0x00]
	movs r0, #0x00
	strh r0, [r4, #0x0C]
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
