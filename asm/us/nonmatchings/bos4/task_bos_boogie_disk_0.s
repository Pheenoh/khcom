.syntax unified
	.align 2, 0
	.global task_bos_boogie_disk_0
	.thumb
	.thumb_func
	.type task_bos_boogie_disk_0, %function
task_bos_boogie_disk_0: @ 080DAC60
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x004
	adds r7, r0, #0x0
	adds r4, r1, #0x0
	movs r0, #0x02
	str r0, [r7, #0x00]
	movs r1, #0x00
	movs r0, #0x00
	strh r0, [r7, #0x04]
	movs r2, #0xAE
	lsls r2, r2, #0x01
	adds r0, r7, r2
	strb r1, [r0, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldr r0, _080DACAC @ =0xFFFFFE00
	str r0, [r1, #0x00]
	ldr r1, _080DACB0 @ =0x02039B84
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x04]
	ldr r0, _080DACB4 @ =0x0000F7FF
	mov r9, r1
	cmp r2, r0
	bgt _080DACBC
	movs r1, #0xF0
	lsls r1, r1, #0x08
	adds r1, r1, r2
	mov r8, r1
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r1, r7, r2
	ldr r0, _080DACB8 @ =0xFFFFFD9A
	b _080DACCA
_080DACAC: .4byte 0xFFFFFE00
_080DACB0: .4byte 0x02039B84
_080DACB4: .4byte 0x0000F7FF
_080DACB8: .4byte 0xFFFFFD9A
_080DACBC:
	ldr r0, _080DAD04 @ =0xFFFF1000
	adds r0, r0, r2
	mov r8, r0
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r1, r7, r2
	ldr r0, _080DAD08 @ =0x00000266
_080DACCA:
	str r0, [r1, #0x00]
	movs r0, #0xAC
	lsls r0, r0, #0x01
	adds r5, r7, r0
	subs r0, #0x25
	str r0, [r5, #0x00]
	movs r1, #0x2E
	ldsh r6, [r4, r1]
	adds r0, r6, #0x0
	movs r1, #0x03
	bl __divsi3
	movs r2, #0x2C
	ldsh r1, [r4, r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bge _080DAD0C
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r2, r7, r0
	ldr r1, [r2, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	str r0, [r2, #0x00]
	ldr r1, [r5, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	b _080DAD2C
_080DAD04: .4byte 0xFFFF1000
_080DAD08: .4byte 0x00000266
_080DAD0C:
	movs r1, #0x2C
	ldsh r4, [r4, r1]
	lsls r0, r6, #0x01
	movs r1, #0x03
	bl __divsi3
	cmp r4, r0
	bge _080DAD2E
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r0, r7, r2
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x01
	str r1, [r0, #0x00]
	ldr r0, [r5, #0x00]
	lsls r0, r0, #0x01
_080DAD2C:
	str r0, [r5, #0x00]
_080DAD2E:
	mov r1, r9
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r3, [r0, #0x08]
	ldr r0, _080DADC8 @ =0xFFFFF000
	adds r5, r7, #0x0
	adds r5, #0x40
	ldr r1, _080DADCC @ =0x096FE098
	str r0, [sp, #0x000]
	adds r0, r5, #0x0
	mov r2, r8
	bl func_0801B37C
	ldr r0, [r7, #0x74]
	ldr r1, [r7, #0x78]
	ldr r2, _080DADD0 @ =0x00000400
	ldr r3, _080DADD4 @ =0x00000000
	orrs r0, r2
	str r0, [r7, #0x74]
	str r1, [r7, #0x78]
	ldr r6, _080DADD8 @ =0x09EF6824
	adds r0, r6, #0x0
	movs r1, #0x08
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DADDC @ =0x0979A426
	bl AllocObjTiles
	str r0, [r7, #0x08]
	ldr r0, _080DADE0 @ =0x0984AFB8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r7, #0x0C]
	ldr r0, _080DADE4 @ =0x08F69BC4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r7, #0x10]
	adds r4, r7, #0x0
	adds r4, #0x14
	ldr r1, _080DADE8 @ =0x09EF6844
	adds r0, r4, #0x0
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r4, #0x18
	adds r0, r4, #0x0
	movs r1, #0x01
	bl TaskPoolInit
	ldr r1, _080DADEC @ =0x09EDB350
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl TaskCreate
	adds r0, r5, #0x0
	bl func_0801BCD4
	ldr r0, _080DADF0 @ =0x00000253
	bl m4aSongNumStart
	add sp, #0x004
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DADC8: .4byte 0xFFFFF000
_080DADCC: .4byte 0x096FE098
_080DADD0: .4byte 0x00000400
_080DADD4: .4byte 0x00000000
_080DADD8: .4byte 0x09EF6824
_080DADDC: .4byte 0x0979A426
_080DADE0: .4byte 0x0984AFB8
_080DADE4: .4byte 0x08F69BC4
_080DADE8: .4byte 0x09EF6844
_080DADEC: .4byte 0x09EDB350
_080DADF0: .4byte 0x00000253
.syntax divided
