.syntax unified
	.align 2, 0
	.global func_08105090
	.thumb
	.thumb_func
	.type func_08105090, %function
func_08105090: @ 08105090
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	bl func_08104B2C
	adds r4, r0, #0x0
	ldr r5, _08105108 @ =0x02035C18
	movs r1, #0x00
	ldsh r0, [r5, r1]
	bl func_08104AA4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	ble _081050BA
	ldrh r0, [r4, #0x04]
	lsls r0, r0, #0x05
	ldr r1, _0810510C @ =0x09A3DD7C
	adds r0, r0, r1
	ldr r1, _08105110 @ =0x050000E0
	movs r2, #0x0C
	bl LoadPalette
_081050BA:
	ldr r0, _08105114 @ =0x02035C16
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x01
	bne _08105158
	movs r6, #0x00
_081050C6:
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	lsls r4, r6, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #0x06
	movs r1, #0xD0
	lsls r1, r1, #0x02
	adds r0, r0, r1
	adds r2, r2, r0
	movs r0, #0x02
	str r0, [sp, #0x000]
	movs r0, #0x00
	ldr r1, _08105118 @ =0x09A1DF7C
	movs r3, #0x20
	bl func_08101588
	lsls r1, r4, #0x01
	ldr r2, _0810511C @ =0x050000EC
	adds r1, r1, r2
	ldr r0, _08105120 @ =0x09A3DE08
	movs r2, #0x02
	bl LoadPalette
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x09
	ble _081050C6
	b _081052B4
	.byte 0x00, 0x00
_08105108: .4byte 0x02035C18
_0810510C: .4byte 0x09A3DD7C
_08105110: .4byte 0x050000E0
_08105114: .4byte 0x02035C16
_08105118: .4byte 0x09A1DF7C
_0810511C: .4byte 0x050000EC
_08105120: .4byte 0x09A3DE08
_08105124:
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	movs r0, #0xD0
	lsls r0, r0, #0x02
	adds r2, r2, r0
	ldr r1, _0810514C @ =0x09A1DF9C
	movs r0, #0x02
	str r0, [sp, #0x000]
	adds r0, r5, #0x0
	movs r3, #0x20
	bl func_08101588
	ldr r0, _08105150 @ =0x09A3DD88
	ldr r1, _08105154 @ =0x050000EC
	movs r2, #0x02
	bl LoadPalette
	b _081051A8
_0810514C: .4byte 0x09A1DF9C
_08105150: .4byte 0x09A3DD88
_08105154: .4byte 0x050000EC
_08105158:
	ldrh r0, [r4, #0x04]
	cmp r0, #0x03
	bne _081051F0
	movs r1, #0x00
	ldsh r0, [r5, r1]
	bl func_08104AA4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	ble _08105178
	ldr r1, _081051DC @ =0x09A3BD5C
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x01
	bl LoadBgMap
_08105178:
	movs r6, #0x00
	adds r7, r4, #0x6
_0810517C:
	lsls r0, r6, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #0x02
	adds r0, r7, r0
	movs r2, #0x00
	ldsh r5, [r0, r2]
	cmp r5, #0x00
	beq _0810519C
	ldr r0, _081051E0 @ =0x02035C18
	movs r1, #0x00
	ldsh r0, [r0, r1]
	bl func_08104AA4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bgt _08105124
_0810519C:
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x09
	ble _0810517C
_081051A8:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x09
	bgt _081051B2
	b _081052B4
_081051B2:
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	movs r0, #0xD0
	lsls r0, r0, #0x02
	adds r2, r2, r0
	ldr r1, _081051E4 @ =0x09A1DF7C
	movs r0, #0x02
	str r0, [sp, #0x000]
	movs r0, #0x00
	movs r3, #0x20
	bl func_08101588
	ldr r0, _081051E8 @ =0x09A3DE08
	ldr r1, _081051EC @ =0x050000EC
	movs r2, #0x02
	bl LoadPalette
	b _081052B4
	.byte 0x00, 0x00
_081051DC: .4byte 0x09A3BD5C
_081051E0: .4byte 0x02035C18
_081051E4: .4byte 0x09A1DF7C
_081051E8: .4byte 0x09A3DE08
_081051EC: .4byte 0x050000EC
_081051F0:
	movs r1, #0x00
	ldsh r0, [r5, r1]
	bl func_08104AA4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	ble _0810520A
	ldr r1, _08105260 @ =0x09A3B85C
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x01
	bl LoadBgMap
_0810520A:
	movs r6, #0x00
	adds r7, r4, #0x6
_0810520E:
	lsls r1, r6, #0x10
	asrs r4, r1, #0x10
	lsls r0, r4, #0x02
	adds r0, r7, r0
	movs r2, #0x00
	ldsh r5, [r0, r2]
	adds r6, r1, #0x0
	cmp r5, #0x00
	beq _08105274
	ldr r0, _08105264 @ =0x02035C18
	movs r1, #0x00
	ldsh r0, [r0, r1]
	bl func_08104AA4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	ble _08105274
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	lsls r0, r4, #0x06
	movs r1, #0xD0
	lsls r1, r1, #0x02
	adds r0, r0, r1
	adds r2, r2, r0
	movs r0, #0x02
	str r0, [sp, #0x000]
	adds r0, r5, #0x0
	ldr r1, _08105268 @ =0x09A1DF9C
	movs r3, #0x20
	bl func_08101588
	lsls r1, r4, #0x01
	ldr r2, _0810526C @ =0x050000EC
	adds r1, r1, r2
	ldr r0, _08105270 @ =0x09A3DD88
	movs r2, #0x02
	bl LoadPalette
	b _081052A6
_08105260: .4byte 0x09A3B85C
_08105264: .4byte 0x02035C18
_08105268: .4byte 0x09A1DF9C
_0810526C: .4byte 0x050000EC
_08105270: .4byte 0x09A3DD88
_08105274:
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	asrs r4, r6, #0x10
	lsls r0, r4, #0x06
	movs r1, #0xD0
	lsls r1, r1, #0x02
	adds r0, r0, r1
	adds r2, r2, r0
	movs r0, #0x02
	str r0, [sp, #0x000]
	movs r0, #0x00
	ldr r1, _081052BC @ =0x09A1DF7C
	movs r3, #0x20
	bl func_08101588
	lsls r4, r4, #0x01
	ldr r2, _081052C0 @ =0x050000EC
	adds r4, r4, r2
	ldr r0, _081052C4 @ =0x09A3DE08
	adds r1, r4, #0x0
	movs r2, #0x02
	bl LoadPalette
_081052A6:
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r6, r1
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x09
	ble _0810520E
_081052B4:
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_081052BC: .4byte 0x09A1DF7C
_081052C0: .4byte 0x050000EC
_081052C4: .4byte 0x09A3DE08
.syntax divided
