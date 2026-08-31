.syntax unified
	.align 2, 0
	.global func_080605A4
	.thumb
	.thumb_func
	.type func_080605A4, %function
func_080605A4: @ 080605A4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x048
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x008]
	movs r1, #0x00
	str r1, [sp, #0x020]
	ldr r0, [sp, #0x000]
	bl GetBgCharBase
	ldr r1, _08060674 @ =0x02034A14
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x000]
	bl GetBgScreenBase
	str r0, [sp, #0x004]
	movs r2, #0x00
	str r2, [sp, #0x00C]
	ldr r0, _08060678 @ =0x02034A20
	ldrb r0, [r0, #0x00]
	cmp r2, r0
	bcc _080605DE
	b _0806096C
_080605DE:
	ldr r3, _0806067C @ =0x02034A1C
	ldr r2, [r3, #0x00]
	ldr r0, [sp, #0x00C]
	lsls r4, r0, #0x05
	adds r0, r4, r0
	lsls r5, r0, #0x02
	adds r2, r5, r2
	adds r0, r2, #0x0
	adds r0, #0x7A
	ldrb r1, [r0, #0x00]
	lsrs r3, r1, #0x03
	str r3, [sp, #0x010]
	adds r2, #0x7B
	ldrb r2, [r2, #0x00]
	lsrs r0, r2, #0x03
	str r0, [sp, #0x014]
	lsls r0, r3, #0x03
	subs r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x018]
	ldr r1, [sp, #0x014]
	lsls r0, r1, #0x03
	subs r2, r2, r0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x01C]
	ldr r6, _08060674 @ =0x02034A14
	ldr r0, [sp, #0x000]
	bl GetBgCharBase
	ldr r2, [sp, #0x014]
	lsls r1, r2, #0x05
	adds r1, #0x01
	ldr r3, [sp, #0x010]
	adds r1, r3, r1
	lsls r1, r1, #0x05
	adds r0, r0, r1
	str r0, [r6, #0x00]
	movs r0, #0x00
	mov r9, r0
	ldr r1, _0806067C @ =0x02034A1C
	ldr r0, [r1, #0x00]
	adds r0, r5, r0
	adds r0, #0x7D
	str r4, [sp, #0x03C]
	ldr r2, [sp, #0x00C]
	adds r2, #0x01
	str r2, [sp, #0x034]
	ldrb r0, [r0, #0x00]
	cmp r9, r0
	bcc _08060648
	b _08060958
_08060648:
	str r5, [sp, #0x028]
_0806064A:
	mov r3, r9
	lsls r1, r3, #0x05
	ldr r4, _08060674 @ =0x02034A14
	ldr r0, [r4, #0x00]
	adds r0, r0, r1
	str r0, [sp, #0x024]
	ldr r1, _0806067C @ =0x02034A1C
	ldr r0, [r1, #0x00]
	ldr r2, [sp, #0x028]
	adds r1, r2, r0
	adds r0, r1, #0x0
	adds r0, #0x80
	ldr r0, [r0, #0x00]
	cmp r0, #0x01
	beq _0806069C
	cmp r0, #0x01
	bcc _08060680
	cmp r0, #0x02
	beq _080606B4
	b _080606CC
	.byte 0x00, 0x00
_08060674: .4byte 0x02034A14
_08060678: .4byte 0x02034A20
_0806067C: .4byte 0x02034A1C
_08060680:
	mov r3, r9
	lsls r0, r3, #0x01
	adds r0, r1, r0
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x05
	ldr r4, _08060698 @ =0x0941BEB8
	adds r0, r0, r4
	str r0, [sp, #0x008]
	movs r0, #0x08
	str r0, [sp, #0x020]
	b _080606CC
	.byte 0x00, 0x00
_08060698: .4byte 0x0941BEB8
_0806069C:
	mov r2, r9
	lsls r0, r2, #0x01
	adds r0, r1, r0
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x05
	ldr r3, _080606B0 @ =0x0941DD38
	adds r0, r0, r3
	str r0, [sp, #0x008]
	movs r4, #0x0A
	b _080606CA
_080606B0: .4byte 0x0941DD38
_080606B4:
	mov r2, r9
	lsls r0, r2, #0x01
	adds r0, r1, r0
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0A
	lsls r0, r0, #0x02
	ldr r3, _08060750 @ =0x09EE26EC
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x008]
	movs r4, #0x08
_080606CA:
	str r4, [sp, #0x020]
_080606CC:
	ldr r0, [sp, #0x01C]
	mov r12, r0
	movs r1, #0x00
	mov r8, r1
	ldr r0, [sp, #0x020]
	add r0, r12
	mov r2, r9
	adds r2, #0x01
	str r2, [sp, #0x038]
	cmp r12, r0
	blt _080606E4
	b _0806093E
_080606E4:
	ldr r3, [sp, #0x03C]
	ldr r4, [sp, #0x00C]
	adds r0, r3, r4
	lsls r0, r0, #0x02
	str r0, [sp, #0x02C]
	ldr r0, [sp, #0x018]
	lsls r0, r0, #0x02
	mov r10, r0
	movs r0, #0x20
	mov r1, r10
	subs r1, r0, r1
	str r1, [sp, #0x030]
	ldr r2, _08060754 @ =0x02034A28
	str r2, [sp, #0x040]
	ldr r3, _08060758 @ =0x02034A18
	str r3, [sp, #0x044]
_08060704:
	ldr r4, [sp, #0x018]
	cmp r4, #0x00
	bne _080607A0
	ldr r1, _0806075C @ =0x02034A1C
	ldr r0, [r1, #0x00]
	ldr r3, [sp, #0x02C]
	adds r2, r3, r0
	adds r0, r2, #0x0
	adds r0, #0x80
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	beq _08060760
	mov r0, r12
	movs r4, #0x07
	ands r0, r4
	mov r1, r12
	lsrs r3, r1, #0x03
	lsls r2, r3, #0x0A
	lsls r0, r0, #0x02
	ldr r4, [sp, #0x024]
	adds r0, r0, r4
	adds r2, r2, r0
	mov r0, r8
	movs r1, #0x07
	ands r0, r1
	mov r4, r8
	lsrs r1, r4, #0x03
	lsls r1, r1, #0x0A
	lsls r0, r0, #0x02
	ldr r4, [sp, #0x008]
	adds r0, r0, r4
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	str r0, [r2, #0x00]
	mov r0, r9
	lsls r1, r0, #0x01
	adds r7, r3, #0x0
	b _080608E4
_08060750: .4byte 0x09EE26EC
_08060754: .4byte 0x02034A28
_08060758: .4byte 0x02034A18
_0806075C: .4byte 0x02034A1C
_08060760:
	mov r0, r12
	movs r1, #0x07
	ands r0, r1
	mov r3, r12
	lsrs r5, r3, #0x03
	lsls r3, r5, #0x0A
	lsls r0, r0, #0x02
	ldr r4, [sp, #0x024]
	adds r0, r0, r4
	adds r3, r3, r0
	mov r1, r8
	movs r0, #0x07
	ands r1, r0
	mov r0, r9
	lsls r4, r0, #0x01
	adds r0, r2, r4
	ldrh r2, [r0, #0x00]
	ldr r0, _0806079C @ =0x000003FF
	ands r0, r2
	lsls r0, r0, #0x05
	lsls r1, r1, #0x02
	ldr r2, [sp, #0x008]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x00]
	adds r1, r4, #0x0
	adds r7, r5, #0x0
	b _080608E4
	.byte 0x00, 0x00
_0806079C: .4byte 0x000003FF
_080607A0:
	mov r3, r9
	cmp r3, #0x00
	bne _080607AE
	ldr r4, [sp, #0x040]
	ldr r0, [r4, #0x00]
	cmp r0, #0x01
	bne _08060848
_080607AE:
	movs r4, #0x07
	mov r0, r12
	ands r0, r4
	mov r1, r12
	lsrs r2, r1, #0x03
	lsls r1, r2, #0x0A
	lsls r0, r0, #0x02
	ldr r3, [sp, #0x024]
	adds r0, r0, r3
	adds r6, r1, r0
	ldr r5, [r6, #0x00]
	ldr r1, _08060804 @ =0x02034A1C
	ldr r0, [r1, #0x00]
	ldr r1, [sp, #0x02C]
	adds r3, r1, r0
	adds r0, r3, #0x0
	adds r0, #0x80
	ldr r0, [r0, #0x00]
	adds r7, r2, #0x0
	cmp r0, #0x02
	beq _08060808
	mov r0, r8
	ands r0, r4
	mov r2, r8
	lsrs r1, r2, #0x03
	lsls r1, r1, #0x0A
	lsls r0, r0, #0x02
	ldr r3, [sp, #0x008]
	adds r0, r0, r3
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	mov r4, r10
	lsls r0, r4
	orrs r5, r0
	str r5, [r6, #0x00]
	ldr r0, [r1, #0x00]
	ldr r1, [sp, #0x030]
	lsrs r0, r1
	str r0, [r6, #0x20]
	mov r2, r9
	lsls r1, r2, #0x01
	b _080608E4
	.byte 0x00, 0x00
_08060804: .4byte 0x02034A1C
_08060808:
	mov r2, r8
	ands r2, r4
	mov r0, r9
	lsls r4, r0, #0x01
	adds r3, r3, r4
	ldrh r1, [r3, #0x00]
	ldr r0, _08060844 @ =0x000003FF
	ands r0, r1
	lsls r0, r0, #0x05
	lsls r2, r2, #0x02
	ldr r1, [sp, #0x008]
	adds r2, r2, r1
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	mov r1, r10
	lsls r0, r1
	orrs r5, r0
	str r5, [r6, #0x00]
	ldrh r1, [r3, #0x00]
	ldr r0, _08060844 @ =0x000003FF
	ands r0, r1
	lsls r0, r0, #0x05
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	ldr r2, [sp, #0x030]
	lsrs r0, r2
	str r0, [r6, #0x20]
	adds r1, r4, #0x0
	b _080608E4
	.byte 0x00, 0x00
_08060844: .4byte 0x000003FF
_08060848:
	ldr r3, _08060898 @ =0x02034A1C
	ldr r0, [r3, #0x00]
	ldr r4, [sp, #0x02C]
	adds r5, r4, r0
	adds r0, r5, #0x0
	adds r0, #0x80
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	beq _0806089C
	mov r0, r12
	movs r1, #0x07
	ands r0, r1
	mov r2, r12
	lsrs r3, r2, #0x03
	lsls r2, r3, #0x0A
	lsls r0, r0, #0x02
	ldr r4, [sp, #0x024]
	adds r0, r0, r4
	adds r2, r2, r0
	mov r0, r8
	ands r0, r1
	mov r4, r8
	lsrs r1, r4, #0x03
	lsls r1, r1, #0x0A
	lsls r0, r0, #0x02
	ldr r4, [sp, #0x008]
	adds r0, r0, r4
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	mov r4, r10
	lsls r0, r4
	str r0, [r2, #0x00]
	ldr r0, [r1, #0x00]
	ldr r1, [sp, #0x030]
	lsrs r0, r1
	str r0, [r2, #0x20]
	movs r1, #0x00
	adds r7, r3, #0x0
	b _080608E4
	.byte 0x00, 0x00
_08060898: .4byte 0x02034A1C
_0806089C:
	mov r0, r12
	movs r2, #0x07
	ands r0, r2
	mov r3, r12
	lsrs r4, r3, #0x03
	lsls r3, r4, #0x0A
	lsls r0, r0, #0x02
	ldr r1, [sp, #0x024]
	adds r0, r0, r1
	adds r3, r3, r0
	mov r2, r8
	movs r0, #0x07
	ands r2, r0
	ldrh r1, [r5, #0x00]
	ldr r0, _08060980 @ =0x000003FF
	ands r0, r1
	lsls r0, r0, #0x05
	lsls r2, r2, #0x02
	ldr r1, [sp, #0x008]
	adds r2, r2, r1
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	mov r1, r10
	lsls r0, r1
	str r0, [r3, #0x00]
	ldrh r1, [r5, #0x00]
	ldr r0, _08060980 @ =0x000003FF
	ands r0, r1
	lsls r0, r0, #0x05
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	ldr r2, [sp, #0x030]
	lsrs r0, r2
	str r0, [r3, #0x20]
	movs r1, #0x00
	adds r7, r4, #0x0
_080608E4:
	lsls r2, r7, #0x18
	lsrs r2, r2, #0x18
	ldr r3, [sp, #0x014]
	adds r2, r3, r2
	lsls r3, r2, #0x05
	lsls r2, r2, #0x06
	ldr r4, [sp, #0x010]
	lsls r0, r4, #0x01
	ldr r4, [sp, #0x004]
	adds r0, r0, r4
	adds r0, r1, r0
	adds r2, r2, r0
	ldr r1, [sp, #0x010]
	adds r1, #0x01
	add r1, r9
	adds r1, r1, r3
	ldr r4, [sp, #0x044]
	ldrb r0, [r4, #0x00]
	lsls r0, r0, #0x0C
	orrs r1, r0
	strh r1, [r2, #0x00]
	ldr r1, [sp, #0x010]
	adds r1, #0x02
	add r1, r9
	adds r1, r1, r3
	ldrb r0, [r4, #0x00]
	lsls r0, r0, #0x0C
	orrs r1, r0
	strh r1, [r2, #0x02]
	mov r0, r12
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r12, r0
	mov r0, r8
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r1, [sp, #0x01C]
	ldr r2, [sp, #0x020]
	adds r0, r1, r2
	cmp r12, r0
	bge _0806093E
	b _08060704
_0806093E:
	ldr r3, [sp, #0x038]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	mov r9, r0
	ldr r4, _08060984 @ =0x02034A1C
	ldr r0, [r4, #0x00]
	ldr r1, [sp, #0x028]
	adds r0, r1, r0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r9, r0
	bcs _08060958
	b _0806064A
_08060958:
	ldr r2, [sp, #0x034]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x00C]
	ldr r0, _08060988 @ =0x02034A20
	ldr r3, [sp, #0x00C]
	ldrb r0, [r0, #0x00]
	cmp r3, r0
	bcs _0806096C
	b _080605DE
_0806096C:
	bl func_0805F904
	add sp, #0x048
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08060980: .4byte 0x000003FF
_08060984: .4byte 0x02034A1C
_08060988: .4byte 0x02034A20
.syntax divided
