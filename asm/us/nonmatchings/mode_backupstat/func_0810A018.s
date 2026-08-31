.syntax unified
	.align 2, 0
	.global func_0810A018
	.thumb
	.thumb_func
	.type func_0810A018, %function
func_0810A018: @ 0810A018
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x028
	mov r8, r0
	ldr r2, [r0, #0x2C]
	cmp r2, #0x00
	bne _0810A02E
	b _0810A406
_0810A02E:
	movs r3, #0x32
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r2, r2, r0
	str r2, [sp, #0x014]
	ldrh r5, [r2, #0x00]
	cmp r5, #0x00
	beq _0810A044
	b _0810A406
_0810A044:
	movs r6, #0x00
	movs r4, #0x00
	ldr r0, _0810A08C @ =0x000002ED
	add r0, r8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _0810A060
	ldr r0, _0810A090 @ =0x02039DC8
	ldr r0, [r0, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x68
	ldrh r6, [r1, #0x00]
	adds r0, #0x6A
	ldrh r4, [r0, #0x00]
_0810A060:
	mov r0, r8
	ldr r0, [r0, #0x4C]
	str r0, [sp, #0x018]
	mov r1, r8
	ldrb r0, [r1, #0x18]
	cmp r0, #0x00
	bne _0810A09A
	mov r0, r8
	adds r0, #0x54
	bl func_0801CA00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0810A094
	mov r2, r8
	ldr r2, [r2, #0x50]
	str r2, [sp, #0x018]
	movs r0, #0x01
	mov r3, r8
	strh r0, [r3, #0x0A]
	b _0810A09E
	.byte 0x00, 0x00
_0810A08C: .4byte 0x000002ED
_0810A090: .4byte 0x02039DC8
_0810A094:
	mov r0, r8
	strh r5, [r0, #0x0A]
	b _0810A09E
_0810A09A:
	mov r1, r8
	strh r5, [r1, #0x0A]
_0810A09E:
	mov r2, r8
	movs r3, #0x0A
	ldsh r1, [r2, r3]
	movs r3, #0x0C
	ldsh r0, [r2, r3]
	cmp r1, r0
	beq _0810A0D6
	cmp r1, #0x00
	bne _0810A0C4
	ldr r0, _0810A0C0 @ =0x09D69274
	movs r1, #0xA0
	lsls r1, r1, #0x13
	movs r2, #0x20
	bl func_08005BE8
	b _0810A0D0
	.byte 0x00, 0x00
_0810A0C0: .4byte 0x09D69274
_0810A0C4:
	ldr r0, _0810A1C0 @ =0x08F69BC4
	movs r1, #0xA0
	lsls r1, r1, #0x13
	movs r2, #0x20
	bl func_08005BE8
_0810A0D0:
	mov r1, r8
	ldrh r0, [r1, #0x0A]
	strh r0, [r1, #0x0C]
_0810A0D6:
	mov r5, sp
	adds r5, #0x12
	lsls r6, r6, #0x10
	asrs r0, r6, #0x08
	mov r3, r8
	ldr r2, [r3, #0x20]
	subs r2, r2, r0
	lsls r4, r4, #0x10
	asrs r0, r4, #0x08
	ldr r3, [r3, #0x24]
	subs r3, r3, r0
	mov r1, r8
	ldr r0, [r1, #0x28]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl func_0801909C
	ldr r1, _0810A1C4 @ =0x09EF9C34
	ldr r2, [sp, #0x014]
	movs r3, #0x20
	ldsh r0, [r2, r3]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r3, [r0, #0x00]
	str r6, [sp, #0x01C]
	str r4, [sp, #0x020]
	movs r2, #0x00
	movs r4, #0x17
	mov r9, r4
	ldr r0, _0810A1C8 @ =0x00001DF0
	add r0, r8
	ldr r1, _0810A1CC @ =0xFFFFFED4
_0810A118:
	strh r2, [r0, #0x00]
	adds r0, r0, r1
	movs r4, #0x01
	negs r4, r4
	add r9, r4
	mov r4, r9
	cmp r4, #0x00
	bge _0810A118
	movs r0, #0x00
	mov r9, r0
	ldrb r1, [r3, #0x00]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0x00
	beq _0810A138
	b _0810A2B0
_0810A138:
	adds r7, r3, #0x0
_0810A13A:
	ldrb r1, [r7, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0810A1D8
	movs r1, #0x02
	ldsh r0, [r7, r1]
	lsls r0, r0, #0x0A
	ldr r2, _0810A1D0 @ =0xFFFFCD00
	adds r0, r0, r2
	mov r3, r8
	ldr r1, [r3, #0x24]
	adds r1, r1, r0
	mov r0, r8
	bl func_08109FF0
	adds r6, r0, #0x0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	movs r4, #0x02
	ldsh r0, [r7, r4]
	lsls r0, r0, #0x0A
	ldr r1, _0810A1D0 @ =0xFFFFCD00
	adds r0, r0, r1
	mov r2, r8
	ldr r1, [r2, #0x24]
	adds r1, r1, r0
	mov r0, r8
	movs r2, #0x01
	bl func_0810A000
	adds r5, r0, #0x0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	add r1, sp, #0x010
	ldrh r0, [r7, #0x04]
	ldrh r1, [r1, #0x00]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r7, #0x06]
	mov r3, sp
	ldrh r3, [r3, #0x12]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r3, _0810A1D4 @ =0x09EFAB18
	ldrb r2, [r7, #0x01]
	lsls r2, r2, #0x02
	adds r2, r2, r3
	ldr r2, [r2, #0x00]
	mov r3, r9
	lsls r4, r3, #0x02
	mov r3, r8
	adds r3, #0x44
	adds r3, r3, r4
	ldr r3, [r3, #0x00]
	ldr r4, [sp, #0x018]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r6, [sp, #0x008]
	str r5, [sp, #0x00C]
	bl func_080023E0
	b _0810A29E
	.byte 0x00, 0x00
_0810A1C0: .4byte 0x08F69BC4
_0810A1C4: .4byte 0x09EF9C34
_0810A1C8: .4byte 0x00001DF0
_0810A1CC: .4byte 0xFFFFFED4
_0810A1D0: .4byte 0xFFFFCD00
_0810A1D4: .4byte 0x09EFAB18
_0810A1D8:
	ldr r1, _0810A350 @ =0x09EFBB18
	ldrb r0, [r7, #0x01]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r6, [r0, #0x00]
	movs r1, #0x02
	ldsh r0, [r7, r1]
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r0, r1, #0x04
	subs r0, r0, r1
	lsls r0, r0, #0x02
	movs r2, #0xBF
	lsls r2, r2, #0x02
	adds r0, r0, r2
	mov r3, r8
	adds r5, r3, r0
	movs r4, #0xFF
	mov r10, r4
	ldrh r0, [r6, #0x02]
	mov r12, r0
	ldrb r2, [r6, #0x02]
	adds r1, r2, #0x0
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0x00
	beq _0810A218
	ldr r2, _0810A354 @ =0xFFFFFF00
	adds r0, r2, #0x0
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
_0810A218:
	ldrh r3, [r7, #0x06]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r4, sp
	ldrh r4, [r4, #0x12]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	movs r1, #0xE0
	lsls r1, r1, #0x0B
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	cmp r0, #0xAE
	bhi _0810A29E
	ldrh r0, [r5, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	adds r1, #0x01
	lsls r1, r1, #0x01
	adds r4, r5, #0x2
	adds r1, r4, r1
	movs r2, #0xFF
	lsls r2, r2, #0x08
	adds r0, r2, #0x0
	mov r2, r12
	ands r2, r0
	mov r0, r12
	adds r0, #0x40
	adds r0, r3, r0
	mov r3, r10
	ands r0, r3
	orrs r2, r0
	strh r2, [r1, #0x00]
	ldrh r0, [r5, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	adds r1, #0x02
	lsls r1, r1, #0x01
	adds r1, r1, r4
	mov r10, r1
	ldrh r2, [r6, #0x04]
	movs r1, #0xFE
	lsls r1, r1, #0x08
	adds r0, r1, #0x0
	adds r3, r2, #0x0
	ands r3, r0
	ldrh r0, [r7, #0x04]
	adds r2, r2, r0
	ldr r1, _0810A358 @ =0x000001FF
	adds r0, r1, #0x0
	ands r2, r0
	orrs r3, r2
	mov r2, r10
	strh r3, [r2, #0x00]
	ldrh r1, [r5, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	adds r0, #0x03
	lsls r0, r0, #0x01
	adds r4, r4, r0
	ldrh r0, [r6, #0x06]
	strh r0, [r4, #0x00]
	ldrh r0, [r5, #0x00]
	adds r0, #0x01
	strh r0, [r5, #0x00]
_0810A29E:
	adds r7, #0x0C
	movs r3, #0x01
	add r9, r3
	ldrb r1, [r7, #0x00]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0x00
	bne _0810A2B0
	b _0810A13A
_0810A2B0:
	movs r4, #0x00
	mov r10, r4
	ldr r5, _0810A35C @ =0x000002FE
	add r5, r8
	ldr r7, _0810A360 @ =0xFFFFCC00
	movs r6, #0xBF
	lsls r6, r6, #0x02
	add r6, r8
	movs r0, #0x17
	mov r9, r0
_0810A2C4:
	ldrh r0, [r6, #0x00]
	cmp r0, #0x00
	beq _0810A31C
	strh r0, [r5, #0x00]
	mov r2, r8
	ldr r1, [r2, #0x24]
	adds r1, r1, r7
	mov r0, r8
	bl func_08109FF0
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x024]
	mov r3, r8
	ldr r1, [r3, #0x24]
	adds r1, r1, r7
	mov r0, r8
	movs r2, #0x01
	bl func_0810A000
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r1, sp, #0x010
	movs r4, #0x00
	ldsh r2, [r1, r4]
	mov r3, sp
	ldrh r1, [r3, #0x12]
	subs r1, #0x40
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	mov r4, r8
	ldr r3, [r4, #0x40]
	ldr r4, [sp, #0x018]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	ldr r4, [sp, #0x024]
	str r4, [sp, #0x008]
	str r0, [sp, #0x00C]
	adds r0, r2, #0x0
	adds r2, r5, #0x0
	bl func_080023E0
_0810A31C:
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r5, r5, r0
	movs r1, #0x80
	lsls r1, r1, #0x03
	adds r7, r7, r1
	adds r6, r6, r0
	movs r2, #0x01
	negs r2, r2
	add r9, r2
	mov r3, r9
	cmp r3, #0x00
	bge _0810A2C4
	movs r4, #0x18
	mov r9, r4
	mov r0, r8
	ldr r1, [r0, #0x2C]
	ldr r0, _0810A364 @ =0x09A4C278
	cmp r1, r0
	bne _0810A36C
	ldr r0, _0810A368 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xD8
	mov r1, r9
	b _0810A374
	.byte 0x00, 0x00
_0810A350: .4byte 0x09EFBB18
_0810A354: .4byte 0xFFFFFF00
_0810A358: .4byte 0x000001FF
_0810A35C: .4byte 0x000002FE
_0810A360: .4byte 0xFFFFCC00
_0810A364: .4byte 0x09A4C278
_0810A368: .4byte 0x02039B84
_0810A36C:
	ldr r0, _0810A418 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xD8
	ldr r1, _0810A41C @ =0x0000FFF6
_0810A374:
	strh r1, [r0, #0x00]
	mov r1, sp
	adds r1, #0x12
	ldr r3, [sp, #0x01C]
	asrs r2, r3, #0x10
	movs r0, #0x70
	negs r0, r0
	subs r0, r0, r2
	lsls r0, r0, #0x08
	mov r4, r8
	ldr r2, [r4, #0x20]
	adds r2, r2, r0
	ldr r0, [sp, #0x020]
	asrs r3, r0, #0x10
	movs r0, #0x64
	negs r0, r0
	subs r0, r0, r3
	lsls r0, r0, #0x08
	ldr r3, [r4, #0x24]
	adds r3, r3, r0
	ldr r0, [r4, #0x28]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	bl func_0801909C
	movs r2, #0x32
	ldsh r1, [r4, r2]
	movs r3, #0x36
	ldsh r0, [r4, r3]
	cmp r1, r0
	beq _0810A3E8
	ldr r4, _0810A420 @ =0x09A4AC84
	ldr r1, [sp, #0x014]
	movs r2, #0x1E
	ldsh r0, [r1, r2]
	lsls r0, r0, #0x04
	adds r0, r0, r4
	ldr r1, [r0, #0x00]
	ldrh r2, [r0, #0x04]
	movs r0, #0x01
	bl func_080050B8
	ldr r3, [sp, #0x014]
	movs r0, #0x1E
	ldsh r2, [r3, r0]
	lsls r2, r2, #0x04
	adds r0, r4, #0x0
	adds r0, #0x08
	adds r0, r2, r0
	ldr r1, [r0, #0x00]
	adds r2, r2, r4
	ldrh r2, [r2, #0x0C]
	movs r0, #0x01
	bl func_0800510C
	mov r1, r8
	ldrh r0, [r1, #0x32]
	strh r0, [r1, #0x36]
_0810A3E8:
	add r0, sp, #0x010
	ldrh r1, [r0, #0x00]
	negs r1, r1
	adds r1, #0x50
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r3, sp
	ldrh r2, [r3, #0x12]
	negs r2, r2
	adds r2, #0x08
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x01
	bl func_080054EC
_0810A406:
	add sp, #0x028
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0810A418: .4byte 0x02039B84
_0810A41C: .4byte 0x0000FFF6
_0810A420: .4byte 0x09A4AC84
.syntax divided
