.syntax unified
	.align 2, 0
	.global task_emy_28_0
	.thumb
	.thumb_func
	.type task_emy_28_0, %function
task_emy_28_0: @ 0803AEE8
	push {r4, lr}
	adds r4, r0, #0x0
	adds r2, r1, #0x0
	ldr r1, _0803AF1C @ =0x0813DF44
	bl func_0800C778
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0803AF20 @ =0x00001001
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0803AF24 @ =0xFFFFD000
	adds r0, r0, r1
	str r0, [r4, #0x48]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r4, r4, r0
	movs r0, #0x07
	str r0, [r4, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_0803AF1C: .4byte 0x0813DF44
_0803AF20: .4byte 0x00001001
_0803AF24: .4byte 0xFFFFD000
.syntax divided
