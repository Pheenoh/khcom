.syntax unified
	.align 2, 0
	.global func_0800B30C
	.thumb
	.thumb_func
	.type func_0800B30C, %function
func_0800B30C: @ 0800B30C
	push {r4, r5, lr}
	add sp, #-0x004
	adds r4, r0, #0x0
	ldr r5, _0800B350 @ =0x0203489C
	ldr r1, [r5, #0x00]
	adds r0, r1, #0x0
	adds r0, #0x24
	ldrh r1, [r1, #0x16]
	ldr r3, [r4, #0x04]
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	bl func_08005974
	ldr r0, [r5, #0x00]
	ldr r0, [r0, #0x1C]
	ldr r1, [r4, #0x08]
	bl func_08002A10
	ldr r0, [r5, #0x00]
	ldr r0, [r0, #0x20]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x10]
	ldrh r1, [r4, #0x1C]
	bl LoadObjPalette
	ldr r1, [r5, #0x00]
	str r0, [r1, #0x20]
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800B350: .4byte 0x0203489C
.syntax divided
