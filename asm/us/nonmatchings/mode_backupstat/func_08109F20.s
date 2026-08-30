.syntax unified
	.align 2, 0
	.global func_08109F20
	.thumb
	.thumb_func
	.type func_08109F20, %function
func_08109F20: @ 08109F20
	push {r4, r5, r6, lr}
	adds r3, r0, #0x0
	movs r1, #0x34
	ldsh r0, [r3, r1]
	mvns r0, r0
	lsrs r4, r0, #0x1F
	cmp r4, #0x00
	beq _08109F88
	movs r5, #0x00
_08109F32:
	movs r6, #0x30
	ldsh r0, [r3, r6]
	lsls r1, r0, #0x03
	adds r1, r1, r0
	lsls r1, r1, #0x02
	ldr r0, [r3, #0x2C]
	adds r1, r0, r1
	ldrh r2, [r1, #0x00]
	cmp r2, #0x01
	beq _08109F78
	cmp r2, #0x01
	bgt _08109F50
	cmp r2, #0x00
	beq _08109F56
	b _08109F84
_08109F50:
	cmp r2, #0x02
	beq _08109F7E
	b _08109F84
_08109F56:
	ldrh r0, [r3, #0x34]
	adds r0, #0x01
	strh r0, [r3, #0x34]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r6, #0x22
	ldsh r1, [r1, r6]
	cmp r0, r1
	ble _08109F72
	ldrh r0, [r3, #0x30]
	adds r0, #0x01
	strh r0, [r3, #0x30]
	strh r2, [r3, #0x34]
	b _08109F84
_08109F72:
	ldrh r0, [r3, #0x30]
	strh r0, [r3, #0x32]
	b _08109F88
_08109F78:
	strh r5, [r3, #0x30]
	strh r5, [r3, #0x34]
	b _08109F84
_08109F7E:
	ldr r0, _08109FC0 @ =0x0000FFFF
	strh r0, [r3, #0x34]
	movs r4, #0x00
_08109F84:
	cmp r4, #0x00
	bne _08109F32
_08109F88:
	movs r0, #0x32
	ldsh r1, [r3, r0]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	ldr r1, [r3, #0x2C]
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08109FEA
	ldrh r2, [r3, #0x34]
	movs r4, #0x34
	ldsh r0, [r3, r4]
	cmp r0, #0x00
	bne _08109FEA
	movs r6, #0xBA
	lsls r6, r6, #0x02
	adds r0, r3, r6
	movs r4, #0x00
	ldsh r0, [r0, r4]
	cmp r0, #0x1F
	bgt _08109FC4
	movs r6, #0x22
	ldsh r0, [r1, r6]
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r0, r0, #0x01
	b _08109FE6
_08109FC0: .4byte 0x0000FFFF
_08109FC4:
	cmp r0, #0x3F
	bgt _08109FD6
	movs r4, #0x22
	ldsh r0, [r1, r4]
	cmp r0, #0x00
	bge _08109FD2
	adds r0, #0x03
_08109FD2:
	asrs r0, r0, #0x02
	b _08109FE6
_08109FD6:
	cmp r0, #0x7F
	bgt _08109FEA
	movs r6, #0x22
	ldsh r0, [r1, r6]
	cmp r0, #0x00
	bge _08109FE4
	adds r0, #0x07
_08109FE4:
	asrs r0, r0, #0x03
_08109FE6:
	adds r0, r2, r0
	strh r0, [r3, #0x34]
_08109FEA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
