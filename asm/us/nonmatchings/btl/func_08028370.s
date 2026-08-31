.syntax unified
	.align 2, 0
	.global func_08028370
	.thumb
	.thumb_func
	.type func_08028370, %function
func_08028370: @ 08028370
	push {r4, lr}
	add sp, #-0x028
	adds r4, r0, #0x0
	movs r1, #0x94
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x78]
	cmp r0, #0x00
	bne _0802841E
	ldr r0, _080283B0 @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080283C4
	movs r1, #0xBC
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080283B8
	ldr r0, _080283B4 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x7C]
	b _080283BA
	.byte 0x00, 0x00
_080283B0: .4byte 0x02039B84
_080283B4: .4byte 0x02039B9C
_080283B8:
	ldr r2, [r3, #0x7C]
_080283BA:
	movs r1, #0x2C
	ldsh r0, [r2, r1]
	cmp r0, #0x00
	ble _0802841C
	b _08028418
_080283C4:
	movs r4, #0x00
	adds r0, r3, #0x0
	adds r0, #0x80
	bl func_08000C8C
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _080283FC
	str r2, [sp, #0x000]
	movs r4, #0x01
_080283D8:
	adds r0, r2, #0x0
	adds r0, #0xB8
	bl func_08000CD4
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _080283FC
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #0x02
	add r1, sp
	str r2, [r1, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x09
	ble _080283D8
_080283FC:
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0x00
	beq _0802841C
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl __modsi3
	lsls r0, r0, #0x02
	add r0, sp
	ldr r2, [r0, #0x00]
_08028418:
	adds r0, r2, #0x0
	b _0802841E
_0802841C:
	movs r0, #0x00
_0802841E:
	add sp, #0x028
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
