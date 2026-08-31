.syntax unified
	.align 2, 0
	.global func_080E0B98
	.thumb
	.thumb_func
	.type func_080E0B98, %function
func_080E0B98: @ 080E0B98
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	cmp r5, #0x00
	beq _080E0BE4
	ldr r0, _080E0BEC @ =0x02034F34
	ldr r0, [r0, #0x00]
	ldr r7, [r0, #0x1C]
	lsls r1, r6, #0x02
	ldr r0, _080E0BF0 @ =0x0984D32C
	adds r4, r1, r0
	cmp r2, #0xFF
	bne _080E0BC8
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #0x03]
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_080E0BC8:
	movs r1, #0x07
	ands r1, r2
	ldrb r0, [r4, #0x01]
	adds r1, r1, r0
	lsls r1, r1, #0x02
	lsrs r0, r2, #0x03
	ldrb r4, [r4, #0x02]
	adds r0, r0, r4
	lsls r0, r0, #0x06
	adds r1, r1, r0
	strb r6, [r5, #0x04]
	lsls r1, r1, #0x01
	adds r1, r7, r1
	str r1, [r5, #0x18]
_080E0BE4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E0BEC: .4byte 0x02034F34
_080E0BF0: .4byte 0x0984D32C
.syntax divided
