.syntax unified
	.align 2, 0
	.global func_080D2034
	.thumb
	.thumb_func
	.type func_080D2034, %function
func_080D2034: @ 080D2034
	push {r4, r5, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	bl _080D1FB8
	ldr r4, [r5, #0x4C]
	lsls r4, r4, #0x04
	ldr r0, _080D2068 @ =0x09EF4C88
	adds r4, r4, r0
	adds r0, r5, #0x0
	adds r0, #0x08
	ldrb r1, [r4, #0x0C]
	ldr r3, [r4, #0x04]
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x01
	bl func_08005974
	ldr r0, [r5, #0x00]
	ldr r1, [r4, #0x08]
	bl func_08002A10
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
_080D2068: .4byte 0x09EF4C88
.syntax divided
