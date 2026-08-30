.syntax unified
	.align 2, 0
	.global func_080E6034
	.thumb
	.thumb_func
	.type func_080E6034, %function
func_080E6034: @ 080E6034
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	ldr r5, _080E6078 @ =0x02039C98
	adds r0, r5, #0x0
	bl func_08000D0C
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _080E6072
	ldr r0, [r4, #0x00]
	str r0, [r2, #0x30]
	adds r0, r4, #0x0
	adds r0, #0xCC
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x34]
	adds r1, r2, #0x0
	adds r0, r4, #0x0
	adds r0, #0x08
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldrb r0, [r4, #0x1C]
	strb r0, [r2, #0x10]
	ldr r0, [r4, #0x18]
	str r0, [r2, #0x14]
	adds r0, r2, #0x0
	adds r0, #0x1C
	adds r1, r5, #0x0
	bl func_08000BC8
_080E6072:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080E6078: .4byte 0x02039C98
.syntax divided
