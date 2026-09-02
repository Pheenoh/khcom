.syntax unified
	.align 2, 0
	.global func_0808F0C0
	.thumb
	.thumb_func
	.type func_0808F0C0, %function
func_0808F0C0: @ 0808F0C0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r0, _0808F0F0 @ =0x000007C2
	adds r2, r5, r0
	ldrh r3, [r2, #0x00]
	movs r1, #0x00
	ldsh r0, [r2, r1]
	cmp r0, #0x01
	bne _0808F112
	movs r7, #0xF8
	lsls r7, r7, #0x03
	adds r1, r5, r7
	ldrh r0, [r1, #0x00]
	cmp r0, #0x0A
	bls _0808F112
	cmp r4, #0x20
	beq _0808F10A
	cmp r4, #0x20
	bgt _0808F0F4
	cmp r4, #0x10
	beq _0808F10E
	b _0808F112
_0808F0F0: .4byte 0x000007C2
_0808F0F4:
	cmp r4, #0x40
	beq _0808F0FE
	cmp r4, #0x80
	beq _0808F104
	b _0808F112
_0808F0FE:
	subs r0, r3, #0x1
	strh r0, [r2, #0x00]
	b _0808F112
_0808F104:
	adds r0, r3, #0x1
	strh r0, [r2, #0x00]
	b _0808F112
_0808F10A:
	movs r0, #0x0A
	b _0808F110
_0808F10E:
	movs r0, #0x00
_0808F110:
	strh r0, [r1, #0x00]
_0808F112:
	ldr r0, _0808F13C @ =0x000007C2
	adds r2, r5, r0
	ldrh r3, [r2, #0x00]
	movs r1, #0x00
	ldsh r0, [r2, r1]
	cmp r0, #0x03
	bne _0808F15E
	movs r7, #0xF8
	lsls r7, r7, #0x03
	adds r1, r5, r7
	ldrh r0, [r1, #0x00]
	cmp r0, #0x0A
	bls _0808F15E
	cmp r4, #0x20
	beq _0808F156
	cmp r4, #0x20
	bgt _0808F140
	cmp r4, #0x10
	beq _0808F15A
	b _0808F15E
	.byte 0x00, 0x00
_0808F13C: .4byte 0x000007C2
_0808F140:
	cmp r4, #0x40
	beq _0808F14A
	cmp r4, #0x80
	beq _0808F150
	b _0808F15E
_0808F14A:
	subs r0, r3, #0x1
	strh r0, [r2, #0x00]
	b _0808F15E
_0808F150:
	adds r0, r3, #0x1
	strh r0, [r2, #0x00]
	b _0808F15E
_0808F156:
	movs r0, #0x0A
	b _0808F15C
_0808F15A:
	movs r0, #0x00
_0808F15C:
	strh r0, [r1, #0x00]
_0808F15E:
	movs r0, #0xF8
	lsls r0, r0, #0x03
	adds r3, r5, r0
	movs r1, #0x00
	ldsh r0, [r3, r1]
	cmp r0, #0x0E
	ble _0808F170
	movs r0, #0x00
	strh r0, [r3, #0x00]
_0808F170:
	movs r7, #0x00
	ldsh r0, [r3, r7]
	cmp r0, #0x00
	bge _0808F17C
	movs r0, #0x0E
	strh r0, [r3, #0x00]
_0808F17C:
	ldr r0, _0808F228 @ =0x000007C2
	adds r2, r5, r0
	movs r1, #0x00
	ldsh r0, [r2, r1]
	cmp r0, #0x06
	ble _0808F18C
	movs r0, #0x00
	strh r0, [r2, #0x00]
_0808F18C:
	movs r7, #0x00
	ldsh r0, [r2, r7]
	cmp r0, #0x00
	bge _0808F198
	movs r0, #0x06
	strh r0, [r2, #0x00]
_0808F198:
	movs r1, #0x00
	ldsh r0, [r3, r1]
	ldr r6, _0808F22C @ =0x09035898
	movs r7, #0x00
	ldsh r1, [r2, r7]
	lsls r1, r1, #0x03
	adds r1, r1, r6
	movs r7, #0x04
	ldsh r1, [r1, r7]
	subs r1, #0x01
	cmp r0, r1
	ble _0808F1B4
	movs r0, #0x00
	strh r0, [r3, #0x00]
_0808F1B4:
	movs r1, #0x00
	ldsh r0, [r3, r1]
	cmp r0, #0x00
	bge _0808F1CA
	movs r7, #0x00
	ldsh r0, [r2, r7]
	lsls r0, r0, #0x03
	adds r0, r0, r6
	ldrh r0, [r0, #0x04]
	subs r0, #0x01
	strh r0, [r3, #0x00]
_0808F1CA:
	movs r1, #0x00
	ldsh r0, [r2, r1]
	ldr r6, _0808F230 @ =0x090358D0
	movs r7, #0x00
	ldsh r1, [r3, r7]
	lsls r1, r1, #0x03
	adds r1, r1, r6
	movs r7, #0x04
	ldsh r1, [r1, r7]
	subs r1, #0x01
	cmp r0, r1
	ble _0808F1E6
	movs r0, #0x00
	strh r0, [r2, #0x00]
_0808F1E6:
	movs r1, #0x00
	ldsh r0, [r2, r1]
	cmp r0, #0x00
	bge _0808F1FC
	movs r7, #0x00
	ldsh r0, [r3, r7]
	lsls r0, r0, #0x03
	adds r0, r0, r6
	ldrh r0, [r0, #0x04]
	subs r0, #0x01
	strh r0, [r2, #0x00]
_0808F1FC:
	movs r1, #0x00
	ldsh r0, [r2, r1]
	cmp r0, #0x06
	bne _0808F250
	movs r7, #0x00
	ldsh r0, [r3, r7]
	cmp r0, #0x09
	ble _0808F250
	cmp r0, #0x0D
	bne _0808F234
	cmp r4, #0x20
	bne _0808F234
	movs r0, #0x09
	strh r0, [r3, #0x00]
	movs r1, #0xF3
	lsls r1, r1, #0x03
	adds r0, r5, r1
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	b _0808F24C
_0808F228: .4byte 0x000007C2
_0808F22C: .4byte 0x09035898
_0808F230: .4byte 0x090358D0
_0808F234:
	movs r7, #0xF8
	lsls r7, r7, #0x03
	adds r0, r5, r7
	movs r1, #0x0E
	strh r1, [r0, #0x00]
	movs r1, #0xF3
	lsls r1, r1, #0x03
	adds r0, r5, r1
	movs r1, #0x01
	movs r2, #0x01
	bl AnimStart
_0808F24C:
	movs r0, #0x00
	b _0808F252
_0808F250:
	movs r0, #0x01
_0808F252:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
