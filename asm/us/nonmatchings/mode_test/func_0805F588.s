.syntax unified
	.align 2, 0
	.global func_0805F588
	.thumb
	.thumb_func
	.type func_0805F588, %function
func_0805F588: @ 0805F588
	push {lr}
	adds r2, r0, #0x0
	muls r2, r0
	adds r0, r2, #0x0
	adds r2, r1, #0x0
	muls r2, r1
	adds r1, r2, #0x0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
.syntax divided
