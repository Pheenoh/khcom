.syntax unified
	.align 2, 0
	.global func_08104D18
	.thumb
	.thumb_func
	.type func_08104D18, %function
func_08104D18: @ 08104D18
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	bl func_08104B2C
	adds r7, r0, #0x0
	ldr r6, _08104E0C @ =0x02035D84
	ldr r0, [r6, #0x00]
	cmp r0, #0x00
	beq _08104D32
	bl ReleaseObjPalette
_08104D32:
	ldr r0, _08104E10 @ =0x02035D88
	mov r8, r0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08104D40
	bl ReleaseObjTiles
_08104D40:
	ldr r1, _08104E14 @ =0x02035D94
	mov r9, r1
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08104D4E
	bl ReleaseObjTiles
_08104D4E:
	ldrh r0, [r7, #0x00]
	cmp r0, #0x8F
	beq _08104E4C
	ldr r0, _08104E18 @ =0x02035C18
	movs r1, #0x00
	ldsh r0, [r0, r1]
	bl func_08104AA4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	ble _08104E4C
	ldrh r1, [r7, #0x02]
	ldr r5, _08104E1C @ =0x08F70AB0
	movs r0, #0x34
	adds r4, r1, #0x0
	muls r4, r0
	adds r0, r5, #0x0
	adds r0, #0x08
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x00]
	adds r0, r5, #0x4
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl LoadObjTiles
	mov r1, r8
	str r0, [r1, #0x00]
	ldr r1, _08104E20 @ =0x02035D8C
	adds r0, r4, r5
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r6, _08104E24 @ =0x08F709B0
	ldrh r1, [r7, #0x04]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r1, r6, #0x0
	adds r1, #0x0C
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0xC0
	lsls r1, r1, #0x02
	bl LoadObjTiles
	mov r1, r9
	str r0, [r1, #0x00]
	ldr r2, _08104E28 @ =0x02035D98
	ldrh r1, [r7, #0x04]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r6
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	ldr r1, _08104E2C @ =0x02035DD8
	adds r0, r7, #0x0
	adds r0, #0x2E
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
	ldr r6, _08104E30 @ =0x02035DE0
	adds r5, #0x0C
	adds r4, r4, r5
	ldr r0, [r4, #0x00]
	ldr r1, _08104E34 @ =0x02035DDC
	ldr r1, [r1, #0x00]
	bl func_08065B6C
	strb r0, [r6, #0x00]
	ldr r4, _08104E38 @ =0x02035DE8
	ldr r1, _08104E3C @ =0x09EE8F48
	ldrh r0, [r7, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldr r1, _08104E40 @ =0x02035DE4
	ldr r1, [r1, #0x00]
	bl func_08065B6C
	strb r0, [r4, #0x00]
	ldr r0, _08104E44 @ =0x02035C44
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x06]
	ldrh r1, [r7, #0x04]
	lsls r1, r1, #0x05
	ldr r2, _08104E48 @ =0x09A3DE7C
	adds r1, r1, r2
	bl LoadObjPaletteBank
	b _08104E6E
_08104E0C: .4byte 0x02035D84
_08104E10: .4byte 0x02035D88
_08104E14: .4byte 0x02035D94
_08104E18: .4byte 0x02035C18
_08104E1C: .4byte 0x08F70AB0
_08104E20: .4byte 0x02035D8C
_08104E24: .4byte 0x08F709B0
_08104E28: .4byte 0x02035D98
_08104E2C: .4byte 0x02035DD8
_08104E30: .4byte 0x02035DE0
_08104E34: .4byte 0x02035DDC
_08104E38: .4byte 0x02035DE8
_08104E3C: .4byte 0x09EE8F48
_08104E40: .4byte 0x02035DE4
_08104E44: .4byte 0x02035C44
_08104E48: .4byte 0x09A3DE7C
_08104E4C:
	ldr r0, _08104E7C @ =0x02035D84
	movs r1, #0x00
	str r1, [r0, #0x00]
	ldr r0, _08104E80 @ =0x02035D88
	str r1, [r0, #0x00]
	ldr r0, _08104E84 @ =0x02035D8C
	str r1, [r0, #0x00]
	ldr r0, _08104E88 @ =0x02035D94
	str r1, [r0, #0x00]
	ldr r0, _08104E8C @ =0x02035D98
	str r1, [r0, #0x00]
	ldr r0, _08104E90 @ =0x02035DD8
	strb r1, [r0, #0x00]
	ldr r0, _08104E94 @ =0x02035DE0
	strb r1, [r0, #0x00]
	ldr r0, _08104E98 @ =0x02035DE8
	strb r1, [r0, #0x00]
_08104E6E:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08104E7C: .4byte 0x02035D84
_08104E80: .4byte 0x02035D88
_08104E84: .4byte 0x02035D8C
_08104E88: .4byte 0x02035D94
_08104E8C: .4byte 0x02035D98
_08104E90: .4byte 0x02035DD8
_08104E94: .4byte 0x02035DE0
_08104E98: .4byte 0x02035DE8
.syntax divided
