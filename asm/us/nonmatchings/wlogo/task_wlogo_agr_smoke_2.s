.syntax unified
	.align 2, 0
	.global task_wlogo_agr_smoke_2
	.thumb
	.thumb_func
	.type task_wlogo_agr_smoke_2, %function
task_wlogo_agr_smoke_2: @ 080B64B0
	push {r4, lr}
	add sp, #-0x010
	ldr r4, [r0, #0x24]
	lsls r4, r4, #0x08
	asrs r4, r4, #0x10
	ldr r1, [r0, #0x28]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, [r0, #0x08]
	ldr r3, [r0, #0x00]
	ldr r0, [r0, #0x04]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x01
	str r0, [sp, #0x00C]
	adds r0, r4, #0x0
	bl func_080023E0
	add sp, #0x010
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
