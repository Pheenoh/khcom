.syntax unified
	.align 2, 0
	.global func_080AEE84
	.thumb
	.thumb_func
	.type func_080AEE84, %function
func_080AEE84: @ 080AEE84
	push {r4, r5, lr}
	ldr r1, _080AEECC @ =0x0203AA88
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r1, _080AEED0 @ =0x0203AAA0
	movs r2, #0x00
	adds r0, r1, #0x0
	adds r0, #0x0C
_080AEE94:
	strb r2, [r0, #0x00]
	subs r0, #0x01
	cmp r0, r1
	bge _080AEE94
	ldr r5, _080AEED4 @ =0x00001FFE
	movs r1, #0x01
	movs r4, #0x01
	ldr r3, _080AEED0 @ =0x0203AAA0
	ldr r2, _080AEECC @ =0x0203AA88
_080AEEA6:
	adds r0, r5, #0x0
	asrs r0, r1
	ands r0, r4
	cmp r0, #0x00
	beq _080AEEBE
	ldrb r0, [r2, #0x00]
	adds r0, #0x01
	adds r0, r0, r3
	strb r1, [r0, #0x00]
	ldrb r0, [r2, #0x00]
	adds r0, #0x01
	strb r0, [r2, #0x00]
_080AEEBE:
	adds r1, #0x01
	cmp r1, #0x0D
	ble _080AEEA6
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080AEECC: .4byte 0x0203AA88
_080AEED0: .4byte 0x0203AAA0
_080AEED4: .4byte 0x00001FFE
.syntax divided
