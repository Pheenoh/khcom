.syntax unified
	.align 2, 0
	.global func_08080994
	.thumb
	.thumb_func
	.type func_08080994, %function
func_08080994: @ 08080994
	push {r4, r5, r6, lr}
	add sp, #-0x014
	adds r5, r0, #0x0
	movs r3, #0x00
	adds r0, #0xC6
	strb r3, [r0, #0x00]
	adds r4, r5, #0x0
	adds r4, #0xB8
	ldrb r1, [r4, #0x00]
	adds r0, r5, #0x0
	bl func_08078914
	ldrb r1, [r4, #0x00]
	adds r0, r5, #0x0
	bl func_08078754
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0x00
	bne _080809BE
	b _08080AB4
_080809BE:
	movs r1, #0x00
	ldsb r1, [r4, r1]
	lsls r1, r1, #0x01
	adds r0, r5, #0x0
	adds r0, #0xA8
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	subs r0, #0x01
	add r6, sp, #0x010
	strh r0, [r6, #0x00]
	ldrb r1, [r4, #0x00]
	adds r0, r5, #0x0
	adds r2, r6, #0x0
	bl func_08076750
	adds r3, r0, #0x0
	cmp r3, #0x00
	bne _080809E4
	b _08080B22
_080809E4:
	movs r0, #0x00
	ldsb r0, [r4, r0]
	lsls r0, r0, #0x04
	adds r0, #0x54
	adds r0, r5, r0
	str r0, [sp, #0x000]
	mov r1, sp
	ldrh r0, [r6, #0x00]
	strh r0, [r1, #0x0C]
	ldrb r0, [r4, #0x00]
	strb r0, [r1, #0x0E]
	str r3, [sp, #0x004]
	mov r2, sp
	movs r1, #0x00
	ldsb r1, [r4, r1]
	lsls r1, r1, #0x01
	adds r0, r5, #0x0
	adds r0, #0x9C
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	strb r0, [r2, #0x0F]
	ldr r1, [r3, #0x00]
	ldr r0, _08080A1C @ =0x0000FFFE
	cmp r1, r0
	bne _08080A24
	ldr r1, _08080A20 @ =0x09EE49FC
	adds r0, r5, #0x0
	b _08080A2A
_08080A1C: .4byte 0x0000FFFE
_08080A20: .4byte 0x09EE49FC
_08080A24:
	ldr r1, _08080AA4 @ =0x09EE49CC
	adds r0, r5, #0x0
	mov r2, sp
_08080A2A:
	bl TaskCreate
	ldr r0, [r0, #0x04]
	mov r12, r0
	mov r0, r12
	adds r0, #0x80
	movs r1, #0x00
	mov r2, r12
	str r1, [r2, #0x7C]
	str r1, [r0, #0x00]
	mov r3, r12
	adds r3, #0x98
	adds r2, #0x94
	ldr r0, _08080AA8 @ =0x090352E4
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	str r0, [r3, #0x00]
	mov r0, r12
	adds r0, #0xA4
	strb r1, [r0, #0x00]
	mov r1, r12
	adds r1, #0xA0
	movs r0, #0x32
	strb r0, [r1, #0x00]
	mov r0, r12
	adds r0, #0x8C
	ldr r0, [r0, #0x00]
	mov r1, r12
	str r0, [r1, #0x4C]
	mov r0, r12
	adds r0, #0x90
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x50]
	adds r1, #0x9C
	movs r0, #0x08
	strh r0, [r1, #0x00]
	mov r2, r12
	ldr r0, [r2, #0x78]
	ldr r1, _08080AAC @ =0x00000814
	orrs r0, r1
	str r0, [r2, #0x78]
	ldr r0, _08080AB0 @ =0x02034AAC
	str r2, [r0, #0x00]
	adds r1, r5, #0x0
	adds r1, #0xC6
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	adds r0, r5, #0x0
	adds r0, #0xB8
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x01
	subs r1, #0x16
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	b _08080B22
	.byte 0x00, 0x00
_08080AA4: .4byte 0x09EE49CC
_08080AA8: .4byte 0x090352E4
_08080AAC: .4byte 0x00000814
_08080AB0: .4byte 0x02034AAC
_08080AB4:
	movs r0, #0x00
	ldsb r0, [r4, r0]
	lsls r0, r0, #0x04
	adds r0, #0x54
	adds r0, r5, r0
	str r0, [sp, #0x000]
	mov r1, sp
	ldr r0, _08080B30 @ =0x0000FFFF
	strh r0, [r1, #0x0C]
	movs r1, #0x00
	ldsb r1, [r4, r1]
	lsls r1, r1, #0x02
	adds r0, r5, #0x0
	adds r0, #0x44
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x004]
	mov r1, sp
	ldrb r0, [r4, #0x00]
	strb r0, [r1, #0x0E]
	ldr r1, _08080B34 @ =0x09EE49E4
	adds r0, r5, #0x0
	mov r2, sp
	bl TaskCreate
	ldr r3, [r0, #0x04]
	adds r0, r3, #0x0
	adds r0, #0x80
	str r6, [r3, #0x7C]
	str r6, [r0, #0x00]
	adds r2, r3, #0x0
	adds r2, #0x98
	adds r1, r3, #0x0
	adds r1, #0x94
	ldr r0, _08080B38 @ =0x090352E4
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	str r0, [r2, #0x00]
	adds r0, r3, #0x0
	adds r0, #0x8C
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x4C]
	adds r0, r3, #0x0
	adds r0, #0x90
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x50]
	adds r1, #0x0C
	movs r0, #0x32
	strb r0, [r1, #0x00]
	ldr r0, [r3, #0x78]
	ldr r1, _08080B3C @ =0x00000806
	orrs r0, r1
	str r0, [r3, #0x78]
	ldr r0, _08080B40 @ =0x02034AAC
	str r3, [r0, #0x00]
_08080B22:
	bl _080818E4
	add sp, #0x014
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08080B30: .4byte 0x0000FFFF
_08080B34: .4byte 0x09EE49E4
_08080B38: .4byte 0x090352E4
_08080B3C: .4byte 0x00000806
_08080B40: .4byte 0x02034AAC
.syntax divided
