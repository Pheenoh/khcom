.syntax unified
	.align 2, 0
	.global task_emy_04_0
	.thumb
	.thumb_func
	.type task_emy_04_0, %function
task_emy_04_0: @ 0803791C
	push {r4, lr}
	adds r4, r0, #0x0
	adds r2, r1, #0x0
	ldr r1, _0803794C @ =0x0813D5DC
	bl func_0800C778
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x07
	str r0, [r1, #0x00]
	movs r1, #0xC2
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r1, #0x00
	strb r1, [r0, #0x00]
	movs r2, #0xC3
	lsls r2, r2, #0x01
	adds r0, r4, r2
	strh r1, [r0, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0803794C: .4byte 0x0813D5DC
.syntax divided
