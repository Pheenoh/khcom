.syntax unified
	.align 2, 0
	.global task_poo_gauge_1
	.thumb
	.thumb_func
	.type task_poo_gauge_1, %function
task_poo_gauge_1: @ 080CC528
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldrh r0, [r4, #0x12]
	adds r0, #0x01
	strh r0, [r4, #0x12]
	ldrh r0, [r4, #0x12]
	bl func_080CC488
	ldr r1, _080CC558 @ =0x09EF5B2C
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x08]
	ldr r0, _080CC55C @ =0x0203C3E4
	ldrh r0, [r0, #0x00]
	cmp r0, #0x01
	bhi _080CC568
	ldr r0, _080CC560 @ =0x0203C3E0
	ldrh r1, [r0, #0x00]
	ldr r0, _080CC564 @ =0x000001CD
	cmp r1, r0
	bhi _080CC568
	movs r0, #0x01
	b _080CC56A
_080CC558: .4byte 0x09EF5B2C
_080CC55C: .4byte 0x0203C3E4
_080CC560: .4byte 0x0203C3E0
_080CC564: .4byte 0x000001CD
_080CC568:
	movs r0, #0x00
_080CC56A:
	strb r0, [r4, #0x10]
	ldrb r0, [r4, #0x10]
	cmp r0, #0x00
	beq _080CC58C
	ldr r0, [r4, #0x0C]
	ldr r5, _080CC5A8 @ =0x09849BB8
	cmp r0, r5
	beq _080CC586
	ldr r0, [r4, #0x04]
	ldrh r0, [r0, #0x06]
	adds r1, r5, #0x0
	bl func_08002BAC
	str r5, [r4, #0x0C]
_080CC586:
	ldrb r0, [r4, #0x10]
	cmp r0, #0x00
	bne _080CC5A0
_080CC58C:
	ldr r0, [r4, #0x0C]
	ldr r5, _080CC5AC @ =0x09849B98
	cmp r0, r5
	beq _080CC5A0
	ldr r0, [r4, #0x04]
	ldrh r0, [r0, #0x06]
	adds r1, r5, #0x0
	bl func_08002BAC
	str r5, [r4, #0x0C]
_080CC5A0:
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
_080CC5A8: .4byte 0x09849BB8
_080CC5AC: .4byte 0x09849B98
.syntax divided
