.syntax unified
	.align 2, 0
	.global task_btl_lockon_2
	.thumb
	.thumb_func
	.type task_btl_lockon_2, %function
task_btl_lockon_2: @ 0801D594
	push {r4, r5, r6, r7, lr}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldr r0, _0801D5F8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r5, [r0, #0x78]
	cmp r5, #0x00
	beq _0801D5F0
	mov r4, sp
	adds r4, #0x12
	adds r0, r5, #0x0
	adds r0, #0xA4
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x08
	ldr r2, [r5, #0x04]
	adds r2, r2, r0
	ldr r3, [r5, #0x08]
	adds r0, r5, #0x0
	adds r0, #0xA2
	movs r7, #0x00
	ldsh r1, [r0, r7]
	lsls r1, r1, #0x08
	ldr r0, [r5, #0x0C]
	subs r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r6, #0x20]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0x10
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	bl DrawSprite
_0801D5F0:
	add sp, #0x014
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0801D5F8: .4byte 0x02039B84
.syntax divided
