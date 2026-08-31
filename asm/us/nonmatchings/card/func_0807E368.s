.syntax unified
	.align 2, 0
	.global func_0807E368
	.thumb
	.thumb_func
	.type func_0807E368, %function
func_0807E368: @ 0807E368
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	movs r0, #0x00
	mov r8, r0
	lsls r7, r6, #0x01
	adds r0, r5, #0x0
	adds r0, #0x94
	adds r2, r0, r7
	ldrh r1, [r2, #0x00]
	ldr r0, _0807E3DC @ =0x0000FFFF
	cmp r1, r0
	beq _0807E40A
	adds r0, r5, #0x0
	adds r0, #0xA8
	adds r0, r0, r7
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	ble _0807E40A
	ldrh r0, [r2, #0x00]
	add r4, sp, #0x010
	strh r0, [r4, #0x00]
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	adds r2, r4, #0x0
	bl func_08076674
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _0807E40A
	lsls r0, r6, #0x04
	adds r0, #0x54
	adds r0, r5, r0
	str r0, [sp, #0x000]
	mov r1, sp
	ldrh r0, [r4, #0x00]
	strh r0, [r1, #0x0C]
	mov r0, sp
	strb r6, [r0, #0x0E]
	str r2, [sp, #0x004]
	adds r0, r5, #0x0
	adds r0, #0x9C
	adds r0, r0, r7
	ldrh r0, [r0, #0x00]
	strb r0, [r1, #0x0F]
	ldr r1, [r2, #0x00]
	ldr r0, _0807E3E0 @ =0x0000FFFE
	cmp r1, r0
	bne _0807E3EC
	ldr r4, _0807E3E4 @ =0x02034AAC
	ldr r1, _0807E3E8 @ =0x09EE49FC
	b _0807E3F0
	.byte 0x00, 0x00
_0807E3DC: .4byte 0x0000FFFF
_0807E3E0: .4byte 0x0000FFFE
_0807E3E4: .4byte 0x02034AAC
_0807E3E8: .4byte 0x09EE49FC
_0807E3EC:
	ldr r4, _0807E41C @ =0x02034AAC
	ldr r1, _0807E420 @ =0x09EE49CC
_0807E3F0:
	adds r0, r5, #0x0
	mov r2, sp
	bl TaskCreate
	ldr r0, [r0, #0x04]
	str r0, [r4, #0x00]
	mov r1, r8
	lsls r0, r1, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	mov r8, r0
_0807E40A:
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0x00
	beq _0807E424
	cmp r4, #0x01
	beq _0807E48C
	b _0807E4B2
	.byte 0x00, 0x00
_0807E41C: .4byte 0x02034AAC
_0807E420: .4byte 0x09EE49CC
_0807E424:
	lsls r0, r6, #0x04
	adds r0, #0x54
	adds r0, r5, r0
	str r0, [sp, #0x000]
	mov r1, sp
	ldr r0, _0807E478 @ =0x0000FFFF
	strh r0, [r1, #0x0C]
	lsls r1, r6, #0x02
	adds r0, r5, #0x0
	adds r0, #0x44
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x004]
	mov r0, sp
	strb r6, [r0, #0x0E]
	ldr r1, _0807E47C @ =0x09EE49E4
	adds r0, r5, #0x0
	mov r2, sp
	bl TaskCreate
	ldr r3, [r0, #0x04]
	adds r2, r3, #0x0
	adds r2, #0x98
	adds r1, r3, #0x0
	adds r1, #0x94
	ldr r0, _0807E480 @ =0x090352E4
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	str r0, [r2, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xA4
	strb r4, [r0, #0x00]
	adds r1, #0x0C
	movs r0, #0x32
	strb r0, [r1, #0x00]
	ldr r0, [r3, #0x78]
	ldr r1, _0807E484 @ =0x00000802
	orrs r0, r1
	str r0, [r3, #0x78]
	ldr r0, _0807E488 @ =0x02034AAC
	str r3, [r0, #0x00]
	b _0807E4B2
_0807E478: .4byte 0x0000FFFF
_0807E47C: .4byte 0x09EE49E4
_0807E480: .4byte 0x090352E4
_0807E484: .4byte 0x00000802
_0807E488: .4byte 0x02034AAC
_0807E48C:
	ldr r3, _0807E4C0 @ =0x02034AAC
	ldr r4, [r3, #0x00]
	adds r2, r4, #0x0
	adds r2, #0x98
	adds r1, r4, #0x0
	adds r1, #0x94
	ldr r0, _0807E4C4 @ =0x090352E4
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	str r0, [r2, #0x00]
	adds r1, #0x0C
	movs r0, #0x32
	strb r0, [r1, #0x00]
	ldr r2, [r3, #0x00]
	ldr r0, [r2, #0x78]
	movs r1, #0x80
	lsls r1, r1, #0x04
	orrs r0, r1
	str r0, [r2, #0x78]
_0807E4B2:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0807E4C0: .4byte 0x02034AAC
_0807E4C4: .4byte 0x090352E4
.syntax divided
