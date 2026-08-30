.syntax unified
	.align 2, 0
	.global func_080D35B0
	.thumb
	.thumb_func
	.type func_080D35B0, %function
func_080D35B0: @ 080D35B0
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x05C
	mov r8, r0
	ldr r1, _080D3630 @ =0x096FDB70
	mov r0, sp
	movs r2, #0x40
	bl _0811F030
	add r2, sp, #0x040
	adds r1, r2, #0x0
	ldr r0, _080D3634 @ =0x096FDBB0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r6, #0x00
	mov r3, r8
	adds r3, #0x1C
	movs r4, #0x00
	mov r2, r8
	adds r2, #0x0C
	str r3, [sp, #0x058]
	mov r9, r2
_080D35E6:
	lsls r1, r6, #0x02
	adds r0, r3, r1
	str r4, [r0, #0x00]
	adds r1, r2, r1
	str r4, [r1, #0x00]
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x03
	bls _080D35E6
	mov r4, r8
	adds r4, #0x98
	ldrb r0, [r4, #0x00]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r10, r4
	cmp r0, #0x01
	beq _080D361C
	ldrb r0, [r4, #0x00]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bne _080D364C
_080D361C:
	mov r1, r10
	ldrb r0, [r1, #0x00]
	movs r1, #0x08
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D3638
	movs r0, #0x11
	b _080D37A6
_080D3630: .4byte 0x096FDB70
_080D3634: .4byte 0x096FDBB0
_080D3638:
	mov r2, r10
	ldrb r0, [r2, #0x00]
	movs r1, #0x02
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3660
	movs r0, #0x01
	b _080D37A6
_080D364C:
	mov r3, r10
	ldrb r0, [r3, #0x00]
	movs r1, #0x02
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3660
	movs r0, #0x00
	b _080D37A6
_080D3660:
	movs r4, #0x00
	str r4, [sp, #0x050]
	movs r6, #0x00
	mov r5, r10
	str r5, [sp, #0x054]
_080D366A:
	ldr r1, [sp, #0x054]
	ldrb r0, [r1, #0x00]
	adds r1, r6, #0x0
	bl func_080D3564
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D367C
	b _080D3790
_080D367C:
	movs r0, #0x01
	lsls r0, r6
	ldr r2, [sp, #0x050]
	adds r2, r2, r0
	str r2, [sp, #0x050]
	mov r3, r10
	ldrb r0, [r3, #0x00]
	adds r1, r6, #0x0
	bl func_080D3538
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D370C
	lsls r4, r6, #0x01
	adds r4, r4, r6
	lsls r4, r4, #0x03
	adds r4, #0x2C
	add r4, r8
	ldr r7, _080D36E4 @ =0x09EF64FC
	adds r0, r4, #0x0
	ldr r1, _080D36E8 @ =0x09EF653C
	adds r2, r7, #0x0
	bl func_08005968
	lsls r5, r6, #0x02
	mov r0, sp
	adds r0, r0, r5
	adds r0, #0x40
	ldrh r1, [r0, #0x00]
	adds r0, r4, #0x0
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	ldr r4, [sp, #0x058]
	adds r1, r4, r5
	str r0, [r1, #0x00]
	mov r0, r8
	adds r0, #0x9C
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D36F0
	ldr r0, _080D36EC @ =0x0976DEDC
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl func_080026A4
	mov r2, r9
	adds r1, r2, r5
	b _080D378E
_080D36E4: .4byte 0x09EF64FC
_080D36E8: .4byte 0x09EF653C
_080D36EC: .4byte 0x0976DEDC
_080D36F0:
	adds r0, r7, #0x0
	movs r1, #0x10
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D3708 @ =0x0976DEDC
	bl func_080028F8
	mov r3, r9
	adds r1, r3, r5
	b _080D378E
_080D3708: .4byte 0x0976DEDC
_080D370C:
	ldr r4, [sp, #0x054]
	ldrb r0, [r4, #0x00]
	adds r1, r6, #0x0
	bl func_080D358C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3790
	lsls r4, r6, #0x01
	adds r4, r4, r6
	lsls r4, r4, #0x03
	adds r4, #0x2C
	add r4, r8
	ldr r7, _080D376C @ =0x09EF654C
	adds r0, r4, #0x0
	ldr r1, _080D3770 @ =0x09EF658C
	adds r2, r7, #0x0
	bl func_08005968
	lsls r5, r6, #0x02
	mov r0, sp
	adds r0, r0, r5
	adds r0, #0x40
	ldrh r1, [r0, #0x00]
	adds r0, r4, #0x0
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	ldr r2, [sp, #0x058]
	adds r1, r2, r5
	str r0, [r1, #0x00]
	mov r0, r8
	adds r0, #0x9C
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D3778
	ldr r0, _080D3774 @ =0x0976E4D4
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl func_080026A4
	mov r3, r9
	adds r1, r3, r5
	b _080D378E
	.byte 0x00, 0x00
_080D376C: .4byte 0x09EF654C
_080D3770: .4byte 0x09EF658C
_080D3774: .4byte 0x0976E4D4
_080D3778:
	adds r0, r7, #0x0
	movs r1, #0x10
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D37B8 @ =0x0976E4D4
	bl func_080028F8
	mov r4, r9
	adds r1, r4, r5
_080D378E:
	str r0, [r1, #0x00]
_080D3790:
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x03
	bhi _080D379C
	b _080D366A
_080D379C:
	ldr r5, [sp, #0x050]
	lsls r0, r5, #0x02
	add r0, sp
	ldr r0, [r0, #0x00]
	adds r0, #0x01
_080D37A6:
	add sp, #0x05C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080D37B8: .4byte 0x0976E4D4
.syntax divided
