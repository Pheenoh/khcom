.syntax unified
	.align 2, 0
	.global func_080148E0
	.thumb
	.thumb_func
	.type func_080148E0, %function
func_080148E0: @ 080148E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	adds r7, r1, #0x0
	mov r8, r2
	adds r4, r3, #0x0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x00
	bne _0801499E
	bl func_08012674
	ldr r0, _08014958 @ =0x02034928
	ldr r1, [r0, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x4C
	movs r0, #0x14
	strh r0, [r2, #0x00]
	str r7, [r1, #0x10]
	mov r0, r8
	str r0, [r1, #0x14]
	str r4, [r1, #0x18]
	ldr r0, [sp, #0x020]
	str r0, [r1, #0x48]
	strh r5, [r1, #0x26]
	mov r4, sp
	adds r4, #0x06
	str r6, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	adds r2, r7, #0x0
	mov r3, r8
	bl func_0801909C
	cmp r5, #0x01
	beq _08014960
	cmp r5, #0x01
	bgt _08014980
	cmp r5, #0x00
	bne _08014980
	ldr r0, _0801495C @ =0x09EDA8A0
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	movs r0, #0x97
	lsls r0, r0, #0x02
	bl func_0811FE70
	b _08014996
	.byte 0x00, 0x00
_08014958: .4byte 0x02034928
_0801495C: .4byte 0x09EDA8A0
_08014960:
	ldr r0, _08014978 @ =0x09EDA8B8
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	ldr r0, _0801497C @ =0x0000025D
	bl func_0811FE70
	b _08014996
_08014978: .4byte 0x09EDA8B8
_0801497C: .4byte 0x0000025D
_08014980:
	ldr r0, _080149AC @ =0x09EDA8D0
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	ldr r0, _080149B0 @ =0x0000025E
	bl func_0811FE70
_08014996:
	ldr r0, _080149B4 @ =0x02034928
	ldr r1, [r0, #0x00]
	ldr r0, _080149B8 @ =0x08014851
	str r0, [r1, #0x04]
_0801499E:
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080149AC: .4byte 0x09EDA8D0
_080149B0: .4byte 0x0000025E
_080149B4: .4byte 0x02034928
_080149B8: .4byte 0x08014851
.syntax divided
