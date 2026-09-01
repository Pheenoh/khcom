.syntax unified
	.align 2, 0
	.global func_080274F0
	.thumb
	.thumb_func
	.type func_080274F0, %function
func_080274F0: @ 080274F0
	push {r4, lr}
	adds r3, r0, #0x0
	movs r1, #0xBC
	lsls r1, r1, #0x01
	adds r0, r3, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08027534
	subs r1, #0x50
	adds r0, r3, r1
	ldr r0, [r0, #0x00]
	ldr r4, [r0, #0x78]
	cmp r4, #0x00
	beq _0802752A
	ldr r0, [r3, #0x48]
	ldr r1, [r4, #0x04]
	adds r0, r0, r1
	asrs r0, r0, #0x01
	ldr r1, [r3, #0x4C]
	ldr r2, [r4, #0x08]
	adds r1, r1, r2
	asrs r1, r1, #0x01
	ldr r2, [r3, #0x50]
	ldr r3, [r4, #0x0C]
	adds r2, r2, r3
	asrs r2, r2, #0x01
	bl func_0802F284
	b _08027534
_0802752A:
	ldr r0, [r3, #0x48]
	ldr r1, [r3, #0x4C]
	ldr r2, [r3, #0x50]
	bl func_0802F284
_08027534:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
