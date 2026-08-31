.syntax unified
	.align 2, 0
	.global task_bos_dsd_0
	.thumb
	.thumb_func
	.type task_bos_dsd_0, %function
task_bos_dsd_0: @ 080C1B60
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r4, r0, #0x0
	movs r0, #0xD6
	lsls r0, r0, #0x02
	adds r5, r4, r0
	movs r0, #0x00
	strh r0, [r5, #0x00]
	cmp r1, #0x00
	beq _080C1B80
	movs r0, #0x10
	strh r0, [r5, #0x00]
_080C1B80:
	movs r1, #0xDF
	lsls r1, r1, #0x02
	adds r6, r4, r1
	adds r0, r6, #0x0
	movs r1, #0x04
	bl TaskPoolInit
	ldrh r1, [r5, #0x00]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _080C1BA8
	ldr r1, _080C1BA4 @ =0x09EF2E78
	adds r0, r6, #0x0
	movs r2, #0x00
	bl TaskCreate
	b _080C1BB6
_080C1BA4: .4byte 0x09EF2E78
_080C1BA8:
	ldr r0, _080C1BE0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x40
	ldr r1, _080C1BE4 @ =0x09EF2E78
	adds r2, r4, #0x0
	bl TaskCreate
_080C1BB6:
	movs r2, #0xE4
	lsls r2, r2, #0x02
	adds r0, r4, r2
	movs r1, #0x00
	strh r1, [r0, #0x00]
	ldr r3, _080C1BE8 @ =0x00000392
	adds r0, r4, r3
	strh r1, [r0, #0x00]
	movs r1, #0xD6
	lsls r1, r1, #0x02
	adds r0, r4, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _080C1BEC
	subs r2, #0x5C
	adds r1, r4, r2
	movs r0, #0x09
	b _080C1BF4
	.byte 0x00, 0x00
_080C1BE0: .4byte 0x02039B84
_080C1BE4: .4byte 0x09EF2E78
_080C1BE8: .4byte 0x00000392
_080C1BEC:
	movs r3, #0xCD
	lsls r3, r3, #0x02
	adds r1, r4, r3
	movs r0, #0x01
_080C1BF4:
	str r0, [r1, #0x00]
	movs r1, #0xCE
	lsls r1, r1, #0x02
	adds r0, r4, r1
	movs r1, #0x01
	str r1, [r0, #0x00]
	movs r2, #0xCC
	lsls r2, r2, #0x02
	adds r0, r4, r2
	str r1, [r0, #0x00]
	movs r3, #0xCF
	lsls r3, r3, #0x02
	adds r0, r4, r3
	movs r1, #0x00
	movs r2, #0x00
	mov r8, r2
	mov r3, r8
	strh r3, [r0, #0x00]
	movs r2, #0xD3
	lsls r2, r2, #0x02
	adds r0, r4, r2
	strh r3, [r0, #0x00]
	ldr r3, _080C1CE0 @ =0x0000034E
	adds r0, r4, r3
	mov r2, r8
	strh r2, [r0, #0x00]
	adds r3, #0x02
	adds r0, r4, r3
	strh r2, [r0, #0x00]
	ldr r2, _080C1CE4 @ =0x00000352
	adds r0, r4, r2
	mov r3, r8
	strh r3, [r0, #0x00]
	adds r2, #0x02
	adds r0, r4, r2
	strh r3, [r0, #0x00]
	ldr r3, _080C1CE8 @ =0x00000356
	adds r0, r4, r3
	mov r2, r8
	strh r2, [r0, #0x00]
	adds r3, #0x04
	adds r0, r4, r3
	strb r1, [r0, #0x00]
	movs r0, #0xD7
	lsls r0, r0, #0x02
	adds r1, r4, r0
	movs r0, #0x33
	negs r0, r0
	str r0, [r1, #0x00]
	movs r1, #0xD6
	lsls r1, r1, #0x02
	adds r0, r4, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x004]
	cmp r0, #0x00
	beq _080C1CFC
	subs r3, #0x1A
	adds r2, r4, r3
	movs r6, #0xDC
	lsls r6, r6, #0x08
	str r6, [r2, #0x00]
	movs r0, #0xD1
	lsls r0, r0, #0x02
	adds r3, r4, r0
	movs r5, #0xB4
	lsls r5, r5, #0x09
	str r5, [r3, #0x00]
	movs r1, #0xD2
	lsls r1, r1, #0x02
	adds r0, r4, r1
	ldr r1, _080C1CEC @ =0xFFFF9C00
	str r1, [r0, #0x00]
	mov r10, r4
	ldr r4, _080C1CF0 @ =0x0961A7B0
	ldr r2, [r2, #0x00]
	ldr r3, [r3, #0x00]
	str r1, [sp, #0x000]
	mov r0, r10
	adds r1, r4, #0x0
	bl func_0801B37C
	movs r2, #0x88
	lsls r2, r2, #0x01
	add r2, r10
	mov r9, r2
	ldr r0, _080C1CF4 @ =0xFFFF7400
	str r0, [sp, #0x000]
	mov r0, r9
	adds r1, r4, #0x0
	adds r2, r6, #0x0
	adds r3, r5, #0x0
	bl func_0801B37C
	movs r7, #0x88
	lsls r7, r7, #0x02
	add r7, r10
	movs r2, #0x90
	lsls r2, r2, #0x08
	mov r3, r8
	str r3, [sp, #0x000]
	adds r0, r7, #0x0
	adds r1, r4, #0x0
	adds r3, r5, #0x0
	bl func_0801B37C
	movs r0, #0xDF
	lsls r0, r0, #0x02
	add r0, r10
	ldr r1, _080C1CF8 @ =0x09EF2E50
	mov r2, r10
	bl TaskCreate
	b _080C1E6E
	.byte 0x00, 0x00
_080C1CE0: .4byte 0x0000034E
_080C1CE4: .4byte 0x00000352
_080C1CE8: .4byte 0x00000356
_080C1CEC: .4byte 0xFFFF9C00
_080C1CF0: .4byte 0x0961A7B0
_080C1CF4: .4byte 0xFFFF7400
_080C1CF8: .4byte 0x09EF2E50
_080C1CFC:
	movs r0, #0xD0
	lsls r0, r0, #0x02
	adds r2, r4, r0
	movs r7, #0xDC
	lsls r7, r7, #0x08
	str r7, [r2, #0x00]
	movs r1, #0xD1
	lsls r1, r1, #0x02
	adds r3, r4, r1
	movs r0, #0xB4
	lsls r0, r0, #0x09
	mov r8, r0
	str r0, [r3, #0x00]
	adds r1, #0x04
	adds r0, r4, r1
	ldr r1, _080C1E80 @ =0xFFFF9C00
	str r1, [r0, #0x00]
	mov r10, r4
	ldr r6, _080C1E84 @ =0x0961A7B0
	ldr r2, [r2, #0x00]
	ldr r3, [r3, #0x00]
	str r1, [sp, #0x000]
	mov r0, r10
	adds r1, r6, #0x0
	bl func_0801B37C
	mov r0, r10
	ldr r2, [r0, #0x34]
	ldr r3, [r0, #0x38]
	ldr r0, _080C1E88 @ =0x01000000
	ldr r1, _080C1E8C @ =0x00000000
	orrs r2, r0
	movs r4, #0x04
	movs r5, #0x00
	adds r0, r2, #0x0
	orrs r0, r4
	adds r1, r3, #0x0
	mov r2, r10
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	movs r3, #0x88
	lsls r3, r3, #0x01
	add r3, r10
	mov r9, r3
	ldr r0, _080C1E90 @ =0xFFFF7400
	str r0, [sp, #0x000]
	mov r0, r9
	adds r1, r6, #0x0
	adds r2, r7, #0x0
	mov r3, r8
	bl func_0801B37C
	mov r0, r9
	ldr r2, [r0, #0x34]
	ldr r3, [r0, #0x38]
	orrs r2, r4
	ldr r4, _080C1E94 @ =0x00000400
	ldr r5, _080C1E98 @ =0x00000000
	adds r0, r2, #0x0
	orrs r0, r4
	adds r1, r3, #0x0
	mov r2, r9
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	movs r0, #0xD9
	lsls r0, r0, #0x01
	add r0, r10
	mov r3, sp
	ldrh r3, [r3, #0x04]
	strh r3, [r0, #0x00]
	movs r0, #0xD7
	lsls r0, r0, #0x01
	add r0, r10
	movs r1, #0x10
	strh r1, [r0, #0x00]
	movs r0, #0xD8
	lsls r0, r0, #0x01
	add r0, r10
	strh r1, [r0, #0x00]
	movs r0, #0xD6
	lsls r0, r0, #0x01
	add r0, r10
	strh r1, [r0, #0x00]
	movs r7, #0x88
	lsls r7, r7, #0x02
	add r7, r10
	movs r2, #0x90
	lsls r2, r2, #0x08
	ldr r3, [sp, #0x004]
	str r3, [sp, #0x000]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	mov r3, r8
	bl func_0801B37C
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	ldr r2, _080C1E9C @ =0x01000004
	ldr r3, _080C1EA0 @ =0x003C0000
	orrs r0, r2
	orrs r1, r3
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldr r0, _080C1EA4 @ =0x000002C2
	add r0, r10
	mov r1, sp
	ldrh r1, [r1, #0x04]
	strh r1, [r0, #0x00]
	ldr r0, _080C1EA8 @ =0x000002BE
	add r0, r10
	movs r2, #0x10
	strh r2, [r0, #0x00]
	movs r0, #0xB0
	lsls r0, r0, #0x02
	add r0, r10
	strh r2, [r0, #0x00]
	movs r1, #0xAF
	lsls r1, r1, #0x02
	add r1, r10
	movs r0, #0x20
	strh r0, [r1, #0x00]
	movs r4, #0x98
	lsls r4, r4, #0x02
	add r4, r10
	adds r0, r4, #0x0
	movs r1, #0x07
	movs r2, #0x10
	movs r3, #0x20
	bl func_080122AC
	ldr r1, [r7, #0x04]
	ldr r2, [r7, #0x08]
	ldr r3, [r7, #0x0C]
	adds r0, r4, #0x0
	bl func_08012324
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08012614
	adds r0, r7, #0x0
	mov r1, r9
	bl func_0801BDD4
	ldr r4, _080C1EAC @ =0x02039B84
	ldr r0, [r4, #0x00]
	adds r0, #0xD8
	mov r3, sp
	ldrh r3, [r3, #0x04]
	strh r3, [r0, #0x00]
	movs r0, #0x00
	movs r1, #0x01
	bl func_0801C298
	movs r0, #0xC8
	lsls r0, r0, #0x07
	mov r1, r8
	movs r2, #0x00
	bl func_0801BCC0
	movs r0, #0xA0
	lsls r0, r0, #0x06
	mov r1, r8
	movs r2, #0x00
	bl func_0801C274
	movs r0, #0xDF
	lsls r0, r0, #0x02
	add r0, r10
	ldr r1, _080C1EB0 @ =0x09EF2E50
	mov r2, r10
	bl TaskCreate
	ldr r2, [r4, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xCC
	mov r3, r10
	ldr r0, [r3, #0x04]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r3, #0x08]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r3, #0x0C]
	str r0, [r1, #0x00]
_080C1E6E:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C1E80: .4byte 0xFFFF9C00
_080C1E84: .4byte 0x0961A7B0
_080C1E88: .4byte 0x01000000
_080C1E8C: .4byte 0x00000000
_080C1E90: .4byte 0xFFFF7400
_080C1E94: .4byte 0x00000400
_080C1E98: .4byte 0x00000000
_080C1E9C: .4byte 0x01000004
_080C1EA0: .4byte 0x003C0000
_080C1EA4: .4byte 0x000002C2
_080C1EA8: .4byte 0x000002BE
_080C1EAC: .4byte 0x02039B84
_080C1EB0: .4byte 0x09EF2E50
.syntax divided
