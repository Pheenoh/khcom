.syntax unified
	.align 2, 0
	.global task_bos_md_fire_0
	.thumb
	.thumb_func
	.type task_bos_md_fire_0, %function
task_bos_md_fire_0: @ 080FD154
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r7, r0, #0x0
	adds r5, r1, #0x0
	movs r0, #0x00
	mov r9, r0
	mov r1, r9
	strh r1, [r7, #0x06]
	strh r1, [r7, #0x08]
	movs r0, #0x19
	str r0, [r7, #0x30]
	movs r0, #0x1E
	strh r0, [r7, #0x34]
	mov r2, r9
	str r2, [r7, #0x00]
	movs r3, #0xA8
	lsls r3, r3, #0x01
	adds r4, r7, r3
	str r2, [r4, #0x00]
	ldrh r0, [r5, #0x04]
	movs r1, #0xAF
	lsls r1, r1, #0x01
	adds r1, r1, r7
	mov r8, r1
	strh r0, [r1, #0x00]
	ldrh r1, [r5, #0x06]
	movs r2, #0xB0
	lsls r2, r2, #0x01
	adds r0, r7, r2
	strh r1, [r0, #0x00]
	adds r3, #0x1C
	adds r1, r7, r3
	ldr r0, [r5, #0x08]
	str r0, [r1, #0x00]
	adds r0, r7, #0x0
	bl _080FCF78
	adds r6, r7, #0x0
	adds r6, #0x38
	ldr r1, _080FD268 @ =0x09992F28
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r0, r7, r2
	ldr r2, [r0, #0x00]
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r0, r7, r3
	ldr r3, [r0, #0x00]
	ldr r0, [r4, #0x00]
	str r0, [sp, #0x000]
	adds r0, r6, #0x0
	bl func_0801B37C
	adds r4, r7, #0x0
	adds r4, #0x78
	adds r0, r4, #0x0
	movs r1, #0x03
	movs r2, #0x10
	movs r3, #0x10
	bl func_080122AC
	ldr r1, [r7, #0x3C]
	ldr r2, [r7, #0x40]
	ldr r3, [r7, #0x44]
	adds r0, r4, #0x0
	bl func_08012324
	ldr r0, [r7, #0x6C]
	ldr r1, [r7, #0x70]
	ldr r2, _080FD26C @ =0x00001000
	ldr r3, _080FD270 @ =0x00000000
	orrs r0, r2
	str r0, [r7, #0x6C]
	str r1, [r7, #0x70]
	adds r0, r7, #0x0
	adds r0, #0x64
	movs r1, #0x14
	strh r1, [r0, #0x00]
	adds r0, #0x02
	strh r1, [r0, #0x00]
	adds r0, r6, #0x0
	movs r1, #0x01
	bl func_0801C2DC
	ldr r0, _080FD274 @ =0x09A3C99C
	movs r1, #0x20
	bl func_08002A14
	str r0, [r7, #0x0C]
	ldr r0, _080FD278 @ =0x08F69BC4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r7, #0x10]
	ldr r0, _080FD27C @ =0x099E367C
	movs r1, #0x80
	lsls r1, r1, #0x04
	bl func_080026A4
	str r0, [r7, #0x14]
	subs r4, #0x60
	ldr r1, _080FD280 @ =0x09EF9BC0
	ldr r2, _080FD284 @ =0x09EF9BB0
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	mov r0, r9
	str r0, [sp, #0x004]
	add r1, sp, #0x004
	ldrh r0, [r5, #0x04]
	strh r0, [r1, #0x04]
	ldr r0, [r5, #0x08]
	str r0, [sp, #0x00C]
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080FD2B6
	mov r1, r8
	movs r2, #0x00
	ldsh r0, [r1, r2]
	cmp r0, #0x02
	bgt _080FD28C
	ldr r1, _080FD288 @ =0x09992EF8
	mov r3, r8
	movs r2, #0x00
	ldsh r0, [r3, r2]
	lsls r0, r0, #0x03
	adds r0, r0, r1
	ldrh r0, [r0, #0x04]
	b _080FD28E
	.byte 0x00, 0x00
_080FD268: .4byte 0x09992F28
_080FD26C: .4byte 0x00001000
_080FD270: .4byte 0x00000000
_080FD274: .4byte 0x09A3C99C
_080FD278: .4byte 0x08F69BC4
_080FD27C: .4byte 0x099E367C
_080FD280: .4byte 0x09EF9BC0
_080FD284: .4byte 0x09EF9BB0
_080FD288: .4byte 0x09992EF8
_080FD28C:
	movs r0, #0x06
_080FD28E:
	movs r4, #0x01
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	adds r6, r0, #0x0
	cmp r4, r1
	bge _080FD2B6
_080FD29A:
	add r0, sp, #0x004
	strh r4, [r0, #0x06]
	ldr r0, [r5, #0x00]
	ldr r1, _080FD2C4 @ =0x09EF8EDC
	add r2, sp, #0x004
	bl func_08000E14
	lsls r0, r4, #0x10
	movs r3, #0x80
	lsls r3, r3, #0x09
	adds r0, r0, r3
	lsrs r4, r0, #0x10
	cmp r0, r6
	blt _080FD29A
_080FD2B6:
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080FD2C4: .4byte 0x09EF8EDC
.syntax divided
