.syntax unified
	.align 2, 0
	.global task_sroll_c_char_2
	.thumb
	.thumb_func
	.type task_sroll_c_char_2, %function
task_sroll_c_char_2: @ 08115244
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	movs r7, #0x00
	adds r4, r5, #0x0
	adds r4, #0x20
	movs r6, #0x04
_08115252:
	adds r0, r4, #0x0
	bl func_08005AFC
	adds r2, r0, #0x0
	ldr r3, [r5, #0x18]
	ldr r0, [r5, #0x1C]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r7, [sp, #0x008]
	movs r0, #0xFF
	lsls r0, r0, #0x04
	str r0, [sp, #0x00C]
	movs r0, #0x78
	movs r1, #0x50
	bl func_080023E0
	adds r4, #0x18
	subs r6, #0x01
	cmp r6, #0x00
	bge _08115252
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
