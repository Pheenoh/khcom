.syntax unified
	.align 2, 0
	.global task_frd_beast_2
	.thumb
	.thumb_func
	.type task_frd_beast_2, %function
task_frd_beast_2: @ 08049C78
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	mov r9, r0
	mov r7, r9
	adds r7, #0x20
	movs r0, #0x98
	lsls r0, r0, #0x01
	add r0, r9
	bl AnimGetGfx
	mov r10, r0
	ldr r0, [r7, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08049CC0
	ldr r0, _08049CBC @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r5, [r0, #0x24]
	adds r6, r5, #0x0
	b _08049CE4
_08049CBC: .4byte 0x02039B84
_08049CC0:
	ldr r0, _08049CDC @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _08049CE0
	adds r5, r2, #0x0
	adds r6, r5, #0x0
	movs r0, #0x01
	mov r1, r8
	orrs r1, r0
	mov r8, r1
	b _08049CE4
_08049CDC: .4byte 0x02039B84
_08049CE0:
	negs r6, r2
	adds r5, r2, #0x0
_08049CE4:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r7, #0x04]
	ldr r3, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	ldr r0, _08049D0C @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	bne _08049D10
	movs r5, #0x00
	b _08049D2C
	.byte 0x00, 0x00
_08049D0C: .4byte 0x02039B84
_08049D10:
	cmp r1, #0xFF
	bgt _08049D1E
	movs r0, #0x00
	adds r1, r6, #0x0
	adds r2, r5, #0x0
	movs r3, #0x00
	b _08049D26
_08049D1E:
	movs r0, #0x00
	adds r1, r6, #0x0
	adds r2, r5, #0x0
	movs r3, #0x01
_08049D26:
	bl AllocObjAffine
	adds r5, r0, #0x0
_08049D2C:
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	mov r4, r9
	ldr r3, [r4, #0x18]
	ldr r2, [r4, #0x1C]
	str r2, [sp, #0x000]
	str r5, [sp, #0x004]
	mov r5, r8
	str r5, [sp, #0x008]
	ldr r2, [r7, #0x08]
	asrs r2, r2, #0x08
	lsls r2, r2, #0x02
	ldr r5, _08049D84 @ =0xFFFFEFFC
	adds r4, r5, #0x0
	subs r2, r4, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	mov r2, r10
	bl DrawSprite
	ldr r0, [r7, #0x08]
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	subs r4, r4, r0
	movs r0, #0x02
	adds r1, r7, #0x0
	adds r1, #0xCC
	orrs r4, r0
	strh r4, [r1, #0x00]
	mov r0, r9
	bl TaskPoolDraw
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08049D84: .4byte 0xFFFFEFFC
.syntax divided
