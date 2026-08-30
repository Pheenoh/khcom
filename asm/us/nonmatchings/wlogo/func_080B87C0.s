.syntax unified
	.align 2, 0
	.global func_080B87C0
	.thumb
	.thumb_func
	.type func_080B87C0, %function
func_080B87C0: @ 080B87C0
	push {r4, r5, lr}
	mov r12, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r0, [r0, #0x00]
	ldrh r1, [r0, #0x28]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	beq _080B8850
	movs r1, #0x94
	lsls r1, r1, #0x01
	add r1, r12
	ldr r4, _080B884C @ =0x09EF1E14
	lsls r5, r5, #0x10
	asrs r2, r5, #0x0B
	adds r2, r2, r4
	ldrb r0, [r2, #0x04]
	ldrb r3, [r1, #0x00]
	adds r0, r0, r3
	strb r0, [r1, #0x00]
	movs r1, #0x91
	lsls r1, r1, #0x02
	add r1, r12
	ldrb r0, [r2, #0x0C]
	ldrb r3, [r1, #0x00]
	adds r0, r0, r3
	strb r0, [r1, #0x00]
	movs r0, #0x00
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	mov r3, r12
	ldr r0, [r3, #0x14]
	adds r0, r0, r1
	str r0, [r3, #0x14]
	movs r3, #0x98
	lsls r3, r3, #0x01
	add r3, r12
	movs r0, #0x08
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	movs r3, #0x93
	lsls r3, r3, #0x02
	add r3, r12
	movs r0, #0x10
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	movs r3, #0xDA
	lsls r3, r3, #0x02
	add r3, r12
	movs r0, #0x18
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	mov r1, r12
	ldr r3, [r1, #0x00]
	movs r0, #0x10
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r3, #0x14]
	adds r0, r0, r1
	b _080B88C6
_080B884C: .4byte 0x09EF1E14
_080B8850:
	movs r1, #0x94
	lsls r1, r1, #0x01
	add r1, r12
	ldr r4, _080B8950 @ =0x09EF1E14
	lsls r5, r5, #0x10
	asrs r2, r5, #0x0B
	adds r2, r2, r4
	ldrb r0, [r2, #0x04]
	ldrb r3, [r1, #0x00]
	adds r0, r0, r3
	strb r0, [r1, #0x00]
	movs r1, #0x91
	lsls r1, r1, #0x02
	add r1, r12
	ldrb r0, [r2, #0x0C]
	ldrb r3, [r1, #0x00]
	adds r0, r0, r3
	strb r0, [r1, #0x00]
	movs r0, #0x00
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	mov r3, r12
	ldr r0, [r3, #0x14]
	subs r0, r0, r1
	str r0, [r3, #0x14]
	movs r3, #0x98
	lsls r3, r3, #0x01
	add r3, r12
	movs r0, #0x08
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r3, #0x00]
	subs r0, r0, r1
	str r0, [r3, #0x00]
	movs r3, #0x93
	lsls r3, r3, #0x02
	add r3, r12
	movs r0, #0x10
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r3, #0x00]
	subs r0, r0, r1
	str r0, [r3, #0x00]
	movs r3, #0xDA
	lsls r3, r3, #0x02
	add r3, r12
	movs r0, #0x18
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r3, #0x00]
	subs r0, r0, r1
	str r0, [r3, #0x00]
	mov r1, r12
	ldr r3, [r1, #0x00]
	movs r0, #0x10
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r3, #0x14]
	subs r0, r0, r1
_080B88C6:
	str r0, [r3, #0x14]
	asrs r2, r5, #0x0B
	adds r2, r2, r4
	movs r3, #0x02
	ldsh r1, [r2, r3]
	lsls r1, r1, #0x08
	mov r4, r12
	ldr r0, [r4, #0x1C]
	adds r0, r0, r1
	str r0, [r4, #0x1C]
	movs r3, #0x9C
	lsls r3, r3, #0x01
	add r3, r12
	movs r0, #0x0A
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	movs r3, #0x95
	lsls r3, r3, #0x02
	add r3, r12
	movs r4, #0x12
	ldsh r1, [r2, r4]
	lsls r1, r1, #0x08
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	movs r3, #0xDC
	lsls r3, r3, #0x02
	add r3, r12
	movs r0, #0x1A
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	mov r1, r12
	ldr r3, [r1, #0x00]
	movs r4, #0x0A
	ldsh r1, [r2, r4]
	lsls r1, r1, #0x08
	ldr r0, [r3, #0x1C]
	adds r0, r0, r1
	str r0, [r3, #0x1C]
	movs r3, #0xD7
	lsls r3, r3, #0x02
	add r3, r12
	ldr r1, _080B8954 @ =0x09EF397C
	movs r4, #0x16
	ldsh r0, [r2, r4]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x00]
	movs r3, #0x8F
	lsls r3, r3, #0x03
	add r3, r12
	ldr r1, _080B8958 @ =0x09EF3960
	movs r4, #0x1E
	ldsh r0, [r2, r4]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B8950: .4byte 0x09EF1E14
_080B8954: .4byte 0x09EF397C
_080B8958: .4byte 0x09EF3960
.syntax divided
