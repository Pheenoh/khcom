.syntax unified
	.align 2, 0
	.global func_08003970
	.thumb
	.thumb_func
	.type func_08003970, %function
func_08003970: @ 08003970
	push {r4, r5, r6, r7, lr}
	lsls r5, r0, #0x10
	ldr r4, _080039C0 @ =0x030074C8
	ldr r0, [r4, #0x00]
	ldr r7, _080039C4 @ =0x00001A94
	adds r0, r0, r7
	bl func_08000D0C
	adds r6, r0, #0x0
	cmp r6, #0x00
	beq _08003A60
	movs r0, #0x02
	str r0, [r6, #0x20]
	lsrs r0, r5, #0x15
	movs r1, #0x00
	strh r0, [r6, #0x08]
	str r1, [r6, #0x00]
	strh r1, [r6, #0x04]
	str r6, [r6, #0x24]
	ldr r0, [r4, #0x00]
	ldr r1, _080039C4 @ =0x00001A94
	adds r0, r0, r1
	bl func_08000C8C
	adds r5, r0, #0x0
	cmp r5, #0x00
	bne _080039CC
	ldr r1, [r4, #0x00]
	ldr r2, _080039C8 @ =0x00001AA4
	adds r0, r1, r2
	ldrh r0, [r0, #0x00]
	strh r0, [r6, #0x06]
	adds r0, r6, #0x0
	adds r0, #0x0C
	adds r1, r1, r7
	bl func_08000BC8
	adds r0, r6, #0x0
	b _08003A62
	.byte 0x00, 0x00
_080039C0: .4byte 0x030074C8
_080039C4: .4byte 0x00001A94
_080039C8: .4byte 0x00001AA4
_080039CC:
	ldr r2, [r4, #0x00]
	ldr r0, _080039F8 @ =0x00001AA4
	adds r1, r2, r0
	ldrh r0, [r1, #0x00]
	strh r0, [r6, #0x06]
	ldrh r0, [r5, #0x06]
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	ldrh r1, [r6, #0x08]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bgt _08003A34
	adds r0, r6, #0x0
	adds r0, #0x0C
	adds r1, r2, r7
	adds r2, r5, #0x0
	adds r2, #0x0C
	bl func_08000C24
	adds r0, r6, #0x0
	b _08003A62
_080039F8: .4byte 0x00001AA4
_080039FC:
	adds r0, r6, #0x0
	adds r0, #0x0C
	ldr r1, _08003A14 @ =0x030074C8
	ldr r1, [r1, #0x00]
	ldr r2, _08003A18 @ =0x00001A94
	adds r1, r1, r2
	adds r2, r4, #0x0
	bl func_08000BF4
	adds r0, r6, #0x0
	b _08003A62
	.byte 0x00, 0x00
_08003A14: .4byte 0x030074C8
_08003A18: .4byte 0x00001A94
_08003A1C:
	cmp r2, #0x00
	beq _08003A22
	ldrh r0, [r2, #0x06]
_08003A22:
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r6, #0x08]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble _080039FC
	adds r5, r2, #0x0
_08003A34:
	cmp r5, #0x00
	beq _08003A60
	adds r4, r5, #0x0
	adds r4, #0x0C
	adds r0, r4, #0x0
	bl func_08000CD4
	adds r2, r0, #0x0
	ldrh r0, [r5, #0x08]
	ldrh r5, [r5, #0x06]
	adds r0, r0, r5
	strh r0, [r6, #0x06]
	ldrh r3, [r6, #0x06]
	ldrh r1, [r6, #0x08]
	adds r1, r3, r1
	ldr r0, _08003A68 @ =0x030074C8
	ldr r0, [r0, #0x00]
	ldr r5, _08003A6C @ =0x00001AA6
	adds r0, r0, r5
	ldrh r0, [r0, #0x00]
	cmp r1, r0
	ble _08003A1C
_08003A60:
	movs r0, #0x00
_08003A62:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08003A68: .4byte 0x030074C8
_08003A6C: .4byte 0x00001AA6
.syntax divided
