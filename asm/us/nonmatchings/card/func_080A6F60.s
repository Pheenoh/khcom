.syntax unified
	.align 2, 0
	.global func_080A6F60
	.thumb
	.thumb_func
	.type func_080A6F60, %function
func_080A6F60: @ 080A6F60
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x24]
	cmp r0, #0x00
	beq _080A6F72
	bl func_080028C0
	movs r0, #0x00
	str r0, [r4, #0x24]
_080A6F72:
	ldr r0, [r4, #0x18]
	cmp r0, #0x00
	beq _080A6FA6
	bl func_080028C0
	ldr r0, [r4, #0x28]
	bl func_08002C10
	ldr r0, [r4, #0x1C]
	bl func_080028C0
	ldr r0, [r4, #0x2C]
	bl func_08002C10
	ldr r0, [r4, #0x20]
	cmp r0, #0x00
	beq _080A6F9C
	bl func_080028C0
	movs r0, #0x00
	str r0, [r4, #0x20]
_080A6F9C:
	movs r0, #0x00
	str r0, [r4, #0x18]
	str r0, [r4, #0x28]
	str r0, [r4, #0x1C]
	str r0, [r4, #0x2C]
_080A6FA6:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
