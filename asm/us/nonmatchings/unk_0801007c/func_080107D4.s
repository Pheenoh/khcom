.syntax unified
	.align 2, 0
	.global func_080107D4
	.thumb
	.thumb_func
	.type func_080107D4, %function
func_080107D4: @ 080107D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08010804 @ =0x02039B9C
	ldr r5, [r0, #0x00]
	ldr r0, _08010808 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x05
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0801080C
	bl func_08008884
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl func_080088B4
	b _08010818
	.byte 0x00, 0x00
_08010804: .4byte 0x02039B9C
_08010808: .4byte 0x02039B84
_0801080C:
	bl func_0800886C
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl func_0800889C
_08010818:
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _08010868 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x0D
	movs r0, #0x00
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	beq _08010848
	movs r0, #0x01
	ands r0, r4
	cmp r0, #0x00
	beq _08010848
	movs r0, #0xC0
	lsls r0, r0, #0x02
	ands r0, r4
	cmp r0, #0x00
	bne _08010848
	bl func_0807E2F4
_08010848:
	ldr r0, _08010868 @ =0x02039B9C
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x11
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08010870
	ldr r1, _0801086C @ =0x020348E2
	movs r0, #0x05
	strh r0, [r1, #0x00]
	b _08010A14
	.byte 0x00, 0x00
_08010868: .4byte 0x02039B9C
_0801086C: .4byte 0x020348E2
_08010870:
	movs r0, #0xE6
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldrh r2, [r1, #0x00]
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r0, #0x00
	ble _08010892
	subs r0, r2, #0x1
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _0801088C
	b _08010A14
_0801088C:
	bl func_0807E260
	b _08010A14
_08010892:
	ldr r1, _080108C8 @ =0x020348E2
	ldrh r2, [r1, #0x00]
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r0, #0x00
	ble _080108A2
	subs r0, r2, #0x1
	strh r0, [r1, #0x00]
_080108A2:
	adds r0, r4, #0x0
	adds r1, r7, #0x0
	movs r2, #0x01
	bl func_08010600
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r8, r0
	beq _080108CC
	movs r0, #0x80
	lsls r0, r0, #0x02
	cmp r8, r0
	bne _080108D0
	bl func_0807E1F4
	b _080108D0
_080108C8: .4byte 0x020348E2
_080108CC:
	bl func_0807E200
_080108D0:
	movs r0, #0x04
	ands r0, r7
	cmp r0, #0x00
	beq _080108DC
	bl func_0807E260
_080108DC:
	bl func_0807E29C
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x00
	beq _080108FC
	adds r0, r5, #0x0
	adds r0, #0xE2
	movs r1, #0x00
	strb r1, [r0, #0x00]
	adds r2, r5, #0x0
	adds r2, #0xE3
	strb r1, [r2, #0x00]
	adds r3, r0, #0x0
	adds r4, r2, #0x0
	b _08010954
_080108FC:
	movs r1, #0xC0
	lsls r1, r1, #0x02
	adds r0, r1, #0x0
	adds r1, r4, #0x0
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #0x02
	cmp r1, r0
	bne _08010920
	adds r0, r5, #0x0
	adds r0, #0xE2
	ldrb r1, [r0, #0x00]
	adds r3, r0, #0x0
	cmp r1, #0xFE
	bhi _08010928
	adds r0, r1, #0x1
	strb r0, [r3, #0x00]
	b _08010928
_08010920:
	adds r0, r5, #0x0
	adds r0, #0xE2
	strb r2, [r0, #0x00]
	adds r3, r0, #0x0
_08010928:
	movs r1, #0xC0
	lsls r1, r1, #0x02
	adds r0, r1, #0x0
	ands r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r4, r0
	bne _0801094A
	adds r0, r5, #0x0
	adds r0, #0xE3
	ldrb r1, [r0, #0x00]
	adds r4, r0, #0x0
	cmp r1, #0xFE
	bhi _08010954
	adds r0, r1, #0x1
	strb r0, [r4, #0x00]
	b _08010954
_0801094A:
	adds r1, r5, #0x0
	adds r1, #0xE3
	movs r0, #0x00
	strb r0, [r1, #0x00]
	adds r4, r1, #0x0
_08010954:
	ldrb r0, [r3, #0x00]
	cmp r0, #0x20
	bls _0801095E
	bl func_0807E1F4
_0801095E:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x20
	bls _08010968
	bl func_0807E200
_08010968:
	ldr r0, [r5, #0x7C]
	ldr r5, [r0, #0x34]
	ldr r6, [r0, #0x38]
	movs r2, #0x80
	lsls r2, r2, #0x02
	adds r0, r5, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _08010A14
	ldr r0, _080109DC @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r3, [r0, #0x68]
	ldr r4, [r0, #0x6C]
	movs r2, #0x40
	adds r0, r3, #0x0
	ands r0, r2
	orrs r0, r1
	cmp r0, #0x00
	bne _08010A14
	movs r0, #0x80
	lsls r0, r0, #0x15
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _08010A14
	movs r0, #0x80
	lsls r0, r0, #0x10
	adds r1, r3, #0x0
	ands r1, r0
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _08010A14
	movs r0, #0x02
	adds r1, r5, #0x0
	ands r1, r0
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _08010A14
	movs r0, #0xC0
	lsls r0, r0, #0x02
	cmp r8, r0
	bne _080109E4
	bl func_0807B3F8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _080109E0
	bl func_0807E224
	b _080109E4
_080109DC: .4byte 0x02039B84
_080109E0:
	bl func_0807E218
_080109E4:
	movs r0, #0x01
	ands r7, r0
	cmp r7, #0x00
	beq _08010A14
	bl func_0807E20C
	bl func_08081838
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x03
	bne _08010A14
	bl func_0807E34C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08010A14
	ldr r0, _08010A20 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	movs r3, #0xE6
	lsls r3, r3, #0x01
	adds r0, r0, r3
	movs r1, #0x0F
	strh r1, [r0, #0x00]
_08010A14:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08010A20: .4byte 0x02039B9C
.syntax divided
