.syntax unified
	.align 2, 0
	.global func_080AE1E8
	.thumb
	.thumb_func
	.type func_080AE1E8, %function
func_080AE1E8: @ 080AE1E8
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r2, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x03
	bne _080AE266
	ldr r0, [r2, #0x00]
	ldr r4, [r0, #0x48]
	ldrh r0, [r4, #0x1C]
	mov r9, r0
	ldr r0, [r2, #0x04]
	ldr r5, [r0, #0x48]
	ldrh r1, [r5, #0x1C]
	mov r8, r1
	ldr r1, [r2, #0x08]
	ldr r0, [r1, #0x48]
	ldrh r7, [r0, #0x1C]
	adds r2, r4, #0x0
	adds r2, #0x2A
	ldrb r2, [r2, #0x00]
	adds r3, r5, #0x0
	adds r3, #0x2A
	ldrb r3, [r3, #0x00]
	adds r0, #0x2A
	ldrb r6, [r0, #0x00]
	mov r12, r1
	cmp r2, #0x01
	bne _080AE244
	ldrh r1, [r4, #0x1E]
	movs r2, #0x04
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	bne _080AE244
	cmp r3, #0x01
	bne _080AE244
	ldrh r1, [r5, #0x1E]
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	bne _080AE244
	cmp r7, #0x2C
	beq _080AE262
_080AE244:
	mov r0, r9
	cmp r0, #0x17
	bne _080AE266
	mov r1, r8
	cmp r1, #0x18
	bne _080AE266
	cmp r6, #0x02
	bne _080AE266
	mov r1, r12
	ldr r0, [r1, #0x48]
	ldrh r1, [r0, #0x1E]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080AE266
_080AE262:
	movs r0, #0x01
	b _080AE268
_080AE266:
	movs r0, #0x00
_080AE268:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
