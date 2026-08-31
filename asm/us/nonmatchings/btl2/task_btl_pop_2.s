.syntax unified
	.align 2, 0
	.global task_btl_pop_2
	.thumb
	.thumb_func
	.type task_btl_pop_2, %function
task_btl_pop_2: @ 080308E4
	push {r4, r5, lr}
	add sp, #-0x014
	adds r4, r0, #0x0
	mov r5, sp
	adds r5, #0x12
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0x28]
	ldr r0, [r4, #0x2C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r5, r2]
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r4, [r4, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0x10
	str r4, [sp, #0x008]
	movs r4, #0x05
	str r4, [sp, #0x00C]
	bl DrawSprite
	add sp, #0x014
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
