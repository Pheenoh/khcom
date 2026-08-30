.syntax unified
	.align 2, 0
	.global func_08008BBC
	.thumb
	.thumb_func
	.type func_08008BBC, %function
func_08008BBC: @ 08008BBC
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	movs r6, #0x01
	negs r6, r6
	adds r7, r6, #0x0
	movs r4, #0x00
_08008BC8:
	lsls r4, r4, #0x10
	asrs r5, r4, #0x10
	adds r0, r5, #0x0
	bl func_08008B84
	lsls r1, r5, #0x02
	add r1, sp
	str r0, [r1, #0x00]
	adds r1, r0, #0x0
	cmp r1, #0x02
	bne _08008BE6
	cmp r6, #0x00
	bge _08008BE8
	adds r6, r5, #0x0
	b _08008BE8
_08008BE6:
	adds r7, r5, #0x0
_08008BE8:
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r4, r2
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x01
	ble _08008BC8
	cmp r6, #0x00
	blt _08008C48
	cmp r7, #0x00
	blt _08008C48
	movs r0, #0x40
	bl func_08000918
	adds r5, r0, #0x0
	lsls r0, r6, #0x06
	ldr r1, _08008C54 @ =0x0E000010
	adds r0, r0, r1
	adds r1, r5, #0x0
	adds r2, r5, #0x0
	movs r3, #0x40
	bl func_08008AD8
	movs r4, #0x00
_08008C18:
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #0x02
	add r0, sp
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	beq _08008C34
	lsls r1, r4, #0x06
	ldr r0, _08008C54 @ =0x0E000010
	adds r1, r1, r0
	adds r0, r5, #0x0
	movs r2, #0x40
	bl func_0811817C
_08008C34:
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x01
	ble _08008C18
	adds r0, r5, #0x0
	bl func_080009C4
	movs r1, #0x02
_08008C48:
	adds r0, r1, #0x0
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08008C54: .4byte 0x0E000010
.syntax divided
