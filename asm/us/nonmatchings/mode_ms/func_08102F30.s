.syntax unified
	.align 2, 0
	.global func_08102F30
	.thumb
	.thumb_func
	.type func_08102F30, %function
func_08102F30: @ 08102F30
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x01C
	ldr r0, _08102F8C @ =0x02035A58
	bl AnimUpdate
	str r0, [sp, #0x014]
	movs r0, #0x00
	str r0, [sp, #0x010]
	ldr r1, _08102F90 @ =0x020358C8
	str r1, [sp, #0x018]
_08102F4C:
	ldr r3, [sp, #0x010]
	lsls r2, r3, #0x10
	asrs r1, r2, #0x10
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r5, r0, #0x03
	ldr r4, [sp, #0x018]
	adds r1, r5, r4
	adds r0, r1, #0x0
	adds r0, #0x47
	ldrb r0, [r0, #0x00]
	adds r7, r2, #0x0
	cmp r0, #0x00
	bne _08102F94
	adds r0, r4, #0x0
	adds r0, #0x34
	adds r0, r5, r0
	ldr r4, [r0, #0x00]
	movs r0, #0x00
	adds r1, r4, #0x0
	adds r2, r4, #0x0
	movs r3, #0x00
	bl AllocObjAffine
	mov r10, r0
	ldr r0, [sp, #0x018]
	adds r0, #0x18
	adds r0, r5, r0
	bl AnimUpdate
	adds r6, r0, #0x0
	b _08102FC6
_08102F8C: .4byte 0x02035A58
_08102F90: .4byte 0x020358C8
_08102F94:
	ldr r2, [sp, #0x018]
	adds r2, #0x34
	adds r2, r5, r2
	ldr r3, _081030D8 @ =0x08121400
	ldrh r1, [r1, #0x30]
	movs r0, #0xFF
	ands r0, r1
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r6, #0x00
	ldsh r0, [r0, r6]
	negs r0, r0
	ldr r2, [r2, #0x00]
	muls r0, r2
	asrs r4, r0, #0x08
	movs r0, #0x00
	adds r1, r4, #0x0
	movs r3, #0x00
	bl AllocObjAffine
	mov r10, r0
	ldr r1, _081030DC @ =0x020358DC
	adds r0, r5, r1
	ldr r6, [r0, #0x00]
_08102FC6:
	cmp r4, #0x00
	bne _08102FCC
	b _0810314E
_08102FCC:
	ldr r5, _081030E0 @ =0x020358C8
	asrs r7, r7, #0x10
	mov r9, r7
	mov r2, r9
	lsls r0, r2, #0x03
	add r0, r9
	lsls r4, r0, #0x03
	adds r0, r5, #0x0
	adds r0, #0x3C
	adds r7, r4, r0
	ldr r0, [r7, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	adds r1, r5, #0x0
	adds r1, #0x40
	adds r1, r1, r4
	mov r8, r1
	ldr r1, [r1, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	adds r2, r5, #0x0
	adds r2, #0x10
	adds r2, r4, r2
	ldr r3, [r2, #0x00]
	adds r2, r5, #0x0
	adds r2, #0x0C
	adds r2, r4, r2
	ldr r2, [r2, #0x00]
	str r2, [sp, #0x000]
	mov r2, r10
	str r2, [sp, #0x004]
	movs r2, #0x00
	str r2, [sp, #0x008]
	movs r2, #0x50
	str r2, [sp, #0x00C]
	adds r2, r6, #0x0
	bl DrawSprite
	adds r6, r4, r5
	adds r0, r6, #0x0
	adds r0, #0x47
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08103026
	b _0810314E
_08103026:
	ldr r0, [r7, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	mov r3, r8
	ldr r1, [r3, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	adds r2, r5, #0x0
	adds r2, #0x08
	adds r2, r4, r2
	ldr r2, [r2, #0x00]
	adds r3, r5, #0x4
	adds r3, r4, r3
	ldr r3, [r3, #0x00]
	ldr r4, [r6, #0x00]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	movs r5, #0x00
	str r5, [sp, #0x008]
	movs r4, #0x58
	str r4, [sp, #0x00C]
	bl DrawSprite
	adds r0, r6, #0x0
	adds r0, #0x46
	ldrb r5, [r0, #0x00]
	cmp r5, #0x00
	beq _08103104
	ldr r0, [r7, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	mov r6, r8
	ldr r1, [r6, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r4, _081030E4 @ =0x09EE9894
	ldr r3, _081030E8 @ =0x02035B58
	mov r5, r9
	lsls r2, r5, #0x01
	adds r2, r2, r3
	ldrh r3, [r2, #0x00]
	ldr r6, _081030EC @ =0x00000FFF
	adds r2, r6, #0x0
	ands r2, r3
	movs r3, #0x34
	muls r2, r3
	ldr r3, _081030F0 @ =0x08F70AB0
	adds r2, r2, r3
	adds r2, #0x20
	ldrb r2, [r2, #0x00]
	lsls r2, r2, #0x02
	adds r2, r2, r4
	ldr r2, [r2, #0x00]
	ldr r3, _081030F4 @ =0x02035A3C
	ldr r3, [r3, #0x00]
	ldr r4, _081030F8 @ =0x02035A38
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	movs r5, #0x00
	str r5, [sp, #0x008]
	movs r4, #0x48
	str r4, [sp, #0x00C]
	bl DrawSprite
	ldr r0, [r7, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	mov r6, r8
	ldr r1, [r6, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _081030FC @ =0x02035A54
	ldr r3, [r2, #0x00]
	ldr r2, _08103100 @ =0x02035A30
	ldr r2, [r2, #0x00]
	str r2, [sp, #0x000]
	mov r2, r10
	str r2, [sp, #0x004]
	str r5, [sp, #0x008]
	movs r2, #0x40
	str r2, [sp, #0x00C]
	ldr r2, [sp, #0x014]
	bl DrawSprite
	b _0810314E
	.byte 0x00, 0x00
_081030D8: .4byte 0x08121400
_081030DC: .4byte 0x020358DC
_081030E0: .4byte 0x020358C8
_081030E4: .4byte 0x09EE9894
_081030E8: .4byte 0x02035B58
_081030EC: .4byte 0x00000FFF
_081030F0: .4byte 0x08F70AB0
_081030F4: .4byte 0x02035A3C
_081030F8: .4byte 0x02035A38
_081030FC: .4byte 0x02035A54
_08103100: .4byte 0x02035A30
_08103104:
	ldr r0, [r7, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	mov r3, r8
	ldr r1, [r3, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r4, _08103248 @ =0x09EE981C
	ldr r3, _0810324C @ =0x02035B58
	mov r6, r9
	lsls r2, r6, #0x01
	adds r2, r2, r3
	ldrh r3, [r2, #0x00]
	ldr r6, _08103250 @ =0x00000FFF
	adds r2, r6, #0x0
	ands r2, r3
	movs r3, #0x34
	muls r2, r3
	ldr r3, _08103254 @ =0x08F70AB0
	adds r2, r2, r3
	adds r2, #0x20
	ldrb r2, [r2, #0x00]
	lsls r2, r2, #0x02
	adds r2, r2, r4
	ldr r2, [r2, #0x00]
	ldr r3, _08103258 @ =0x02035A34
	ldr r3, [r3, #0x00]
	ldr r4, _0810325C @ =0x02035A30
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	movs r4, #0x48
	str r4, [sp, #0x00C]
	bl DrawSprite
_0810314E:
	ldr r5, _08103260 @ =0x020358C8
	mov r8, r5
	ldr r6, [sp, #0x010]
	lsls r0, r6, #0x10
	asrs r7, r0, #0x10
	lsls r0, r7, #0x03
	adds r0, r0, r7
	lsls r0, r0, #0x03
	add r0, r8
	ldrh r0, [r0, #0x38]
	cmp r0, #0x09
	bne _08103202
	ldr r0, _08103264 @ =0x02035A44
	ldr r2, [r0, #0x00]
	ldr r0, _08103268 @ =0x02035A40
	ldr r3, [r0, #0x00]
	movs r0, #0x00
	str r0, [sp, #0x000]
	ldr r0, _0810326C @ =0x02035A48
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x30
	movs r1, #0x63
	bl func_080664D8
	ldr r0, _08103270 @ =0x02035A4C
	ldr r2, [r0, #0x00]
	ldr r1, _08103274 @ =0x02035AE0
	ldr r3, [r1, #0x00]
	movs r4, #0x00
	str r4, [sp, #0x000]
	ldr r0, _08103278 @ =0x02035A50
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x31
	movs r1, #0x72
	bl func_080664D8
	ldr r6, _0810327C @ =0x02035AD4
	ldr r4, _08103280 @ =0x02035B62
	movs r5, #0x00
	ldsh r1, [r4, r5]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x03
	mov r1, r8
	adds r1, #0x3C
	adds r0, r0, r1
	ldr r1, [r0, #0x00]
	ldr r0, _08103284 @ =0xFFFFF000
	adds r1, r1, r0
	adds r0, r6, #0x0
	bl func_0805F1C0
	ldr r5, _08103288 @ =0x02035AD8
	movs r2, #0x00
	ldsh r1, [r4, r2]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x03
	mov r1, r8
	adds r1, #0x40
	adds r0, r0, r1
	ldr r1, [r0, #0x00]
	ldr r3, _0810328C @ =0xFFFFE000
	adds r1, r1, r3
	adds r0, r5, #0x0
	bl func_0805F1C0
	ldr r0, _08103290 @ =0x02035AE8
	bl AnimUpdate
	adds r2, r0, #0x0
	ldr r0, [r6, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r5, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r3, _08103294 @ =0x02035ADC
	ldr r3, [r3, #0x00]
	ldr r5, _08103274 @ =0x02035AE0
	ldr r4, [r5, #0x00]
	str r4, [sp, #0x000]
	movs r6, #0x00
	str r6, [sp, #0x004]
	str r6, [sp, #0x008]
	str r6, [sp, #0x00C]
	bl DrawSprite
_08103202:
	adds r0, r7, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	str r1, [sp, #0x010]
	asrs r0, r0, #0x10
	cmp r0, #0x04
	bgt _08103212
	b _08102F4C
_08103212:
	movs r2, #0x00
	str r2, [sp, #0x010]
_08103216:
	ldr r3, [sp, #0x010]
	lsls r4, r3, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #0x02
	adds r0, r0, r4
	lsls r0, r0, #0x02
	ldr r1, _08103298 @ =0x02035A70
	adds r0, r0, r1
	bl TaskPoolDraw
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	str r5, [sp, #0x010]
	asrs r4, r4, #0x10
	cmp r4, #0x04
	ble _08103216
	add sp, #0x01C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08103248: .4byte 0x09EE981C
_0810324C: .4byte 0x02035B58
_08103250: .4byte 0x00000FFF
_08103254: .4byte 0x08F70AB0
_08103258: .4byte 0x02035A34
_0810325C: .4byte 0x02035A30
_08103260: .4byte 0x020358C8
_08103264: .4byte 0x02035A44
_08103268: .4byte 0x02035A40
_0810326C: .4byte 0x02035A48
_08103270: .4byte 0x02035A4C
_08103274: .4byte 0x02035AE0
_08103278: .4byte 0x02035A50
_0810327C: .4byte 0x02035AD4
_08103280: .4byte 0x02035B62
_08103284: .4byte 0xFFFFF000
_08103288: .4byte 0x02035AD8
_0810328C: .4byte 0xFFFFE000
_08103290: .4byte 0x02035AE8
_08103294: .4byte 0x02035ADC
_08103298: .4byte 0x02035A70
.syntax divided
