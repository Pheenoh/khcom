.syntax unified
	.align 2, 0
	.global task_hum_leon_0
	.thumb
	.thumb_func
	.type task_hum_leon_0, %function
task_hum_leon_0: @ 080598E4
	push {r4, r5, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	ldr r1, _08059954 @ =0x0813FDA8
	bl func_0800E168
	movs r0, #0xC4
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r2, #0x00
	movs r0, #0x00
	strh r0, [r1, #0x00]
	movs r1, #0xC5
	lsls r1, r1, #0x01
	adds r0, r5, r1
	strb r2, [r0, #0x00]
	ldr r0, _08059958 @ =0x0813FD58
	adds r1, r5, #0x0
	adds r1, #0x14
	ldr r2, [r5, #0x04]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x01
	bl func_08019068
	movs r0, #0xC6
	lsls r0, r0, #0x01
	adds r2, r5, r0
	ldr r3, _0805995C @ =0x02039BB0
	movs r1, #0x86
	lsls r1, r1, #0x01
	adds r4, r3, r1
	ldr r0, [r4, #0x00]
	ldr r1, [r4, #0x04]
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	movs r0, #0xCA
	lsls r0, r0, #0x01
	adds r2, r5, r0
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r3, r3, r1
	ldr r0, [r3, #0x00]
	ldr r1, [r3, #0x04]
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	movs r0, #0x00
	movs r1, #0x00
	str r0, [r4, #0x00]
	str r1, [r4, #0x04]
	str r0, [r3, #0x00]
	str r1, [r3, #0x04]
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
_08059954: .4byte 0x0813FDA8
_08059958: .4byte 0x0813FD58
_0805995C: .4byte 0x02039BB0
.syntax divided
