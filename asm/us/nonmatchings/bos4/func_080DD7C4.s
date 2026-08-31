.syntax unified
	.align 2, 0
	.global func_080DD7C4
	.thumb
	.thumb_func
	.type func_080DD7C4, %function
func_080DD7C4: @ 080DD7C4
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	movs r1, #0x60
	mov r0, sp
	strb r1, [r0, #0x00]
	bl func_080DC510
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DD7E8
	mov r0, sp
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	negs r0, r0
	mov r1, sp
	strb r0, [r1, #0x00]
_080DD7E8:
	adds r4, r5, #0x4
	ldr r6, _080DD850 @ =0x09EF5268
	adds r0, r4, #0x0
	adds r1, r6, #0x0
	mov r2, sp
	bl TaskCreate
	str r0, [r5, #0x18]
	mov r1, sp
	movs r0, #0x20
	strb r0, [r1, #0x00]
	bl func_080DC510
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DD812
	mov r1, sp
	mov r0, sp
	ldrb r0, [r0, #0x00]
	negs r0, r0
	strb r0, [r1, #0x00]
_080DD812:
	adds r0, r4, #0x0
	adds r1, r6, #0x0
	mov r2, sp
	bl TaskCreate
	str r0, [r5, #0x1C]
	mov r1, sp
	movs r0, #0x40
	strb r0, [r1, #0x00]
	bl func_080DC510
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DD838
	mov r1, sp
	mov r0, sp
	ldrb r0, [r0, #0x00]
	negs r0, r0
	strb r0, [r1, #0x00]
_080DD838:
	adds r0, r4, #0x0
	adds r1, r6, #0x0
	mov r2, sp
	bl TaskCreate
	str r0, [r5, #0x20]
	movs r0, #0x03
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080DD850: .4byte 0x09EF5268
.syntax divided
