.syntax unified
	.align 2, 0
	.global MovieSetupAudioCodec
	.thumb
	.thumb_func
	.type MovieSetupAudioCodec, %function
MovieSetupAudioCodec: @ 08118ADC
	push {r4, r7, lr}
	add sp, #-0x024
	mov r7, sp
	str r0, [r7, #0x00]
	str r1, [r7, #0x04]
	str r2, [r7, #0x08]
	ldr r0, _08118B1C @ =0x0811D1B0
	ldr r1, _08118B20 @ =0x0811CE44
	subs r0, r0, r1
	str r0, [r7, #0x0C]
	ldr r0, _08118B24 @ =0x0203C7D0
	ldr r1, [r7, #0x0C]
	ldr r2, [r0, #0x00]
	adds r0, r1, #0x0
	bl _call_via_r2
	ldr r1, [r7, #0x00]
	str r0, [r1, #0x08]
	ldr r1, [r7, #0x00]
	ldr r0, [r1, #0x08]
	ldr r1, _08118B20 @ =0x0811CE44
	ldr r2, [r7, #0x0C]
	bl memcpy
	ldr r0, [r7, #0x08]
	cmp r0, #0x01
	beq _08118B48
	cmp r0, #0x01
	bgt _08118B28
	cmp r0, #0x00
	beq _08118B2E
	b _08118C2A
_08118B1C: .4byte 0x0811D1B0
_08118B20: .4byte 0x0811CE44
_08118B24: .4byte 0x0203C7D0
_08118B28:
	cmp r0, #0x02
	beq _08118B64
	b _08118C2A
_08118B2E:
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x00]
	ldr r2, _08118B40 @ =0x0811CE44
	ldr r3, _08118B44 @ =0x0811D184
	subs r2, r2, r3
	ldr r1, [r1, #0x08]
	subs r2, r1, r2
	str r2, [r0, #0x00]
	b _08118C2A
_08118B40: .4byte 0x0811CE44
_08118B44: .4byte 0x0811D184
_08118B48:
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x00]
	ldr r2, _08118B5C @ =0x0811CE44
	ldr r3, _08118B60 @ =0x0811D1A4
	subs r2, r2, r3
	ldr r1, [r1, #0x08]
	subs r2, r1, r2
	str r2, [r0, #0x00]
	b _08118C2A
	.byte 0x00, 0x00
_08118B5C: .4byte 0x0811CE44
_08118B60: .4byte 0x0811D1A4
_08118B64:
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x00]
	ldr r2, _08118B90 @ =0x0811CE44
	ldr r3, _08118B94 @ =0x0811D10C
	subs r2, r2, r3
	ldr r1, [r1, #0x08]
	subs r2, r1, r2
	str r2, [r0, #0x00]
	ldr r0, [r7, #0x00]
	ldr r1, _08118B90 @ =0x0811CE44
	ldr r2, _08118B98 @ =0x0811CE44
	subs r1, r1, r2
	ldr r0, [r0, #0x08]
	subs r1, r0, r1
	str r1, [r7, #0x1C]
	movs r0, #0x00
	str r0, [r7, #0x14]
_08118B86:
	ldr r0, [r7, #0x14]
	cmp r0, #0x58
	ble _08118B9C
	b _08118C28
	.byte 0x00, 0x00
_08118B90: .4byte 0x0811CE44
_08118B94: .4byte 0x0811D10C
_08118B98: .4byte 0x0811CE44
_08118B9C:
	ldr r0, _08118BB8 @ =0x09D6D1E4
	ldr r1, [r7, #0x14]
	adds r2, r1, #0x0
	lsls r1, r2, #0x01
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	str r1, [r7, #0x18]
	movs r0, #0x00
	str r0, [r7, #0x10]
_08118BAE:
	ldr r0, [r7, #0x10]
	cmp r0, #0x03
	ble _08118BBC
	b _08118C20
	.byte 0x00, 0x00
_08118BB8: .4byte 0x09D6D1E4
_08118BBC:
	ldr r0, [r7, #0x10]
	cmp r0, #0x01
	bgt _08118BEA
	ldr r1, [r7, #0x14]
	lsls r0, r1, #0x02
	ldr r1, [r7, #0x10]
	adds r0, r0, r1
	adds r1, r0, #0x0
	lsls r0, r1, #0x01
	ldr r1, [r7, #0x1C]
	adds r0, r0, r1
	ldr r1, [r7, #0x10]
	ldr r2, [r7, #0x18]
	muls r1, r2
	ldr r2, [r7, #0x18]
	asrs r3, r2, #0x1F
	lsrs r4, r3, #0x1F
	adds r3, r2, r4
	asrs r2, r3, #0x01
	adds r1, r1, r2
	adds r2, r1, #0x0
	strh r2, [r0, #0x00]
	b _08118C18
_08118BEA:
	ldr r1, [r7, #0x14]
	lsls r0, r1, #0x02
	ldr r1, [r7, #0x10]
	adds r0, r0, r1
	adds r1, r0, #0x0
	lsls r0, r1, #0x01
	ldr r1, [r7, #0x1C]
	adds r0, r0, r1
	ldr r1, [r7, #0x10]
	movs r2, #0x01
	ands r1, r2
	ldr r2, [r7, #0x18]
	muls r1, r2
	ldr r2, [r7, #0x18]
	asrs r3, r2, #0x1F
	lsrs r4, r3, #0x1F
	adds r3, r2, r4
	asrs r2, r3, #0x01
	adds r1, r1, r2
	adds r2, r1, #0x0
	negs r1, r2
	adds r2, r1, #0x0
	strh r2, [r0, #0x00]
_08118C18:
	ldr r0, [r7, #0x10]
	adds r1, r0, #0x1
	str r1, [r7, #0x10]
	b _08118BAE
_08118C20:
	ldr r0, [r7, #0x14]
	adds r1, r0, #0x1
	str r1, [r7, #0x14]
	b _08118B86
_08118C28:
	b _08118C2A
_08118C2A:
	add sp, #0x024
	pop {r4, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
