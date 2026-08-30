.syntax unified
	.align 2, 0
	.global task_emy_08_2
	.thumb
	.thumb_func
	.type task_emy_08_2, %function
task_emy_08_2: @ 080387D4
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0xC6
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080387EE
	movs r1, #0xC2
	lsls r1, r1, #0x01
	b _080387F2
_080387EE:
	movs r1, #0xC4
	lsls r1, r1, #0x01
_080387F2:
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	bl func_0800DF30
	movs r1, #0xC4
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x04]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
