.syntax unified
	.align 2, 0
	.global func_080858B8
	.thumb
	.thumb_func
	.type func_080858B8, %function
func_080858B8: @ 080858B8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0x0
	movs r5, #0x00
	bl GetActiveDeck
	adds r6, r0, #0x0
	cmp r4, #0x00
	beq _080858D2
	cmp r4, #0x01
	beq _08085934
	b _08085982
_080858D2:
	movs r1, #0x00
	ldr r0, _08085924 @ =0x0000FFFF
	mov r8, r0
	ldr r7, _08085928 @ =0x08F70AB0
	ldr r0, _0808592C @ =0x00000FFF
	mov r12, r0
	ldr r4, _08085930 @ =0x0203A080
_080858E0:
	lsls r0, r1, #0x10
	asrs r1, r0, #0x0F
	adds r2, r1, r6
	ldrh r1, [r2, #0x00]
	adds r3, r0, #0x0
	cmp r1, r8
	beq _08085912
	adds r0, r1, #0x0
	lsls r0, r0, #0x01
	adds r0, r0, r4
	ldrh r1, [r0, #0x00]
	mov r0, r12
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	adds r0, r0, r7
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bhi _08085912
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r5, r0, #0x10
_08085912:
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r3, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x62
	ble _080858E0
	b _08085982
	.byte 0x00, 0x00
_08085924: .4byte 0x0000FFFF
_08085928: .4byte 0x08F70AB0
_0808592C: .4byte 0x00000FFF
_08085930: .4byte 0x0203A080
_08085934:
	movs r1, #0x00
	ldr r0, _08085990 @ =0x0000FFFF
	mov r8, r0
	ldr r7, _08085994 @ =0x08F70AB0
	ldr r0, _08085998 @ =0x00000FFF
	mov r12, r0
	ldr r4, _0808599C @ =0x0203A080
_08085942:
	lsls r0, r1, #0x10
	asrs r1, r0, #0x0F
	adds r2, r1, r6
	ldrh r1, [r2, #0x00]
	adds r3, r0, #0x0
	cmp r1, r8
	beq _08085974
	adds r0, r1, #0x0
	lsls r0, r0, #0x01
	adds r0, r0, r4
	ldrh r1, [r0, #0x00]
	mov r0, r12
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	adds r0, r0, r7
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _08085974
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r5, r0, #0x10
_08085974:
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r3, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x62
	ble _08085942
_08085982:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08085990: .4byte 0x0000FFFF
_08085994: .4byte 0x08F70AB0
_08085998: .4byte 0x00000FFF
_0808599C: .4byte 0x0203A080
.syntax divided
