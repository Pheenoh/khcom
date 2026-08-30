.syntax unified
	.align 2, 0
	.global task_bos_dsd_3
	.thumb
	.thumb_func
	.type task_bos_dsd_3, %function
task_bos_dsd_3: @ 080C20E0
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r4, r6, r0
	movs r1, #0x88
	lsls r1, r1, #0x02
	adds r5, r6, r1
	movs r1, #0xDF
	lsls r1, r1, #0x02
	adds r0, r6, r1
	bl func_08000F0C
	movs r1, #0x98
	lsls r1, r1, #0x02
	adds r0, r6, r1
	bl func_08012304
	adds r0, r6, #0x0
	bl func_0801B7D8
	adds r0, r4, #0x0
	bl func_0801B7D8
	adds r0, r5, #0x0
	bl func_0801B7D8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
