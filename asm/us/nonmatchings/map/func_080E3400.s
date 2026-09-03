.syntax unified
	.align 2, 0
	.global func_080E3400
	.thumb
	.thumb_func
	.type func_080E3400, %function
func_080E3400: @ 080E3400
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x030
	ldr r4, [sp, #0x050]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r10, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x000]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x004]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #0x008]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp, #0x00C]
	ldr r0, _080E34BC @ =0x02034F20
	ldr r1, [r0, #0x00]
	mov r2, r10
	lsls r0, r2, #0x01
	add r0, r10
	lsls r0, r0, #0x03
	adds r0, r0, r1
	ldr r0, [r0, #0x04]
	str r0, [sp, #0x020]
	movs r0, #0x60
	bl EwramAlloc
	str r0, [sp, #0x018]
	ldr r3, [sp, #0x008]
	str r3, [sp, #0x014]
	movs r0, #0x06
	str r0, [sp, #0x010]
	ldr r1, [sp, #0x004]
	lsls r5, r1, #0x10
	asrs r4, r5, #0x10
	ldr r2, _080E34C0 @ =0xFFFF0000
	adds r0, r5, r2
	asrs r0, r0, #0x10
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	bl func_080E08BC
	adds r7, r0, #0x0
	movs r1, #0x06
	ldr r2, [sp, #0x020]
	bl func_080E0900
	ldrh r1, [r7, #0x00]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r7, #0x00]
	mov r3, sp
	ldrh r0, [r3, #0x14]
	ldr r3, [sp, #0x018]
	strh r0, [r3, #0x00]
	adds r3, #0x02
	str r3, [sp, #0x01C]
	subs r4, #0x02
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	lsls r1, r7, #0x10
	ldr r2, [sp, #0x000]
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	cmp r1, r0
	ble _080E355A
	mov r9, r0
	mov r8, r5
	str r2, [sp, #0x024]
_080E3498:
	asrs r5, r1, #0x10
	ldr r3, [sp, #0x014]
	lsls r0, r3, #0x10
	asrs r6, r0, #0x10
	mov r0, r10
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl func_080E300C
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x0B
	bne _080E350C
	cmp r6, #0x03
	bgt _080E34C4
	movs r4, #0x04
	b _080E350C
	.byte 0x00, 0x00
_080E34BC: .4byte 0x02034F20
_080E34C0: .4byte 0xFFFF0000
_080E34C4:
	mov r0, r10
	cmp r0, #0x00
	bne _080E34FA
	ldr r1, [sp, #0x00C]
	cmp r1, #0x02
	bne _080E34E2
	mov r2, r9
	asrs r0, r2, #0x10
	mov r3, r8
	asrs r1, r3, #0x10
	adds r2, r5, #0x0
	movs r3, #0x01
	bl func_080E2F48
	b _080E3508
_080E34E2:
	ldr r0, [sp, #0x00C]
	cmp r0, #0x03
	bne _080E34FA
	mov r1, r9
	asrs r0, r1, #0x10
	mov r2, r8
	asrs r1, r2, #0x10
	adds r2, r5, #0x0
	movs r3, #0x01
	bl func_080E2F98
	b _080E3508
_080E34FA:
	mov r3, r9
	asrs r0, r3, #0x10
	mov r2, r8
	asrs r1, r2, #0x10
	adds r2, r5, #0x0
	bl func_080E2E24
_080E3508:
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_080E350C:
	ldr r3, [sp, #0x010]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [sp, #0x014]
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	adds r1, r4, #0x0
	bl func_080E1204
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	str r4, [sp, #0x010]
	lsls r4, r7, #0x10
	asrs r4, r4, #0x10
	lsrs r2, r1, #0x10
	str r2, [sp, #0x014]
	asrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl func_080E08BC
	adds r7, r0, #0x0
	ldr r1, [sp, #0x010]
	ldr r2, [sp, #0x020]
	bl func_080E0900
	mov r3, sp
	ldrh r0, [r3, #0x14]
	ldr r3, [sp, #0x01C]
	strh r0, [r3, #0x00]
	adds r3, #0x02
	str r3, [sp, #0x01C]
	subs r4, #0x01
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	lsls r1, r7, #0x10
	asrs r0, r1, #0x10
	ldr r2, [sp, #0x024]
	cmp r0, r2
	bgt _080E3498
_080E355A:
	ldr r3, [sp, #0x010]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [sp, #0x014]
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	movs r1, #0x04
	bl func_080E1204
	adds r4, r0, #0x0
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r1, r4, #0x0
	bl func_080E08BC
	adds r7, r0, #0x0
	movs r1, #0x04
	ldr r2, [sp, #0x020]
	bl func_080E0900
	ldrh r0, [r7, #0x00]
	movs r6, #0x10
	orrs r0, r6
	strh r0, [r7, #0x00]
	ldr r2, [sp, #0x004]
	lsls r2, r2, #0x10
	str r2, [sp, #0x028]
	asrs r5, r2, #0x10
	ldr r3, [sp, #0x000]
	lsls r3, r3, #0x10
	mov r8, r3
	asrs r3, r3, #0x10
	mov r9, r3
	subs r0, r5, r3
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r10, r4
	ldr r0, [sp, #0x008]
	lsls r1, r0, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r1, r1, r2
	subs r0, r5, #0x1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsrs r3, r1, #0x10
	str r3, [sp, #0x014]
	asrs r1, r1, #0x10
	bl func_080E08BC
	adds r7, r0, #0x0
	movs r0, #0x03
	str r0, [sp, #0x010]
	adds r0, r7, #0x0
	movs r1, #0x03
	ldr r2, [sp, #0x020]
	bl func_080E0900
	ldrh r0, [r7, #0x00]
	orrs r6, r0
	strh r6, [r7, #0x00]
	ldr r1, [sp, #0x018]
	adds r1, #0x02
	str r1, [sp, #0x01C]
	subs r5, #0x02
	lsls r5, r5, #0x10
	lsrs r7, r5, #0x10
	asrs r5, r5, #0x10
	ldr r2, [sp, #0x028]
	str r2, [sp, #0x02C]
	mov r6, r8
	cmp r5, r9
	bgt _080E35F4
	b _080E3718
_080E35F4:
	ldr r3, [sp, #0x010]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [sp, #0x014]
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	movs r1, #0x01
	bl func_080E1204
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r2, r7, #0x10
	asrs r1, r2, #0x10
	asrs r0, r6, #0x10
	subs r1, r1, r0
	adds r4, r2, #0x0
	mov r2, r10
	lsls r2, r2, #0x10
	mov r8, r2
	cmp r1, #0x01
	bne _080E362C
	asrs r0, r2, #0x10
	lsls r2, r5, #0x10
	asrs r1, r2, #0x10
	subs r0, r0, r1
	mov r9, r2
	cmp r0, #0x02
	beq _080E3652
_080E362C:
	mov r0, r8
	asrs r3, r0, #0x10
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	subs r1, r3, r2
	mov r9, r0
	cmp r1, #0x01
	bne _080E3640
	movs r4, #0x01
	b _080E36B8
_080E3640:
	cmp r2, r3
	bge _080E3662
	ldr r1, [sp, #0x01C]
	ldrh r0, [r1, #0x02]
	subs r0, r2, r0
	ldr r1, _080E3658 @ =0x0203C7B0
	ldrb r2, [r1, #0x05]
	cmp r0, r2
	bge _080E365C
_080E3652:
	movs r4, #0x03
	b _080E36B8
	.byte 0x00, 0x00
_080E3658: .4byte 0x0203C7B0
_080E365C:
	ldrb r1, [r1, #0x06]
	cmp r0, r1
	ble _080E3666
_080E3662:
	movs r4, #0x05
	b _080E36B8
_080E3666:
	cmp r0, r2
	beq _080E366E
	cmp r0, r1
	bne _080E367C
_080E366E:
	asrs r0, r4, #0x10
	ldr r2, [sp, #0x01C]
	movs r3, #0x00
	ldsh r1, [r2, r3]
	bl func_080E2F14
	b _080E36B4
_080E367C:
	ldr r0, [sp, #0x00C]
	cmp r0, #0x02
	bne _080E3692
	asrs r2, r4, #0x10
	asrs r0, r6, #0x10
	ldr r3, [sp, #0x02C]
	asrs r1, r3, #0x10
	movs r3, #0x00
	bl func_080E2F48
	b _080E36B4
_080E3692:
	ldr r0, [sp, #0x00C]
	cmp r0, #0x03
	bne _080E36A8
	asrs r2, r4, #0x10
	asrs r0, r6, #0x10
	ldr r3, [sp, #0x02C]
	asrs r1, r3, #0x10
	movs r3, #0x00
	bl func_080E2F98
	b _080E36B4
_080E36A8:
	asrs r2, r4, #0x10
	asrs r0, r6, #0x10
	ldr r3, [sp, #0x02C]
	asrs r1, r3, #0x10
	bl func_080E2E9C
_080E36B4:
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_080E36B8:
	mov r0, r9
	asrs r1, r0, #0x10
	ldr r0, _080E3760 @ =0x02034F2A
	ldrh r0, [r0, #0x00]
	subs r0, #0x01
	cmp r1, r0
	blt _080E36CC
	cmp r4, #0x03
	bne _080E36CC
	movs r4, #0x01
_080E36CC:
	ldr r1, [sp, #0x010]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	ldr r3, [sp, #0x014]
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	adds r1, r4, #0x0
	bl func_080E1204
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	str r4, [sp, #0x010]
	lsls r4, r7, #0x10
	asrs r4, r4, #0x10
	lsrs r0, r1, #0x10
	str r0, [sp, #0x014]
	asrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl func_080E08BC
	adds r7, r0, #0x0
	ldr r1, [sp, #0x010]
	ldr r2, [sp, #0x020]
	bl func_080E0900
	ldr r1, [sp, #0x01C]
	adds r1, #0x02
	str r1, [sp, #0x01C]
	ldr r0, _080E3764 @ =0xFFFF0000
	add r0, r8
	lsrs r0, r0, #0x10
	mov r10, r0
	subs r4, #0x01
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	cmp r4, r6
	ble _080E3718
	b _080E35F4
_080E3718:
	ldr r2, [sp, #0x010]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	ldr r3, [sp, #0x014]
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	movs r1, #0x05
	bl func_080E1204
	adds r1, r0, #0x0
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080E08BC
	adds r7, r0, #0x0
	movs r1, #0x05
	ldr r2, [sp, #0x020]
	bl func_080E0900
	ldrh r1, [r7, #0x00]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r7, #0x00]
	ldr r0, [sp, #0x018]
	bl EwramFree
	add sp, #0x030
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080E3760: .4byte 0x02034F2A
_080E3764: .4byte 0xFFFF0000
.syntax divided
