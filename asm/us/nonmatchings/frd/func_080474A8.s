.syntax unified
	.align 2, 0
	.global func_080474A8
	.thumb
	.thumb_func
	.type func_080474A8, %function
func_080474A8: @ 080474A8
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x20
	adds r0, #0x24
	adds r1, r4, #0x0
	adds r1, #0x28
	adds r2, r4, #0x0
	adds r2, #0x2C
	adds r3, r4, #0x0
	adds r3, #0x30
	bl func_0801C6D4
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r0, [r5, #0x0C]
	ldr r1, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	ldr r0, [r2, #0x00]
	adds r0, #0x33
	str r0, [r2, #0x00]
	ldr r0, [r5, #0x0C]
	ldr r1, [r5, #0x10]
	cmp r0, r1
	bgt _080474E2
	movs r0, #0x00
	b _080474EA
_080474E2:
	str r1, [r5, #0x0C]
	movs r0, #0x00
	str r0, [r2, #0x00]
	movs r0, #0x01
_080474EA:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
