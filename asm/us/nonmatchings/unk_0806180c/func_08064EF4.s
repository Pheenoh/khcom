.syntax unified
	.align 2, 0
	.global func_08064EF4
	.thumb
	.thumb_func
	.type func_08064EF4, %function
func_08064EF4: @ 08064EF4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	adds r6, r2, #0x0
	str r3, [sp, #0x008]
	movs r0, #0x00
	mov r10, r0
	mov r8, r0
	movs r1, #0x00
	str r1, [sp, #0x00C]
	ldr r3, _08064F20 @ =0x02034A84
	ldr r0, [r3, #0x00]
	cmp r0, #0x00
	bne _08064F2A
	movs r0, #0x00
	b _0806514A
	.byte 0x00, 0x00
_08064F20: .4byte 0x02034A84
_08064F24:
	ldr r2, [sp, #0x008]
	str r6, [r2, #0x00]
	b _08065148
_08064F2A:
	ldr r0, _08064FBC @ =0x02034A90
	mov r1, r8
	strb r1, [r0, #0x00]
	ldrh r1, [r6, #0x00]
	adds r5, r0, #0x0
	cmp r1, #0x00
	bne _08064F3A
	b _08065142
_08064F3A:
	mov r9, r5
_08064F3C:
	movs r4, #0x00
	mov r2, r9
	ldrb r1, [r2, #0x00]
	ldr r0, _08064FC0 @ =0x02034A84
	ldr r2, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	ldr r1, [sp, #0x000]
	add r1, r10
	str r1, [r0, #0x00]
	mov r0, r9
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	ldr r1, [sp, #0x004]
	add r1, r8
	str r1, [r0, #0x04]
	mov r0, r9
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	movs r1, #0x01
	strb r1, [r0, #0x15]
	ldrh r1, [r6, #0x00]
	ldr r0, _08064FC4 @ =0x00004079
	cmp r1, r0
	bne _08064F84
	movs r1, #0x01
	str r1, [sp, #0x00C]
	adds r6, #0x02
_08064F84:
	ldrh r1, [r6, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x07
	cmp r1, r0
	bne _08064F94
	movs r2, #0x00
	str r2, [sp, #0x00C]
	adds r6, #0x02
_08064F94:
	mov r1, r9
	ldrb r0, [r1, #0x00]
	ldr r1, _08064FC0 @ =0x02034A84
	ldr r2, [r1, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	adds r1, r1, r2
	mov r2, sp
	ldrb r2, [r2, #0x0C]
	strb r2, [r1, #0x14]
	ldrh r0, [r6, #0x00]
	cmp r0, #0x0A
	bne _08064FC8
	movs r0, #0x00
	mov r10, r0
	movs r1, #0xC0
	lsls r1, r1, #0x04
	add r8, r1
	b _0806512E
_08064FBC: .4byte 0x02034A90
_08064FC0: .4byte 0x02034A84
_08064FC4: .4byte 0x00004079
_08064FC8:
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xDF
	bhi _08064FD6
	ldrh r4, [r6, #0x00]
	b _080650B2
_08064FD6:
	ldrh r1, [r6, #0x00]
	movs r0, #0x99
	lsls r0, r0, #0x06
	cmp r1, r0
	beq _080650A8
	cmp r1, r0
	bgt _08065030
	ldr r0, _08065000 @ =0x00002192
	cmp r1, r0
	beq _08065088
	cmp r1, r0
	bgt _08065008
	subs r0, #0x02
	cmp r1, r0
	beq _08065084
	cmp r1, r0
	bgt _0806507C
	ldr r0, _08065004 @ =0x0000203B
	cmp r1, r0
	beq _0806509C
	b _080650B2
_08065000: .4byte 0x00002192
_08065004: .4byte 0x0000203B
_08065008:
	ldr r0, _0806501C @ =0x000025A0
	cmp r1, r0
	beq _080650B0
	cmp r1, r0
	bgt _08065024
	ldr r0, _08065020 @ =0x00002193
	cmp r1, r0
	beq _08065080
	b _080650B2
	.byte 0x00, 0x00
_0806501C: .4byte 0x000025A0
_08065020: .4byte 0x00002193
_08065024:
	ldr r0, _0806502C @ =0x00002605
	cmp r1, r0
	beq _080650AC
	b _080650B2
_0806502C: .4byte 0x00002605
_08065030:
	ldr r0, _0806504C @ =0x0000300D
	cmp r1, r0
	beq _08065090
	cmp r1, r0
	bgt _08065060
	ldr r0, _08065050 @ =0x0000266A
	cmp r1, r0
	beq _080650A0
	cmp r1, r0
	bgt _08065054
	subs r0, #0x28
	cmp r1, r0
	beq _080650A4
	b _080650B2
_0806504C: .4byte 0x0000300D
_08065050: .4byte 0x0000266A
_08065054:
	ldr r0, _0806505C @ =0x0000300C
	cmp r1, r0
	beq _0806508C
	b _080650B2
_0806505C: .4byte 0x0000300C
_08065060:
	ldr r0, _08065078 @ =0x0000300F
	cmp r1, r0
	beq _08065098
	cmp r1, r0
	blt _08065094
	movs r0, #0xE0
	lsls r0, r0, #0x08
	cmp r1, r0
	bne _080650B2
	movs r4, #0x19
	b _080650B2
	.byte 0x00, 0x00
_08065078: .4byte 0x0000300F
_0806507C:
	movs r4, #0x0A
	b _080650B2
_08065080:
	movs r4, #0x0B
	b _080650B2
_08065084:
	movs r4, #0x0C
	b _080650B2
_08065088:
	movs r4, #0x0D
	b _080650B2
_0806508C:
	movs r4, #0x01
	b _080650B2
_08065090:
	movs r4, #0x02
	b _080650B2
_08065094:
	movs r4, #0x03
	b _080650B2
_08065098:
	movs r4, #0x04
	b _080650B2
_0806509C:
	movs r4, #0x06
	b _080650B2
_080650A0:
	movs r4, #0x12
	b _080650B2
_080650A4:
	movs r4, #0x08
	b _080650B2
_080650A8:
	movs r4, #0x09
	b _080650B2
_080650AC:
	movs r4, #0x15
	b _080650B2
_080650B0:
	movs r4, #0x11
_080650B2:
	ldr r7, _0806515C @ =0x02034A90
	ldrb r0, [r7, #0x00]
	ldr r5, _08065160 @ =0x02034A84
	ldr r2, [r5, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	adds r1, r1, r2
	ldr r0, [r1, #0x08]
	cmp r0, #0x00
	beq _080650DC
	bl ReleaseObjTiles
	ldrb r1, [r7, #0x00]
	ldr r2, [r5, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	movs r1, #0x00
	str r1, [r0, #0x08]
_080650DC:
	ldr r0, _08065164 @ =0x08F7D438
	lsls r1, r4, #0x01
	adds r1, r1, r0
	movs r2, #0x00
	ldsh r0, [r1, r2]
	lsls r0, r0, #0x08
	add r10, r0
	cmp r4, #0x20
	beq _08065114
	ldr r1, _08065168 @ =0x09EEC134
	lsls r0, r4, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldrh r4, [r0, #0x06]
	lsls r0, r4, #0x05
	ldr r1, _0806516C @ =0x090CBFB2
	adds r0, r0, r1
	movs r1, #0x80
	bl LoadObjTiles
	ldrb r2, [r7, #0x00]
	ldr r1, _08065160 @ =0x02034A84
	ldr r3, [r1, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x03
	adds r1, r1, r3
	str r0, [r1, #0x08]
_08065114:
	ldrb r0, [r7, #0x00]
	adds r0, #0x01
	strb r0, [r7, #0x00]
	movs r0, #0x9B
	lsls r0, r0, #0x08
	adds r5, r7, #0x0
	cmp r10, r0
	ble _0806512E
	movs r2, #0x00
	mov r10, r2
	movs r0, #0xC0
	lsls r0, r0, #0x04
	add r8, r0
_0806512E:
	adds r6, #0x02
	movs r0, #0xC0
	lsls r0, r0, #0x05
	cmp r8, r0
	ble _0806513A
	b _08064F24
_0806513A:
	ldrh r0, [r6, #0x00]
	cmp r0, #0x00
	beq _08065142
	b _08064F3C
_08065142:
	movs r0, #0x00
	ldr r1, [sp, #0x008]
	str r0, [r1, #0x00]
_08065148:
	ldrb r0, [r5, #0x00]
_0806514A:
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_0806515C: .4byte 0x02034A90
_08065160: .4byte 0x02034A84
_08065164: .4byte 0x08F7D438
_08065168: .4byte 0x09EEC134
_0806516C: .4byte 0x090CBFB2
.syntax divided
