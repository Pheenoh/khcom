.syntax unified
	.align 2, 0
	.global func_08083E54
	.thumb
	.thumb_func
	.type func_08083E54, %function
func_08083E54: @ 08083E54
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r3, #0x00
	ldr r0, _08083E6C @ =0x0203A850
	ldr r4, [r0, #0x00]
	cmp r1, #0x00
	beq _08083E70
	cmp r1, #0x03
	beq _08083EB4
	b _08083EE8
	.byte 0x00, 0x00
_08083E6C: .4byte 0x0203A850
_08083E70:
	movs r2, #0x00
	ldr r0, _08083EA8 @ =0x0000FFFF
	mov r12, r0
	ldr r6, _08083EAC @ =0x08F70AB0
	ldr r7, _08083EB0 @ =0x00000FFF
	movs r5, #0x34
_08083E7C:
	lsls r0, r2, #0x01
	adds r0, r0, r4
	ldrh r1, [r0, #0x00]
	cmp r1, r12
	beq _08083E9C
	adds r0, r7, #0x0
	ands r0, r1
	muls r0, r5
	adds r0, r0, r6
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bhi _08083E9C
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_08083E9C:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x62
	bls _08083E7C
	b _08083EE8
_08083EA8: .4byte 0x0000FFFF
_08083EAC: .4byte 0x08F70AB0
_08083EB0: .4byte 0x00000FFF
_08083EB4:
	movs r2, #0x00
	ldr r7, _08083EF0 @ =0x0000FFFF
	ldr r5, _08083EF4 @ =0x08F70AB0
	ldr r6, _08083EF8 @ =0x00000FFF
_08083EBC:
	lsls r0, r2, #0x01
	adds r0, r0, r4
	ldrh r1, [r0, #0x00]
	cmp r1, r7
	beq _08083EDE
	adds r0, r6, #0x0
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	adds r0, r0, r5
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _08083EDE
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_08083EDE:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x62
	bls _08083EBC
_08083EE8:
	adds r0, r3, #0x0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08083EF0: .4byte 0x0000FFFF
_08083EF4: .4byte 0x08F70AB0
_08083EF8: .4byte 0x00000FFF
.syntax divided
