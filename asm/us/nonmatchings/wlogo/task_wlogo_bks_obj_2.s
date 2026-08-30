.syntax unified
	.align 2, 0
	.global task_wlogo_bks_obj_2
	.thumb
	.thumb_func
	.type task_wlogo_bks_obj_2, %function
task_wlogo_bks_obj_2: @ 080B7E10
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r1, [r5, #0x3C]
	ldr r2, [r5, #0x40]
	movs r0, #0x00
	movs r3, #0x01
	bl func_08002CB4
	adds r6, r0, #0x0
	ldr r0, [r5, #0x2C]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r5, #0x30]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	movs r4, #0x00
	str r4, [sp, #0x008]
	adds r5, #0x48
	ldrh r4, [r5, #0x00]
	str r4, [sp, #0x00C]
	bl func_080023E0
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
