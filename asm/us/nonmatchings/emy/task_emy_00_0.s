.syntax unified
	.align 2, 0
	.global task_emy_00_0
	.thumb
	.thumb_func
	.type task_emy_00_0, %function
task_emy_00_0: @ 08036BFC
	push {r4, lr}
	adds r4, r0, #0x0
	adds r2, r1, #0x0
	ldr r1, _08036C30 @ =0x0813D3CC
	bl func_0800C778
	movs r0, #0xAC
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldrh r1, [r2, #0x00]
	movs r0, #0x01
	orrs r0, r1
	strh r0, [r2, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x12
	str r0, [r1, #0x00]
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x16
	str r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_08036C30: .4byte 0x0813D3CC
.syntax divided
