.syntax unified
	.align 2, 0
	.global func_0808DED0
	.thumb
	.thumb_func
	.type func_0808DED0, %function
func_0808DED0: @ 0808DED0
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
	ldr r4, _0808DF3C @ =0x00000884
	add r4, r8
	movs r1, #0x00
	ldsh r0, [r4, r1]
	lsls r1, r0, #0x02
	adds r1, r1, r0
	ldr r2, _0808DF40 @ =0x00000886
	mov r12, r2
	mov r6, r8
	add r6, r12
	ldrb r3, [r6, #0x00]
	adds r1, r3, r1
	lsls r1, r1, #0x18
	ldr r2, _0808DF44 @ =0x000004D4
	add r2, r8
	movs r0, #0x88
	lsls r0, r0, #0x04
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
	beq _0808DF24
	b _0808E184
_0808DF24:
	cmp r5, #0x20
	beq _0808DFD8
	cmp r5, #0x20
	bgt _0808DF48
	cmp r5, #0x00
	bne _0808DF32
	b _0808E110
_0808DF32:
	cmp r5, #0x10
	bne _0808DF38
	b _0808E06C
_0808DF38:
	b _0808E184
	.byte 0x00, 0x00
_0808DF3C: .4byte 0x00000884
_0808DF40: .4byte 0x00000886
_0808DF44: .4byte 0x000004D4
_0808DF48:
	ldr r1, [sp, #0x000]
	cmp r1, #0x40
	beq _0808DF54
	cmp r1, #0x80
	beq _0808DF96
	b _0808E184
_0808DF54:
	adds r3, r6, #0x0
	adds r5, r4, #0x0
_0808DF58:
	ldrh r1, [r3, #0x00]
	movs r2, #0x00
	ldsh r0, [r3, r2]
	cmp r0, #0x00
	ble _0808DF66
	subs r0, r1, #0x1
	b _0808DF68
_0808DF66:
	movs r0, #0x04
_0808DF68:
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
	bne _0808DF8A
	movs r1, #0x00
	ldsh r0, [r2, r1]
	cmp r0, r9
	beq _0808E012
_0808DF8A:
	lsls r0, r4, #0x01
	adds r0, r7, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0808DF58
	b _0808E184
_0808DF96:
	adds r3, r6, #0x0
	adds r5, r4, #0x0
_0808DF9A:
	ldrh r1, [r3, #0x00]
	movs r2, #0x00
	ldsh r0, [r3, r2]
	cmp r0, #0x03
	bgt _0808DFA8
	adds r0, r1, #0x1
	b _0808DFAA
_0808DFA8:
	movs r0, #0x00
_0808DFAA:
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
	bne _0808DFCC
	movs r1, #0x00
	ldsh r0, [r2, r1]
	cmp r0, r9
	beq _0808E012
_0808DFCC:
	lsls r0, r4, #0x01
	adds r0, r7, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0808DF9A
	b _0808E184
_0808DFD8:
	movs r3, #0x00
	ldsh r0, [r6, r3]
	lsls r0, r0, #0x01
	adds r0, r7, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0808DFF4
	lsls r0, r2, #0x10
	cmp r0, #0x00
	bgt _0808DFEE
	b _0808E184
_0808DFEE:
	subs r0, r2, #0x1
	strh r0, [r4, #0x00]
	b _0808E184
_0808DFF4:
	movs r3, #0x00
	adds r1, r7, #0x0
	movs r2, #0x04
_0808DFFA:
	ldrh r0, [r1, #0x00]
	adds r3, r3, r0
	adds r1, #0x02
	subs r2, #0x01
	cmp r2, #0x00
	bge _0808DFFA
	cmp r3, #0x00
	bne _0808E01C
	ldr r1, _0808E018 @ =0x00000884
	add r1, r8
	movs r0, #0x01
	strh r0, [r1, #0x00]
_0808E012:
	movs r0, #0x00
	b _0808E186
	.byte 0x00, 0x00
_0808E018: .4byte 0x00000884
_0808E01C:
	ldr r3, _0808E028 @ =0x00000886
	add r3, r8
	ldrb r0, [r3, #0x00]
	movs r2, #0xFF
	subs r0, #0x01
	b _0808E04A
_0808E028: .4byte 0x00000886
_0808E02C:
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bge _0808E03A
	negs r0, r0
	lsls r0, r0, #0x18
	b _0808E040
_0808E03A:
	adds r0, #0x01
	lsls r0, r0, #0x18
	negs r0, r0
_0808E040:
	lsrs r2, r0, #0x18
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	ldrb r4, [r3, #0x00]
	adds r0, r0, r4
_0808E04A:
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r0, #0x00
	bge _0808E054
	movs r1, #0x00
_0808E054:
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x04
	ble _0808E05E
	movs r1, #0x04
_0808E05E:
	lsls r0, r1, #0x18
	asrs r1, r0, #0x17
	adds r1, r7, r1
	ldrh r1, [r1, #0x00]
	cmp r1, #0x00
	beq _0808E02C
	b _0808E100
_0808E06C:
	movs r1, #0x00
	ldsh r0, [r6, r1]
	adds r0, #0x05
	lsls r0, r0, #0x01
	adds r0, r7, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0808E08A
	lsls r0, r2, #0x10
	cmp r0, #0x00
	ble _0808E084
	b _0808E184
_0808E084:
	adds r0, r2, #0x1
	strh r0, [r4, #0x00]
	b _0808E184
_0808E08A:
	movs r3, #0x00
	adds r1, r7, #0x0
	adds r1, #0x0A
	movs r2, #0x04
_0808E092:
	ldrh r0, [r1, #0x00]
	adds r3, r3, r0
	adds r1, #0x02
	subs r2, #0x01
	cmp r2, #0x00
	bge _0808E092
	cmp r3, #0x00
	bne _0808E0B0
	ldr r0, _0808E0AC @ =0x00000884
	add r0, r8
	strh r3, [r0, #0x00]
	b _0808E012
	.byte 0x00, 0x00
_0808E0AC: .4byte 0x00000884
_0808E0B0:
	ldr r3, _0808E0BC @ =0x00000886
	add r3, r8
	ldrb r0, [r3, #0x00]
	movs r2, #0xFF
	subs r0, #0x01
	b _0808E0DE
_0808E0BC: .4byte 0x00000886
_0808E0C0:
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bge _0808E0CE
	negs r0, r0
	lsls r0, r0, #0x18
	b _0808E0D4
_0808E0CE:
	adds r0, #0x01
	lsls r0, r0, #0x18
	negs r0, r0
_0808E0D4:
	lsrs r2, r0, #0x18
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	ldrb r4, [r3, #0x00]
	adds r0, r0, r4
_0808E0DE:
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r0, #0x00
	bge _0808E0E8
	movs r1, #0x00
_0808E0E8:
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x04
	ble _0808E0F2
	movs r1, #0x04
_0808E0F2:
	lsls r0, r1, #0x18
	asrs r1, r0, #0x17
	adds r1, #0x0A
	adds r1, r7, r1
	ldrh r1, [r1, #0x00]
	cmp r1, #0x00
	beq _0808E0C0
_0808E100:
	asrs r1, r0, #0x18
	ldr r0, _0808E10C @ =0x00000886
	add r0, r8
	strh r1, [r0, #0x00]
	b _0808E184
	.byte 0x00, 0x00
_0808E10C: .4byte 0x00000886
_0808E110:
	ldr r4, _0808E128 @ =0x00000886
	add r4, r8
	movs r5, #0x00
_0808E116:
	ldrh r1, [r4, #0x00]
	movs r2, #0x00
	ldsh r0, [r4, r2]
	cmp r0, #0x03
	bgt _0808E12C
	adds r0, r1, #0x1
	strh r0, [r4, #0x00]
	b _0808E12E
	.byte 0x00, 0x00
_0808E128: .4byte 0x00000886
_0808E12C:
	strh r5, [r4, #0x00]
_0808E12E:
	ldr r1, _0808E154 @ =0x00000884
	add r1, r8
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r0, r10
	bne _0808E168
	movs r2, #0x00
	ldsh r0, [r4, r2]
	cmp r0, r9
	bne _0808E168
	ldrh r2, [r1, #0x00]
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r0, #0x00
	bgt _0808E158
	adds r0, r2, #0x1
	strh r0, [r1, #0x00]
	b _0808E15A
	.byte 0x00, 0x00
_0808E154: .4byte 0x00000884
_0808E158:
	strh r5, [r1, #0x00]
_0808E15A:
	strh r5, [r4, #0x00]
	adds r0, r7, #0x0
	bl func_0808DEB8
	cmp r0, #0x00
	bne _0808E168
	b _0808E012
_0808E168:
	ldr r0, _0808E198 @ =0x00000884
	add r0, r8
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	ldrb r3, [r4, #0x00]
	adds r0, r0, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r7, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0808E116
_0808E184:
	movs r0, #0x01
_0808E186:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_0808E198: .4byte 0x00000884
.syntax divided
