.syntax unified
	.align 2, 0
	.global task_btl_pop_1
	.thumb
	.thumb_func
	.type task_btl_pop_1, %function
task_btl_pop_1: @ 080308B4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x2C]
	subs r0, #0xC0
	str r0, [r4, #0x2C]
	ldrh r1, [r4, #0x30]
	movs r2, #0x30
	ldsh r0, [r4, r2]
	cmp r0, #0x31
	bgt _080308DA
	adds r0, r1, #0x1
	strh r0, [r4, #0x30]
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl AnimUpdate
	str r0, [r4, #0x08]
	movs r0, #0x01
	b _080308DC
_080308DA:
	movs r0, #0x00
_080308DC:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
