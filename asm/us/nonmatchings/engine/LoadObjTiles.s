.syntax unified
	.align 2, 0
	.global LoadObjTiles
	.thumb
	.thumb_func
	.type LoadObjTiles, %function
LoadObjTiles: @ 080026A4
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	cmp r1, #0x00
	bne _080026BA
	b _08002834
_080026BA:
	cmp r7, #0x00
	bne _080026C0
	b _08002834
_080026C0:
	ldr r0, _080026D0 @ =0x030074C8
	ldr r0, [r0, #0x00]
	movs r1, #0xC0
	lsls r1, r1, #0x05
	adds r0, r0, r1
	bl func_08000C8C
	b _080026EC
_080026D0: .4byte 0x030074C8
_080026D4:
	ldr r0, [r5, #0x00]
	cmp r0, r7
	bne _080026E4
	adds r0, r5, #0x0
	adds r0, #0x24
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080027B4
_080026E4:
	adds r0, r5, #0x0
	adds r0, #0x0C
	bl func_08000CD4
_080026EC:
	adds r5, r0, #0x0
	cmp r5, #0x00
	bne _080026D4
	ldr r4, _08002760 @ =0x030074C8
	ldr r0, [r4, #0x00]
	movs r2, #0xC0
	lsls r2, r2, #0x05
	mov r9, r2
	add r0, r9
	bl func_08000D0C
	adds r6, r0, #0x0
	cmp r6, #0x00
	bne _0800270A
	b _08002834
_0800270A:
	movs r0, #0x00
	str r0, [r6, #0x28]
	mov r5, r8
	lsrs r1, r5, #0x05
	movs r2, #0x00
	strh r1, [r6, #0x08]
	str r7, [r6, #0x00]
	strh r0, [r6, #0x04]
	str r0, [r6, #0x20]
	adds r0, r6, #0x0
	adds r0, #0x24
	strb r2, [r0, #0x00]
	str r6, [r6, #0x2C]
	ldr r0, [r4, #0x00]
	movs r1, #0xC0
	lsls r1, r1, #0x05
	adds r0, r0, r1
	bl func_08000C8C
	adds r5, r0, #0x0
	cmp r5, #0x00
	bne _0800276C
	ldr r0, [r4, #0x00]
	ldr r2, _08002764 @ =0x00001810
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	strh r0, [r6, #0x06]
	ldrh r1, [r6, #0x06]
	lsls r1, r1, #0x05
	ldr r5, _08002768 @ =0x06010000
	adds r1, r1, r5
	adds r0, r7, #0x0
	mov r2, r8
	bl RequestDma3Copy
	adds r0, r6, #0x0
	adds r0, #0x0C
	ldr r1, [r4, #0x00]
	add r1, r9
	bl func_08000BC8
	adds r0, r6, #0x0
	b _08002836
_08002760: .4byte 0x030074C8
_08002764: .4byte 0x00001810
_08002768: .4byte 0x06010000
_0800276C:
	ldr r1, [r4, #0x00]
	ldr r0, _080027AC @ =0x00001810
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
	bgt _08002808
	ldrh r1, [r6, #0x06]
	lsls r1, r1, #0x05
	ldr r2, _080027B0 @ =0x06010000
	adds r1, r1, r2
	adds r0, r7, #0x0
	mov r2, r8
	bl RequestDma3Copy
	adds r0, r6, #0x0
	adds r0, #0x0C
	ldr r1, [r4, #0x00]
	add r1, r9
	adds r2, r5, #0x0
	adds r2, #0x0C
	bl func_08000C24
	adds r0, r6, #0x0
	b _08002836
	.byte 0x00, 0x00
_080027AC: .4byte 0x00001810
_080027B0: .4byte 0x06010000
_080027B4:
	ldrh r0, [r5, #0x04]
	adds r0, #0x01
	strh r0, [r5, #0x04]
	adds r0, r5, #0x0
	b _08002836
_080027BE:
	ldrh r1, [r6, #0x06]
	lsls r1, r1, #0x05
	ldr r5, _080027E8 @ =0x06010000
	adds r1, r1, r5
	adds r0, r7, #0x0
	mov r2, r8
	bl RequestDma3Copy
	adds r0, r6, #0x0
	adds r0, #0x0C
	ldr r1, _080027EC @ =0x030074C8
	ldr r1, [r1, #0x00]
	movs r2, #0xC0
	lsls r2, r2, #0x05
	adds r1, r1, r2
	adds r2, r4, #0x0
	bl func_08000BF4
	adds r0, r6, #0x0
	b _08002836
	.byte 0x00, 0x00
_080027E8: .4byte 0x06010000
_080027EC: .4byte 0x030074C8
_080027F0:
	cmp r3, #0x00
	beq _080027F6
	ldrh r0, [r3, #0x06]
_080027F6:
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r6, #0x08]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble _080027BE
	adds r5, r3, #0x0
_08002808:
	cmp r5, #0x00
	beq _08002834
	adds r4, r5, #0x0
	adds r4, #0x0C
	adds r0, r4, #0x0
	bl func_08000CD4
	adds r3, r0, #0x0
	ldrh r0, [r5, #0x08]
	ldrh r5, [r5, #0x06]
	adds r0, r0, r5
	strh r0, [r6, #0x06]
	ldrh r2, [r6, #0x06]
	ldrh r1, [r6, #0x08]
	adds r1, r2, r1
	ldr r0, _08002844 @ =0x030074C8
	ldr r0, [r0, #0x00]
	ldr r5, _08002848 @ =0x00001812
	adds r0, r0, r5
	ldrh r0, [r0, #0x00]
	cmp r1, r0
	ble _080027F0
_08002834:
	movs r0, #0x00
_08002836:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08002844: .4byte 0x030074C8
_08002848: .4byte 0x00001812
.syntax divided
