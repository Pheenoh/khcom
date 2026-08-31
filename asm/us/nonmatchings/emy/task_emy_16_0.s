.syntax unified
	.align 2, 0
	.global task_emy_16_0
	.thumb
	.thumb_func
	.type task_emy_16_0, %function
task_emy_16_0: @ 08038BDC
	push {r4, lr}
	adds r4, r0, #0x0
	adds r2, r1, #0x0
	ldr r1, _08038C0C @ =0x0813D9CC
	bl func_0800C778
	movs r1, #0xC2
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r1, #0x00
	str r1, [r0, #0x00]
	movs r2, #0xC4
	lsls r2, r2, #0x01
	adds r0, r4, r2
	str r1, [r0, #0x00]
	movs r1, #0xC6
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r1, #0x02
	bl TaskPoolInit
	pop {r4}
	pop {r0}
	bx r0
_08038C0C: .4byte 0x0813D9CC
.syntax divided
