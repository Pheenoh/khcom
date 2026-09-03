.syntax unified
	.align 2, 0
	.global func_080F01B0
	.thumb
	.thumb_func
	.type func_080F01B0, %function
func_080F01B0: @ 080F01B0
	push {r4, lr}
	mov r12, r0
	mov r2, r12
	adds r2, #0x08
	ldr r0, [r2, #0x10]
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r0, r1
	str r0, [r2, #0x10]
	movs r1, #0xA0
	lsls r1, r1, #0x03
	cmp r0, r1
	ble _080F01CC
	str r1, [r2, #0x10]
_080F01CC:
	mov r0, r12
	adds r0, #0xD4
	ldr r1, [r0, #0x00]
	mov r3, r12
	ldr r0, [r3, #0x08]
	subs r1, r1, r0
	cmp r1, #0x00
	bge _080F01DE
	adds r1, #0x1F
_080F01DE:
	asrs r1, r1, #0x05
	ldr r3, [r2, #0x10]
	cmp r1, r3
	ble _080F01EA
	adds r1, r3, #0x0
	b _080F01F2
_080F01EA:
	negs r0, r3
	cmp r1, r0
	bge _080F01F2
	adds r1, r0, #0x0
_080F01F2:
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	mov r0, r12
	adds r0, #0xD8
	ldr r1, [r0, #0x00]
	ldr r0, [r2, #0x04]
	subs r1, r1, r0
	adds r4, r0, #0x0
	cmp r1, #0x00
	bge _080F020A
	adds r1, #0x1F
_080F020A:
	asrs r0, r1, #0x05
	cmp r0, r3
	ble _080F0214
	adds r0, r3, #0x0
	b _080F021C
_080F0214:
	negs r1, r3
	cmp r0, r1
	bge _080F021C
	adds r0, r1, #0x0
_080F021C:
	adds r0, r4, r0
	str r0, [r2, #0x04]
	mov r1, r12
	adds r1, #0xD0
	ldrh r0, [r1, #0x00]
	cmp r0, #0x40
	bhi _080F0232
	adds r0, #0x01
	strh r0, [r1, #0x00]
	movs r0, #0x00
	b _080F0234
_080F0232:
	movs r0, #0x01
_080F0234:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
