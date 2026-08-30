.syntax unified
	.align 2, 0
	.global func_080ADF94
	.thumb
	.thumb_func
	.type func_080ADF94, %function
func_080ADF94: @ 080ADF94
	push {r4, lr}
	adds r3, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	cmp r1, #0x03
	bne _080ADFCC
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x48]
	ldrh r1, [r0, #0x1E]
	ldr r0, [r3, #0x04]
	ldr r0, [r0, #0x48]
	ldrh r0, [r0, #0x1E]
	movs r2, #0x04
	ands r1, r2
	cmp r1, #0x00
	beq _080ADFCC
	ands r0, r2
	cmp r0, #0x00
	beq _080ADFCC
	ldr r0, [r3, #0x08]
	ldr r0, [r0, #0x48]
	ldrh r0, [r0, #0x1C]
	cmp r0, r4
	bne _080ADFCC
	movs r0, #0x01
	b _080ADFCE
_080ADFCC:
	movs r0, #0x00
_080ADFCE:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
