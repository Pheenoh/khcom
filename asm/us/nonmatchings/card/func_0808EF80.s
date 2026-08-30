.syntax unified
	.align 2, 0
	.global func_0808EF80
	.thumb
	.thumb_func
	.type func_0808EF80, %function
func_0808EF80: @ 0808EF80
	push {r4, r5, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _0808EFB0 @ =0x000007C2
	adds r3, r4, r0
	ldrh r5, [r3, #0x00]
	movs r2, #0x00
	ldsh r0, [r3, r2]
	cmp r0, #0x03
	bne _0808EFD2
	movs r0, #0xF8
	lsls r0, r0, #0x03
	adds r2, r4, r0
	ldrh r0, [r2, #0x00]
	cmp r0, #0x09
	bls _0808EFD2
	cmp r1, #0x20
	beq _0808EFCA
	cmp r1, #0x20
	bgt _0808EFB4
	cmp r1, #0x10
	beq _0808EFCE
	b _0808EFD2
_0808EFB0: .4byte 0x000007C2
_0808EFB4:
	cmp r1, #0x40
	beq _0808EFBE
	cmp r1, #0x80
	beq _0808EFC4
	b _0808EFD2
_0808EFBE:
	subs r0, r5, #0x1
	strh r0, [r3, #0x00]
	b _0808EFD2
_0808EFC4:
	adds r0, r5, #0x1
	strh r0, [r3, #0x00]
	b _0808EFD2
_0808EFCA:
	movs r0, #0x09
	b _0808EFD0
_0808EFCE:
	movs r0, #0x00
_0808EFD0:
	strh r0, [r2, #0x00]
_0808EFD2:
	ldr r2, _0808F00C @ =0x000007C7
	adds r0, r4, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0808F032
	ldr r5, _0808F010 @ =0x000007C2
	adds r3, r4, r5
	ldrh r5, [r3, #0x00]
	movs r2, #0x00
	ldsh r0, [r3, r2]
	cmp r0, #0x05
	bne _0808F032
	movs r0, #0xF8
	lsls r0, r0, #0x03
	adds r2, r4, r0
	ldrh r0, [r2, #0x00]
	subs r0, #0x05
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bhi _0808F032
	cmp r1, #0x20
	beq _0808F02A
	cmp r1, #0x20
	bgt _0808F014
	cmp r1, #0x10
	beq _0808F02E
	b _0808F032
	.byte 0x00, 0x00
_0808F00C: .4byte 0x000007C7
_0808F010: .4byte 0x000007C2
_0808F014:
	cmp r1, #0x40
	beq _0808F01E
	cmp r1, #0x80
	beq _0808F024
	b _0808F032
_0808F01E:
	subs r0, r5, #0x1
	strh r0, [r3, #0x00]
	b _0808F032
_0808F024:
	adds r0, r5, #0x1
	strh r0, [r3, #0x00]
	b _0808F032
_0808F02A:
	movs r0, #0x04
	b _0808F030
_0808F02E:
	movs r0, #0x0A
_0808F030:
	strh r0, [r2, #0x00]
_0808F032:
	ldr r2, _0808F098 @ =0x000007C2
	adds r3, r4, r2
	movs r5, #0x00
	ldsh r0, [r3, r5]
	cmp r0, #0x06
	ble _0808F042
	movs r0, #0x00
	strh r0, [r3, #0x00]
_0808F042:
	movs r2, #0x00
	ldsh r0, [r3, r2]
	cmp r0, #0x00
	bge _0808F04E
	movs r0, #0x06
	strh r0, [r3, #0x00]
_0808F04E:
	movs r5, #0xF8
	lsls r5, r5, #0x03
	adds r2, r4, r5
	movs r5, #0x00
	ldsh r0, [r2, r5]
	cmp r0, #0x0E
	ble _0808F060
	movs r0, #0x00
	strh r0, [r2, #0x00]
_0808F060:
	movs r5, #0x00
	ldsh r0, [r2, r5]
	cmp r0, #0x00
	bge _0808F06C
	movs r0, #0x0E
	strh r0, [r2, #0x00]
_0808F06C:
	movs r5, #0x00
	ldsh r0, [r3, r5]
	cmp r0, #0x06
	bne _0808F0B8
	movs r3, #0x00
	ldsh r0, [r2, r3]
	cmp r0, #0x0B
	ble _0808F0B8
	cmp r0, #0x0D
	bne _0808F09C
	cmp r1, #0x20
	bne _0808F09C
	movs r0, #0x0B
	strh r0, [r2, #0x00]
	movs r5, #0xF3
	lsls r5, r5, #0x03
	adds r0, r4, r5
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	b _0808F0B4
_0808F098: .4byte 0x000007C2
_0808F09C:
	movs r1, #0xF8
	lsls r1, r1, #0x03
	adds r0, r4, r1
	movs r1, #0x0E
	strh r1, [r0, #0x00]
	movs r2, #0xF3
	lsls r2, r2, #0x03
	adds r0, r4, r2
	movs r1, #0x01
	movs r2, #0x01
	bl func_080059A4
_0808F0B4:
	movs r0, #0x00
	b _0808F0BA
_0808F0B8:
	movs r0, #0x01
_0808F0BA:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
