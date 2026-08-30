.syntax unified
	.align 2, 0
	.global func_080AA77C
	.thumb
	.thumb_func
	.type func_080AA77C, %function
func_080AA77C: @ 080AA77C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	str r5, [sp, #0x000]
	movs r4, #0xDA
	lsls r4, r4, #0x03
	add r4, r8
	movs r1, #0x00
	ldsh r0, [r4, r1]
	lsls r1, r0, #0x02
	adds r1, r1, r0
	ldr r2, _080AA7E8 @ =0x000006D2
	mov r12, r2
	mov r6, r8
	add r6, r12
	ldrb r3, [r6, #0x00]
	adds r1, r3, r1
	lsls r1, r1, #0x18
	ldr r2, _080AA7EC @ =0x000004CC
	add r2, r8
	ldr r0, _080AA7F0 @ =0x000006CC
	add r0, r8
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x05
	ldr r2, [r2, #0x00]
	adds r7, r2, r0
	ldrh r2, [r4, #0x00]
	ldrb r0, [r4, #0x00]
	mov r10, r0
	mov r9, r3
	lsrs r1, r1, #0x17
	adds r1, r7, r1
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080AA7D0
	b _080AAA24
_080AA7D0:
	cmp r5, #0x20
	beq _080AA884
	cmp r5, #0x20
	bgt _080AA7F4
	cmp r5, #0x00
	bne _080AA7DE
	b _080AA9B4
_080AA7DE:
	cmp r5, #0x10
	bne _080AA7E4
	b _080AA914
_080AA7E4:
	b _080AAA24
	.byte 0x00, 0x00
_080AA7E8: .4byte 0x000006D2
_080AA7EC: .4byte 0x000004CC
_080AA7F0: .4byte 0x000006CC
_080AA7F4:
	ldr r1, [sp, #0x000]
	cmp r1, #0x40
	beq _080AA800
	cmp r1, #0x80
	beq _080AA842
	b _080AAA24
_080AA800:
	adds r3, r6, #0x0
	adds r5, r4, #0x0
_080AA804:
	ldrh r1, [r3, #0x00]
	movs r2, #0x00
	ldsh r0, [r3, r2]
	cmp r0, #0x00
	ble _080AA812
	subs r0, r1, #0x1
	b _080AA814
_080AA812:
	movs r0, #0x04
_080AA814:
	strh r0, [r3, #0x00]
	movs r4, #0x00
	ldsh r1, [r5, r4]
	lsls r0, r1, #0x02
	mov r2, r8
	add r2, r12
	adds r0, r0, r1
	ldrb r4, [r2, #0x00]
	adds r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r1, r10
	bne _080AA836
	movs r1, #0x00
	ldsh r0, [r2, r1]
	cmp r0, r9
	beq _080AA8C0
_080AA836:
	lsls r0, r4, #0x01
	adds r0, r7, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080AA804
	b _080AAA24
_080AA842:
	adds r3, r6, #0x0
	adds r5, r4, #0x0
_080AA846:
	ldrh r1, [r3, #0x00]
	movs r2, #0x00
	ldsh r0, [r3, r2]
	cmp r0, #0x03
	bgt _080AA854
	adds r0, r1, #0x1
	b _080AA856
_080AA854:
	movs r0, #0x00
_080AA856:
	strh r0, [r3, #0x00]
	movs r4, #0x00
	ldsh r1, [r5, r4]
	lsls r0, r1, #0x02
	mov r2, r8
	add r2, r12
	adds r0, r0, r1
	ldrb r4, [r2, #0x00]
	adds r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r1, r10
	bne _080AA878
	movs r1, #0x00
	ldsh r0, [r2, r1]
	cmp r0, r9
	beq _080AA8C0
_080AA878:
	lsls r0, r4, #0x01
	adds r0, r7, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080AA846
	b _080AAA24
_080AA884:
	movs r3, #0x00
	ldsh r0, [r6, r3]
	lsls r0, r0, #0x01
	adds r0, r7, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080AA8A0
	lsls r0, r2, #0x10
	cmp r0, #0x00
	bgt _080AA89A
	b _080AAA24
_080AA89A:
	subs r0, r2, #0x1
	strh r0, [r4, #0x00]
	b _080AAA24
_080AA8A0:
	movs r3, #0x00
	adds r1, r7, #0x0
	movs r2, #0x04
_080AA8A6:
	ldrh r0, [r1, #0x00]
	adds r3, r3, r0
	adds r1, #0x02
	subs r2, #0x01
	cmp r2, #0x00
	bge _080AA8A6
	cmp r3, #0x00
	bne _080AA8C4
	movs r1, #0xDA
	lsls r1, r1, #0x03
	add r1, r8
	movs r0, #0x01
	strh r0, [r1, #0x00]
_080AA8C0:
	movs r0, #0x00
	b _080AAA26
_080AA8C4:
	ldr r3, _080AA8D0 @ =0x000006D2
	add r3, r8
	ldrb r0, [r3, #0x00]
	movs r2, #0xFF
	subs r0, #0x01
	b _080AA8F2
_080AA8D0: .4byte 0x000006D2
_080AA8D4:
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bge _080AA8E2
	negs r0, r0
	lsls r0, r0, #0x18
	b _080AA8E8
_080AA8E2:
	adds r0, #0x01
	lsls r0, r0, #0x18
	negs r0, r0
_080AA8E8:
	lsrs r2, r0, #0x18
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	ldrb r4, [r3, #0x00]
	adds r0, r0, r4
_080AA8F2:
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r0, #0x00
	bge _080AA8FC
	movs r1, #0x00
_080AA8FC:
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x04
	ble _080AA906
	movs r1, #0x04
_080AA906:
	lsls r0, r1, #0x18
	asrs r1, r0, #0x17
	adds r1, r7, r1
	ldrh r1, [r1, #0x00]
	cmp r1, #0x00
	beq _080AA8D4
	b _080AA9A4
_080AA914:
	movs r1, #0x00
	ldsh r0, [r6, r1]
	adds r0, #0x05
	lsls r0, r0, #0x01
	adds r0, r7, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080AA932
	lsls r0, r2, #0x10
	cmp r0, #0x00
	ble _080AA92C
	b _080AAA24
_080AA92C:
	adds r0, r2, #0x1
	strh r0, [r4, #0x00]
	b _080AAA24
_080AA932:
	movs r3, #0x00
	adds r1, r7, #0x0
	adds r1, #0x0A
	movs r2, #0x04
_080AA93A:
	ldrh r0, [r1, #0x00]
	adds r3, r3, r0
	adds r1, #0x02
	subs r2, #0x01
	cmp r2, #0x00
	bge _080AA93A
	cmp r3, #0x00
	bne _080AA954
	movs r0, #0xDA
	lsls r0, r0, #0x03
	add r0, r8
	strh r3, [r0, #0x00]
	b _080AA8C0
_080AA954:
	ldr r3, _080AA960 @ =0x000006D2
	add r3, r8
	ldrb r0, [r3, #0x00]
	movs r2, #0xFF
	subs r0, #0x01
	b _080AA982
_080AA960: .4byte 0x000006D2
_080AA964:
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bge _080AA972
	negs r0, r0
	lsls r0, r0, #0x18
	b _080AA978
_080AA972:
	adds r0, #0x01
	lsls r0, r0, #0x18
	negs r0, r0
_080AA978:
	lsrs r2, r0, #0x18
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	ldrb r4, [r3, #0x00]
	adds r0, r0, r4
_080AA982:
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r0, #0x00
	bge _080AA98C
	movs r1, #0x00
_080AA98C:
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x04
	ble _080AA996
	movs r1, #0x04
_080AA996:
	lsls r0, r1, #0x18
	asrs r1, r0, #0x17
	adds r1, #0x0A
	adds r1, r7, r1
	ldrh r1, [r1, #0x00]
	cmp r1, #0x00
	beq _080AA964
_080AA9A4:
	asrs r1, r0, #0x18
	ldr r0, _080AA9B0 @ =0x000006D2
	add r0, r8
	strh r1, [r0, #0x00]
	b _080AAA24
	.byte 0x00, 0x00
_080AA9B0: .4byte 0x000006D2
_080AA9B4:
	ldr r5, _080AA9CC @ =0x000006D2
	add r5, r8
	movs r6, #0x00
_080AA9BA:
	ldrh r1, [r5, #0x00]
	movs r2, #0x00
	ldsh r0, [r5, r2]
	cmp r0, #0x03
	bgt _080AA9D0
	adds r0, r1, #0x1
	strh r0, [r5, #0x00]
	b _080AA9D2
	.byte 0x00, 0x00
_080AA9CC: .4byte 0x000006D2
_080AA9D0:
	strh r6, [r5, #0x00]
_080AA9D2:
	movs r2, #0xDA
	lsls r2, r2, #0x03
	add r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	lsls r0, r1, #0x02
	ldr r3, _080AAA08 @ =0x000006D2
	add r3, r8
	adds r0, r0, r1
	ldrb r4, [r3, #0x00]
	adds r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r1, r10
	bne _080AAA1A
	movs r1, #0x00
	ldsh r0, [r3, r1]
	cmp r0, r9
	bne _080AAA1A
	ldrh r1, [r2, #0x00]
	movs r3, #0x00
	ldsh r0, [r2, r3]
	cmp r0, #0x00
	bgt _080AAA0C
	adds r0, r1, #0x1
	strh r0, [r2, #0x00]
	b _080AAA0E
_080AAA08: .4byte 0x000006D2
_080AAA0C:
	strh r6, [r2, #0x00]
_080AAA0E:
	adds r0, r7, #0x0
	bl func_080AA764
	cmp r0, #0x00
	bne _080AAA1A
	b _080AA8C0
_080AAA1A:
	lsls r0, r4, #0x01
	adds r0, r7, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080AA9BA
_080AAA24:
	movs r0, #0x01
_080AAA26:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x30, 0xB5, 0x04, 0x1C, 0x03, 0x49, 0x60, 0x18, 0x00, 0x68, 0x00, 0x28, 0x1C, 0xD0
	.byte 0x00, 0x25, 0x0D, 0xE0, 0x00, 0x00, 0xCC, 0x04, 0x00, 0x00, 0x0D, 0x49, 0x60, 0x18, 0x01, 0x68
	.byte 0x68, 0x01, 0x40, 0x18, 0xC0, 0x69, 0x55, 0xF7, 0xB2, 0xFF, 0x68, 0x1C, 0x00, 0x04, 0x05, 0x0C
	.byte 0xDC, 0x21, 0xC9, 0x00, 0x60, 0x18, 0x00, 0x88, 0x85, 0x42, 0xEE, 0xD3, 0x05, 0x48, 0x24, 0x18
	.byte 0x20, 0x68, 0x55, 0xF7, 0xA4, 0xFF, 0x00, 0x20, 0x20, 0x60, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0x00, 0x00, 0xCC, 0x04, 0x00, 0x00
.syntax divided
