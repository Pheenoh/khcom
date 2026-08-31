.syntax unified
	.align 2, 0
	.global task_poo_tanpopo_2
	.thumb
	.thumb_func
	.type task_poo_tanpopo_2, %function
task_poo_tanpopo_2: @ 080CF5DC
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r1, [r5, #0x44]
	asrs r1, r1, #0x08
	ldr r0, _080CF64C @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	ldr r0, [r5, #0x48]
	asrs r0, r0, #0x08
	ldr r2, _080CF650 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r0, r0, r2
	lsls r1, r1, #0x10
	asrs r7, r1, #0x10
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	movs r4, #0x00
	str r4, [sp, #0x000]
	movs r0, #0x30
	str r0, [sp, #0x004]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	movs r2, #0x00
	movs r3, #0x20
	bl func_080035CC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0x00
	beq _080CF654
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	beq _080CF71E
	ldr r0, [r5, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r5, #0x24]
	bl ReleaseObjTiles
	ldr r0, [r5, #0x04]
	bl ReleaseObjPalette
	str r4, [r5, #0x04]
	adds r0, r5, #0x0
	adds r0, #0x54
	bl func_08012304
	adds r0, r5, #0x0
	adds r0, #0xB0
	strb r4, [r0, #0x00]
	b _080CF71E
_080CF64C: .4byte 0x0203C40C
_080CF650: .4byte 0x0203C3F8
_080CF654:
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	bne _080CF68A
	ldr r0, _080CF6F8 @ =0x0975E40E
	movs r1, #0x80
	lsls r1, r1, #0x04
	bl LoadObjTiles
	str r0, [r5, #0x00]
	ldr r0, _080CF6FC @ =0x0975EC8E
	movs r1, #0xC0
	lsls r1, r1, #0x05
	bl LoadObjTiles
	str r0, [r5, #0x24]
	ldr r0, _080CF700 @ =0x09849E18
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	adds r0, r5, #0x0
	adds r0, #0x54
	movs r1, #0x06
	movs r2, #0x18
	movs r3, #0x00
	bl func_080122AC
_080CF68A:
	movs r0, #0xB0
	adds r0, r0, r5
	mov r9, r0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080CF71E
	adds r0, r5, #0x0
	adds r0, #0x0C
	bl AnimUpdate
	str r0, [r5, #0x08]
	adds r4, r5, #0x0
	adds r4, #0x2C
	adds r0, r4, #0x0
	bl AnimUpdate
	str r0, [r5, #0x28]
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x00]
	ldr r0, [r5, #0x04]
	str r0, [sp, #0x000]
	mov r1, r8
	str r1, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	mov r8, r0
	str r0, [sp, #0x008]
	ldr r0, _080CF704 @ =0x0000FFF1
	str r0, [sp, #0x00C]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	bl DrawSprite
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x00
	bne _080CF708
	ldr r2, [r5, #0x28]
	ldr r3, [r5, #0x24]
	ldr r0, [r5, #0x04]
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	mov r1, r8
	str r1, [sp, #0x008]
	movs r0, #0x64
	str r0, [sp, #0x00C]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	bl DrawSprite
	b _080CF71E
	.byte 0x00, 0x00
_080CF6F8: .4byte 0x0975E40E
_080CF6FC: .4byte 0x0975EC8E
_080CF700: .4byte 0x09849E18
_080CF704: .4byte 0x0000FFF1
_080CF708:
	adds r0, r5, #0x0
	adds r0, #0x82
	ldrh r1, [r0, #0x00]
	movs r0, #0x02
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	bne _080CF71E
	mov r1, r9
	strb r0, [r1, #0x00]
_080CF71E:
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
