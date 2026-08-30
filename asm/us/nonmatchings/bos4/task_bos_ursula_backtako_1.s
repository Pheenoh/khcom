.syntax unified
	.align 2, 0
	.global task_bos_ursula_backtako_1
	.thumb
	.thumb_func
	.type task_bos_ursula_backtako_1, %function
task_bos_ursula_backtako_1: @ 080DD3A8
	push {r4, r5, lr}
	adds r4, r0, #0x0
	bl func_080DC628
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080DD3FE
	adds r0, r4, #0x0
	adds r0, #0x2C
	adds r1, r4, #0x0
	adds r1, #0x30
	adds r2, r4, #0x0
	adds r2, #0x34
	adds r3, r4, #0x0
	bl func_080DD248
	movs r1, #0x00
	adds r5, r4, #0x0
	adds r5, #0x22
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	bne _080DD3D6
	movs r1, #0x01
_080DD3D6:
	strb r1, [r5, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x38
	adds r1, r4, #0x0
	adds r1, #0x3C
	adds r2, r4, #0x0
	adds r2, #0x40
	adds r3, r4, #0x0
	bl func_080DD248
	movs r1, #0x00
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	bne _080DD3F4
	movs r1, #0x01
_080DD3F4:
	strb r1, [r5, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x08
	bl func_08005A64
_080DD3FE:
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
