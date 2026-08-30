.syntax unified
	.align 2, 0
	.global task_sroll_tmr_2
	.thumb
	.thumb_func
	.type task_sroll_tmr_2, %function
task_sroll_tmr_2: @ 08115314
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r7, r0, #0x0
	ldrb r0, [r7, #0x00]
	cmp r0, #0x00
	bne _08115328
	b _08115472
_08115328:
	ldr r4, [r7, #0x04]
	movs r1, #0xE1
	lsls r1, r1, #0x04
	adds r0, r4, #0x0
	bl __divsi3
	adds r5, r0, #0x0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r0, r4, #0x0
	movs r1, #0x3C
	bl __divsi3
	movs r1, #0x3C
	bl __modsi3
	mov r8, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	adds r0, r4, #0x0
	movs r1, #0x3C
	bl __modsi3
	mov r9, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	movs r4, #0x00
	ldr r6, _08115480 @ =0x09EFBAE8
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x0E
	adds r0, r0, r6
	ldr r2, [r0, #0x00]
	ldr r3, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0x08
	movs r1, #0x08
	bl func_080023E0
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x0E
	adds r0, r0, r6
	ldr r2, [r0, #0x00]
	ldr r3, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0x10
	movs r1, #0x08
	bl func_080023E0
	ldr r2, [r6, #0x28]
	ldr r3, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0x18
	movs r1, #0x08
	bl func_080023E0
	mov r0, r8
	movs r1, #0x0A
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x0E
	adds r0, r0, r6
	ldr r2, [r0, #0x00]
	ldr r3, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0x20
	movs r1, #0x08
	bl func_080023E0
	mov r0, r8
	movs r1, #0x0A
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x0E
	adds r0, r0, r6
	ldr r2, [r0, #0x00]
	ldr r3, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0x28
	movs r1, #0x08
	bl func_080023E0
	ldr r2, [r6, #0x28]
	ldr r3, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0x30
	movs r1, #0x08
	bl func_080023E0
	mov r0, r9
	movs r1, #0x0A
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x0E
	adds r0, r0, r6
	ldr r2, [r0, #0x00]
	ldr r3, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0x38
	movs r1, #0x08
	bl func_080023E0
	mov r0, r9
	movs r1, #0x0A
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x0E
	adds r0, r0, r6
	ldr r2, [r0, #0x00]
	ldr r3, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0x40
	movs r1, #0x08
	bl func_080023E0
_08115472:
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08115480: .4byte 0x09EFBAE8
.syntax divided
