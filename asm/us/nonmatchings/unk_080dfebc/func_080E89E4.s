.syntax unified
	.align 2, 0
	.global func_080E89E4
	.thumb
	.thumb_func
	.type func_080E89E4, %function
func_080E89E4: @ 080E89E4
	push {r4, r5, r6, lr}
	adds r4, r2, #0x0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	b _080E8A14
_080E89F2:
	ldrb r0, [r4, #0x00]
	adds r0, r0, r6
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrb r1, [r4, #0x01]
	adds r1, r1, r5
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080E548C
	ldrb r0, [r0, #0x05]
	ldrb r1, [r4, #0x02]
	cmp r0, r1
	beq _080E8A12
	movs r0, #0x00
	b _080E8A1C
_080E8A12:
	adds r4, #0x04
_080E8A14:
	ldrb r0, [r4, #0x00]
	cmp r0, #0xFF
	bne _080E89F2
	movs r0, #0x01
_080E8A1C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
