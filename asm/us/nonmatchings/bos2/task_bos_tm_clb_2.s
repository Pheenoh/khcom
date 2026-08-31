.syntax unified
	.align 2, 0
	.global task_bos_tm_clb_2
	.thumb
	.thumb_func
	.type task_bos_tm_clb_2, %function
task_bos_tm_clb_2: @ 080BB354
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldrb r0, [r6, #0x0C]
	movs r1, #0x00
	bl func_08002C28
	mov r9, r0
	movs r0, #0x12
	add r0, sp
	mov r8, r0
	ldr r2, [r6, #0x10]
	ldr r3, [r6, #0x14]
	ldr r0, [r6, #0x18]
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
	ldr r2, _080BB404 @ =0x0962E838
	ldr r3, [r6, #0x04]
	ldr r4, [r6, #0x08]
	str r4, [sp, #0x000]
	mov r4, r9
	str r4, [sp, #0x004]
	movs r7, #0x80
	lsls r7, r7, #0x04
	mov r10, r7
	mov r4, r10
	str r4, [sp, #0x008]
	ldr r5, [r6, #0x14]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r7, _080BB408 @ =0xFFFFEFFE
	adds r4, r7, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	movs r0, #0x01
	mov r1, r9
	strb r0, [r1, #0x0A]
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	mov r3, r8
	movs r4, #0x00
	ldsh r1, [r3, r4]
	ldr r3, [r6, #0x00]
	ldr r2, [r3, #0x14]
	ldr r3, [r3, #0x10]
	ldr r4, [r6, #0x08]
	str r4, [sp, #0x000]
	mov r7, r9
	str r7, [sp, #0x004]
	mov r4, r10
	str r4, [sp, #0x008]
	ldr r5, [r6, #0x14]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r6, _080BB40C @ =0xFFFFEFFD
	adds r4, r6, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080BB404: .4byte 0x0962E838
_080BB408: .4byte 0xFFFFEFFE
_080BB40C: .4byte 0xFFFFEFFD
.syntax divided
