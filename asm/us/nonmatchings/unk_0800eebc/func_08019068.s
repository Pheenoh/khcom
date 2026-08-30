.syntax unified
	.align 2, 0
	.global func_08019068
	.thumb
	.thumb_func
	.type func_08019068, %function
func_08019068: @ 08019068
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	adds r0, r1, #0x0
	adds r4, r3, #0x0
	ldr r6, [sp, #0x014]
	lsls r2, r2, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsrs r2, r2, #0x0C
	adds r5, r5, r2
	ldrb r1, [r5, #0x0C]
	ldr r3, [r5, #0x04]
	ldr r2, [r5, #0x00]
	str r2, [sp, #0x000]
	adds r2, r4, #0x0
	bl func_08005974
	ldr r1, [r5, #0x08]
	adds r0, r6, #0x0
	bl func_08002A10
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
