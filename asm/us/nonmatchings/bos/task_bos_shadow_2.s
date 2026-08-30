.syntax unified
	.align 2, 0
	.global task_bos_shadow_2
	.thumb
	.thumb_func
	.type task_bos_shadow_2, %function
task_bos_shadow_2: @ 0803F198
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	ldr r6, [r7, #0x08]
	movs r5, #0x00
	ldr r0, _0803F234 @ =0x08B22BA8
	mov r9, r0
	ldr r0, [r6, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x0C]
	subs r0, r0, r1
	asrs r0, r0, #0x07
	movs r4, #0x80
	lsls r4, r4, #0x01
	subs r3, r4, r0
	cmp r3, #0xB2
	bgt _0803F1CC
	movs r3, #0xB3
_0803F1CC:
	ldr r0, [r7, #0x08]
	ldr r1, [r0, #0x38]
	ldr r0, [r0, #0x34]
	movs r2, #0x80
	lsls r2, r2, #0x0A
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803F1E4
	adds r3, r3, r4
	movs r5, #0x01
_0803F1E4:
	movs r0, #0x00
	adds r1, r3, #0x0
	adds r2, r3, #0x0
	adds r3, r5, #0x0
	bl func_08002CB4
	adds r5, r0, #0x0
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r6, #0x04]
	ldr r3, [r6, #0x08]
	ldr r0, [r6, #0x10]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r3, [r7, #0x00]
	ldr r2, [r7, #0x04]
	str r2, [sp, #0x000]
	str r5, [sp, #0x004]
	mov r2, r8
	str r2, [sp, #0x008]
	ldr r2, _0803F238 @ =0x0000FFF0
	str r2, [sp, #0x00C]
	mov r2, r9
	bl func_080023E0
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0803F234: .4byte 0x08B22BA8
_0803F238: .4byte 0x0000FFF0
.syntax divided
