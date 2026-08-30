.syntax unified
	.align 2, 0
	.global task_emy_83_s_2
	.thumb
	.thumb_func
	.type task_emy_83_s_2, %function
task_emy_83_s_2: @ 0803EC58
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldr r0, [r6, #0x0C]
	bl func_0801AF1C
	mov r8, r0
	mov r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r1, #0x12
	add r1, sp
	mov r10, r1
	ldr r2, [r6, #0x08]
	ldr r3, [r6, #0x0C]
	ldr r0, [r6, #0x10]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	bl func_0801909C
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	mov r3, r10
	movs r4, #0x00
	ldsh r1, [r3, r4]
	ldr r2, _0803ED0C @ =0x08B1D828
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	movs r7, #0x00
	mov r9, r7
	mov r4, r9
	str r4, [sp, #0x004]
	mov r7, r8
	str r7, [sp, #0x008]
	ldr r5, [r6, #0x0C]
	movs r4, #0x80
	lsls r4, r4, #0x03
	adds r5, r5, r4
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r7, _0803ED10 @ =0xFFFFEFFC
	adds r4, r7, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
	ldr r2, [r6, #0x08]
	ldr r3, [r6, #0x0C]
	mov r0, r9
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r10
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r10
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r2, _0803ED14 @ =0x08B1D832
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	mov r4, r9
	str r4, [sp, #0x004]
	mov r7, r8
	str r7, [sp, #0x008]
	ldr r4, _0803ED18 @ =0x0000FFFE
	str r4, [sp, #0x00C]
	bl func_080023E0
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0803ED0C: .4byte 0x08B1D828
_0803ED10: .4byte 0xFFFFEFFC
_0803ED14: .4byte 0x08B1D832
_0803ED18: .4byte 0x0000FFFE
.syntax divided
