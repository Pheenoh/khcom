.syntax unified
	.align 2, 0
	.global task_hum_vixen_frg_2
	.thumb
	.thumb_func
	.type task_hum_vixen_frg_2, %function
task_hum_vixen_frg_2: @ 08055FFC
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	movs r1, #0x87
	lsls r1, r1, #0x02
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0805601E
	ldrh r1, [r7, #0x38]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _0805608E
_0805601E:
	movs r2, #0x12
	add r2, sp
	mov r8, r2
	adds r6, r7, #0x0
	adds r6, #0x3C
	movs r3, #0x0E
	mov r9, r3
_0805602C:
	ldr r0, [r6, #0x08]
	bl func_0801AF1C
	adds r5, r0, #0x0
	ldrh r0, [r6, #0x1C]
	orrs r5, r0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r2, [r6, #0x04]
	ldr r3, [r6, #0x08]
	ldr r0, [r6, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r2, [r6, #0x00]
	ldr r3, [r7, #0x30]
	ldr r4, [r7, #0x34]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r5, [r6, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	mov r12, r5
	ldr r5, _0805609C @ =0xFFFFEFFC
	adds r4, r5, #0x0
	mov r5, r12
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	adds r6, #0x20
	movs r0, #0x01
	negs r0, r0
	add r9, r0
	mov r1, r9
	cmp r1, #0x00
	bge _0805602C
_0805608E:
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0805609C: .4byte 0xFFFFEFFC
.syntax divided
