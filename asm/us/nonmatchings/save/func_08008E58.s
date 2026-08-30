.syntax unified
	.align 2, 0
	.global func_08008E58
	.thumb
	.thumb_func
	.type func_08008E58, %function
func_08008E58: @ 08008E58
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	movs r6, #0x01
	negs r6, r6
	adds r7, r6, #0x0
	movs r1, #0x00
_08008E64:
	lsls r4, r1, #0x10
	asrs r5, r4, #0x10
	adds r0, r5, #0x0
	bl func_08008E18
	lsls r1, r5, #0x02
	add r1, sp
	str r0, [r1, #0x00]
	adds r2, r0, #0x0
	cmp r2, #0x02
	bne _08008E82
	cmp r6, #0x00
	bge _08008E84
	adds r6, r5, #0x0
	b _08008E84
_08008E82:
	adds r7, r5, #0x0
_08008E84:
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r4, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x01
	ble _08008E64
	cmp r6, #0x00
	blt _08008EEC
	cmp r7, #0x00
	blt _08008EEC
	ldr r4, _08008EF8 @ =0x00000F14
	adds r0, r4, #0x0
	bl func_08000918
	adds r5, r0, #0x0
	adds r0, r6, #0x0
	muls r0, r4
	ldr r1, _08008EFC @ =0x0E000090
	adds r0, r0, r1
	adds r1, r5, #0x0
	adds r2, r5, #0x0
	adds r3, r4, #0x0
	bl func_08008AD8
	movs r1, #0x00
	adds r6, r4, #0x0
_08008EBA:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #0x02
	add r0, sp
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	beq _08008ED8
	adds r1, r4, #0x0
	muls r1, r6
	ldr r0, _08008EFC @ =0x0E000090
	adds r1, r1, r0
	adds r0, r5, #0x0
	adds r2, r6, #0x0
	bl WriteAndVerifySramFast
_08008ED8:
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x01
	ble _08008EBA
	adds r0, r5, #0x0
	bl func_080009C4
	movs r2, #0x02
_08008EEC:
	adds r0, r2, #0x0
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08008EF8: .4byte 0x00000F14
_08008EFC: .4byte 0x0E000090
.syntax divided
