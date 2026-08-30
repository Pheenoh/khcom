.syntax unified
	.align 2, 0
	.global func_0810563C
	.thumb
	.thumb_func
	.type func_0810563C, %function
func_0810563C: @ 0810563C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x048
	add r2, sp, #0x034
	movs r0, #0x00
	strh r0, [r2, #0x00]
	ldr r1, _08105798 @ =0x040000D4
	str r2, [r1, #0x00]
	ldr r2, _0810579C @ =0x02035C10
	ldr r0, [r2, #0x00]
	str r0, [r1, #0x04]
	ldr r0, _081057A0 @ =0x81001D0C
	str r0, [r1, #0x08]
	ldr r0, [r1, #0x08]
	movs r0, #0x00
	str r0, [sp, #0x038]
	mov r8, r2
	movs r7, #0x00
	ldr r6, _081057A4 @ =0x000003B6
	ldr r5, _081057A8 @ =0x0000011D
	movs r4, #0x34
	movs r3, #0x8F
_0810566E:
	ldr r1, [sp, #0x038]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	mov r1, r8
	ldr r2, [r1, #0x00]
	adds r1, r0, #0x0
	muls r1, r4
	adds r1, r1, r2
	strh r3, [r1, #0x00]
	strh r6, [r1, #0x02]
	adds r1, #0x2E
	strb r7, [r1, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	str r2, [sp, #0x038]
	asrs r0, r0, #0x10
	cmp r0, r5
	ble _0810566E
	bl func_08084BAC
	ldr r1, _081057AC @ =0x02035C3C
	strh r0, [r1, #0x00]
	ldr r4, _081057B0 @ =0x02035C38
	bl func_08084BF0
	strh r0, [r4, #0x00]
	movs r6, #0x00
	ldr r7, _081057B4 @ =0x02035C20
	movs r3, #0x00
	ldr r5, _081057B8 @ =0x02035C30
	ldr r4, _081057BC @ =0x02035C28
_081056AE:
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #0x01
	adds r0, r2, r7
	strh r3, [r0, #0x00]
	adds r0, r2, r5
	strh r3, [r0, #0x00]
	adds r2, r2, r4
	strh r3, [r2, #0x00]
	adds r1, #0x01
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x03
	ble _081056AE
	ldr r0, _081057C0 @ =0x02035C3A
	movs r1, #0x00
	strh r1, [r0, #0x00]
	movs r3, #0x00
	str r3, [sp, #0x038]
	movs r2, #0x00
	ldr r0, _081057C4 @ =0x0203A858
	adds r4, r0, #0x0
	ldrh r0, [r4, #0x00]
	cmp r2, r0
	blt _081056E4
	b _08105858
_081056E4:
	ldr r0, _081057C8 @ =0x0203A080
	lsls r2, r2, #0x10
	asrs r1, r2, #0x0F
	adds r1, r1, r0
	ldrh r3, [r1, #0x00]
	adds r5, r3, #0x0
	ldr r1, _081057CC @ =0x00000FFF
	ands r5, r1
	str r5, [sp, #0x03C]
	str r2, [sp, #0x044]
	cmp r3, r1
	bne _081056FE
	b _08105844
_081056FE:
	movs r2, #0xE0
	lsls r2, r2, #0x07
	adds r1, r2, #0x0
	adds r0, r3, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _0810570E
	b _08105844
_0810570E:
	movs r0, #0x87
	lsls r0, r0, #0x02
	cmp r5, r0
	bls _08105718
	b _08105844
_08105718:
	ldr r1, _081057D0 @ =0x08F70AB0
	movs r0, #0x34
	mov r10, r0
	mov r0, r10
	muls r0, r5
	adds r4, r0, r1
	adds r0, r4, #0x0
	adds r0, #0x2A
	ldrb r6, [r0, #0x00]
	ldrh r1, [r4, #0x1C]
	mov r9, r1
	movs r2, #0x80
	lsls r2, r2, #0x08
	adds r0, r2, #0x0
	ands r3, r0
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	negs r0, r0
	lsrs r7, r0, #0x1F
	ldr r1, _081057B8 @ =0x02035C30
	lsls r3, r6, #0x01
	str r3, [sp, #0x040]
	adds r1, r3, r1
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	ldr r1, _081057C0 @ =0x02035C3A
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	ldr r1, [sp, #0x038]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	mov r0, r9
	adds r1, r7, #0x0
	mov r2, r8
	bl func_081055E8
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r0, #0x00
	blt _081057D4
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r0, _0810579C @ =0x02035C10
	ldr r0, [r0, #0x00]
	mov r2, r10
	muls r2, r1
	adds r2, r2, r0
	adds r0, r4, #0x0
	adds r0, #0x20
	ldrb r3, [r0, #0x00]
	lsls r3, r3, #0x02
	adds r1, r2, #0x6
	adds r1, r1, r3
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	adds r2, #0x08
	adds r2, r2, r3
	strh r5, [r2, #0x00]
	b _08105842
	.byte 0x00, 0x00
_08105798: .4byte 0x040000D4
_0810579C: .4byte 0x02035C10
_081057A0: .4byte 0x81001D0C
_081057A4: .4byte 0x000003B6
_081057A8: .4byte 0x0000011D
_081057AC: .4byte 0x02035C3C
_081057B0: .4byte 0x02035C38
_081057B4: .4byte 0x02035C20
_081057B8: .4byte 0x02035C30
_081057BC: .4byte 0x02035C28
_081057C0: .4byte 0x02035C3A
_081057C4: .4byte 0x0203A858
_081057C8: .4byte 0x0203A080
_081057CC: .4byte 0x00000FFF
_081057D0: .4byte 0x08F70AB0
_081057D4:
	ldr r2, _0810591C @ =0x02035C10
	mov r12, r2
	ldr r2, [r2, #0x00]
	mov r3, r10
	mov r5, r8
	muls r5, r3
	adds r2, r5, r2
	mov r0, r9
	strh r0, [r2, #0x00]
	ldrh r0, [r4, #0x28]
	strh r0, [r2, #0x02]
	strh r6, [r2, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x20
	ldrb r3, [r0, #0x00]
	lsls r3, r3, #0x02
	adds r1, r2, #0x6
	adds r1, r1, r3
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	adds r0, r2, #0x0
	adds r0, #0x08
	adds r0, r0, r3
	mov r1, sp
	ldrh r1, [r1, #0x3C]
	strh r1, [r0, #0x00]
	adds r2, #0x2E
	strb r7, [r2, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x11
	cmp r7, #0x00
	beq _0810581A
	movs r2, #0xC0
	lsls r2, r2, #0x12
_0810581A:
	mov r3, r12
	ldr r1, [r3, #0x00]
	adds r1, r5, r1
	ldrh r0, [r1, #0x04]
	lsls r0, r0, #0x01
	lsls r2, r0
	ldrh r0, [r1, #0x02]
	orrs r2, r0
	str r2, [r1, #0x30]
	ldr r1, _08105920 @ =0x02035C28
	ldr r0, [sp, #0x040]
	adds r1, r0, r1
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	mov r0, r8
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x038]
_08105842:
	ldr r4, _08105924 @ =0x0203A858
_08105844:
	ldr r1, [sp, #0x044]
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r1, r2
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r4, #0x00]
	cmp r0, r3
	bge _08105858
	b _081056E4
_08105858:
	movs r6, #0x01
	ldr r0, [sp, #0x038]
	lsls r0, r0, #0x10
	mov r9, r0
	ldr r4, _08105928 @ =0x02035C20
	ldr r5, _08105920 @ =0x02035C28
_08105864:
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #0x01
	adds r2, r2, r4
	subs r0, r1, #0x1
	lsls r0, r0, #0x01
	adds r3, r0, r4
	adds r0, r0, r5
	ldrh r0, [r0, #0x00]
	ldrh r3, [r3, #0x00]
	adds r0, r0, r3
	strh r0, [r2, #0x00]
	adds r1, #0x01
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x03
	ble _08105864
	movs r2, #0x01
	mov r1, r9
	asrs r0, r1, #0x10
	cmp r2, r0
	bge _0810590C
	ldr r3, _0810591C @ =0x02035C10
	mov r8, r3
	movs r7, #0x34
_08105898:
	lsls r5, r2, #0x10
	asrs r4, r5, #0x10
	mov r1, r8
	ldr r0, [r1, #0x00]
	adds r1, r4, #0x0
	muls r1, r7
	adds r1, r1, r0
	mov r0, sp
	movs r2, #0x34
	bl _0811F030
	subs r4, #0x01
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x10
	lsls r0, r6, #0x10
	str r5, [sp, #0x044]
	cmp r0, #0x00
	blt _081058E8
_081058BC:
	asrs r4, r0, #0x10
	mov r2, r8
	ldr r1, [r2, #0x00]
	adds r0, r4, #0x0
	muls r0, r7
	adds r2, r0, r1
	ldr r1, [r2, #0x30]
	ldr r0, [sp, #0x030]
	cmp r1, r0
	bls _081058E8
	adds r0, r2, #0x0
	adds r0, #0x34
	adds r1, r2, #0x0
	movs r2, #0x34
	bl _0811F030
	subs r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r0, r6, #0x10
	cmp r0, #0x00
	bge _081058BC
_081058E8:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	mov r3, r8
	ldr r1, [r3, #0x00]
	muls r0, r7
	adds r0, r0, r1
	adds r0, #0x34
	mov r1, sp
	movs r2, #0x34
	bl _0811F030
	ldr r1, [sp, #0x044]
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r1, r2
	lsrs r2, r0, #0x10
	cmp r0, r9
	blt _08105898
_0810590C:
	add sp, #0x048
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0810591C: .4byte 0x02035C10
_08105920: .4byte 0x02035C28
_08105924: .4byte 0x0203A858
_08105928: .4byte 0x02035C20
.syntax divided
