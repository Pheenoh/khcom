.syntax unified
	.align 2, 0
	.global task_bos_boogie_explosiondice_3
	.thumb
	.thumb_func
	.type task_bos_boogie_explosiondice_3, %function
task_bos_boogie_explosiondice_3: @ 080DA710
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x80
	bl func_08012304
	ldr r0, [r4, #0x08]
	bl func_080028C0
	ldr r0, [r4, #0x0C]
	bl func_08002C10
	ldr r0, [r4, #0x10]
	bl func_08002C10
	adds r4, #0x2C
	adds r0, r4, #0x0
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
