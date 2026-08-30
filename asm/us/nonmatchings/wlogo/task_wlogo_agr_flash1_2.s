.syntax unified
	.align 2, 0
	.global task_wlogo_agr_flash1_2
	.thumb
	.thumb_func
	.type task_wlogo_agr_flash1_2, %function
task_wlogo_agr_flash1_2: @ 080B664C
	push {r4, lr}
	add sp, #-0x010
	movs r1, #0x24
	ldsh r4, [r0, r1]
	movs r2, #0x26
	ldsh r1, [r0, r2]
	ldr r2, [r0, #0x08]
	ldr r3, [r0, #0x00]
	ldr r0, [r0, #0x04]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	str r0, [sp, #0x00C]
	adds r0, r4, #0x0
	bl func_080023E0
	add sp, #0x010
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
