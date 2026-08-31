.syntax unified
	.align 2, 0
	.global task_poo_cabbage_2
	.thumb
	.thumb_func
	.type task_poo_cabbage_2, %function
task_poo_cabbage_2: @ 080D14A0
	push {r4, r5, r6, r7, lr}
	add sp, #-0x01C
	adds r5, r0, #0x0
	ldr r1, _080D150C @ =0x096FD86E
	add r0, sp, #0x010
	movs r2, #0x0A
	bl memcpy
	ldr r2, [r5, #0x24]
	asrs r2, r2, #0x08
	ldr r0, _080D1510 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldr r1, [r5, #0x28]
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x2C]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	ldr r0, _080D1514 @ =0x0203C3F8
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsrs r7, r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x0D
	adds r2, r2, r0
	movs r0, #0x88
	lsls r0, r0, #0x11
	cmp r2, r0
	bhi _080D14F2
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	movs r1, #0x24
	negs r1, r1
	adds r4, r0, #0x0
	cmp r2, r1
	blt _080D14F2
	cmp r2, #0xC4
	ble _080D1518
_080D14F2:
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	beq _080D15E2
	ldr r0, [r5, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r5, #0x04]
	bl ReleaseObjPalette
	movs r0, #0x00
	str r0, [r5, #0x04]
	b _080D15E2
	.byte 0x00, 0x00
_080D150C: .4byte 0x096FD86E
_080D1510: .4byte 0x0203C40C
_080D1514: .4byte 0x0203C3F8
_080D1518:
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	bne _080D1534
	ldr r0, _080D1584 @ =0x09756E28
	movs r1, #0xE9
	lsls r1, r1, #0x05
	bl LoadObjTiles
	str r0, [r5, #0x00]
	ldr r0, _080D1588 @ =0x09849DB8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
_080D1534:
	adds r0, r5, #0x0
	adds r0, #0xD2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D1548
	adds r0, r5, #0x0
	adds r0, #0x0C
	bl AnimUpdate
	str r0, [r5, #0x08]
_080D1548:
	adds r1, r5, #0x0
	adds r1, #0xD1
	movs r0, #0x01
	strb r0, [r1, #0x00]
	adds r0, r5, #0x0
	adds r0, #0xD0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D1568
	adds r0, r5, #0x0
	adds r0, #0x44
	ldr r1, [r5, #0x24]
	ldr r2, [r5, #0x28]
	ldr r3, [r5, #0x2C]
	bl func_08012324
_080D1568:
	adds r1, r5, #0x0
	adds r1, #0xD4
	ldrh r0, [r1, #0x00]
	subs r0, #0x09
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bls _080D1590
	ldr r1, [r5, #0x28]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r2, _080D158C @ =0xFFFFEFFC
	b _080D159E
	.byte 0x00, 0x00
_080D1584: .4byte 0x09756E28
_080D1588: .4byte 0x09849DB8
_080D158C: .4byte 0xFFFFEFFC
_080D1590:
	ldrh r0, [r1, #0x00]
	subs r0, #0x09
	lsls r0, r0, #0x01
	add r0, sp
	adds r0, #0x10
	ldrh r1, [r0, #0x00]
	ldr r2, _080D15EC @ =0x0000DA38
_080D159E:
	adds r0, r2, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	asrs r1, r4, #0x10
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	str r6, [sp, #0x00C]
	bl DrawSprite
	adds r0, r5, #0x0
	adds r0, #0xA4
	ldrh r0, [r0, #0x00]
	cmp r0, #0x04
	beq _080D15E2
	cmp r0, #0x01
	beq _080D15E2
	adds r4, r5, #0x0
	adds r4, #0xA8
	adds r0, r4, #0x0
	bl TaskPoolUpdate
	adds r0, r4, #0x0
	bl TaskPoolDraw
_080D15E2:
	add sp, #0x01C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D15EC: .4byte 0x0000DA38
.syntax divided
