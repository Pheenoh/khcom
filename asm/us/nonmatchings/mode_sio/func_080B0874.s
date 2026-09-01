.syntax unified
	.align 2, 0
	.global func_080B0874
	.thumb
	.thumb_func
	.type func_080B0874, %function
func_080B0874: @ 080B0874
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	bl GetActiveDeckIndex
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r6, _080B099C @ =0x02039B58
	ldr r7, _080B09A0 @ =0x0203AA8C
	ldrb r4, [r7, #0x00]
	movs r1, #0x0F
	ands r1, r4
	lsls r1, r1, #0x0C
	ldrh r2, [r6, #0x04]
	orrs r1, r2
	strh r1, [r6, #0x04]
	ldr r5, _080B09A4 @ =0x02039DE0
	movs r2, #0x00
	ldsb r2, [r7, r2]
	subs r2, #0x01
	lsls r2, r2, #0x01
	lsls r1, r0, #0x03
	subs r1, r1, r0
	lsls r1, r1, #0x05
	adds r0, r2, r1
	adds r5, #0xC6
	adds r0, r0, r5
	ldrb r3, [r0, #0x00]
	adds r1, #0x01
	adds r2, r2, r1
	adds r2, r2, r5
	ldrb r0, [r2, #0x00]
	lsls r0, r0, #0x08
	orrs r3, r0
	strh r3, [r6, #0x06]
	adds r4, #0x01
	strb r4, [r7, #0x00]
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	cmp r4, #0x0A
	ble _080B08CA
	movs r0, #0x01
	strb r0, [r7, #0x00]
_080B08CA:
	ldr r5, _080B09A8 @ =0x02039810
	ldrh r0, [r5, #0x08]
	lsrs r0, r0, #0x0C
	cmp r0, #0x00
	beq _080B0926
	subs r2, r0, #0x1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r4, _080B09AC @ =0x0203AAE0
	lsls r1, r2, #0x01
	adds r3, r1, r4
	ldrh r0, [r5, #0x0C]
	strb r0, [r3, #0x00]
	adds r1, #0x01
	adds r1, r1, r4
	ldrh r0, [r5, #0x0C]
	lsrs r0, r0, #0x08
	strb r0, [r1, #0x00]
	cmp r2, #0x09
	bne _080B0926
	movs r3, #0x00
	ldr r7, _080B09B0 @ =0x0203AA30
	ldr r0, _080B09B4 @ =0x02034B40
	mov r8, r0
	ldr r6, _080B09B8 @ =0x0203AA60
	adds r5, r4, #0x0
	adds r4, r7, #0x0
_080B0900:
	adds r2, r3, r6
	adds r0, r3, r5
	ldrb r1, [r0, #0x00]
	strb r1, [r2, #0x00]
	adds r0, r3, r4
	strb r1, [r0, #0x00]
	adds r3, #0x01
	cmp r3, #0x13
	ble _080B0900
	mov r2, r8
	ldr r1, [r2, #0x00]
	adds r1, #0xFC
	adds r0, r7, #0x0
	bl func_08065B6C
	mov r2, r8
	ldr r1, [r2, #0x00]
	adds r1, #0xF8
	strb r0, [r1, #0x00]
_080B0926:
	ldr r5, _080B09A8 @ =0x02039810
	ldrh r0, [r5, #0x0A]
	lsrs r0, r0, #0x0C
	cmp r0, #0x00
	beq _080B0990
	subs r2, r0, #0x1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, _080B09AC @ =0x0203AAE0
	lsls r1, r2, #0x01
	adds r4, r0, #0x0
	adds r4, #0x14
	adds r3, r1, r4
	ldrh r0, [r5, #0x0E]
	strb r0, [r3, #0x00]
	adds r1, #0x01
	adds r1, r1, r4
	ldrh r0, [r5, #0x0E]
	lsrs r0, r0, #0x08
	strb r0, [r1, #0x00]
	cmp r2, #0x09
	bne _080B0990
	movs r3, #0x00
	ldr r7, _080B09B0 @ =0x0203AA30
	ldr r0, _080B09B4 @ =0x02034B40
	mov r8, r0
	adds r7, #0x14
	ldr r6, _080B09BC @ =0x0203AA74
	adds r5, r4, #0x0
	adds r4, r7, #0x0
_080B0962:
	adds r2, r3, r6
	adds r0, r3, r5
	ldrb r1, [r0, #0x00]
	strb r1, [r2, #0x00]
	adds r0, r3, r4
	strb r1, [r0, #0x00]
	adds r3, #0x01
	cmp r3, #0x13
	ble _080B0962
	mov r2, r8
	ldr r1, [r2, #0x00]
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r1, r1, r0
	adds r0, r7, #0x0
	bl func_08065B6C
	mov r2, r8
	ldr r1, [r2, #0x00]
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r1, r1, r2
	strb r0, [r1, #0x00]
_080B0990:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B099C: .4byte 0x02039B58
_080B09A0: .4byte 0x0203AA8C
_080B09A4: .4byte 0x02039DE0
_080B09A8: .4byte 0x02039810
_080B09AC: .4byte 0x0203AAE0
_080B09B0: .4byte 0x0203AA30
_080B09B4: .4byte 0x02034B40
_080B09B8: .4byte 0x0203AA60
_080B09BC: .4byte 0x0203AA74
.syntax divided
