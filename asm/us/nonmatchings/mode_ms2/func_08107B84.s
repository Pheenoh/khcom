.syntax unified
	.align 2, 0
	.global func_08107B84
	.thumb
	.thumb_func
	.type func_08107B84, %function
func_08107B84: @ 08107B84
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x01C
	mov r1, sp
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r1, _08107CFC @ =0x040000D4
	mov r0, sp
	str r0, [r1, #0x00]
	ldr r2, _08107D00 @ =0x02035E28
	ldr r0, [r2, #0x00]
	str r0, [r1, #0x04]
	ldr r0, _08107D04 @ =0x8100017A
	str r0, [r1, #0x08]
	ldr r0, [r1, #0x08]
	movs r4, #0x00
	ldr r6, _08107D08 @ =0x02035E48
	adds r5, r2, #0x0
	movs r3, #0x1B
_08107BB0:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ldr r2, [r5, #0x00]
	lsls r1, r0, #0x03
	subs r1, r1, r0
	lsls r1, r1, #0x02
	adds r1, r1, r2
	strh r3, [r1, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1A
	ble _08107BB0
	movs r1, #0x00
	str r1, [sp, #0x008]
	strh r1, [r6, #0x00]
	movs r3, #0x00
	str r3, [sp, #0x004]
_08107BD6:
	ldr r4, [sp, #0x004]
	lsls r3, r4, #0x10
	asrs r1, r3, #0x0F
	ldr r5, _08107D0C @ =0x02035E30
	adds r0, r1, r5
	movs r2, #0x00
	mov r4, sp
	ldrh r4, [r4, #0x08]
	strh r4, [r0, #0x00]
	ldr r5, _08107D10 @ =0x02035E40
	adds r0, r1, r5
	strh r2, [r0, #0x00]
	str r3, [sp, #0x018]
	str r1, [sp, #0x00C]
	ldr r3, _08107D14 @ =0x099937A0
	adds r0, r1, r3
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x010]
_08107BFA:
	lsls r1, r2, #0x10
	asrs r2, r1, #0x10
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x03
	adds r0, r0, r2
	lsls r0, r0, #0x04
	ldr r4, _08107D18 @ =0x09EE4C80
	adds r0, r0, r4
	ldrh r5, [r0, #0x24]
	mov r12, r5
	str r1, [sp, #0x014]
	ldr r3, [sp, #0x008]
	lsls r1, r3, #0x10
	ldr r4, [sp, #0x010]
	cmp r12, r4
	bne _08107C90
	ldrh r0, [r0, #0x20]
	mov r10, r0
	movs r4, #0x00
	lsls r0, r2, #0x02
	adds r0, r0, r2
	lsls r7, r0, #0x01
	ldr r0, _08107D10 @ =0x02035E40
	asrs r1, r1, #0x10
	ldr r5, _08107D08 @ =0x02035E48
	mov r8, r5
	ldr r2, [sp, #0x00C]
	adds r6, r2, r0
	lsls r0, r1, #0x03
	subs r0, r0, r1
	lsls r0, r0, #0x02
	mov r9, r0
_08107C3C:
	lsls r1, r4, #0x10
	asrs r4, r1, #0x10
	adds r0, r4, r7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08107D1C @ =0x0203A8C0
	adds r0, r0, r3
	ldrb r2, [r0, #0x00]
	adds r3, r2, #0x0
	adds r5, r1, #0x0
	cmp r2, #0x00
	beq _08107C82
	mov r0, r12
	cmp r0, #0x04
	beq _08107C62
	mov r1, r8
	ldrh r0, [r1, #0x00]
	adds r0, r2, r0
	strh r0, [r1, #0x00]
_08107C62:
	ldrh r0, [r6, #0x00]
	adds r0, r3, r0
	strh r0, [r6, #0x00]
	ldr r2, _08107D00 @ =0x02035E28
	ldr r0, [r2, #0x00]
	add r0, r9
	mov r1, r10
	strh r1, [r0, #0x00]
	strh r7, [r0, #0x02]
	mov r2, sp
	ldrh r2, [r2, #0x04]
	strh r2, [r0, #0x04]
	lsls r1, r4, #0x01
	adds r0, #0x06
	adds r0, r0, r1
	strh r3, [r0, #0x00]
_08107C82:
	movs r3, #0x80
	lsls r3, r3, #0x09
	adds r0, r5, r3
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x09
	ble _08107C3C
_08107C90:
	ldr r4, [sp, #0x008]
	lsls r0, r4, #0x10
	asrs r2, r0, #0x10
	ldr r5, _08107D00 @ =0x02035E28
	ldr r1, [r5, #0x00]
	lsls r0, r2, #0x03
	subs r0, r0, r2
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	cmp r0, #0x1A
	bhi _08107CB0
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x008]
_08107CB0:
	ldr r1, [sp, #0x014]
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r1, r2
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1A
	ble _08107BFA
	ldr r3, [sp, #0x018]
	asrs r1, r3, #0x10
	lsls r0, r1, #0x01
	ldr r4, _08107D20 @ =0x02035E38
	adds r3, r0, r4
	ldr r5, _08107D0C @ =0x02035E30
	adds r0, r0, r5
	ldrh r2, [r0, #0x00]
	ldr r4, [sp, #0x008]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	subs r0, r0, r2
	strh r0, [r3, #0x00]
	adds r1, #0x01
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	str r5, [sp, #0x004]
	asrs r1, r1, #0x10
	cmp r1, #0x03
	bgt _08107CEA
	b _08107BD6
_08107CEA:
	add sp, #0x01C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08107CFC: .4byte 0x040000D4
_08107D00: .4byte 0x02035E28
_08107D04: .4byte 0x8100017A
_08107D08: .4byte 0x02035E48
_08107D0C: .4byte 0x02035E30
_08107D10: .4byte 0x02035E40
_08107D14: .4byte 0x099937A0
_08107D18: .4byte 0x09EE4C80
_08107D1C: .4byte 0x0203A8C0
_08107D20: .4byte 0x02035E38
.syntax divided
