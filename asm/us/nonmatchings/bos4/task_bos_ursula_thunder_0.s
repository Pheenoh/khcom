.syntax unified
	.align 2, 0
	.global task_bos_ursula_thunder_0
	.thumb
	.thumb_func
	.type task_bos_ursula_thunder_0, %function
task_bos_ursula_thunder_0: @ 080DDD74
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _080DDD9C @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x7C]
	ldr r0, [r2, #0x04]
	str r0, [r4, #0x04]
	ldr r1, [r2, #0x08]
	str r1, [r4, #0x08]
	ldr r2, [r2, #0x0C]
	ldr r3, _080DDDA0 @ =0xFFFFA000
	adds r2, r2, r3
	str r2, [r4, #0x0C]
	bl func_08017390
	movs r0, #0x00
	strh r0, [r4, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_080DDD9C: .4byte 0x02039B84
_080DDDA0: .4byte 0xFFFFA000
.syntax divided
