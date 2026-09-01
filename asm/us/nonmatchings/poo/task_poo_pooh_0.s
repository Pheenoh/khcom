.syntax unified
	.align 2, 0
	.global task_poo_pooh_0
	.thumb
	.thumb_func
	.type task_poo_pooh_0, %function
task_poo_pooh_0: @ 080C85C4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	adds r7, r0, #0x0
	ldr r0, _080C86F8 @ =0x02034DA8
	str r7, [r0, #0x00]
	adds r0, r7, #0x0
	adds r0, #0xCC
	movs r5, #0x00
	strb r5, [r0, #0x00]
	ldr r0, _080C86FC @ =0x0203C3E4
	ldr r1, _080C8700 @ =0x0203C3E0
	bl func_080D2CD0
	adds r0, r7, #0x0
	adds r0, #0xD0
	str r5, [r0, #0x00]
	adds r0, #0x04
	movs r1, #0x00
	mov r10, r1
	strh r5, [r0, #0x00]
	ldr r0, _080C8704 @ =0x0203C3F0
	str r5, [r0, #0x00]
	adds r0, r7, #0x0
	adds r0, #0xDC
	strh r5, [r0, #0x00]
	adds r0, #0x1C
	strh r5, [r0, #0x00]
	adds r1, r7, #0x0
	adds r1, #0x38
	movs r0, #0x2D
	strb r0, [r1, #0x00]
	adds r2, r7, #0x0
	adds r2, #0x3A
	strb r0, [r2, #0x00]
	ldrb r0, [r1, #0x00]
	adds r1, #0x03
	strb r0, [r1, #0x00]
	adds r0, r7, #0x0
	bl func_080C7CC8
	str r5, [r7, #0x3C]
	adds r0, r7, #0x0
	adds r0, #0x24
	mov r1, r10
	strb r1, [r0, #0x00]
	ldr r0, _080C8708 @ =0x0000FFFF
	strh r0, [r7, #0x26]
	movs r0, #0x28
	adds r0, r0, r7
	mov r9, r0
	ldr r6, _080C870C @ =0x02034DAC
	adds r1, r6, #0x0
	bl func_080D2CA8
	str r5, [r7, #0x34]
	ldr r0, [r7, #0x28]
	str r0, [r7, #0x40]
	ldr r0, [r7, #0x2C]
	str r0, [r7, #0x44]
	ldr r0, _080C8710 @ =0x0203C3EC
	mov r1, r9
	str r1, [r0, #0x00]
	ldr r4, _080C8714 @ =0x096FC010
	ldrh r0, [r4, #0x04]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl AllocObjTiles
	str r0, [r7, #0x00]
	ldr r0, [r4, #0x00]
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r7, #0x04]
	movs r0, #0x0C
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimInit
	ldr r1, [r6, #0x00]
	adds r0, r7, #0x0
	bl func_080C84E0
	adds r0, r7, #0x0
	adds r0, #0xFA
	mov r1, r10
	strb r1, [r0, #0x00]
	ldr r1, [r6, #0x00]
	adds r0, r7, #0x0
	bl func_080C7FEC
	mov r0, r8
	bl AnimGetGfx
	str r0, [r7, #0x08]
	adds r6, r7, #0x0
	adds r6, #0x4C
	ldrh r2, [r4, #0x08]
	ldrh r3, [r4, #0x06]
	adds r0, r6, #0x0
	movs r1, #0x09
	bl func_080122AC
	ldr r1, [r7, #0x28]
	ldr r2, [r7, #0x2C]
	ldr r3, [r7, #0x30]
	adds r0, r6, #0x0
	bl func_08012324
	adds r4, r7, #0x0
	adds r4, #0xB0
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl TaskPoolInit
	mov r0, r9
	str r0, [sp, #0x000]
	adds r0, r7, #0x0
	adds r0, #0xE0
	str r0, [sp, #0x004]
	ldr r1, _080C8718 @ =0x09EF4940
	adds r0, r4, #0x0
	mov r2, sp
	bl TaskCreate
	adds r0, r7, #0x0
	adds r0, #0xC4
	str r5, [r0, #0x00]
	adds r0, #0x04
	str r5, [r0, #0x00]
	adds r2, r7, #0x0
	adds r2, #0xE8
	adds r0, r6, #0x0
	mov r1, r9
	bl func_080C8B38
	adds r1, r7, #0x0
	adds r1, #0xEC
	str r0, [r1, #0x00]
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080C86F8: .4byte 0x02034DA8
_080C86FC: .4byte 0x0203C3E4
_080C8700: .4byte 0x0203C3E0
_080C8704: .4byte 0x0203C3F0
_080C8708: .4byte 0x0000FFFF
_080C870C: .4byte 0x02034DAC
_080C8710: .4byte 0x0203C3EC
_080C8714: .4byte 0x096FC010
_080C8718: .4byte 0x09EF4940
.syntax divided
