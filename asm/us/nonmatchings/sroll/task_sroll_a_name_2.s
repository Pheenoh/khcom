.syntax unified
	.align 2, 0
	.global task_sroll_a_name_2
	.thumb
	.thumb_func
	.type task_sroll_a_name_2, %function
task_sroll_a_name_2: @ 081148D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r6, r0, #0x0
	movs r1, #0x04
	ldsh r0, [r6, r1]
	cmp r0, #0x1D
	bgt _0811490C
	ldr r0, [r6, #0x10]
	ldr r4, [r6, #0x08]
	subs r0, r0, r4
	movs r2, #0x04
	ldsh r5, [r6, r2]
	muls r0, r5
	movs r1, #0x1E
	bl func_0811D5EC
	adds r7, r4, r0
	ldr r0, [r6, #0x14]
	ldr r4, [r6, #0x0C]
	subs r0, r0, r4
	muls r0, r5
	movs r1, #0x1E
	bl func_0811D5EC
	adds r4, r4, r0
	b _08114910
_0811490C:
	ldr r7, [r6, #0x10]
	ldr r4, [r6, #0x14]
_08114910:
	movs r0, #0x00
	mov r8, r0
	movs r1, #0x02
	ldsh r0, [r6, r1]
	adds r5, r6, #0x0
	adds r5, #0x20
	cmp r0, #0x02
	bne _08114948
	movs r2, #0x04
	mov r8, r2
	adds r0, r5, #0x0
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x0B
	adds r0, #0x20
	ldr r1, _08114988 @ =0x09D6CD74
	adds r0, r0, r1
	ldr r1, [r6, #0x1C]
	ldrh r2, [r1, #0x06]
	movs r1, #0x0F
	ands r1, r2
	lsls r1, r1, #0x05
	ldr r2, _0811498C @ =0x05000220
	adds r1, r1, r2
	movs r2, #0x20
	bl func_08005BE8
_08114948:
	adds r0, r5, #0x0
	bl func_08005AFC
	adds r2, r0, #0x0
	lsls r0, r7, #0x08
	asrs r0, r0, #0x10
	lsls r1, r4, #0x08
	asrs r1, r1, #0x10
	ldr r3, [r6, #0x18]
	ldr r4, [r6, #0x1C]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldrh r5, [r6, #0x02]
	movs r6, #0xFF
	lsls r6, r6, #0x04
	adds r4, r6, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08114988: .4byte 0x09D6CD74
_0811498C: .4byte 0x05000220
.syntax divided
