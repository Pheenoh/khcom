.syntax unified
	.align 2, 0
	.global func_080E8594
	.thumb
	.thumb_func
	.type func_080E8594, %function
func_080E8594: @ 080E8594
	push {r4, r5, lr}
	movs r4, #0x00
_080E8598:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl func_080E54A0
	adds r2, r0, #0x0
	ldrb r0, [r2, #0x08]
	cmp r0, #0x00
	bne _080E85BE
	ldr r1, [r2, #0x14]
	movs r0, #0x80
	lsls r0, r0, #0x0D
	cmp r1, r0
	beq _080E85BE
	ldr r0, _080E8610 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0x78
	ldr r1, _080E8614 @ =0x09EF6C54
	bl func_08000E14
_080E85BE:
	adds r4, #0x01
	cmp r4, #0x0B
	ble _080E8598
	movs r4, #0x00
	ldr r0, _080E8618 @ =0x02034F78
	ldrb r0, [r0, #0x00]
	cmp r4, r0
	bge _080E85FA
	movs r5, #0x00
_080E85D0:
	ldr r0, _080E861C @ =0x0203C7B8
	ldr r0, [r0, #0x00]
	adds r2, r5, r0
	ldr r3, [r2, #0x14]
	ldrh r1, [r2, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _080E85EE
	ldr r0, _080E8610 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0x78
	ldr r1, [r3, #0x24]
	bl func_08000E14
_080E85EE:
	adds r5, #0x18
	adds r4, #0x01
	ldr r0, _080E8618 @ =0x02034F78
	ldrb r0, [r0, #0x00]
	cmp r4, r0
	blt _080E85D0
_080E85FA:
	ldr r0, _080E8610 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0x78
	ldr r1, _080E8620 @ =0x09EF6C84
	movs r2, #0x00
	bl func_08000E14
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E8610: .4byte 0x02039BA0
_080E8614: .4byte 0x09EF6C54
_080E8618: .4byte 0x02034F78
_080E861C: .4byte 0x0203C7B8
_080E8620: .4byte 0x09EF6C84
.syntax divided
