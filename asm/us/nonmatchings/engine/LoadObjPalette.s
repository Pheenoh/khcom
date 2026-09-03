.syntax unified
	.align 2, 0
	.global LoadObjPalette
	.thumb
	.thumb_func
	.type LoadObjPalette, %function
LoadObjPalette: @ 08002A14
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	cmp r1, #0x00
	bne _08002A2A
	b _08002B94
_08002A2A:
	cmp r7, #0x00
	bne _08002A30
	b _08002B94
_08002A30:
	ldr r0, _08002A40 @ =0x030074C8
	ldr r0, [r0, #0x00]
	ldr r1, _08002A44 @ =0x00001A94
	adds r0, r0, r1
	bl ListPoolFirst
	b _08002A56
	.byte 0x00, 0x00
_08002A40: .4byte 0x030074C8
_08002A44: .4byte 0x00001A94
_08002A48:
	ldr r0, [r5, #0x00]
	cmp r0, r7
	beq _08002B14
	adds r0, r5, #0x0
	adds r0, #0x0C
	bl ListPoolNext
_08002A56:
	adds r5, r0, #0x0
	cmp r5, #0x00
	bne _08002A48
	ldr r4, _08002ABC @ =0x030074C8
	ldr r0, [r4, #0x00]
	ldr r2, _08002AC0 @ =0x00001A94
	mov r9, r2
	add r0, r9
	bl ListPoolFirstFree
	adds r6, r0, #0x0
	cmp r6, #0x00
	bne _08002A72
	b _08002B94
_08002A72:
	movs r1, #0x00
	str r1, [r6, #0x20]
	mov r5, r8
	lsrs r0, r5, #0x05
	strh r0, [r6, #0x08]
	str r7, [r6, #0x00]
	strh r1, [r6, #0x04]
	str r6, [r6, #0x24]
	ldr r0, [r4, #0x00]
	ldr r1, _08002AC0 @ =0x00001A94
	adds r0, r0, r1
	bl ListPoolFirst
	adds r5, r0, #0x0
	cmp r5, #0x00
	bne _08002ACC
	ldr r0, [r4, #0x00]
	ldr r2, _08002AC4 @ =0x00001AA4
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	strh r0, [r6, #0x06]
	ldrh r1, [r6, #0x06]
	lsls r1, r1, #0x05
	ldr r5, _08002AC8 @ =0x05000200
	adds r1, r1, r5
	adds r0, r7, #0x0
	mov r2, r8
	bl LoadPalette
	adds r0, r6, #0x0
	adds r0, #0x0C
	ldr r1, [r4, #0x00]
	add r1, r9
	bl ListPoolActivate
	adds r0, r6, #0x0
	b _08002B96
_08002ABC: .4byte 0x030074C8
_08002AC0: .4byte 0x00001A94
_08002AC4: .4byte 0x00001AA4
_08002AC8: .4byte 0x05000200
_08002ACC:
	ldr r1, [r4, #0x00]
	ldr r0, _08002B0C @ =0x00001AA4
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	strh r0, [r6, #0x06]
	ldrh r0, [r5, #0x06]
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	ldrh r1, [r6, #0x08]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bgt _08002B68
	ldrh r1, [r6, #0x06]
	lsls r1, r1, #0x05
	ldr r2, _08002B10 @ =0x05000200
	adds r1, r1, r2
	adds r0, r7, #0x0
	mov r2, r8
	bl LoadPalette
	adds r0, r6, #0x0
	adds r0, #0x0C
	ldr r1, [r4, #0x00]
	add r1, r9
	adds r2, r5, #0x0
	adds r2, #0x0C
	bl ListPoolActivateBefore
	adds r0, r6, #0x0
	b _08002B96
	.byte 0x00, 0x00
_08002B0C: .4byte 0x00001AA4
_08002B10: .4byte 0x05000200
_08002B14:
	ldrh r0, [r5, #0x04]
	adds r0, #0x01
	strh r0, [r5, #0x04]
	adds r0, r5, #0x0
	b _08002B96
_08002B1E:
	ldrh r1, [r6, #0x06]
	lsls r1, r1, #0x05
	ldr r5, _08002B44 @ =0x05000200
	adds r1, r1, r5
	adds r0, r7, #0x0
	mov r2, r8
	bl LoadPalette
	adds r0, r6, #0x0
	adds r0, #0x0C
	ldr r1, _08002B48 @ =0x030074C8
	ldr r1, [r1, #0x00]
	ldr r2, _08002B4C @ =0x00001A94
	adds r1, r1, r2
	adds r2, r4, #0x0
	bl ListPoolActivateAfter
	adds r0, r6, #0x0
	b _08002B96
_08002B44: .4byte 0x05000200
_08002B48: .4byte 0x030074C8
_08002B4C: .4byte 0x00001A94
_08002B50:
	cmp r3, #0x00
	beq _08002B56
	ldrh r0, [r3, #0x06]
_08002B56:
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r6, #0x08]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble _08002B1E
	adds r5, r3, #0x0
_08002B68:
	cmp r5, #0x00
	beq _08002B94
	adds r4, r5, #0x0
	adds r4, #0x0C
	adds r0, r4, #0x0
	bl ListPoolNext
	adds r3, r0, #0x0
	ldrh r0, [r5, #0x08]
	ldrh r5, [r5, #0x06]
	adds r0, r0, r5
	strh r0, [r6, #0x06]
	ldrh r2, [r6, #0x06]
	ldrh r1, [r6, #0x08]
	adds r1, r2, r1
	ldr r0, _08002BA4 @ =0x030074C8
	ldr r0, [r0, #0x00]
	ldr r5, _08002BA8 @ =0x00001AA6
	adds r0, r0, r5
	ldrh r0, [r0, #0x00]
	cmp r1, r0
	ble _08002B50
_08002B94:
	movs r0, #0x00
_08002B96:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08002BA4: .4byte 0x030074C8
_08002BA8: .4byte 0x00001AA6
.syntax divided
