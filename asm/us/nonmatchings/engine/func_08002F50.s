.syntax unified
	.align 2, 0
	.global func_08002F50
	.thumb
	.thumb_func
	.type func_08002F50, %function
func_08002F50: @ 08002F50
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x038
	ldr r0, _080030D4 @ =0x030074C8
	ldr r2, [r0, #0x00]
	ldr r3, _080030D8 @ =0x00002BAE
	adds r1, r2, r3
	ldrb r1, [r1, #0x00]
	adds r5, r0, #0x0
	cmp r1, #0x00
	beq _08002F6E
	b _080034BA
_08002F6E:
	movs r4, #0xE0
	lsls r4, r4, #0x13
	str r4, [sp, #0x01C]
	movs r3, #0x00
	ldr r4, _080030DC @ =0x00002BAC
	adds r0, r2, r4
	ldrh r0, [r0, #0x00]
	cmp r3, r0
	bge _08002FE0
	adds r2, r5, #0x0
	movs r1, #0x00
_08002F84:
	ldr r6, [sp, #0x01C]
	adds r6, #0x06
	str r6, [sp, #0x01C]
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	ldr r6, _080030E0 @ =0x000028AC
	adds r0, r0, r6
	ldrh r0, [r0, #0x00]
	ldr r6, [sp, #0x01C]
	strh r0, [r6, #0x00]
	adds r6, #0x08
	str r6, [sp, #0x01C]
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	ldr r6, _080030E4 @ =0x000028AE
	adds r0, r0, r6
	ldrh r0, [r0, #0x00]
	ldr r6, [sp, #0x01C]
	strh r0, [r6, #0x00]
	adds r6, #0x08
	str r6, [sp, #0x01C]
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	ldr r6, _080030E8 @ =0x000028B0
	adds r0, r0, r6
	ldrh r0, [r0, #0x00]
	ldr r6, [sp, #0x01C]
	strh r0, [r6, #0x00]
	adds r6, #0x08
	str r6, [sp, #0x01C]
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	ldr r6, _080030EC @ =0x000028B2
	adds r0, r0, r6
	ldrh r0, [r0, #0x00]
	ldr r6, [sp, #0x01C]
	strh r0, [r6, #0x00]
	adds r6, #0x02
	str r6, [sp, #0x01C]
	adds r1, #0x18
	adds r3, #0x01
	ldr r0, [r2, #0x00]
	adds r0, r0, r4
	ldrh r0, [r0, #0x00]
	cmp r3, r0
	blt _08002F84
_08002FE0:
	ldr r1, [r5, #0x00]
	ldr r0, _080030DC @ =0x00002BAC
	adds r2, r1, r0
	movs r0, #0x00
	strh r0, [r2, #0x00]
	movs r2, #0x00
	str r2, [sp, #0x00C]
	movs r3, #0xE0
	lsls r3, r3, #0x13
	str r3, [sp, #0x01C]
	ldr r4, _080030F0 @ =0x000028A8
	adds r0, r1, r4
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x014]
	ldr r6, _080030F4 @ =0x000026A8
	adds r6, r1, r6
	str r6, [sp, #0x004]
	ldr r0, _080030F8 @ =0x00002BAF
	adds r1, r1, r0
	ldrb r1, [r1, #0x00]
	str r1, [sp, #0x024]
	movs r3, #0x00
	ldr r1, [sp, #0x014]
	cmp r3, r1
	blt _08003014
	b _08003494
_08003014:
	lsls r0, r3, #0x02
	ldr r2, [sp, #0x004]
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	mov r10, r0
	ldr r4, [r0, #0x0C]
	ldr r6, [r0, #0x08]
	str r6, [sp, #0x008]
	ldrh r2, [r4, #0x00]
	adds r4, #0x02
	str r4, [sp, #0x018]
	movs r0, #0x00
	str r0, [sp, #0x020]
	ldr r1, [sp, #0x024]
	cmp r1, #0x00
	beq _08003046
	mov r4, r10
	ldrh r1, [r4, #0x16]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	bne _08003046
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r4, #0x16]
_08003046:
	adds r3, #0x01
	str r3, [sp, #0x028]
	cmp r2, #0x00
	bne _08003050
	b _0800348A
_08003050:
	str r2, [sp, #0x010]
_08003052:
	ldr r6, [sp, #0x018]
	ldrh r6, [r6, #0x00]
	mov r12, r6
	ldr r0, [sp, #0x018]
	adds r0, #0x02
	ldrh r7, [r0, #0x00]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	mov r9, r1
	adds r0, #0x02
	str r0, [sp, #0x018]
	movs r3, #0xFF
	ands r3, r6
	adds r1, r3, #0x0
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0x00
	beq _0800307E
	movs r3, #0xFF
	eors r3, r1
	ldr r0, _080030FC @ =0x0000FFFF
	eors r3, r0
_0800307E:
	ldr r4, _08003100 @ =0x000001FF
	adds r6, r7, #0x0
	ands r6, r4
	movs r2, #0x80
	lsls r2, r2, #0x01
	adds r1, r2, #0x0
	adds r2, r6, #0x0
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _0800309C
	adds r6, r4, #0x0
	eors r6, r2
	ldr r0, _080030FC @ =0x0000FFFF
	eors r6, r0
_0800309C:
	mov r2, sp
	mov r4, sp
	adds r4, #0x02
	lsls r1, r7, #0x10
	mov r0, r12
	orrs r1, r0
	ldr r0, _08003104 @ =0xC000C000
	ands r1, r0
	ldr r0, _08003108 @ =0x40008000
	mov r8, r4
	cmp r1, r0
	bne _080030B6
	b _080031B8
_080030B6:
	cmp r1, r0
	bhi _08003120
	movs r0, #0x80
	lsls r0, r0, #0x08
	cmp r1, r0
	beq _080031AC
	cmp r1, r0
	bhi _0800310C
	cmp r1, #0x00
	beq _08003168
	movs r0, #0x80
	lsls r0, r0, #0x07
	cmp r1, r0
	beq _08003188
	b _080031D4
_080030D4: .4byte 0x030074C8
_080030D8: .4byte 0x00002BAE
_080030DC: .4byte 0x00002BAC
_080030E0: .4byte 0x000028AC
_080030E4: .4byte 0x000028AE
_080030E8: .4byte 0x000028B0
_080030EC: .4byte 0x000028B2
_080030F0: .4byte 0x000028A8
_080030F4: .4byte 0x000026A8
_080030F8: .4byte 0x00002BAF
_080030FC: .4byte 0x0000FFFF
_08003100: .4byte 0x000001FF
_08003104: .4byte 0xC000C000
_08003108: .4byte 0x40008000
_0800310C:
	movs r0, #0x80
	lsls r0, r0, #0x17
	cmp r1, r0
	beq _0800316C
	ldr r0, _0800311C @ =0x40004000
	cmp r1, r0
	beq _08003190
	b _080031D4
_0800311C: .4byte 0x40004000
_08003120:
	ldr r0, _0800313C @ =0x80008000
	cmp r1, r0
	beq _080031BC
	cmp r1, r0
	bhi _08003144
	movs r0, #0x80
	lsls r0, r0, #0x18
	cmp r1, r0
	beq _08003176
	ldr r0, _08003140 @ =0x80004000
	cmp r1, r0
	beq _08003198
	b _080031D4
	.byte 0x00, 0x00
_0800313C: .4byte 0x80008000
_08003140: .4byte 0x80004000
_08003144:
	ldr r0, _08003158 @ =0xC0004000
	cmp r1, r0
	beq _080031A0
	cmp r1, r0
	bhi _0800315C
	movs r0, #0xC0
	lsls r0, r0, #0x18
	cmp r1, r0
	beq _08003180
	b _080031D4
_08003158: .4byte 0xC0004000
_0800315C:
	ldr r0, _08003164 @ =0xC0008000
	cmp r1, r0
	beq _080031C8
	b _080031D4
_08003164: .4byte 0xC0008000
_08003168:
	movs r1, #0x08
	b _08003178
_0800316C:
	movs r4, #0x10
	strh r4, [r2, #0x00]
	mov r0, r8
	strh r4, [r0, #0x00]
	b _080031DA
_08003176:
	movs r1, #0x20
_08003178:
	strh r1, [r2, #0x00]
	mov r2, r8
	strh r1, [r2, #0x00]
	b _080031DA
_08003180:
	movs r0, #0x40
	strh r0, [r2, #0x00]
	mov r4, r8
	b _080031D8
_08003188:
	movs r0, #0x10
	strh r0, [r2, #0x00]
	movs r2, #0x08
	b _080031B2
_08003190:
	movs r4, #0x20
	strh r4, [r2, #0x00]
	movs r1, #0x08
	b _080031C2
_08003198:
	movs r4, #0x20
	strh r4, [r2, #0x00]
	movs r1, #0x10
	b _080031C2
_080031A0:
	movs r0, #0x40
	strh r0, [r2, #0x00]
	movs r4, #0x20
	mov r2, r8
	strh r4, [r2, #0x00]
	b _080031DA
_080031AC:
	movs r0, #0x08
	strh r0, [r2, #0x00]
	movs r2, #0x10
_080031B2:
	mov r1, r8
	strh r2, [r1, #0x00]
	b _080031DA
_080031B8:
	movs r4, #0x08
	b _080031BE
_080031BC:
	movs r4, #0x10
_080031BE:
	strh r4, [r2, #0x00]
	movs r1, #0x20
_080031C2:
	mov r0, r8
	strh r1, [r0, #0x00]
	b _080031DA
_080031C8:
	movs r4, #0x20
	strh r4, [r2, #0x00]
	movs r0, #0x40
	mov r1, r8
	strh r0, [r1, #0x00]
	b _080031DA
_080031D4:
	movs r0, #0x00
	strh r0, [r2, #0x00]
_080031D8:
	strh r0, [r4, #0x00]
_080031DA:
	ldr r2, [sp, #0x008]
	cmp r2, #0x00
	bne _080031E2
	b _0800330E
_080031E2:
	mov r0, sp
	ldrh r1, [r0, #0x00]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r4, r8
	ldrh r1, [r4, #0x00]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrb r0, [r2, #0x14]
	cmp r0, #0x00
	beq _08003278
	ldr r5, _08003274 @ =0x08121400
	adds r2, r0, #0x0
	negs r2, r2
	adds r1, r2, #0x0
	adds r1, #0x40
	movs r0, #0xFF
	ands r1, r0
	lsls r0, r1, #0x01
	adds r0, r0, r5
	movs r4, #0x00
	ldsh r0, [r0, r4]
	lsls r4, r6, #0x10
	asrs r4, r4, #0x10
	str r4, [sp, #0x034]
	adds r6, r0, #0x0
	muls r6, r4
	str r6, [sp, #0x02C]
	movs r0, #0xFF
	ands r2, r0
	lsls r0, r2, #0x01
	adds r0, r0, r5
	movs r4, #0x00
	ldsh r0, [r0, r4]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r6, r0, #0x0
	muls r6, r3
	ldr r0, [sp, #0x02C]
	adds r6, r0, r6
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r0, r1, r5
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r4, [sp, #0x034]
	adds r1, r0, #0x0
	muls r1, r4
	adds r2, #0x40
	lsls r2, r2, #0x01
	adds r2, r2, r5
	movs r4, #0x00
	ldsh r0, [r2, r4]
	muls r0, r3
	adds r2, r1, r0
	ldr r1, [sp, #0x008]
	ldr r0, [r1, #0x0C]
	muls r0, r6
	asrs r6, r0, #0x08
	ldr r0, [r1, #0x10]
	muls r0, r2
	asrs r2, r0, #0x08
	b _0800328E
_08003274: .4byte 0x08121400
_08003278:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #0x008]
	ldr r1, [r2, #0x0C]
	adds r6, r1, #0x0
	muls r6, r0
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r2, #0x10]
	adds r2, r1, #0x0
	muls r2, r0
_0800328E:
	lsls r1, r6, #0x08
	lsls r2, r2, #0x08
	mov r0, sp
	ldrh r5, [r0, #0x00]
	lsls r0, r5, #0x10
	asrs r4, r0, #0x11
	asrs r1, r1, #0x10
	subs r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	mov r3, r8
	ldrh r0, [r3, #0x00]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x11
	asrs r2, r2, #0x10
	subs r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r3, r2, #0x10
	ldr r2, [sp, #0x008]
	ldrb r0, [r2, #0x0A]
	cmp r0, #0x00
	beq _080032F0
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov r1, sp
	lsls r0, r5, #0x01
	strh r0, [r1, #0x00]
	mov r4, r8
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x01
	strh r0, [r4, #0x00]
	ldrb r0, [r2, #0x0A]
	cmp r0, #0x00
	beq _080032F0
	movs r1, #0xC0
	lsls r1, r1, #0x02
	adds r0, r1, #0x0
	mov r2, r12
	orrs r2, r0
	mov r12, r2
	b _08003300
_080032F0:
	movs r4, #0x80
	lsls r4, r4, #0x01
	adds r0, r4, #0x0
	mov r1, r12
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov r12, r0
_08003300:
	ldr r2, [sp, #0x008]
	ldrh r0, [r2, #0x08]
	lsls r0, r0, #0x09
	orrs r7, r0
	lsls r0, r7, #0x10
	lsrs r7, r0, #0x10
	b _08003352
_0800330E:
	mov r4, r10
	ldrh r2, [r4, #0x16]
	movs r0, #0x02
	ands r0, r2
	cmp r0, #0x00
	beq _08003332
	lsls r0, r0, #0x0C
	eors r7, r0
	lsls r0, r7, #0x10
	lsrs r7, r0, #0x10
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	negs r0, r0
	mov r3, r8
	ldrh r1, [r3, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_08003332:
	movs r0, #0x01
	ands r0, r2
	cmp r0, #0x00
	beq _08003352
	lsls r0, r0, #0x0C
	eors r7, r0
	lsls r0, r7, #0x10
	lsrs r7, r0, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	negs r0, r0
	mov r1, sp
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_08003352:
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	mov r4, r10
	ldrh r4, [r4, #0x10]
	adds r1, r1, r4
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	mov r6, r10
	ldrh r6, [r6, #0x12]
	adds r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	asrs r4, r1, #0x10
	cmp r4, #0xEF
	bgt _0800338E
	mov r0, sp
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmn r4, r0
	ble _0800338E
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0x9F
	bgt _0800338E
	mov r2, r8
	movs r3, #0x00
	ldsh r0, [r2, r3]
	cmn r1, r0
	bgt _080033AE
_0800338E:
	mov r4, r10
	ldr r0, [r4, #0x00]
	adds r0, #0x24
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800347E
	mov r0, r12
	adds r1, r7, #0x0
	bl GetObjTileCount
	ldr r6, [sp, #0x020]
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x020]
	b _0800347E
_080033AE:
	movs r2, #0xFF
	lsls r2, r2, #0x08
	adds r0, r2, #0x0
	mov r3, r12
	ands r3, r0
	movs r0, #0xFF
	ands r0, r1
	orrs r3, r0
	ldr r6, [sp, #0x01C]
	strh r3, [r6, #0x00]
	movs r1, #0xFE
	lsls r1, r1, #0x08
	adds r0, r1, #0x0
	ands r7, r0
	ldr r2, _0800341C @ =0x000001FF
	adds r1, r2, #0x0
	adds r0, r4, #0x0
	ands r0, r1
	orrs r7, r0
	strh r7, [r6, #0x02]
	mov r3, r10
	ldr r2, [r3, #0x00]
	adds r0, r2, #0x0
	adds r0, #0x24
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08003420
	ldr r0, [r3, #0x04]
	mov r4, r9
	lsrs r1, r4, #0x0C
	ldrh r0, [r0, #0x06]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	movs r6, #0xC0
	lsls r6, r6, #0x04
	adds r0, r6, #0x0
	ands r4, r0
	ldrh r0, [r2, #0x06]
	ldr r2, [sp, #0x020]
	adds r0, r2, r0
	orrs r4, r0
	lsrs r1, r1, #0x04
	orrs r4, r1
	ldr r3, [sp, #0x01C]
	strh r4, [r3, #0x04]
	ldrh r0, [r3, #0x00]
	ldrh r1, [r3, #0x02]
	bl GetObjTileCount
	ldr r4, [sp, #0x020]
	adds r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x020]
	b _08003442
_0800341C: .4byte 0x000001FF
_08003420:
	mov r6, r10
	ldr r1, [r6, #0x04]
	mov r3, r9
	lsrs r0, r3, #0x0C
	ldrh r1, [r1, #0x06]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r4, _080034CC @ =0x00000FFF
	adds r1, r4, #0x0
	ands r3, r1
	mov r9, r3
	ldrh r1, [r2, #0x06]
	add r1, r9
	lsrs r0, r0, #0x04
	orrs r1, r0
	ldr r6, [sp, #0x01C]
	strh r1, [r6, #0x04]
_08003442:
	mov r1, r10
	ldrh r0, [r1, #0x16]
	movs r1, #0x08
	ands r1, r0
	lsls r1, r1, #0x09
	ldr r2, [sp, #0x01C]
	ldrh r0, [r2, #0x00]
	orrs r1, r0
	strh r1, [r2, #0x00]
	mov r3, r10
	ldrh r2, [r3, #0x16]
	movs r0, #0x04
	ands r0, r2
	lsls r0, r0, #0x08
	orrs r1, r0
	ldr r4, [sp, #0x01C]
	strh r1, [r4, #0x00]
	ldrh r0, [r3, #0x16]
	movs r6, #0xC0
	lsls r6, r6, #0x04
	adds r1, r6, #0x0
	ands r0, r1
	ldrh r1, [r4, #0x04]
	orrs r0, r1
	strh r0, [r4, #0x04]
	adds r4, #0x08
	str r4, [sp, #0x01C]
	ldr r0, [sp, #0x00C]
	adds r0, #0x01
	str r0, [sp, #0x00C]
_0800347E:
	ldr r1, [sp, #0x010]
	subs r1, #0x01
	str r1, [sp, #0x010]
	cmp r1, #0x00
	beq _0800348A
	b _08003052
_0800348A:
	ldr r3, [sp, #0x028]
	ldr r2, [sp, #0x014]
	cmp r3, r2
	bge _08003494
	b _08003014
_08003494:
	ldr r3, [sp, #0x00C]
	ldr r5, _080034D0 @ =0x030074C8
	cmp r3, #0x7F
	bgt _080034B0
	movs r4, #0x80
	lsls r4, r4, #0x02
	adds r0, r4, #0x0
_080034A2:
	ldr r6, [sp, #0x01C]
	strh r0, [r6, #0x00]
	adds r6, #0x08
	str r6, [sp, #0x01C]
	adds r3, #0x01
	cmp r3, #0x7F
	ble _080034A2
_080034B0:
	ldr r0, [r5, #0x00]
	ldr r1, _080034D4 @ =0x000028A8
	adds r0, r0, r1
	movs r1, #0x00
	strh r1, [r0, #0x00]
_080034BA:
	add sp, #0x038
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080034CC: .4byte 0x00000FFF
_080034D0: .4byte 0x030074C8
_080034D4: .4byte 0x000028A8
.syntax divided
