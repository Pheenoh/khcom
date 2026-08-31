.syntax unified
	.align 2, 0
	.global HeapFree
	.thumb
	.thumb_func
	.type HeapFree, %function
HeapFree: @ 08000938
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0x0
	adds r7, r1, #0x0
	cmp r2, #0x00
	beq _080009BC
	adds r5, r2, #0x0
	subs r5, #0x20
	ldr r0, [r5, #0x1C]
	cmp r0, r5
	bne _080009BC
	adds r0, r2, #0x0
	bl func_080007B8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080009BC
	ldr r0, [r5, #0x00]
	negs r6, r0
	cmp r6, #0x00
	blt _080009BC
	str r6, [r5, #0x00]
	ldr r4, [r5, #0x0C]
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	ble _08000986
	adds r0, r4, #0x0
	bl func_080007A8
	ldr r0, [r4, #0x00]
	adds r0, r0, r6
	str r0, [r4, #0x00]
	ldr r0, [r5, #0x10]
	str r0, [r4, #0x10]
	ldr r0, [r5, #0x10]
	str r4, [r0, #0x0C]
	movs r0, #0x00
	str r0, [r5, #0x0C]
	str r0, [r5, #0x10]
	adds r5, r4, #0x0
_08000986:
	ldr r4, [r5, #0x10]
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	ble _080009AA
	adds r0, r4, #0x0
	bl func_080007A8
	ldr r0, [r5, #0x00]
	ldr r1, [r4, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x00]
	ldr r0, [r4, #0x10]
	str r0, [r5, #0x10]
	ldr r0, [r4, #0x10]
	str r5, [r0, #0x0C]
	movs r0, #0x00
	str r0, [r4, #0x0C]
	str r0, [r4, #0x10]
_080009AA:
	ldr r1, [r7, #0x00]
	str r1, [r5, #0x04]
	ldr r0, [r1, #0x08]
	str r0, [r5, #0x08]
	ldr r0, [r1, #0x08]
	str r5, [r0, #0x04]
	str r5, [r1, #0x08]
	movs r0, #0x00
	str r0, [r5, #0x1C]
_080009BC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
