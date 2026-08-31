.syntax unified
	.align 2, 0
	.global task_bos_boogie_dice_0
	.thumb
	.thumb_func
	.type task_bos_boogie_dice_0, %function
task_bos_boogie_dice_0: @ 080D9B90
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x004
	adds r7, r0, #0x0
	movs r0, #0x40
	adds r0, r0, r1
	mov r8, r0
	ldr r2, _080D9CEC @ =0x00000175
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	subs r2, #0x05
	adds r2, r2, r7
	mov r9, r2
	movs r6, #0x00
	strb r0, [r2, #0x00]
	movs r2, #0xB6
	lsls r2, r2, #0x01
	adds r0, r7, r2
	str r1, [r0, #0x00]
	movs r0, #0x0A
	str r0, [r7, #0x00]
	movs r5, #0x00
	strh r6, [r7, #0x04]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldr r0, _080D9CF0 @ =0xFFFFFB34
	str r0, [r1, #0x00]
	bl GetRandom
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r4, r7, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, #0x61
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x4C
	str r0, [r4, #0x00]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x78
	bl __umodsi3
	adds r0, #0x44
	movs r2, #0xAC
	lsls r2, r2, #0x01
	adds r1, r7, r2
	strb r0, [r1, #0x00]
	movs r1, #0xB0
	lsls r1, r1, #0x01
	adds r0, r7, r1
	movs r1, #0x33
	str r1, [r0, #0x00]
	adds r2, #0x04
	adds r0, r7, r2
	str r1, [r0, #0x00]
	movs r1, #0xB2
	lsls r1, r1, #0x01
	adds r0, r7, r1
	str r6, [r0, #0x00]
	adds r2, #0x0C
	adds r0, r7, r2
	strb r5, [r0, #0x00]
	ldr r0, _080D9CF4 @ =0x0203C564
	strb r5, [r0, #0x00]
	mov r0, r8
	ldr r2, [r0, #0x04]
	movs r3, #0x90
	lsls r3, r3, #0x0A
	ldr r0, [r0, #0x0C]
	ldr r1, _080D9CF8 @ =0xFFFFC800
	adds r0, r0, r1
	adds r6, r7, #0x0
	adds r6, #0x40
	ldr r4, _080D9CFC @ =0x096FDF54
	str r0, [sp, #0x000]
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl func_0801B37C
	adds r0, r7, #0x0
	adds r0, #0x80
	ldrh r2, [r4, #0x08]
	ldrh r3, [r4, #0x06]
	movs r1, #0x03
	bl func_080122AC
	ldr r2, [r7, #0x74]
	ldr r3, [r7, #0x78]
	ldr r0, _080D9D00 @ =0x00000400
	ldr r1, _080D9D04 @ =0x00000000
	orrs r2, r0
	movs r4, #0x80
	movs r5, #0x00
	adds r0, r2, #0x0
	orrs r0, r4
	adds r1, r3, #0x0
	str r0, [r7, #0x74]
	str r1, [r7, #0x78]
	ldr r5, _080D9D08 @ =0x09EF6788
	adds r0, r5, #0x0
	movs r1, #0x04
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D9D0C @ =0x09796EAA
	bl AllocObjTiles
	str r0, [r7, #0x08]
	ldr r0, _080D9D10 @ =0x0984AF98
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r7, #0x0C]
	ldr r0, _080D9D14 @ =0x08F69BC4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r7, #0x10]
	adds r4, r7, #0x0
	adds r4, #0x14
	ldr r1, _080D9D18 @ =0x09EF6798
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	bl GetRandom
	lsls r0, r0, #0x10
	movs r1, #0xC0
	lsls r1, r1, #0x0A
	ands r1, r0
	lsrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl func_08005B44
	adds r4, #0x18
	adds r0, r4, #0x0
	movs r1, #0x01
	bl TaskPoolInit
	ldr r1, _080D9D1C @ =0x09EDB350
	adds r0, r4, #0x0
	adds r2, r6, #0x0
	bl TaskCreate
	mov r2, r9
	ldrb r0, [r2, #0x00]
	cmp r0, #0x00
	bne _080D9CDE
	adds r0, r6, #0x0
	bl func_0801BCD4
_080D9CDE:
	add sp, #0x004
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D9CEC: .4byte 0x00000175
_080D9CF0: .4byte 0xFFFFFB34
_080D9CF4: .4byte 0x0203C564
_080D9CF8: .4byte 0xFFFFC800
_080D9CFC: .4byte 0x096FDF54
_080D9D00: .4byte 0x00000400
_080D9D04: .4byte 0x00000000
_080D9D08: .4byte 0x09EF6788
_080D9D0C: .4byte 0x09796EAA
_080D9D10: .4byte 0x0984AF98
_080D9D14: .4byte 0x08F69BC4
_080D9D18: .4byte 0x09EF6798
_080D9D1C: .4byte 0x09EDB350
.syntax divided
