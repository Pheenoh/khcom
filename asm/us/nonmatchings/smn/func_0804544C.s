.syntax unified
	.align 2, 0
	.global func_0804544C
	.thumb
	.thumb_func
	.type func_0804544C, %function
func_0804544C: @ 0804544C
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
	bgt _08045486
	movs r0, #0x00
	b _0804548E
_08045486:
	str r1, [r5, #0x0C]
	movs r0, #0x00
	str r0, [r2, #0x00]
	movs r0, #0x01
_0804548E:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
