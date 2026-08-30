.syntax unified
	.align 2, 0
	.global func_08115F34
	.thumb
	.thumb_func
	.type func_08115F34, %function
func_08115F34: @ 08115F34
	push {r4, r5, r6, lr}
	adds r5, r1, #0x0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r6, #0x00
	movs r0, #0xFE
	lsls r0, r0, #0x07
	ands r0, r4
	lsrs r0, r0, #0x06
	adds r0, r0, r5
	ldrb r1, [r0, #0x01]
	lsls r1, r1, #0x08
	ldrb r2, [r0, #0x00]
	orrs r2, r1
	ldrb r1, [r0, #0x03]
	lsls r1, r1, #0x08
	ldrb r3, [r0, #0x02]
	orrs r3, r1
	ldr r0, _08115F84 @ =0x0000FFFF
	cmp r2, r0
	beq _08115F7A
	ldr r1, _08115F88 @ =0x0000FFC0
	adds r0, r2, r1
	movs r1, #0xFF
	ands r1, r4
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, r0
	ldrb r0, [r1, #0x00]
	cmp r0, #0xFF
	beq _08115F7A
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_08115F7A:
	adds r0, r6, #0x0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08115F84: .4byte 0x0000FFFF
_08115F88: .4byte 0x0000FFC0
.syntax divided
