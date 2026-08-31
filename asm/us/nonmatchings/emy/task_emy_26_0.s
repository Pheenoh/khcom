.syntax unified
	.align 2, 0
	.global task_emy_26_0
	.thumb
	.thumb_func
	.type task_emy_26_0, %function
task_emy_26_0: @ 0803A9F0
	push {r4, lr}
	adds r4, r0, #0x0
	adds r2, r1, #0x0
	ldr r1, _0803AA24 @ =0x0813DE14
	bl func_0800C778
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0803AA28 @ =0x00001001
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0803AA2C @ =0xFFFFD000
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
_0803AA24: .4byte 0x0813DE14
_0803AA28: .4byte 0x00001001
_0803AA2C: .4byte 0xFFFFD000
.syntax divided
