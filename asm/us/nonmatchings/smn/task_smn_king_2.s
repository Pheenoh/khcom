.syntax unified
	.align 2, 0
	.global task_smn_king_2
	.thumb
	.thumb_func
	.type task_smn_king_2, %function
task_smn_king_2: @ 080452DC
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	mov r8, r0
	mov r7, r8
	adds r7, #0x38
	adds r0, #0x08
	bl func_08005AFC
	mov r10, r0
	ldr r0, [r7, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08045320
	ldr r0, _0804531C @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r5, [r0, #0x24]
	adds r6, r5, #0x0
	b _08045358
_0804531C: .4byte 0x02039B84
_08045320:
	ldr r0, _0804534C @ =0x02039B84
	ldr r1, [r0, #0x00]
	ldr r2, [r1, #0x24]
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r3, r0, #0x0
	cmp r2, r1
	bne _08045350
	movs r0, #0xAA
	lsls r0, r0, #0x01
	add r0, r8
	ldr r0, [r0, #0x00]
	cmp r0, r2
	bne _08045350
	adds r5, r0, #0x0
	adds r6, r5, #0x0
	movs r0, #0x01
	mov r1, r9
	orrs r1, r0
	mov r9, r1
	b _08045358
	.byte 0x00, 0x00
_0804534C: .4byte 0x02039B84
_08045350:
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x24]
	negs r6, r0
	adds r5, r0, #0x0
_08045358:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	add r0, r8
	ldr r1, [r0, #0x00]
	adds r0, r6, #0x0
	muls r0, r1
	asrs r6, r0, #0x08
	adds r0, r5, #0x0
	muls r0, r1
	asrs r5, r0, #0x08
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r7, #0x04]
	ldr r3, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r6, r0
	bgt _08045396
	cmp r5, r0
	bgt _08045396
	movs r0, #0x00
	adds r1, r6, #0x0
	adds r2, r5, #0x0
	movs r3, #0x00
	b _0804539E
_08045396:
	movs r0, #0x00
	adds r1, r6, #0x0
	adds r2, r5, #0x0
	movs r3, #0x01
_0804539E:
	bl func_08002CB4
	adds r5, r0, #0x0
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	mov r4, r8
	ldr r3, [r4, #0x00]
	ldr r2, [r4, #0x04]
	str r2, [sp, #0x000]
	str r5, [sp, #0x004]
	mov r5, r9
	str r5, [sp, #0x008]
	ldr r2, [r7, #0x08]
	asrs r2, r2, #0x08
	lsls r2, r2, #0x02
	ldr r5, _08045400 @ =0xFFFFEFFC
	adds r4, r5, #0x0
	subs r2, r4, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	mov r2, r10
	bl func_080023E0
	ldr r0, [r7, #0x08]
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	subs r4, r4, r0
	movs r0, #0x02
	adds r1, r7, #0x0
	adds r1, #0xCC
	orrs r4, r0
	strh r4, [r1, #0x00]
	mov r0, r8
	adds r0, #0x20
	bl func_08000EE0
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08045400: .4byte 0xFFFFEFFC
.syntax divided
