.syntax unified
	.align 2, 0
	.global task_bos_md_hahen_2
	.thumb
	.thumb_func
	.type task_bos_md_hahen_2, %function
task_bos_md_hahen_2: @ 080FD930
	push {r4, r5, r6, r7, lr}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldr r0, _080FD998 @ =0x03007480
	ldr r7, [r0, #0x00]
	movs r0, #0x01
	ands r7, r0
	cmp r7, #0x00
	bne _080FD98E
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r6, #0x00]
	ldr r3, [r6, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	ldr r0, [r6, #0x04]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r1, sp, #0x010
	movs r2, #0x00
	ldsh r5, [r1, r2]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r6, #0x20]
	ldr r3, [r6, #0x1C]
	ldr r4, [r6, #0x18]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	str r0, [sp, #0x008]
	ldr r4, [r6, #0x04]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r6, _080FD99C @ =0xFFFFEFFC
	adds r0, r6, #0x0
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r5, #0x0
	bl func_080023E0
_080FD98E:
	add sp, #0x014
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080FD998: .4byte 0x03007480
_080FD99C: .4byte 0xFFFFEFFC
.syntax divided
