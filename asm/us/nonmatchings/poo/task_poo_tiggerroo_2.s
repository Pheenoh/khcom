.syntax unified
	.align 2, 0
	.global task_poo_tiggerroo_2
	.thumb
	.thumb_func
	.type task_poo_tiggerroo_2, %function
task_poo_tiggerroo_2: @ 080CEB64
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r0, [r5, #0x28]
	asrs r0, r0, #0x08
	ldr r1, _080CEBE4 @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, [r5, #0x2C]
	asrs r1, r1, #0x08
	ldr r2, [r5, #0x30]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	ldr r2, _080CEBE8 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r2, r0, #0x10
	mov r9, r2
	asrs r0, r0, #0x10
	lsrs r3, r1, #0x10
	mov r8, r3
	asrs r1, r1, #0x10
	movs r2, #0x18
	str r2, [sp, #0x000]
	str r2, [sp, #0x004]
	movs r2, #0x38
	movs r3, #0x08
	bl func_080035CC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CEBEC
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	bne _080CEBB6
	b _080CED18
_080CEBB6:
	bl ReleaseObjPalette
	movs r0, #0x00
	str r0, [r5, #0x04]
	adds r0, r5, #0x0
	adds r0, #0x38
	bl func_08012304
	adds r0, r5, #0x0
	adds r0, #0xD1
	ldrb r4, [r0, #0x00]
	cmp r4, #0x00
	beq _080CEBD2
	b _080CED18
_080CEBD2:
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	bne _080CEBDA
	b _080CED18
_080CEBDA:
	bl ReleaseObjTiles
	str r4, [r5, #0x00]
	b _080CED18
	.byte 0x00, 0x00
_080CEBE4: .4byte 0x0203C40C
_080CEBE8: .4byte 0x0203C3F8
_080CEBEC:
	ldr r0, [r5, #0x04]
	adds r4, r5, #0x0
	adds r4, #0x38
	cmp r0, #0x00
	bne _080CEC40
	adds r0, r5, #0x0
	adds r0, #0xD1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080CEC1C
	ldr r0, _080CEC18 @ =0x09849BD8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	adds r0, r4, #0x0
	movs r1, #0x04
	movs r2, #0x08
	movs r3, #0x08
	bl func_080122AC
	b _080CEC40
_080CEC18: .4byte 0x09849BD8
_080CEC1C:
	ldr r0, _080CEC88 @ =0x09849CF8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	adds r0, r5, #0x0
	adds r0, #0xD2
	ldrh r0, [r0, #0x00]
	ldr r1, _080CEC8C @ =0x09753154
	bl AllocObjTiles
	str r0, [r5, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x04
	movs r2, #0x08
	movs r3, #0x08
	bl func_080122AC
_080CEC40:
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x2C]
	ldr r3, [r5, #0x30]
	adds r0, r4, #0x0
	bl func_08012324
	adds r0, r5, #0x0
	adds r0, #0x24
	ldrb r0, [r0, #0x00]
	movs r7, #0x80
	lsls r7, r7, #0x04
	cmp r0, #0x00
	beq _080CEC5C
	adds r7, #0x01
_080CEC5C:
	adds r0, r5, #0x0
	adds r0, #0xD0
	ldrb r2, [r0, #0x00]
	cmp r2, #0x00
	beq _080CECC0
	subs r0, #0x50
	ldr r1, [r0, #0x00]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r2, _080CEC90 @ =0xFFFFEFF8
	adds r0, r2, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _080CEC94 @ =0x0203C420
	ldr r1, [r5, #0x2C]
	ldr r0, [r0, #0x04]
	cmp r1, r0
	blt _080CEC98
	subs r0, r6, #0x2
	b _080CEC9A
	.byte 0x00, 0x00
_080CEC88: .4byte 0x09849CF8
_080CEC8C: .4byte 0x09753154
_080CEC90: .4byte 0xFFFFEFF8
_080CEC94: .4byte 0x0203C420
_080CEC98:
	adds r0, r6, #0x2
_080CEC9A:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r5, #0x0
	adds r0, #0x84
	ldr r1, [r0, #0x00]
	ldr r0, [r5, #0x48]
	cmp r1, r0
	bgt _080CECB6
	adds r0, r5, #0x0
	adds r0, #0xCC
	movs r1, #0x00
	str r1, [r0, #0x00]
	subs r0, #0x04
	b _080CECEE
_080CECB6:
	adds r1, r5, #0x0
	adds r1, #0xCC
	ldr r0, [r5, #0x78]
	str r0, [r1, #0x00]
	b _080CECE8
_080CECC0:
	ldr r1, [r5, #0x2C]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r3, _080CECE4 @ =0xFFFFEFFC
	adds r0, r3, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r5, #0x0
	adds r0, #0xCC
	str r2, [r0, #0x00]
	ldr r0, [r5, #0x34]
	cmp r2, r0
	beq _080CECE8
	adds r0, r5, #0x0
	adds r0, #0xC8
	strh r2, [r0, #0x00]
	b _080CECF0
_080CECE4: .4byte 0xFFFFEFFC
_080CECE8:
	adds r1, r6, #0x1
	adds r0, r5, #0x0
	adds r0, #0xC8
_080CECEE:
	strh r1, [r0, #0x00]
_080CECF0:
	mov r1, r9
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	mov r2, r8
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r7, [sp, #0x008]
	str r6, [sp, #0x00C]
	bl DrawSprite
	adds r0, r5, #0x0
	adds r0, #0x94
	bl TaskPoolDraw
_080CED18:
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
