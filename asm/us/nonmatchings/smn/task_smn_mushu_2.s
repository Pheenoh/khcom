.syntax unified
	.align 2, 0
	.global task_smn_mushu_2
	.thumb
	.thumb_func
	.type task_smn_mushu_2, %function
task_smn_mushu_2: @ 08043BD4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	movs r0, #0x38
	adds r0, r0, r7
	mov r8, r0
	adds r0, r7, #0x0
	adds r0, #0x08
	bl AnimGetGfx
	mov r10, r0
	mov r1, r8
	ldr r0, [r1, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	mov r2, r8
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08043C20
	ldr r0, _08043C1C @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r5, [r0, #0x24]
	adds r6, r5, #0x0
	b _08043C58
_08043C1C: .4byte 0x02039B84
_08043C20:
	ldr r0, _08043C4C @ =0x02039B84
	ldr r1, [r0, #0x00]
	ldr r2, [r1, #0x24]
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r3, r0, #0x0
	cmp r2, r1
	bne _08043C50
	movs r5, #0xA6
	lsls r5, r5, #0x01
	adds r0, r7, r5
	ldr r0, [r0, #0x00]
	cmp r0, r2
	bne _08043C50
	adds r5, r0, #0x0
	adds r6, r5, #0x0
	movs r0, #0x01
	mov r1, r9
	orrs r1, r0
	mov r9, r1
	b _08043C58
	.byte 0x00, 0x00
_08043C4C: .4byte 0x02039B84
_08043C50:
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x24]
	negs r6, r0
	adds r5, r0, #0x0
_08043C58:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r0, r7, r2
	ldr r1, [r0, #0x00]
	adds r0, r6, #0x0
	muls r0, r1
	asrs r6, r0, #0x08
	adds r0, r5, #0x0
	muls r0, r1
	asrs r5, r0, #0x08
	mov r4, sp
	adds r4, #0x12
	mov r0, r8
	ldr r2, [r0, #0x04]
	ldr r3, [r0, #0x08]
	ldr r0, [r0, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r6, r0
	bgt _08043C98
	cmp r5, r0
	bgt _08043C98
	movs r0, #0x00
	adds r1, r6, #0x0
	adds r2, r5, #0x0
	movs r3, #0x00
	b _08043CA0
_08043C98:
	movs r0, #0x00
	adds r1, r6, #0x0
	adds r2, r5, #0x0
	movs r3, #0x01
_08043CA0:
	bl AllocObjAffine
	adds r5, r0, #0x0
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r3, [r7, #0x00]
	ldr r2, [r7, #0x04]
	str r2, [sp, #0x000]
	str r5, [sp, #0x004]
	mov r5, r9
	str r5, [sp, #0x008]
	mov r2, r8
	ldr r4, [r2, #0x08]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r5, _08043CF0 @ =0xFFFFEFFB
	adds r2, r5, #0x0
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	mov r2, r10
	bl DrawSprite
	adds r0, r7, #0x0
	adds r0, #0x20
	bl TaskPoolDraw
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08043CF0: .4byte 0xFFFFEFFB
.syntax divided
