.syntax unified
	.align 2, 0
	.global task_bos_ursula_bubble_single_2
	.thumb
	.thumb_func
	.type task_bos_ursula_bubble_single_2, %function
task_bos_ursula_bubble_single_2: @ 080DDC84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	adds r5, r6, #0x0
	adds r5, #0x24
	ldr r0, [r5, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	adds r0, r5, #0x0
	bl func_0801CA00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DDCAE
	ldr r7, [r6, #0x08]
	b _080DDCB0
_080DDCAE:
	ldr r7, [r6, #0x04]
_080DDCB0:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	adds r0, r6, #0x0
	adds r0, #0x0C
	bl AnimGetGfx
	adds r2, r0, #0x0
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r3, #0x00
	ldsh r1, [r4, r3]
	ldr r3, [r6, #0x00]
	str r7, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r5, [r5, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r6, _080DDD08 @ =0xFFFFEFFC
	adds r4, r6, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DDD08: .4byte 0xFFFFEFFC
.syntax divided
