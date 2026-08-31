.syntax unified
	.align 2, 0
	.global AllocObjTiles
	.thumb
	.thumb_func
	.type AllocObjTiles, %function
AllocObjTiles: @ 080028F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r1, #0x0
	lsls r4, r0, #0x10
	cmp r4, #0x00
	beq _080029FC
	ldr r7, _08002960 @ =0x030074C8
	ldr r0, [r7, #0x00]
	movs r1, #0xC0
	lsls r1, r1, #0x05
	mov r8, r1
	add r0, r8
	bl func_08000D0C
	adds r6, r0, #0x0
	cmp r6, #0x00
	beq _080029FC
	movs r2, #0x01
	str r2, [r6, #0x28]
	lsrs r0, r4, #0x15
	movs r1, #0x00
	strh r0, [r6, #0x08]
	str r5, [r6, #0x00]
	strh r1, [r6, #0x04]
	str r1, [r6, #0x20]
	adds r0, r6, #0x0
	adds r0, #0x24
	strb r2, [r0, #0x00]
	str r6, [r6, #0x2C]
	ldr r0, [r7, #0x00]
	movs r2, #0xC0
	lsls r2, r2, #0x05
	adds r0, r0, r2
	bl func_08000C8C
	adds r5, r0, #0x0
	cmp r5, #0x00
	bne _08002968
	ldr r1, [r7, #0x00]
	ldr r3, _08002964 @ =0x00001810
	adds r0, r1, r3
	ldrh r0, [r0, #0x00]
	strh r0, [r6, #0x06]
	adds r0, r6, #0x0
	adds r0, #0x0C
	add r1, r8
	bl func_08000BC8
	adds r0, r6, #0x0
	b _080029FE
	.byte 0x00, 0x00
_08002960: .4byte 0x030074C8
_08002964: .4byte 0x00001810
_08002968:
	ldr r2, [r7, #0x00]
	ldr r0, _08002998 @ =0x00001810
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
	bgt _080029D0
	adds r0, r6, #0x0
	adds r0, #0x0C
	mov r3, r8
	adds r1, r2, r3
	adds r2, r5, #0x0
	adds r2, #0x0C
	bl func_08000C24
	adds r0, r6, #0x0
	b _080029FE
	.byte 0x00, 0x00
_08002998: .4byte 0x00001810
_0800299C:
	adds r0, r6, #0x0
	adds r0, #0x0C
	ldr r1, _080029B4 @ =0x030074C8
	ldr r1, [r1, #0x00]
	movs r5, #0xC0
	lsls r5, r5, #0x05
	adds r1, r1, r5
	adds r2, r4, #0x0
	bl func_08000BF4
	adds r0, r6, #0x0
	b _080029FE
_080029B4: .4byte 0x030074C8
_080029B8:
	cmp r2, #0x00
	beq _080029BE
	ldrh r0, [r2, #0x06]
_080029BE:
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r6, #0x08]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble _0800299C
	adds r5, r2, #0x0
_080029D0:
	cmp r5, #0x00
	beq _080029FC
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
	ldr r0, _08002A08 @ =0x030074C8
	ldr r0, [r0, #0x00]
	ldr r5, _08002A0C @ =0x00001812
	adds r0, r0, r5
	ldrh r0, [r0, #0x00]
	cmp r1, r0
	ble _080029B8
_080029FC:
	movs r0, #0x00
_080029FE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08002A08: .4byte 0x030074C8
_08002A0C: .4byte 0x00001812
.syntax divided
