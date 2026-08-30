.syntax unified
	.align 2, 0
	.global task_title_obj_2
	.thumb
	.thumb_func
	.type task_title_obj_2, %function
task_title_obj_2: @ 080D66FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r6, r0, #0x0
	adds r0, #0x48
	bl func_08005A64
	str r0, [r6, #0x20]
	movs r0, #0x00
	mov r8, r0
	adds r5, r6, #0x0
	movs r7, #0x00
_080D6716:
	adds r0, r6, #0x0
	adds r0, #0x10
	adds r0, r0, r7
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	movs r2, #0x0C
	ldsh r1, [r5, r2]
	adds r2, r6, #0x0
	adds r2, #0x08
	adds r2, r2, r7
	ldr r2, [r2, #0x00]
	ldr r3, [r5, #0x00]
	adds r4, r6, #0x4
	adds r4, r4, r7
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	mov r4, r8
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
	adds r5, #0x18
	adds r7, #0x18
	movs r0, #0x01
	add r8, r0
	mov r2, r8
	cmp r2, #0x01
	ble _080D6716
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
