.syntax unified
	.align 2, 0
	.global func_080D206C
	.thumb
	.thumb_func
	.type func_080D206C, %function
func_080D206C: @ 080D206C
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r0, #0x48
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	blt _080D2084
	ldr r0, [r5, #0x38]
	str r0, [r5, #0x40]
	ldr r0, [r5, #0x3C]
	b _080D208A
_080D2084:
	ldr r0, [r5, #0x30]
	str r0, [r5, #0x40]
	ldr r0, [r5, #0x34]
_080D208A:
	str r0, [r5, #0x44]
	movs r0, #0x40
	movs r1, #0x00
	bl func_080028F8
	str r0, [r5, #0x00]
	adds r4, r5, #0x0
	adds r4, #0x08
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_08005968
	adds r0, r5, #0x0
	bl func_080D2034
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r5, #0x04]
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
