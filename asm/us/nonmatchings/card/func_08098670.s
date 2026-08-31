.syntax unified
	.align 2, 0
	.global func_08098670
	.thumb
	.thumb_func
	.type func_08098670, %function
func_08098670: @ 08098670
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r7, r5, #0x0
	ldr r6, [r4, #0x00]
	cmp r6, #0x00
	beq _080986A4
	ldr r0, [r4, #0x24]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x28]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, [r4, #0x18]
	ldr r3, [r4, #0x0C]
	str r3, [sp, #0x000]
	movs r3, #0x00
	str r3, [sp, #0x004]
	str r5, [sp, #0x008]
	movs r3, #0x0A
	str r3, [sp, #0x00C]
	adds r3, r6, #0x0
	bl DrawSprite
_080986A4:
	ldr r6, [r4, #0x04]
	cmp r6, #0x00
	beq _080986CC
	ldr r0, [r4, #0x24]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x28]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, [r4, #0x1C]
	ldr r3, [r4, #0x10]
	str r3, [sp, #0x000]
	movs r3, #0x00
	str r3, [sp, #0x004]
	str r5, [sp, #0x008]
	movs r3, #0x09
	str r3, [sp, #0x00C]
	adds r3, r6, #0x0
	bl DrawSprite
_080986CC:
	ldr r5, [r4, #0x08]
	cmp r5, #0x00
	beq _080986F4
	ldr r0, [r4, #0x24]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x28]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, [r4, #0x20]
	ldr r3, [r4, #0x14]
	str r3, [sp, #0x000]
	movs r3, #0x00
	str r3, [sp, #0x004]
	str r7, [sp, #0x008]
	movs r3, #0x08
	str r3, [sp, #0x00C]
	adds r3, r5, #0x0
	bl DrawSprite
_080986F4:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
