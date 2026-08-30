.syntax unified
	.align 2, 0
	.global func_08042018
	.thumb
	.thumb_func
	.type func_08042018, %function
func_08042018: @ 08042018
	push {r4, r5, r6, r7, lr}
	add sp, #-0x028
	adds r7, r0, #0x0
	ldr r0, _08042048 @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08042060
	ldr r1, _0804204C @ =0x00000163
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08042054
	ldr r0, _08042050 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x7C]
	b _08042056
	.byte 0x00, 0x00
_08042048: .4byte 0x02039B84
_0804204C: .4byte 0x00000163
_08042050: .4byte 0x02039B9C
_08042054:
	ldr r2, [r3, #0x7C]
_08042056:
	movs r1, #0x2C
	ldsh r0, [r2, r1]
	cmp r0, #0x00
	ble _080420D4
	b _080420C8
_08042060:
	movs r4, #0x00
	adds r0, r3, #0x0
	adds r0, #0x80
	bl func_08000C8C
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _080420A6
	ldr r6, _080420D0 @ =0x00000000
	ldr r5, _080420CC @ =0x01000000
_08042074:
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	ands r0, r5
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _08042098
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
	bgt _080420A6
_08042098:
	adds r0, r2, #0x0
	adds r0, #0xB8
	bl func_08000CD4
	adds r2, r0, #0x0
	cmp r2, #0x00
	bne _08042074
_080420A6:
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0x00
	beq _080420D4
	movs r2, #0xB6
	lsls r2, r2, #0x01
	adds r4, r7, r2
	movs r2, #0x00
	ldsh r0, [r4, r2]
	bl __modsi3
	lsls r0, r0, #0x02
	add r0, sp
	ldr r2, [r0, #0x00]
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
_080420C8:
	adds r0, r2, #0x0
	b _080420D6
_080420CC: .4byte 0x01000000
_080420D0: .4byte 0x00000000
_080420D4:
	movs r0, #0x00
_080420D6:
	add sp, #0x028
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
