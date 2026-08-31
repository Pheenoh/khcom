.syntax unified
	.align 2, 0
	.global task_poo_bee_2
	.thumb
	.thumb_func
	.type task_poo_bee_2, %function
task_poo_bee_2: @ 080D0CE8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	bl func_080CFCC0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D0CFE
	b _080D0DFC
_080D0CFE:
	adds r0, r5, #0x0
	adds r0, #0xA4
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x08
	ldr r1, _080D0D5C @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	adds r4, r5, #0x0
	adds r4, #0xA8
	ldr r1, [r4, #0x00]
	asrs r1, r1, #0x08
	adds r2, r5, #0x0
	adds r2, #0xAC
	ldr r2, [r2, #0x00]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	ldr r2, _080D0D60 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x2E
	str r2, [sp, #0x000]
	movs r2, #0x10
	str r2, [sp, #0x004]
	movs r2, #0x13
	movs r3, #0x11
	bl func_080035CC
	lsls r0, r0, #0x18
	mov r8, r4
	cmp r0, #0x00
	beq _080D0D64
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	beq _080D0DFC
	bl ReleaseObjPalette
	ldr r0, [r5, #0x00]
	bl ReleaseObjTiles
	movs r0, #0x00
	str r0, [r5, #0x04]
	b _080D0DFC
	.byte 0x00, 0x00
_080D0D5C: .4byte 0x0203C40C
_080D0D60: .4byte 0x0203C3F8
_080D0D64:
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	bne _080D0D80
	ldr r0, _080D0E08 @ =0x09849D98
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	ldr r0, _080D0E0C @ =0x09756ACE
	movs r1, #0xC0
	lsls r1, r1, #0x01
	bl LoadObjTiles
	str r0, [r5, #0x00]
_080D0D80:
	movs r6, #0x00
	ldr r0, _080D0E10 @ =0x02034E2C
	ldr r0, [r0, #0x00]
	adds r0, #0x01
	cmp r6, r0
	bcs _080D0DFC
_080D0D8C:
	lsls r3, r6, #0x05
	adds r0, r5, #0x0
	adds r0, #0x24
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x08
	ldr r1, _080D0E14 @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	adds r1, r5, #0x0
	adds r1, #0x28
	adds r1, r1, r3
	ldr r1, [r1, #0x00]
	asrs r1, r1, #0x08
	adds r2, r5, #0x0
	adds r2, #0x2C
	adds r2, r2, r3
	ldr r2, [r2, #0x00]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	ldr r2, _080D0E18 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	mov r7, r8
	ldr r4, [r7, #0x00]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r7, _080D0E1C @ =0x00001003
	adds r4, r4, r7
	subs r4, r6, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	adds r6, #0x01
	ldr r0, _080D0E10 @ =0x02034E2C
	ldr r0, [r0, #0x00]
	adds r0, #0x01
	cmp r6, r0
	bcs _080D0DFC
	cmp r6, #0x03
	ble _080D0D8C
_080D0DFC:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D0E08: .4byte 0x09849D98
_080D0E0C: .4byte 0x09756ACE
_080D0E10: .4byte 0x02034E2C
_080D0E14: .4byte 0x0203C40C
_080D0E18: .4byte 0x0203C3F8
_080D0E1C: .4byte 0x00001003
.syntax divided
