.syntax unified
	.align 2, 0
	.global task_bos_pc_fld_2
	.thumb
	.thumb_func
	.type task_bos_pc_fld_2, %function
task_bos_pc_fld_2: @ 0810B6FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	bl func_0810B4F4
	ldr r0, _0810B798 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x7C]
	ldr r1, [r2, #0x0C]
	ldr r0, _0810B79C @ =0xFFFFFF00
	cmp r1, r0
	blt _0810B78A
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	movs r2, #0x80
	ands r0, r2
	movs r1, #0x00
	adds r2, r1, #0x0
	orrs r2, r0
	mov r8, r2
	cmp r2, #0x00
	bne _0810B78A
	ldr r0, [r7, #0x08]
	cmp r0, #0x00
	beq _0810B78A
	ldr r0, [r7, #0x0C]
	cmp r0, #0x00
	beq _0810B78A
	movs r2, #0xB8
	lsls r2, r2, #0x09
	movs r5, #0xA4
	lsls r5, r5, #0x09
	ldr r0, _0810B7A0 @ =0xFFFFF800
	mov r4, sp
	adds r4, #0x12
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	adds r3, r5, #0x0
	bl func_0801909C
	adds r0, r5, #0x0
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r1, sp, #0x010
	movs r2, #0x00
	ldsh r6, [r1, r2]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, _0810B7A4 @ =0x09EFBEB8
	ldr r2, [r2, #0x00]
	ldr r3, [r7, #0x08]
	ldr r4, [r7, #0x0C]
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	str r0, [sp, #0x008]
	lsrs r5, r5, #0x06
	ldr r4, _0810B7A8 @ =0xFFFFEFFC
	adds r0, r4, #0x0
	subs r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r6, #0x0
	bl func_080023E0
_0810B78A:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0810B798: .4byte 0x02039B84
_0810B79C: .4byte 0xFFFFFF00
_0810B7A0: .4byte 0xFFFFF800
_0810B7A4: .4byte 0x09EFBEB8
_0810B7A8: .4byte 0xFFFFEFFC
.syntax divided
