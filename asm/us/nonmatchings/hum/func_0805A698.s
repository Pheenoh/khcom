.syntax unified
	.align 2, 0
	.global func_0805A698
	.thumb
	.thumb_func
	.type func_0805A698, %function
func_0805A698: @ 0805A698
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	mov r10, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	adds r2, r0, #0x0
	lsls r0, r0, #0x10
	lsrs r4, r1, #0x10
	cmp r0, r1
	ble _0805A6B6
	adds r2, r4, #0x0
_0805A6B6:
	adds r0, r2, #0x0
	cmp r3, #0x00
	bne _0805A74C
	lsls r0, r0, #0x10
	movs r4, #0x00
	mov r8, r0
	cmp r0, #0x00
	bgt _0805A6C8
	b _0805A7C0
_0805A6C8:
	movs r7, #0x60
	mov r9, r4
	mov r6, r10
_0805A6CE:
	ldr r0, [sp, #0x020]
	cmp r0, #0x00
	beq _0805A714
	add r0, r9
	ldrh r0, [r0, #0x00]
	bl func_0805A574
	ldr r5, _0805A700 @ =0x02034934
	ldr r1, [r5, #0x00]
	ldr r2, _0805A704 @ =0x00000C68
	adds r1, r1, r2
	adds r1, r1, r4
	strb r0, [r1, #0x00]
	ldr r1, [r5, #0x00]
	adds r0, r1, r2
	adds r0, r0, r4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _0805A708
	adds r0, r4, #0x0
	mov r1, r10
	bl func_0805A638
	b _0805A72E
	.byte 0x00, 0x00
_0805A700: .4byte 0x02034934
_0805A704: .4byte 0x00000C68
_0805A708:
	ldr r0, [r6, #0x00]
	adds r1, r1, r7
	bl func_08065B6C
	ldr r1, [r5, #0x00]
	b _0805A724
_0805A714:
	ldr r0, [r6, #0x00]
	ldr r2, _0805A748 @ =0x02034934
	ldr r1, [r2, #0x00]
	adds r1, r1, r7
	bl func_08065B6C
	ldr r2, _0805A748 @ =0x02034934
	ldr r1, [r2, #0x00]
_0805A724:
	movs r2, #0xC6
	lsls r2, r2, #0x04
	adds r1, r1, r2
	adds r1, r1, r4
	strb r0, [r1, #0x00]
_0805A72E:
	movs r0, #0xC0
	lsls r0, r0, #0x01
	adds r7, r7, r0
	movs r1, #0x02
	add r9, r1
	adds r6, #0x04
	adds r4, #0x01
	mov r2, r8
	asrs r0, r2, #0x10
	cmp r4, r0
	blt _0805A6CE
	b _0805A7C0
	.byte 0x00, 0x00
_0805A748: .4byte 0x02034934
_0805A74C:
	lsls r0, r0, #0x10
	movs r4, #0x00
	mov r8, r0
	cmp r0, #0x00
	ble _0805A7C0
	adds r6, r3, #0x0
	movs r0, #0x60
	mov r9, r0
	mov r7, r10
_0805A75E:
	ldrh r0, [r6, #0x00]
	bl func_0800FF00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0805A7A4
	ldr r0, [r7, #0x00]
	ldr r5, _0805A79C @ =0x02034934
	ldr r1, [r5, #0x00]
	add r1, r9
	bl func_08065B6C
	ldr r1, [r5, #0x00]
	movs r2, #0xC6
	lsls r2, r2, #0x04
	adds r1, r1, r2
	adds r1, r1, r4
	strb r0, [r1, #0x00]
	ldrh r0, [r6, #0x00]
	bl func_0800FF70
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0805A7AC
	ldr r0, [r5, #0x00]
	ldr r1, _0805A7A0 @ =0x00000C68
	adds r0, r0, r1
	adds r0, r0, r4
	movs r1, #0x01
	strb r1, [r0, #0x00]
	b _0805A7AC
_0805A79C: .4byte 0x02034934
_0805A7A0: .4byte 0x00000C68
_0805A7A4:
	adds r0, r4, #0x0
	mov r1, r10
	bl func_0805A638
_0805A7AC:
	adds r6, #0x02
	movs r2, #0xC0
	lsls r2, r2, #0x01
	add r9, r2
	adds r7, #0x04
	adds r4, #0x01
	mov r1, r8
	asrs r0, r1, #0x10
	cmp r4, r0
	blt _0805A75E
_0805A7C0:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
