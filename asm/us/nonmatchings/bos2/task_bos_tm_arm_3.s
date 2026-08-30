.syntax unified
	.align 2, 0
	.global task_bos_tm_arm_3
	.thumb
	.thumb_func
	.type task_bos_tm_arm_3, %function
task_bos_tm_arm_3: @ 080BCB70
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	bl func_080028C0
	movs r1, #0x8E
	lsls r1, r1, #0x02
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	ldr r0, [r4, #0x08]
	bl func_08002C10
	movs r1, #0xDA
	lsls r1, r1, #0x01
	adds r0, r4, r1
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
