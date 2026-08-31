.syntax unified
	.align 2, 0
	.global func_080789E4
	.thumb
	.thumb_func
	.type func_080789E4, %function
func_080789E4: @ 080789E4
	push {r4, r5, r6, r7, lr}
	add sp, #-0x018
	adds r6, r0, #0x0
	movs r3, #0x00
	adds r0, #0xC6
	strb r3, [r0, #0x00]
	adds r4, r6, #0x0
	adds r4, #0xB8
	ldrb r1, [r4, #0x00]
	adds r0, r6, #0x0
	bl func_08078914
	ldrb r1, [r4, #0x00]
	adds r0, r6, #0x0
	bl func_08078754
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _08078AF8
	movs r1, #0x00
	ldsb r1, [r4, r1]
	lsls r1, r1, #0x01
	adds r0, r6, #0x0
	adds r0, #0xA8
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	subs r0, #0x01
	add r7, sp, #0x014
	strh r0, [r7, #0x00]
	ldrb r1, [r4, #0x00]
	adds r0, r6, #0x0
	adds r2, r7, #0x0
	bl func_08076750
	adds r3, r0, #0x0
	adds r5, r4, #0x0
	subs r4, #0x08
	cmp r3, #0x00
	beq _08078ADC
	movs r0, #0x00
	ldsb r0, [r5, r0]
	lsls r0, r0, #0x04
	adds r0, #0x54
	adds r0, r6, r0
	str r0, [sp, #0x004]
	add r1, sp, #0x004
	ldrh r0, [r7, #0x00]
	strh r0, [r1, #0x0C]
	ldrb r0, [r5, #0x00]
	strb r0, [r1, #0x0E]
	str r3, [sp, #0x008]
	adds r2, r1, #0x0
	movs r1, #0x00
	ldsb r1, [r5, r1]
	lsls r1, r1, #0x01
	adds r0, r6, #0x0
	adds r0, #0x9C
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	strb r0, [r2, #0x0F]
	ldr r1, [r3, #0x00]
	ldr r0, _08078A6C @ =0x0000FFFE
	cmp r1, r0
	bne _08078A74
	ldr r1, _08078A70 @ =0x09EE499C
	adds r0, r6, #0x0
	b _08078A7A
	.byte 0x00, 0x00
_08078A6C: .4byte 0x0000FFFE
_08078A70: .4byte 0x09EE499C
_08078A74:
	ldr r1, _08078AE4 @ =0x09EE496C
	adds r0, r6, #0x0
	add r2, sp, #0x004
_08078A7A:
	bl TaskCreate
	ldr r3, [r0, #0x04]
	adds r1, r3, #0x0
	adds r1, #0x80
	ldr r0, _08078AE8 @ =0x09033FA8
	ldr r0, [r0, #0x04]
	str r0, [r3, #0x7C]
	str r0, [r1, #0x00]
	adds r2, r3, #0x0
	adds r2, #0x98
	adds r1, #0x14
	ldr r0, _08078AEC @ =0x09033FB8
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	str r0, [r2, #0x00]
	adds r1, #0x10
	movs r0, #0x01
	strb r0, [r1, #0x00]
	subs r1, #0x08
	movs r0, #0x08
	strh r0, [r1, #0x00]
	adds r1, #0x04
	movs r0, #0x32
	strb r0, [r1, #0x00]
	ldr r0, [r3, #0x78]
	ldr r1, _08078AF0 @ =0x00000814
	orrs r0, r1
	str r0, [r3, #0x78]
	ldr r0, _08078AF4 @ =0x02034A98
	str r3, [r0, #0x00]
	adds r1, r6, #0x0
	adds r1, #0xC6
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	adds r3, r6, #0x0
	adds r3, #0xB8
	movs r1, #0x00
	ldsb r1, [r3, r1]
	lsls r1, r1, #0x01
	adds r2, r6, #0x0
	adds r2, #0xB0
	adds r1, r2, r1
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	adds r5, r3, #0x0
	adds r4, r2, #0x0
_08078ADC:
	movs r0, #0x91
	bl m4aSongNumStart
	b _08078B5E
_08078AE4: .4byte 0x09EE496C
_08078AE8: .4byte 0x09033FA8
_08078AEC: .4byte 0x09033FB8
_08078AF0: .4byte 0x00000814
_08078AF4: .4byte 0x02034A98
_08078AF8:
	movs r0, #0x00
	ldsb r0, [r4, r0]
	lsls r0, r0, #0x04
	adds r0, #0x54
	adds r0, r6, r0
	str r0, [sp, #0x004]
	add r1, sp, #0x004
	ldr r0, _08078B9C @ =0x0000FFFF
	strh r0, [r1, #0x0C]
	movs r1, #0x00
	ldsb r1, [r4, r1]
	lsls r1, r1, #0x02
	adds r0, r6, #0x0
	adds r0, #0x44
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x008]
	add r1, sp, #0x004
	ldrb r0, [r4, #0x00]
	strb r0, [r1, #0x0E]
	ldr r1, _08078BA0 @ =0x09EE4984
	adds r0, r6, #0x0
	add r2, sp, #0x004
	bl TaskCreate
	ldr r3, [r0, #0x04]
	adds r1, r3, #0x0
	adds r1, #0x80
	ldr r0, _08078BA4 @ =0x09033FA8
	ldr r0, [r0, #0x04]
	str r0, [r3, #0x7C]
	str r0, [r1, #0x00]
	adds r2, r3, #0x0
	adds r2, #0x98
	adds r1, #0x14
	ldr r0, _08078BA8 @ =0x09033FB8
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	str r0, [r2, #0x00]
	adds r1, #0x0C
	movs r0, #0x32
	strb r0, [r1, #0x00]
	ldr r0, [r3, #0x78]
	ldr r1, _08078BAC @ =0x00000806
	orrs r0, r1
	str r0, [r3, #0x78]
	ldr r0, _08078BB0 @ =0x02034A98
	str r3, [r0, #0x00]
	adds r5, r4, #0x0
	adds r4, r6, #0x0
	adds r4, #0xB0
_08078B5E:
	movs r3, #0x00
	ldsb r3, [r5, r3]
	lsls r2, r3, #0x01
	adds r0, r4, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	ble _08078B8E
	adds r0, r6, #0x0
	adds r0, #0xBC
	adds r0, r0, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08078B8E
	adds r2, #0xB0
	adds r2, r6, r2
	adds r3, #0xBC
	adds r3, r6, r3
	movs r0, #0x01
	str r0, [sp, #0x000]
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	bl func_080991CC
_08078B8E:
	bl _0807BB04
	add sp, #0x018
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08078B9C: .4byte 0x0000FFFF
_08078BA0: .4byte 0x09EE4984
_08078BA4: .4byte 0x09033FA8
_08078BA8: .4byte 0x09033FB8
_08078BAC: .4byte 0x00000806
_08078BB0: .4byte 0x02034A98
.syntax divided
