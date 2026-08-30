.syntax unified
	.align 2, 0
	.global task_bos_lst_snp_2
	.thumb
	.thumb_func
	.type task_bos_lst_snp_2, %function
task_bos_lst_snp_2: @ 08112514
	push {r4, r5, r6, lr}
	mov r6, r9
	mov r5, r8
	push {r5, r6}
	add sp, #-0x014
	adds r4, r0, #0x0
	movs r0, #0x12
	add r0, sp
	mov r8, r0
	ldr r2, [r4, #0x04]
	ldr r3, [r4, #0x08]
	ldr r0, [r4, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl func_0801909C
	ldrb r0, [r4, #0x00]
	movs r1, #0x01
	bl func_08002C28
	adds r6, r0, #0x0
	adds r0, r4, #0x0
	adds r0, #0x20
	bl func_08005AFC
	mov r9, r0
	ldr r0, [r4, #0x08]
	bl func_0801AF1C
	movs r1, #0x04
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r1, sp, #0x010
	movs r2, #0x00
	ldsh r5, [r1, r2]
	mov r3, r8
	movs r2, #0x00
	ldsh r1, [r3, r2]
	ldr r3, [r4, #0x18]
	ldr r2, [r4, #0x1C]
	str r2, [sp, #0x000]
	str r6, [sp, #0x004]
	str r0, [sp, #0x008]
	ldr r2, [r4, #0x08]
	asrs r2, r2, #0x08
	lsls r2, r2, #0x02
	ldr r4, _08112598 @ =0xFFFFEFFC
	adds r0, r4, #0x0
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r5, #0x0
	mov r2, r9
	bl func_080023E0
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08112598: .4byte 0xFFFFEFFC
.syntax divided
