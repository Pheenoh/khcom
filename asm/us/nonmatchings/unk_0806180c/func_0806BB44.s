.syntax unified
	.align 2, 0
	.global func_0806BB44
	.thumb
	.thumb_func
	.type func_0806BB44, %function
func_0806BB44: @ 0806BB44
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	adds r7, r2, #0x0
	str r3, [sp, #0x008]
	movs r0, #0x00
	mov r10, r0
	mov r9, r0
	movs r1, #0x00
	str r1, [sp, #0x00C]
	ldr r3, _0806BB70 @ =0x02034A88
	ldr r0, [r3, #0x00]
	cmp r0, #0x00
	bne _0806BB7A
	movs r0, #0x00
	b _0806BD94
	.byte 0x00, 0x00
_0806BB70: .4byte 0x02034A88
_0806BB74:
	ldr r2, [sp, #0x008]
	str r7, [r2, #0x00]
	b _0806BD92
_0806BB7A:
	ldr r0, _0806BBEC @ =0x02034A90
	mov r1, r9
	strb r1, [r0, #0x00]
	ldrh r1, [r7, #0x00]
	adds r4, r0, #0x0
	cmp r1, #0x00
	bne _0806BB8A
	b _0806BD8C
_0806BB8A:
	ldrb r1, [r4, #0x00]
	ldr r0, _0806BBF0 @ =0x02034A88
	ldr r2, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	ldr r1, [sp, #0x000]
	add r1, r10
	str r1, [r0, #0x00]
	ldrb r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	ldr r1, [sp, #0x004]
	add r1, r9
	str r1, [r0, #0x04]
	ldrb r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	movs r1, #0x01
	strb r1, [r0, #0x15]
	ldrh r1, [r7, #0x00]
	ldr r0, _0806BBF4 @ =0x00004079
	cmp r1, r0
	bne _0806BBCA
	movs r2, #0x01
	str r2, [sp, #0x00C]
	adds r7, #0x02
_0806BBCA:
	ldrh r1, [r7, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x07
	cmp r1, r0
	bne _0806BBDA
	movs r0, #0x00
	str r0, [sp, #0x00C]
	adds r7, #0x02
_0806BBDA:
	ldrh r0, [r7, #0x00]
	cmp r0, #0x0A
	bne _0806BBF8
	movs r1, #0x00
	mov r10, r1
	movs r2, #0xC0
	lsls r2, r2, #0x04
	add r9, r2
	b _0806BD78
_0806BBEC: .4byte 0x02034A90
_0806BBF0: .4byte 0x02034A88
_0806BBF4: .4byte 0x00004079
_0806BBF8:
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xDF
	bhi _0806BC06
	ldrh r4, [r7, #0x00]
	b _0806BCE6
_0806BC06:
	ldrh r1, [r7, #0x00]
	movs r0, #0x99
	lsls r0, r0, #0x06
	cmp r1, r0
	beq _0806BCD8
	cmp r1, r0
	bgt _0806BC60
	ldr r0, _0806BC30 @ =0x00002192
	cmp r1, r0
	beq _0806BCB8
	cmp r1, r0
	bgt _0806BC38
	subs r0, #0x02
	cmp r1, r0
	beq _0806BCB4
	cmp r1, r0
	bgt _0806BCAC
	ldr r0, _0806BC34 @ =0x0000203B
	cmp r1, r0
	beq _0806BCCC
	b _0806BCE4
_0806BC30: .4byte 0x00002192
_0806BC34: .4byte 0x0000203B
_0806BC38:
	ldr r0, _0806BC4C @ =0x000025A0
	cmp r1, r0
	beq _0806BCE0
	cmp r1, r0
	bgt _0806BC54
	ldr r0, _0806BC50 @ =0x00002193
	cmp r1, r0
	beq _0806BCB0
	b _0806BCE4
	.byte 0x00, 0x00
_0806BC4C: .4byte 0x000025A0
_0806BC50: .4byte 0x00002193
_0806BC54:
	ldr r0, _0806BC5C @ =0x00002605
	cmp r1, r0
	beq _0806BCDC
	b _0806BCE4
_0806BC5C: .4byte 0x00002605
_0806BC60:
	ldr r0, _0806BC7C @ =0x0000300D
	cmp r1, r0
	beq _0806BCC0
	cmp r1, r0
	bgt _0806BC90
	ldr r0, _0806BC80 @ =0x0000266A
	cmp r1, r0
	beq _0806BCD0
	cmp r1, r0
	bgt _0806BC84
	subs r0, #0x28
	cmp r1, r0
	beq _0806BCD4
	b _0806BCE4
_0806BC7C: .4byte 0x0000300D
_0806BC80: .4byte 0x0000266A
_0806BC84:
	ldr r0, _0806BC8C @ =0x0000300C
	cmp r1, r0
	beq _0806BCBC
	b _0806BCE4
_0806BC8C: .4byte 0x0000300C
_0806BC90:
	ldr r0, _0806BCA8 @ =0x0000300F
	cmp r1, r0
	beq _0806BCC8
	cmp r1, r0
	blt _0806BCC4
	movs r0, #0xE0
	lsls r0, r0, #0x08
	cmp r1, r0
	bne _0806BCE4
	movs r4, #0x19
	b _0806BCE6
	.byte 0x00, 0x00
_0806BCA8: .4byte 0x0000300F
_0806BCAC:
	movs r4, #0x0A
	b _0806BCE6
_0806BCB0:
	movs r4, #0x0B
	b _0806BCE6
_0806BCB4:
	movs r4, #0x0C
	b _0806BCE6
_0806BCB8:
	movs r4, #0x0D
	b _0806BCE6
_0806BCBC:
	movs r4, #0x01
	b _0806BCE6
_0806BCC0:
	movs r4, #0x02
	b _0806BCE6
_0806BCC4:
	movs r4, #0x03
	b _0806BCE6
_0806BCC8:
	movs r4, #0x04
	b _0806BCE6
_0806BCCC:
	movs r4, #0x06
	b _0806BCE6
_0806BCD0:
	movs r4, #0x12
	b _0806BCE6
_0806BCD4:
	movs r4, #0x08
	b _0806BCE6
_0806BCD8:
	movs r4, #0x09
	b _0806BCE6
_0806BCDC:
	movs r4, #0x15
	b _0806BCE6
_0806BCE0:
	movs r4, #0x11
	b _0806BCE6
_0806BCE4:
	movs r4, #0x00
_0806BCE6:
	ldr r6, _0806BDA4 @ =0x02034A90
	ldrb r1, [r6, #0x00]
	ldr r5, _0806BDA8 @ =0x02034A88
	ldr r2, [r5, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	movs r1, #0x00
	mov r8, r1
	mov r2, sp
	ldrb r2, [r2, #0x0C]
	strb r2, [r0, #0x14]
	ldrb r1, [r6, #0x00]
	ldr r2, [r5, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	ldr r0, [r0, #0x08]
	cmp r0, #0x00
	beq _0806BD26
	bl ReleaseObjTiles
	ldrb r0, [r6, #0x00]
	ldr r2, [r5, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	adds r1, r1, r2
	mov r0, r8
	str r0, [r1, #0x08]
_0806BD26:
	ldr r0, _0806BDAC @ =0x08F7D438
	lsls r1, r4, #0x01
	adds r1, r1, r0
	movs r2, #0x00
	ldsh r0, [r1, r2]
	lsls r0, r0, #0x08
	add r10, r0
	cmp r4, #0x20
	beq _0806BD5E
	ldr r1, _0806BDB0 @ =0x09EEC134
	lsls r0, r4, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldrh r4, [r0, #0x06]
	lsls r0, r4, #0x05
	ldr r1, _0806BDB4 @ =0x090CBFB2
	adds r0, r0, r1
	movs r1, #0x80
	bl LoadObjTiles
	ldrb r2, [r6, #0x00]
	ldr r1, _0806BDA8 @ =0x02034A88
	ldr r3, [r1, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x03
	adds r1, r1, r3
	str r0, [r1, #0x08]
_0806BD5E:
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	strb r0, [r6, #0x00]
	movs r0, #0x9B
	lsls r0, r0, #0x08
	adds r4, r6, #0x0
	cmp r10, r0
	ble _0806BD78
	movs r2, #0x00
	mov r10, r2
	movs r0, #0xC0
	lsls r0, r0, #0x04
	add r9, r0
_0806BD78:
	adds r7, #0x02
	movs r0, #0xC0
	lsls r0, r0, #0x05
	cmp r9, r0
	ble _0806BD84
	b _0806BB74
_0806BD84:
	ldrh r0, [r7, #0x00]
	cmp r0, #0x00
	beq _0806BD8C
	b _0806BB8A
_0806BD8C:
	movs r0, #0x00
	ldr r1, [sp, #0x008]
	str r0, [r1, #0x00]
_0806BD92:
	ldrb r0, [r4, #0x00]
_0806BD94:
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_0806BDA4: .4byte 0x02034A90
_0806BDA8: .4byte 0x02034A88
_0806BDAC: .4byte 0x08F7D438
_0806BDB0: .4byte 0x09EEC134
_0806BDB4: .4byte 0x090CBFB2
.syntax divided
