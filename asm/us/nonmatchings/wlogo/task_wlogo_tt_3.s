.syntax unified
	.align 2, 0
	.global task_wlogo_tt_3
	.thumb
	.thumb_func
	.type task_wlogo_tt_3, %function
task_wlogo_tt_3: @ 080B75B0
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080B7664
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r4, r1
	bl func_08000F0C
	ldr r0, [r4, #0x08]
	bl func_080028C0
	ldr r0, [r4, #0x0C]
	bl func_080028C0
	ldr r0, [r4, #0x10]
	bl func_080028C0
	ldr r0, [r4, #0x14]
	bl func_080028C0
	ldr r0, [r4, #0x1C]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
