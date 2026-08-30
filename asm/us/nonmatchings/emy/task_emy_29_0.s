.syntax unified
	.align 2, 0
	.global task_emy_29_0
	.thumb
	.thumb_func
	.type task_emy_29_0, %function
task_emy_29_0: @ 0803B420
	push {r4, lr}
	adds r4, r0, #0x0
	adds r2, r1, #0x0
	ldr r1, _0803B464 @ =0x0813DFCC
	bl func_0800C778
	movs r0, #0xB6
	lsls r0, r0, #0x01
	adds r1, r4, r0
	adds r0, #0x14
	str r0, [r1, #0x00]
	subs r0, #0x30
	adds r1, r4, r0
	movs r0, #0x07
	str r0, [r1, #0x00]
	movs r1, #0xAC
	lsls r1, r1, #0x01
	adds r2, r4, r1
	ldrh r1, [r2, #0x00]
	movs r0, #0x01
	movs r3, #0x00
	orrs r0, r1
	strh r0, [r2, #0x00]
	movs r1, #0xC2
	lsls r1, r1, #0x01
	adds r0, r4, r1
	strh r3, [r0, #0x00]
	adds r1, #0x02
	adds r0, r4, r1
	strh r3, [r0, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0803B464: .4byte 0x0813DFCC
.syntax divided
