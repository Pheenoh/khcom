.syntax unified
	.align 2, 0
	.global m4aMPlayImmInit
	.thumb
	.thumb_func
	.type m4aMPlayImmInit, %function
m4aMPlayImmInit: @ 08120068
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r7, r0, #0x0
	ldr r1, [r7, #0x34]
	ldr r0, _081200CC @ =0x68736D53
	cmp r1, r0
	bne _081200C2
	adds r0, r1, #0x1
	str r0, [r7, #0x34]
	ldrb r5, [r7, #0x08]
	ldr r4, [r7, #0x2C]
	cmp r5, #0x00
	ble _081200BE
	movs r2, #0x80
_08120084:
	ldrb r1, [r4, #0x00]
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _081200B6
	movs r6, #0x40
	adds r0, r6, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _081200B6
	adds r0, r4, #0x0
	str r2, [sp, #0x000]
	bl ClearModM
	ldr r2, [sp, #0x000]
	strb r2, [r4, #0x00]
	movs r0, #0x02
	strb r0, [r4, #0x0F]
	strb r6, [r4, #0x13]
	movs r0, #0x16
	strb r0, [r4, #0x19]
	adds r1, r4, #0x0
	adds r1, #0x24
	movs r0, #0x01
	strb r0, [r1, #0x00]
_081200B6:
	subs r5, #0x01
	adds r4, #0x50
	cmp r5, #0x00
	bgt _08120084
_081200BE:
	ldr r0, _081200CC @ =0x68736D53
	str r0, [r7, #0x34]
_081200C2:
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_081200CC: .4byte 0x68736D53
.syntax divided
