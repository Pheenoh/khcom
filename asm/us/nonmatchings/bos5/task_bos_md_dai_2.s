.syntax unified
	.align 2, 0
	.global task_bos_md_dai_2
	.thumb
	.thumb_func
	.type task_bos_md_dai_2, %function
task_bos_md_dai_2: @ 080FD698
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	movs r0, #0x12
	add r0, sp
	mov r9, r0
	ldr r2, [r7, #0x00]
	ldr r3, [r7, #0x04]
	ldr r0, [r7, #0x08]
	ldr r1, [r7, #0x0C]
	adds r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r9
	bl WorldToScreen
	ldr r0, [r7, #0x04]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r7, #0x0
	adds r0, #0x7E
	ldrh r0, [r0, #0x00]
	cmp r0, #0x02
	bhi _080FD76E
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r9
	ldrh r1, [r2, #0x00]
	adds r1, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r3, _080FD7E0 @ =0x09999E0C
	mov r8, r3
	ldr r3, [r7, #0x18]
	ldr r2, [r7, #0x14]
	str r2, [sp, #0x000]
	movs r4, #0x00
	mov r10, r4
	str r4, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r2, [r7, #0x04]
	asrs r2, r2, #0x08
	lsls r2, r2, #0x02
	ldr r4, _080FD7E4 @ =0xFFFFEFFC
	adds r5, r4, #0x0
	subs r2, r5, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	mov r2, r8
	bl DrawSprite
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r9
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r2, _080FD7E8 @ =0x09999E1C
	ldr r3, [r7, #0x18]
	ldr r4, [r7, #0x14]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r4, [r7, #0x04]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	subs r4, r5, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	adds r0, #0x08
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r9
	ldrh r1, [r2, #0x00]
	subs r1, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r3, [r7, #0x18]
	ldr r2, [r7, #0x14]
	str r2, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r2, [r7, #0x04]
	asrs r2, r2, #0x08
	lsls r2, r2, #0x02
	subs r5, r5, r2
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r5, [sp, #0x00C]
	mov r2, r8
	bl DrawSprite
_080FD76E:
	ldr r2, [r7, #0x00]
	ldr r3, [r7, #0x04]
	ldr r0, [r7, #0x08]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r9
	bl WorldToScreen
	ldr r0, [r7, #0x04]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r2, r7, #0x0
	adds r2, #0x7C
	movs r1, #0x00
	ldsh r0, [r2, r1]
	cmp r0, #0x00
	ble _080FD7D0
	add r0, sp, #0x010
	movs r3, #0x00
	ldsh r0, [r0, r3]
	mov r4, r9
	movs r3, #0x00
	ldsh r1, [r4, r3]
	ldr r3, _080FD7EC @ =0x09EF9740
	movs r4, #0x00
	ldsh r2, [r2, r4]
	adds r2, #0x01
	lsls r2, r2, #0x02
	adds r2, r2, r3
	ldr r2, [r2, #0x00]
	ldr r3, [r7, #0x18]
	ldr r4, [r7, #0x14]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r5, [r7, #0x04]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r6, _080FD7E4 @ =0xFFFFEFFC
	adds r4, r6, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
_080FD7D0:
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080FD7E0: .4byte 0x09999E0C
_080FD7E4: .4byte 0xFFFFEFFC
_080FD7E8: .4byte 0x09999E1C
_080FD7EC: .4byte 0x09EF9740
.syntax divided
