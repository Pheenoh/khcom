.syntax unified
	.align 2, 0
	.global task_bos_ursula_border_2
	.thumb
	.thumb_func
	.type task_bos_ursula_border_2, %function
task_bos_ursula_border_2: @ 080DC914
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	adds r6, r0, #0x0
	movs r4, #0xCC
	lsls r4, r4, #0x09
	adds r0, r4, #0x0
	bl func_0801AF1C
	movs r0, #0x12
	add r0, sp
	mov r8, r0
	movs r2, #0x80
	lsls r2, r2, #0x08
	ldr r5, _080DC9B8 @ =0xFFFFF800
	str r5, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	adds r3, r4, #0x0
	bl func_0801909C
	add r1, sp, #0x014
	mov r10, r1
	mov r7, sp
	adds r7, #0x16
	movs r2, #0xC0
	lsls r2, r2, #0x09
	str r5, [sp, #0x000]
	mov r0, r10
	adds r1, r7, #0x0
	adds r3, r4, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	mov r3, r8
	movs r4, #0x00
	ldsh r1, [r3, r4]
	ldr r2, _080DC9BC @ =0x0979D090
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	mov r9, r4
	str r4, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	mov r8, r4
	str r4, [sp, #0x008]
	movs r5, #0xFB
	lsls r5, r5, #0x08
	str r5, [sp, #0x00C]
	bl func_080023E0
	mov r1, r10
	movs r2, #0x00
	ldsh r0, [r1, r2]
	movs r3, #0x00
	ldsh r1, [r7, r3]
	ldr r2, _080DC9C0 @ =0x0979D8B8
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	mov r4, r9
	str r4, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	str r5, [sp, #0x00C]
	bl func_080023E0
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080DC9B8: .4byte 0xFFFFF800
_080DC9BC: .4byte 0x0979D090
_080DC9C0: .4byte 0x0979D8B8
.syntax divided
