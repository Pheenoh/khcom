.syntax unified
	.align 2, 0
	.global func_0801DDE4
	.thumb
	.thumb_func
	.type func_0801DDE4, %function
func_0801DDE4: @ 0801DDE4
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	lsls r5, r5, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsrs r5, r5, #0x0C
	ldr r0, _0801DE18 @ =0x0813BA2C
	adds r5, r5, r0
	adds r0, r6, #0x0
	adds r0, #0x0C
	ldrb r1, [r5, #0x0C]
	ldr r3, [r5, #0x04]
	ldr r4, [r5, #0x00]
	str r4, [sp, #0x000]
	bl func_08005974
	ldr r0, [r6, #0x00]
	ldr r1, [r5, #0x08]
	bl func_08002A10
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0801DE18: .4byte 0x0813BA2C
.syntax divided
