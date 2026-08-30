.syntax unified
	.align 2, 0
	.global task_sroll_tmr_1
	.thumb
	.thumb_func
	.type task_sroll_tmr_1, %function
task_sroll_tmr_1: @ 081152D4
	push {r4, r5, lr}
	adds r4, r0, #0x0
	movs r5, #0x01
	bl func_08001390
	movs r1, #0x04
	ands r1, r0
	cmp r1, #0x00
	beq _081152F4
	ldrb r0, [r4, #0x00]
	cmp r0, #0x01
	bne _081152F2
	movs r0, #0x00
	strb r0, [r4, #0x00]
	b _081152F4
_081152F2:
	strb r5, [r4, #0x00]
_081152F4:
	ldr r0, [r4, #0x0C]
	ldrh r1, [r0, #0x06]
	movs r0, #0x0F
	ands r0, r1
	adds r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, [r4, #0x04]
	adds r0, #0x01
	str r0, [r4, #0x04]
	adds r0, r5, #0x0
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
