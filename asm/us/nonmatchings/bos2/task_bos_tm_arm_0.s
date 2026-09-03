.syntax unified
	.align 2, 0
	.global task_bos_tm_arm_0
	.thumb
	.thumb_func
	.type task_bos_tm_arm_0, %function
task_bos_tm_arm_0: @ 080BB64C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	str r1, [r7, #0x0C]
	ldr r0, _080BB8DC @ =0x09652E84
	movs r1, #0xEC
	lsls r1, r1, #0x05
	bl LoadObjTiles
	str r0, [r7, #0x00]
	ldr r0, _080BB8E0 @ =0x096FB2A4
	movs r1, #0x60
	bl LoadObjPalette
	str r0, [r7, #0x04]
	ldr r0, _080BB8E4 @ =0x08F69BC4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r7, #0x08]
	movs r1, #0xD8
	lsls r1, r1, #0x01
	adds r0, r7, r1
	movs r1, #0x00
	strh r1, [r0, #0x00]
	movs r2, #0xD9
	lsls r2, r2, #0x01
	adds r0, r7, r2
	strh r1, [r0, #0x00]
	movs r6, #0x8C
	lsls r6, r6, #0x02
	adds r2, r7, r6
	movs r0, #0x01
	strb r0, [r2, #0x00]
	movs r2, #0x8D
	lsls r2, r2, #0x02
	adds r0, r7, r2
	str r1, [r0, #0x00]
	subs r6, #0x04
	adds r0, r7, r6
	str r1, [r0, #0x00]
	subs r2, #0x14
	adds r0, r7, r2
	str r1, [r0, #0x00]
	subs r6, #0x08
	adds r0, r7, r6
	ldr r1, _080BB8E8 @ =0x09619CDC
	adds r3, r7, #0x0
	adds r3, #0x10
	movs r2, #0x03
	bl func_080BB43C
	movs r1, #0x86
	lsls r1, r1, #0x02
	adds r0, r7, r1
	ldr r1, _080BB8EC @ =0x09619D18
	adds r3, r7, #0x0
	adds r3, #0xE0
	movs r2, #0x03
	bl func_080BB43C
	adds r2, r7, #0x0
	adds r2, #0xE8
	adds r1, r7, #0x0
	adds r1, #0x18
	movs r3, #0x03
_080BB6D8:
	ldrh r0, [r1, #0x0C]
	strh r0, [r1, #0x00]
	ldrh r0, [r2, #0x0C]
	strh r0, [r2, #0x00]
	adds r2, #0x34
	adds r1, #0x34
	subs r3, #0x01
	cmp r3, #0x00
	bge _080BB6D8
	adds r5, r7, #0x0
	adds r5, #0x10
	adds r0, r5, #0x0
	bl func_080BB518
	adds r4, r7, #0x0
	adds r4, #0xE0
	adds r0, r4, #0x0
	bl func_080BB518
	movs r3, #0x00
	str r5, [sp, #0x000]
	mov r12, r4
	movs r2, #0x1C
	adds r2, r2, r7
	mov r10, r2
	movs r6, #0x14
	adds r6, r6, r7
	mov r9, r6
	movs r0, #0x20
	adds r0, r0, r7
	mov r8, r0
	adds r5, #0xDC
	adds r4, #0x04
	adds r1, r7, #0x0
	adds r1, #0xF0
	str r1, [sp, #0x010]
	adds r2, r7, #0x0
	adds r2, #0x40
	str r2, [sp, #0x004]
	adds r6, r7, #0x0
	adds r6, #0xDC
	str r6, [sp, #0x008]
_080BB72C:
	movs r0, #0x34
	adds r1, r3, #0x0
	muls r1, r0
	ldr r0, [sp, #0x000]
	adds r2, r0, r1
	mov r6, r10
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	mov r0, r9
	adds r2, r0, r1
	mov r6, r8
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	mov r0, r12
	adds r2, r0, r1
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	adds r2, r4, r1
	ldr r6, [sp, #0x010]
	adds r1, r6, r1
	ldr r0, [r1, #0x00]
	str r0, [r2, #0x00]
	adds r3, #0x01
	cmp r3, #0x03
	ble _080BB72C
	adds r0, r7, #0x0
	bl func_080BB464
	adds r0, r7, #0x0
	bl func_080BB4C0
	movs r0, #0x81
	lsls r0, r0, #0x02
	adds r1, r7, r0
	subs r0, #0xF4
	strh r0, [r1, #0x00]
	movs r2, #0x85
	lsls r2, r2, #0x02
	adds r1, r7, r2
	movs r0, #0xF0
	strh r0, [r1, #0x00]
	movs r3, #0x00
	ldr r6, _080BB8F0 @ =0x09EF39B4
	mov r10, r6
	ldr r0, _080BB8F4 @ =0x09EF39A0
	mov r9, r0
_080BB78E:
	movs r0, #0x34
	adds r5, r3, #0x0
	muls r5, r0
	adds r4, r5, r7
	adds r4, #0x28
	adds r0, r4, #0x0
	mov r1, r10
	mov r2, r9
	str r3, [sp, #0x00C]
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r6, r7, r5
	ldr r3, [sp, #0x00C]
	lsls r1, r3, #0x01
	mov r8, r1
	strh r1, [r6, #0x36]
	adds r0, r4, #0x0
	str r3, [sp, #0x00C]
	bl AnimGetGfx
	ldr r2, [sp, #0x004]
	adds r1, r2, r5
	str r0, [r1, #0x00]
	adds r4, r5, r7
	adds r4, #0xF8
	adds r0, r4, #0x0
	mov r1, r10
	mov r2, r9
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	movs r1, #0x83
	lsls r1, r1, #0x01
	adds r0, r6, r1
	mov r2, r8
	strh r2, [r0, #0x00]
	adds r0, r4, #0x0
	bl AnimGetGfx
	movs r6, #0x88
	lsls r6, r6, #0x01
	adds r1, r7, r6
	adds r1, r1, r5
	str r0, [r1, #0x00]
	ldr r3, [sp, #0x00C]
	adds r3, #0x01
	cmp r3, #0x02
	ble _080BB78E
	ldr r1, _080BB8F8 @ =0x0962E7A0
	ldr r0, [sp, #0x008]
	str r1, [r0, #0x00]
	movs r2, #0xD6
	lsls r2, r2, #0x01
	adds r0, r7, r2
	str r1, [r0, #0x00]
	movs r0, #0xA0
	lsls r0, r0, #0x01
	ldr r1, _080BB8FC @ =0x09657C04
	bl AllocObjTiles
	movs r1, #0x8E
	lsls r1, r1, #0x02
	adds r6, r7, r1
	str r0, [r6, #0x00]
	ldr r1, [r7, #0x0C]
	ldr r1, [r1, #0x18]
	adds r1, #0x42
	ldrh r0, [r0, #0x08]
	ldrh r2, [r1, #0x00]
	adds r0, r0, r2
	movs r2, #0x00
	mov r8, r2
	movs r5, #0x00
	strh r0, [r1, #0x00]
	movs r0, #0x8F
	lsls r0, r0, #0x02
	adds r4, r7, r0
	ldr r1, _080BB900 @ =0x09EF3A18
	ldr r2, _080BB904 @ =0x09EF39F8
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	movs r2, #0xEC
	lsls r2, r2, #0x01
	adds r1, r7, r2
	ldr r0, [r6, #0x00]
	str r0, [r1, #0x00]
	movs r0, #0xF8
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldr r0, [r6, #0x00]
	str r0, [r1, #0x00]
	adds r0, r4, #0x0
	bl AnimGetGfx
	movs r2, #0xEE
	lsls r2, r2, #0x01
	adds r1, r7, r2
	str r0, [r1, #0x00]
	movs r6, #0xFA
	lsls r6, r6, #0x01
	adds r1, r7, r6
	str r0, [r1, #0x00]
	movs r1, #0x95
	lsls r1, r1, #0x02
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0, #0x00]
	subs r6, #0x40
	adds r4, r7, r6
	adds r0, r4, #0x0
	movs r1, #0x02
	bl TaskPoolInit
	movs r0, #0xE4
	lsls r0, r0, #0x01
	adds r1, r7, r0
	adds r6, #0x44
	adds r2, r7, r6
	adds r0, r4, #0x0
	bl func_080BB1B8
	movs r0, #0xF0
	lsls r0, r0, #0x01
	adds r1, r7, r0
	adds r6, #0x10
	adds r2, r7, r6
	adds r0, r4, #0x0
	bl func_080BB1B8
	ldr r0, _080BB908 @ =0x0203AC74
	strh r5, [r0, #0x00]
	ldr r0, _080BB90C @ =0x0203AC64
	str r5, [r0, #0x00]
	ldr r0, _080BB910 @ =0x0203AC78
	str r5, [r0, #0x00]
	ldr r0, _080BB914 @ =0x0203AC70
	str r5, [r0, #0x00]
	ldr r0, _080BB918 @ =0x0203AC60
	strh r5, [r0, #0x00]
	ldr r0, _080BB91C @ =0x0203AC6C
	strh r5, [r0, #0x00]
	ldr r0, _080BB920 @ =0x0203AC68
	strh r5, [r0, #0x00]
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080BB8DC: .4byte 0x09652E84
_080BB8E0: .4byte 0x096FB2A4
_080BB8E4: .4byte 0x08F69BC4
_080BB8E8: .4byte 0x09619CDC
_080BB8EC: .4byte 0x09619D18
_080BB8F0: .4byte 0x09EF39B4
_080BB8F4: .4byte 0x09EF39A0
_080BB8F8: .4byte 0x0962E7A0
_080BB8FC: .4byte 0x09657C04
_080BB900: .4byte 0x09EF3A18
_080BB904: .4byte 0x09EF39F8
_080BB908: .4byte 0x0203AC74
_080BB90C: .4byte 0x0203AC64
_080BB910: .4byte 0x0203AC78
_080BB914: .4byte 0x0203AC70
_080BB918: .4byte 0x0203AC60
_080BB91C: .4byte 0x0203AC6C
_080BB920: .4byte 0x0203AC68
.syntax divided
