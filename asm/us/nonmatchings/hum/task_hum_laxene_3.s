.syntax unified
	.align 2, 0
	.global task_hum_laxene_3
	.thumb
	.thumb_func
	.type task_hum_laxene_3, %function
task_hum_laxene_3: @ 080523EC
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _08052410 @ =0x000002A2
	bl func_0811FF3C
	adds r0, r4, #0x0
	bl func_0800E380
	movs r0, #0xCA
	lsls r0, r0, #0x01
	adds r4, r4, r0
	adds r0, r4, #0x0
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08052410: .4byte 0x000002A2
.syntax divided
