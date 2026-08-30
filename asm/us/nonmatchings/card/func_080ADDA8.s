.syntax unified
	.align 2, 0
	.global func_080ADDA8
	.thumb
	.thumb_func
	.type func_080ADDA8, %function
func_080ADDA8: @ 080ADDA8
	push {r4, r5, r6, lr}
	adds r3, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x03
	bne _080ADE24
	ldr r0, [r3, #0x00]
	ldr r6, [r0, #0x48]
	ldrh r5, [r6, #0x1C]
	ldr r2, [r3, #0x04]
	ldr r0, [r2, #0x48]
	ldrh r4, [r0, #0x1C]
	ldr r1, [r3, #0x08]
	ldr r0, [r1, #0x48]
	ldrh r3, [r0, #0x1C]
	cmp r5, r4
	beq _080ADE24
	cmp r4, r3
	beq _080ADE24
	cmp r3, r5
	beq _080ADE24
	adds r0, r6, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080ADDEC
	cmp r4, #0x27
	bne _080ADDE4
	cmp r3, #0x28
	beq _080ADE20
_080ADDE4:
	cmp r4, #0x28
	bne _080ADDEC
	cmp r3, #0x27
	beq _080ADE20
_080ADDEC:
	ldr r0, [r2, #0x48]
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080ADE06
	cmp r5, #0x27
	bne _080ADDFE
	cmp r3, #0x28
	beq _080ADE20
_080ADDFE:
	cmp r5, #0x28
	bne _080ADE06
	cmp r3, #0x27
	beq _080ADE20
_080ADE06:
	ldr r0, [r1, #0x48]
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080ADE24
	cmp r4, #0x27
	bne _080ADE18
	cmp r5, #0x28
	beq _080ADE20
_080ADE18:
	cmp r4, #0x28
	bne _080ADE24
	cmp r5, #0x27
	bne _080ADE24
_080ADE20:
	movs r0, #0x01
	b _080ADE26
_080ADE24:
	movs r0, #0x00
_080ADE26:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
