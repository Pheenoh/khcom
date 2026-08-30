.syntax unified
	.align 2, 0
	.global func_080E8D1C
	.thumb
	.thumb_func
	.type func_080E8D1C, %function
func_080E8D1C: @ 080E8D1C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080E8D58 @ =0x02034F7C
	ldr r2, [r1, #0x00]
	ldr r1, _080E8D5C @ =0x02034F84
	ldr r3, [r1, #0x00]
	ldrb r1, [r3, #0x00]
	lsls r1, r1, #0x02
	ldr r2, [r2, #0x04]
	adds r2, r2, r1
	lsls r1, r0, #0x02
	adds r2, r2, r1
	ldr r4, _080E8D60 @ =0x02034F80
	ldr r1, [r2, #0x00]
	str r1, [r4, #0x00]
	cmp r0, #0x00
	bne _080E8D4E
	ldrb r0, [r2, #0x02]
	cmp r0, #0x04
	bne _080E8D4E
	ldrb r1, [r3, #0x01]
	cmp r1, #0x00
	beq _080E8D4E
	strb r1, [r4, #0x03]
_080E8D4E:
	ldr r0, _080E8D60 @ =0x02034F80
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080E8D58: .4byte 0x02034F7C
_080E8D5C: .4byte 0x02034F84
_080E8D60: .4byte 0x02034F80
.syntax divided
