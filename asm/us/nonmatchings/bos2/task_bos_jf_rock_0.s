.syntax unified
	.align 2, 0
	.global task_bos_jf_rock_0
	.thumb
	.thumb_func
	.type task_bos_jf_rock_0, %function
task_bos_jf_rock_0: @ 080C09B8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r7, r0, #0x0
	str r1, [r7, #0x00]
	ldr r6, [r1, #0x04]
	str r6, [r7, #0x30]
	ldr r5, [r1, #0x08]
	movs r2, #0xA0
	lsls r2, r2, #0x03
	adds r0, r5, r2
	str r0, [r7, #0x34]
	ldr r3, [r1, #0x0C]
	mov r8, r3
	ldr r0, _080C0A80 @ =0xFFFFB800
	add r0, r8
	str r0, [r7, #0x38]
	movs r4, #0x00
	str r4, [r7, #0x3C]
	adds r2, r7, #0x0
	adds r2, #0xF8
	movs r0, #0x00
	mov r9, r0
	movs r0, #0xFE
	lsls r0, r0, #0x08
	strh r0, [r2, #0x00]
	ldr r2, _080C0A84 @ =0x00020000
	ldr r3, _080C0A88 @ =0x00000000
	str r2, [r7, #0x60]
	str r3, [r7, #0x64]
	movs r2, #0x9E
	lsls r2, r2, #0x01
	adds r0, r7, r2
	str r4, [r0, #0x00]
	movs r3, #0xA0
	lsls r3, r3, #0x01
	adds r0, r7, r3
	str r4, [r0, #0x00]
	movs r0, #0xA2
	lsls r0, r0, #0x01
	adds r3, r7, r0
	str r4, [r3, #0x00]
	adds r2, #0x0C
	adds r0, r7, r2
	str r4, [r0, #0x00]
	adds r2, #0x04
	adds r0, r7, r2
	str r4, [r0, #0x00]
	adds r2, #0x04
	adds r0, r7, r2
	str r4, [r0, #0x00]
	adds r2, #0x04
	adds r0, r7, r2
	str r4, [r0, #0x00]
	strh r4, [r7, #0x28]
	strh r4, [r7, #0x2A]
	movs r4, #0xCA
	lsls r4, r4, #0x01
	adds r0, r7, r4
	mov r2, r9
	strb r2, [r0, #0x00]
	ldr r0, [r1, #0x34]
	ldr r1, [r1, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080C0A98
	subs r4, #0x24
	adds r1, r7, r4
	movs r2, #0x80
	lsls r2, r2, #0x06
	adds r0, r6, r2
	str r0, [r1, #0x00]
	adds r4, #0x04
	adds r1, r7, r4
	movs r2, #0xA0
	lsls r2, r2, #0x04
	adds r0, r5, r2
	str r0, [r1, #0x00]
	adds r4, #0x04
	adds r1, r7, r4
	ldr r0, _080C0A8C @ =0xFFFFE700
	add r0, r8
	str r0, [r1, #0x00]
	ldr r0, _080C0A90 @ =0x0203ACC0
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r0, #0x01
	lsls r0, r0, #0x0B
	negs r0, r0
	ldr r2, _080C0A94 @ =0xFFFFE000
	adds r0, r0, r2
	str r0, [r3, #0x00]
	b _080C0ACC
	.byte 0x00, 0x00
_080C0A80: .4byte 0xFFFFB800
_080C0A84: .4byte 0x00020000
_080C0A88: .4byte 0x00000000
_080C0A8C: .4byte 0xFFFFE700
_080C0A90: .4byte 0x0203ACC0
_080C0A94: .4byte 0xFFFFE000
_080C0A98:
	movs r4, #0xB8
	lsls r4, r4, #0x01
	adds r1, r7, r4
	ldr r2, _080C0BCC @ =0xFFFFE000
	adds r0, r6, r2
	str r0, [r1, #0x00]
	movs r0, #0xBA
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r4, #0xA0
	lsls r4, r4, #0x04
	adds r0, r5, r4
	str r0, [r1, #0x00]
	movs r0, #0xBC
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldr r0, _080C0BD0 @ =0xFFFFE700
	add r0, r8
	str r0, [r1, #0x00]
	ldr r0, _080C0BD4 @ =0x0203ACC4
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r0, #0x01
	lsls r0, r0, #0x0B
	subs r2, r2, r0
	str r2, [r3, #0x00]
_080C0ACC:
	movs r2, #0xBE
	lsls r2, r2, #0x01
	adds r0, r7, r2
	movs r2, #0x00
	strb r2, [r0, #0x00]
	movs r3, #0xBF
	lsls r3, r3, #0x01
	adds r3, r7, r3
	str r3, [sp, #0x000]
	movs r3, #0x00
	ldr r4, [sp, #0x000]
	strh r2, [r4, #0x00]
	movs r1, #0xAD
	lsls r1, r1, #0x01
	adds r0, r7, r1
	strb r3, [r0, #0x00]
	movs r4, #0xAC
	lsls r4, r4, #0x01
	adds r4, r4, r7
	mov r10, r4
	strh r2, [r4, #0x00]
	movs r0, #0xAE
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0x78
	strh r0, [r1, #0x00]
	movs r1, #0xAF
	lsls r1, r1, #0x01
	adds r0, r7, r1
	strh r2, [r0, #0x00]
	movs r2, #0xB0
	lsls r2, r2, #0x01
	adds r0, r7, r2
	strb r3, [r0, #0x00]
	ldr r3, _080C0BD8 @ =0x09682AA4
	mov r8, r3
	movs r4, #0xA0
	lsls r4, r4, #0x06
	mov r9, r4
	mov r0, r8
	mov r1, r9
	bl LoadObjTiles
	str r0, [r7, #0x04]
	ldr r6, _080C0BDC @ =0x096FB5A4
	adds r0, r6, #0x0
	movs r1, #0x60
	bl LoadObjPalette
	str r0, [r7, #0x08]
	adds r4, r7, #0x0
	adds r4, #0x10
	ldr r1, _080C0BE0 @ =0x09EF3B40
	adds r0, r4, #0x0
	ldr r2, _080C0BE4 @ =0x09EF3A48
	bl AnimInit
	ldr r1, _080C0BE8 @ =0x09EF2A38
	mov r2, r10
	movs r3, #0x00
	ldsh r0, [r2, r3]
	adds r0, r0, r1
	movs r1, #0x00
	ldsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0x0
	movs r2, #0x00
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x0C]
	mov r0, r8
	mov r1, r9
	bl LoadObjTiles
	movs r4, #0xB2
	lsls r4, r4, #0x01
	adds r1, r7, r4
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	movs r1, #0x60
	bl LoadObjPalette
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r1, r7, r2
	str r0, [r1, #0x00]
	movs r3, #0xB6
	lsls r3, r3, #0x01
	adds r2, r7, r3
	ldr r1, _080C0BEC @ =0x09EF2A42
	ldr r4, [sp, #0x000]
	movs r3, #0x00
	ldsh r0, [r4, r3]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r4, #0x00
	ldsh r0, [r0, r4]
	lsls r0, r0, #0x02
	ldr r1, _080C0BE4 @ =0x09EF3A48
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	movs r2, #0xC0
	lsls r2, r2, #0x01
	adds r4, r7, r2
	adds r0, r4, #0x0
	movs r1, #0x01
	bl TaskPoolInit
	ldr r1, _080C0BF0 @ =0x09EF34D8
	adds r2, r7, #0x0
	adds r2, #0x2C
	adds r0, r4, #0x0
	bl TaskCreate
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C0BCC: .4byte 0xFFFFE000
_080C0BD0: .4byte 0xFFFFE700
_080C0BD4: .4byte 0x0203ACC4
_080C0BD8: .4byte 0x09682AA4
_080C0BDC: .4byte 0x096FB5A4
_080C0BE0: .4byte 0x09EF3B40
_080C0BE4: .4byte 0x09EF3A48
_080C0BE8: .4byte 0x09EF2A38
_080C0BEC: .4byte 0x09EF2A42
_080C0BF0: .4byte 0x09EF34D8
.syntax divided
