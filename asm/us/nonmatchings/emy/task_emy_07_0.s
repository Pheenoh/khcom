.syntax unified
	.align 2, 0
	.global task_emy_07_0
	.thumb
	.thumb_func
	.type task_emy_07_0, %function
task_emy_07_0: @ 08037D64
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r2, r1, #0x0
	ldr r1, _08037DA8 @ =0x0813D73C
	bl func_0800C778
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r4, #0x00
	movs r0, #0x00
	strh r0, [r1, #0x00]
	movs r1, #0xC3
	lsls r1, r1, #0x01
	adds r0, r5, r1
	strb r4, [r0, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x12
	str r0, [r1, #0x00]
	ldr r0, [r5, #0x70]
	ldr r1, [r5, #0x74]
	ldr r2, _08037DAC @ =0x00001000
	ldr r3, _08037DB0 @ =0x00000000
	orrs r0, r2
	str r0, [r5, #0x70]
	str r1, [r5, #0x74]
	ldr r1, _08037DB4 @ =0x00000187
	adds r0, r5, r1
	strb r4, [r0, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_08037DA8: .4byte 0x0813D73C
_08037DAC: .4byte 0x00001000
_08037DB0: .4byte 0x00000000
_08037DB4: .4byte 0x00000187
.syntax divided
