.syntax unified
	.align 2, 0
	.global task_hum_leon_3
	.thumb
	.thumb_func
	.type task_hum_leon_3, %function
task_hum_leon_3: @ 08059C8C
	push {lr}
	ldr r1, _08059CC4 @ =0x02039BB0
	mov r12, r1
	movs r3, #0x86
	lsls r3, r3, #0x01
	add r3, r12
	movs r2, #0xC6
	lsls r2, r2, #0x01
	adds r1, r0, r2
	ldr r2, [r1, #0x04]
	ldr r1, [r1, #0x00]
	str r1, [r3, #0x00]
	str r2, [r3, #0x04]
	movs r3, #0x8A
	lsls r3, r3, #0x01
	add r3, r12
	movs r2, #0xCA
	lsls r2, r2, #0x01
	adds r1, r0, r2
	ldr r2, [r1, #0x04]
	ldr r1, [r1, #0x00]
	str r1, [r3, #0x00]
	str r2, [r3, #0x04]
	bl func_0800E380
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08059CC4: .4byte 0x02039BB0
.syntax divided
