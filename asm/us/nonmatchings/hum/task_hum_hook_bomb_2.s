.syntax unified
	.align 2, 0
	.global task_hum_hook_bomb_2
	.thumb
	.thumb_func
	.type task_hum_hook_bomb_2, %function
task_hum_hook_bomb_2: @ 0804CF24
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	adds r0, #0x48
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0804CFD8
	adds r0, r7, #0x0
	adds r0, #0x08
	bl func_08005AFC
	mov r9, r0
	ldr r0, [r7, #0x24]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r7, #0x0
	adds r0, #0x2C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0804CF5A
	movs r0, #0x01
	orrs r5, r0
_0804CF5A:
	mov r6, sp
	adds r6, #0x12
	ldr r2, [r7, #0x20]
	ldr r3, [r7, #0x24]
	ldr r0, [r7, #0x28]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	ldr r3, [r7, #0x00]
	ldr r2, [r7, #0x04]
	str r2, [sp, #0x000]
	movs r4, #0x00
	mov r8, r4
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, [r7, #0x24]
	movs r2, #0x80
	lsls r2, r2, #0x04
	adds r4, r4, r2
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	mov r12, r4
	ldr r4, _0804CFE8 @ =0xFFFFEFFC
	adds r2, r4, #0x0
	mov r4, r12
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	mov r2, r9
	bl func_080023E0
	ldr r2, [r7, #0x20]
	ldr r3, [r7, #0x24]
	mov r0, r8
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	ldr r2, _0804CFEC @ =0x08B22CBC
	ldr r3, [r7, #0x40]
	ldr r4, [r7, #0x44]
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _0804CFF0 @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl func_080023E0
_0804CFD8:
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0804CFE8: .4byte 0xFFFFEFFC
_0804CFEC: .4byte 0x08B22CBC
_0804CFF0: .4byte 0x0000FFF0
.syntax divided
