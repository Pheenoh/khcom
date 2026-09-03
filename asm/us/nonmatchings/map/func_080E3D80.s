.syntax unified
	.align 2, 0
	.global func_080E3D80
	.thumb
	.thumb_func
	.type func_080E3D80, %function
func_080E3D80: @ 080E3D80
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x02C
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	str r2, [sp, #0x008]
	str r3, [sp, #0x00C]
	movs r0, #0x00
	str r0, [sp, #0x010]
	movs r1, #0x00
	str r1, [sp, #0x014]
	movs r2, #0x00
	str r2, [sp, #0x018]
	mov r9, r2
	str r0, [sp, #0x01C]
	mov r10, r0
	mov r8, r0
	movs r7, #0x00
	ldr r0, _080E3DBC @ =0x02034F28
	adds r1, r0, #0x0
	ldrh r2, [r1, #0x00]
	cmp r9, r2
	bge _080E3E00
_080E3DB4:
	ldr r0, _080E3DC0 @ =0x02034F2A
	ldrh r0, [r0, #0x00]
	subs r4, r0, #0x1
	b _080E3DCA
_080E3DBC: .4byte 0x02034F28
_080E3DC0: .4byte 0x02034F2A
_080E3DC4:
	cmp r1, #0x0B
	bne _080E3DF0
	subs r4, #0x01
_080E3DCA:
	cmp r4, #0x00
	blt _080E3DF0
	lsls r6, r7, #0x10
	asrs r0, r6, #0x10
	lsls r5, r4, #0x10
	asrs r1, r5, #0x10
	bl func_080E08BC
	ldrb r1, [r0, #0x02]
	cmp r1, #0x03
	bne _080E3DC4
	lsrs r6, r6, #0x10
	str r6, [sp, #0x010]
	lsrs r5, r5, #0x10
	str r5, [sp, #0x014]
	ldr r0, [r0, #0x08]
	str r0, [sp, #0x01C]
	movs r0, #0x01
	mov r8, r0
_080E3DF0:
	ldr r1, _080E3E28 @ =0x02034F28
	mov r2, r8
	cmp r2, #0x00
	bne _080E3E00
	adds r7, #0x01
	ldrh r0, [r1, #0x00]
	cmp r7, r0
	blt _080E3DB4
_080E3E00:
	movs r0, #0x00
	mov r8, r0
	ldrh r0, [r1, #0x00]
	subs r7, r0, #0x1
	ldr r1, [sp, #0x014]
	lsls r1, r1, #0x10
	str r1, [sp, #0x020]
	cmp r7, #0x00
	blt _080E3E72
	lsls r0, r7, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r3, r0, r2
_080E3E1A:
	ldr r0, _080E3E2C @ =0x02034F2A
	ldrh r0, [r0, #0x00]
	subs r4, r0, #0x1
	adds r2, r3, #0x0
	lsls r6, r7, #0x10
	b _080E3E36
	.byte 0x00, 0x00
_080E3E28: .4byte 0x02034F28
_080E3E2C: .4byte 0x02034F2A
_080E3E30:
	cmp r1, #0x0B
	bne _080E3E62
	subs r4, #0x01
_080E3E36:
	cmp r4, #0x00
	blt _080E3E62
	lsls r5, r4, #0x10
	asrs r1, r5, #0x10
	asrs r0, r6, #0x10
	str r2, [sp, #0x024]
	str r3, [sp, #0x028]
	bl func_080E08BC
	ldrb r1, [r0, #0x02]
	ldr r2, [sp, #0x024]
	ldr r3, [sp, #0x028]
	cmp r1, #0x05
	bne _080E3E30
	lsrs r2, r2, #0x10
	str r2, [sp, #0x018]
	lsrs r5, r5, #0x10
	mov r9, r5
	ldr r0, [r0, #0x08]
	mov r10, r0
	movs r0, #0x01
	mov r8, r0
_080E3E62:
	mov r1, r8
	cmp r1, #0x00
	bne _080E3E72
	ldr r2, _080E3EC8 @ =0xFFFF0000
	adds r3, r3, r2
	subs r7, #0x01
	cmp r7, #0x00
	bge _080E3E1A
_080E3E72:
	ldr r0, [sp, #0x020]
	asrs r2, r0, #0x10
	ldr r0, _080E3ECC @ =0x02034F2A
	ldrh r1, [r0, #0x00]
	lsrs r0, r1, #0x02
	subs r1, r1, r0
	cmp r2, r1
	bgt _080E3EE8
	mov r2, r9
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, r1
	bgt _080E3EE8
	ldr r0, [sp, #0x018]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	ldr r2, [sp, #0x010]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	cmp r1, #0x04
	ble _080E3EE8
	ldr r0, [sp, #0x000]
	strh r2, [r0, #0x00]
	mov r1, sp
	ldrh r2, [r1, #0x18]
	ldr r1, [sp, #0x004]
	strh r2, [r1, #0x00]
	ldr r0, [sp, #0x01C]
	cmp r0, r10
	ble _080E3ED0
	cmp r0, #0x00
	bge _080E3EB6
	adds r0, #0x0F
_080E3EB6:
	asrs r0, r0, #0x0C
	ldr r1, [sp, #0x00C]
	strh r0, [r1, #0x00]
	mov r2, sp
	ldrh r0, [r2, #0x14]
	ldr r2, [sp, #0x008]
	strh r0, [r2, #0x00]
	movs r0, #0x01
	b _080E3EEA
_080E3EC8: .4byte 0xFFFF0000
_080E3ECC: .4byte 0x02034F2A
_080E3ED0:
	mov r0, r10
	cmp r0, #0x00
	bge _080E3ED8
	adds r0, #0x0F
_080E3ED8:
	asrs r0, r0, #0x0C
	ldr r1, [sp, #0x00C]
	strh r0, [r1, #0x00]
	mov r0, r9
	ldr r2, [sp, #0x008]
	strh r0, [r2, #0x00]
	movs r0, #0x02
	b _080E3EEA
_080E3EE8:
	movs r0, #0x00
_080E3EEA:
	add sp, #0x02C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
