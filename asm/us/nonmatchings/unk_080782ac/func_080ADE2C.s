.syntax unified
	.align 2, 0
	.global func_080ADE2C
	.thumb
	.thumb_func
	.type func_080ADE2C, %function
func_080ADE2C: @ 080ADE2C
	push {r4, lr}
	adds r1, r0, #0x0
	ldr r0, [sp, #0x008]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x48]
	ldrh r0, [r0, #0x1C]
	cmp r0, r2
	bne _080ADE6E
	ldr r0, [r1, #0x04]
	ldr r0, [r0, #0x48]
	ldrh r0, [r0, #0x1C]
	cmp r0, r3
	bne _080ADE6E
	ldr r0, [r1, #0x08]
	ldr r1, [r0, #0x48]
	adds r0, r1, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, r4
	bne _080ADE6E
	ldrh r1, [r1, #0x1E]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	bne _080ADE6E
	movs r0, #0x01
	b _080ADE70
_080ADE6E:
	movs r0, #0x00
_080ADE70:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
