.syntax unified
	.align 2, 0
	.global func_080AA634
	.thumb
	.thumb_func
	.type func_080AA634, %function
func_080AA634: @ 080AA634
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x1C]
	cmp r0, #0x00
	beq _080AA646
	bl func_080028C0
	movs r0, #0x00
	str r0, [r4, #0x1C]
_080AA646:
	ldr r0, [r4, #0x10]
	cmp r0, #0x00
	beq _080AA67A
	bl func_080028C0
	ldr r0, [r4, #0x20]
	bl func_08002C10
	ldr r0, [r4, #0x14]
	bl func_080028C0
	ldr r0, [r4, #0x24]
	bl func_08002C10
	ldr r0, [r4, #0x18]
	cmp r0, #0x00
	beq _080AA670
	bl func_080028C0
	movs r0, #0x00
	str r0, [r4, #0x18]
_080AA670:
	movs r0, #0x00
	str r0, [r4, #0x10]
	str r0, [r4, #0x20]
	str r0, [r4, #0x14]
	str r0, [r4, #0x24]
_080AA67A:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
