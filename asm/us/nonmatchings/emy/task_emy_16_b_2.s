.syntax unified
	.align 2, 0
	.global task_emy_16_b_2
	.thumb
	.thumb_func
	.type task_emy_16_b_2, %function
task_emy_16_b_2: @ 080390BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r5, r0, #0x0
	adds r0, #0x08
	bl AnimGetGfx
	mov r8, r0
	adds r0, r5, #0x0
	adds r0, #0x9C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08039164
	ldr r0, [r5, #0x24]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x20]
	ldr r3, [r5, #0x24]
	ldr r0, [r5, #0x28]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	ldr r0, _08039118 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x01
	adds r7, r4, #0x0
	cmp r2, r0
	bne _0803911C
	movs r4, #0x00
	adds r0, r5, #0x0
	adds r0, #0x2C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08039138
	movs r0, #0x01
	orrs r6, r0
	b _08039138
_08039118: .4byte 0x02039B84
_0803911C:
	adds r0, r5, #0x0
	adds r0, #0x2C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0803912C
	negs r1, r2
	movs r0, #0x00
	b _08039130
_0803912C:
	movs r0, #0x00
	adds r1, r2, #0x0
_08039130:
	movs r3, #0x01
	bl AllocObjAffine
	adds r4, r0, #0x0
_08039138:
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r7, r2]
	ldr r3, [r5, #0x00]
	ldr r2, [r5, #0x04]
	str r2, [sp, #0x000]
	str r4, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r4, [r5, #0x24]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r5, _08039170 @ =0xFFFFEFFC
	adds r2, r5, #0x0
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	mov r2, r8
	bl DrawSprite
_08039164:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08039170: .4byte 0xFFFFEFFC
.syntax divided
