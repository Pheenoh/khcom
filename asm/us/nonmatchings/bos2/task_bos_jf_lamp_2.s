.syntax unified
	.align 2, 0
	.global task_bos_jf_lamp_2
	.thumb
	.thumb_func
	.type task_bos_jf_lamp_2, %function
task_bos_jf_lamp_2: @ 080BE118
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	ldr r0, [r7, #0x00]
	movs r1, #0x88
	lsls r1, r1, #0x01
	adds r1, r1, r0
	mov r9, r1
	ldr r0, [r1, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r10, r0
	mov r2, r9
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080BE15C
	ldr r0, _080BE158 @ =0x0000FFFE
	mov r4, r10
	ands r4, r0
	mov r10, r4
	b _080BE164
_080BE158: .4byte 0x0000FFFE
_080BE15C:
	movs r0, #0x01
	mov r5, r10
	orrs r5, r0
	mov r10, r5
_080BE164:
	ldr r0, _080BE194 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080BE19C
	ldr r0, [r7, #0x00]
	movs r6, #0x93
	lsls r6, r6, #0x02
	adds r0, r0, r6
	ldrh r1, [r0, #0x00]
	movs r2, #0x01
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _080BE19C
	ldr r0, _080BE198 @ =0x03007480
	ldr r0, [r0, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _080BE19C
	ldr r4, [r7, #0x18]
	b _080BE19E
	.byte 0x00, 0x00
_080BE194: .4byte 0x02039B84
_080BE198: .4byte 0x03007480
_080BE19C:
	ldr r4, [r7, #0x14]
_080BE19E:
	mov r6, sp
	adds r6, #0x12
	mov r0, r9
	ldr r2, [r0, #0x04]
	ldr r3, [r0, #0x08]
	ldr r0, [r0, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	ldr r2, [r7, #0x08]
	ldr r3, [r7, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	mov r8, r4
	str r4, [sp, #0x004]
	mov r5, r10
	str r5, [sp, #0x008]
	mov r4, r9
	ldr r5, [r4, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	mov r12, r5
	ldr r5, _080BE244 @ =0xFFFFEFFC
	adds r4, r5, #0x0
	mov r5, r12
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldrh r1, [r6, #0x00]
	subs r1, #0x0E
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x10]
	ldr r3, [r7, #0x0C]
	ldr r4, [r7, #0x14]
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	mov r5, r10
	str r5, [sp, #0x008]
	mov r6, r9
	ldr r5, [r6, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r6, _080BE248 @ =0xFFFFEFFB
	adds r4, r6, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	adds r0, r7, #0x0
	adds r0, #0x2D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080BE232
	adds r0, r7, #0x0
	adds r0, #0x44
	bl TaskPoolDraw
_080BE232:
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080BE244: .4byte 0xFFFFEFFC
_080BE248: .4byte 0xFFFFEFFB
.syntax divided
