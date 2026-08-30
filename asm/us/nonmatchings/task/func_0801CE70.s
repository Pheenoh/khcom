.syntax unified
	.align 2, 0
	.global func_0801CE70
	.thumb
	.thumb_func
	.type func_0801CE70, %function
func_0801CE70: @ 0801CE70
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r6, r0, #0x0
	ldr r0, [r6, #0x00]
	ldr r2, [r0, #0x00]
	ldr r5, [r2, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x0C
	ldrh r1, [r2, #0x0C]
	ldrh r2, [r2, #0x0E]
	ldr r3, [r5, #0x04]
	ldr r4, [r5, #0x00]
	str r4, [sp, #0x000]
	bl func_08005974
	ldr r0, [r6, #0x04]
	ldr r1, [r5, #0x08]
	bl func_08002A10
	ldr r2, [r6, #0x00]
	ldrh r1, [r2, #0x14]
	ldr r0, _0801CEA8 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2, #0x14]
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0801CEA8: .4byte 0x0000FFFE
.syntax divided
