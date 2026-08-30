.syntax unified
	.align 2, 0
	.global func_080C8B38
	.thumb
	.thumb_func
	.type func_080C8B38, %function
func_080C8B38: @ 080C8B38
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldrh r0, [r4, #0x2E]
	movs r5, #0x01
	adds r3, r5, #0x0
	ands r3, r0
	cmp r3, #0x00
	beq _080C8B56
	ldr r1, [r1, #0x0C]
	ldr r0, [r4, #0x40]
	cmp r1, r0
	bge _080C8B52
	adds r0, r1, #0x0
_080C8B52:
	strb r5, [r2, #0x00]
	b _080C8B5A
_080C8B56:
	strb r3, [r2, #0x00]
	ldr r0, [r1, #0x0C]
_080C8B5A:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
