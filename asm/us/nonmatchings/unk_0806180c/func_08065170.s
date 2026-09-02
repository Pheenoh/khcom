.syntax unified
	.align 2, 0
	.global func_08065170
	.thumb
	.thumb_func
	.type func_08065170, %function
func_08065170: @ 08065170
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	adds r6, r2, #0x0
	movs r0, #0x00
	mov r10, r0
	mov r8, r0
	movs r1, #0x00
	str r1, [sp, #0x008]
	ldr r3, _08065198 @ =0x02034A84
	ldr r0, [r3, #0x00]
	cmp r0, #0x00
	bne _0806519C
	movs r0, #0x00
	b _080653AE
_08065198: .4byte 0x02034A84
_0806519C:
	ldr r0, _08065230 @ =0x02034A90
	mov r2, r8
	strb r2, [r0, #0x00]
	ldrh r1, [r6, #0x00]
	adds r5, r0, #0x0
	cmp r1, #0x00
	bne _080651AC
	b _080653AC
_080651AC:
	mov r9, r5
_080651AE:
	movs r4, #0x00
	mov r0, r9
	ldrb r1, [r0, #0x00]
	ldr r0, _08065234 @ =0x02034A84
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
	ldr r0, _08065238 @ =0x00004079
	cmp r1, r0
	bne _080651F6
	movs r1, #0x01
	str r1, [sp, #0x008]
	adds r6, #0x02
_080651F6:
	ldrh r1, [r6, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x07
	cmp r1, r0
	bne _08065206
	movs r2, #0x00
	str r2, [sp, #0x008]
	adds r6, #0x02
_08065206:
	mov r1, r9
	ldrb r0, [r1, #0x00]
	ldr r1, _08065234 @ =0x02034A84
	ldr r2, [r1, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	adds r1, r1, r2
	mov r2, sp
	ldrb r2, [r2, #0x08]
	strb r2, [r1, #0x14]
	ldrh r0, [r6, #0x00]
	cmp r0, #0x0A
	bne _0806523C
	movs r0, #0x00
	mov r10, r0
	movs r1, #0xC0
	lsls r1, r1, #0x04
	add r8, r1
	b _080653A2
	.byte 0x00, 0x00
_08065230: .4byte 0x02034A90
_08065234: .4byte 0x02034A84
_08065238: .4byte 0x00004079
_0806523C:
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xDF
	bhi _0806524A
	ldrh r4, [r6, #0x00]
	b _08065326
_0806524A:
	ldrh r1, [r6, #0x00]
	movs r0, #0x99
	lsls r0, r0, #0x06
	cmp r1, r0
	beq _0806531C
	cmp r1, r0
	bgt _080652A4
	ldr r0, _08065274 @ =0x00002192
	cmp r1, r0
	beq _080652FC
	cmp r1, r0
	bgt _0806527C
	subs r0, #0x02
	cmp r1, r0
	beq _080652F8
	cmp r1, r0
	bgt _080652F0
	ldr r0, _08065278 @ =0x0000203B
	cmp r1, r0
	beq _08065310
	b _08065326
_08065274: .4byte 0x00002192
_08065278: .4byte 0x0000203B
_0806527C:
	ldr r0, _08065290 @ =0x000025A0
	cmp r1, r0
	beq _08065324
	cmp r1, r0
	bgt _08065298
	ldr r0, _08065294 @ =0x00002193
	cmp r1, r0
	beq _080652F4
	b _08065326
	.byte 0x00, 0x00
_08065290: .4byte 0x000025A0
_08065294: .4byte 0x00002193
_08065298:
	ldr r0, _080652A0 @ =0x00002605
	cmp r1, r0
	beq _08065320
	b _08065326
_080652A0: .4byte 0x00002605
_080652A4:
	ldr r0, _080652C0 @ =0x0000300D
	cmp r1, r0
	beq _08065304
	cmp r1, r0
	bgt _080652D4
	ldr r0, _080652C4 @ =0x0000266A
	cmp r1, r0
	beq _08065314
	cmp r1, r0
	bgt _080652C8
	subs r0, #0x28
	cmp r1, r0
	beq _08065318
	b _08065326
_080652C0: .4byte 0x0000300D
_080652C4: .4byte 0x0000266A
_080652C8:
	ldr r0, _080652D0 @ =0x0000300C
	cmp r1, r0
	beq _08065300
	b _08065326
_080652D0: .4byte 0x0000300C
_080652D4:
	ldr r0, _080652EC @ =0x0000300F
	cmp r1, r0
	beq _0806530C
	cmp r1, r0
	blt _08065308
	movs r0, #0xE0
	lsls r0, r0, #0x08
	cmp r1, r0
	bne _08065326
	movs r4, #0x19
	b _08065326
	.byte 0x00, 0x00
_080652EC: .4byte 0x0000300F
_080652F0:
	movs r4, #0x0A
	b _08065326
_080652F4:
	movs r4, #0x0B
	b _08065326
_080652F8:
	movs r4, #0x0C
	b _08065326
_080652FC:
	movs r4, #0x0D
	b _08065326
_08065300:
	movs r4, #0x01
	b _08065326
_08065304:
	movs r4, #0x02
	b _08065326
_08065308:
	movs r4, #0x03
	b _08065326
_0806530C:
	movs r4, #0x04
	b _08065326
_08065310:
	movs r4, #0x06
	b _08065326
_08065314:
	movs r4, #0x12
	b _08065326
_08065318:
	movs r4, #0x08
	b _08065326
_0806531C:
	movs r4, #0x09
	b _08065326
_08065320:
	movs r4, #0x15
	b _08065326
_08065324:
	movs r4, #0x11
_08065326:
	ldr r7, _080653C0 @ =0x02034A90
	ldrb r0, [r7, #0x00]
	ldr r5, _080653C4 @ =0x02034A84
	ldr r2, [r5, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	adds r1, r1, r2
	ldr r0, [r1, #0x08]
	cmp r0, #0x00
	beq _08065350
	bl ReleaseObjTiles
	ldrb r1, [r7, #0x00]
	ldr r2, [r5, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	movs r1, #0x00
	str r1, [r0, #0x08]
_08065350:
	ldr r0, _080653C8 @ =0x08F7D438
	lsls r1, r4, #0x01
	adds r1, r1, r0
	movs r2, #0x00
	ldsh r0, [r1, r2]
	lsls r0, r0, #0x08
	add r10, r0
	cmp r4, #0x20
	beq _08065388
	ldr r1, _080653CC @ =0x09EEC134
	lsls r0, r4, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldrh r4, [r0, #0x06]
	lsls r0, r4, #0x05
	ldr r1, _080653D0 @ =0x090CBFB2
	adds r0, r0, r1
	movs r1, #0x80
	bl LoadObjTiles
	ldrb r2, [r7, #0x00]
	ldr r1, _080653C4 @ =0x02034A84
	ldr r3, [r1, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x03
	adds r1, r1, r3
	str r0, [r1, #0x08]
_08065388:
	ldrb r0, [r7, #0x00]
	adds r0, #0x01
	strb r0, [r7, #0x00]
	movs r0, #0x9B
	lsls r0, r0, #0x08
	adds r5, r7, #0x0
	cmp r10, r0
	ble _080653A2
	movs r2, #0x00
	mov r10, r2
	movs r0, #0xC0
	lsls r0, r0, #0x04
	add r8, r0
_080653A2:
	adds r6, #0x02
	ldrh r0, [r6, #0x00]
	cmp r0, #0x00
	beq _080653AC
	b _080651AE
_080653AC:
	ldrb r0, [r5, #0x00]
_080653AE:
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080653C0: .4byte 0x02034A90
_080653C4: .4byte 0x02034A84
_080653C8: .4byte 0x08F7D438
_080653CC: .4byte 0x09EEC134
_080653D0: .4byte 0x090CBFB2
.syntax divided
