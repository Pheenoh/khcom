.syntax unified
	.align 2, 0
	.global task_emy_37_0
	.thumb
	.thumb_func
	.type task_emy_37_0, %function
task_emy_37_0: @ 0803C4E8
	push {r4, lr}
	adds r4, r0, #0x0
	adds r2, r1, #0x0
	ldr r1, _0803C528 @ =0x0813E264
	bl func_0800C778
	movs r0, #0xAC
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldrh r1, [r2, #0x00]
	movs r0, #0x01
	movs r3, #0x00
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
	movs r0, #0x1C
	str r0, [r1, #0x00]
	movs r1, #0xC2
	lsls r1, r1, #0x01
	adds r0, r4, r1
	strb r3, [r0, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0803C528: .4byte 0x0813E264
.syntax divided
