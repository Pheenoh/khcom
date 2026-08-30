.syntax unified
	.align 2, 0
	.global func_08116008
	.thumb
	.thumb_func
	.type func_08116008, %function
func_08116008: @ 08116008
	push {r4, r5, r6, lr}
	adds r6, r2, #0x0
	adds r4, r3, #0x0
	ldr r5, [sp, #0x010]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	bl func_08115F34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r4, r4, #0x03
	muls r0, r4
	muls r0, r5
	adds r6, r6, r0
	adds r0, r6, #0x0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
