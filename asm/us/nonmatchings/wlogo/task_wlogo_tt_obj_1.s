.syntax unified
	.align 2, 0
	.global task_wlogo_tt_obj_1
	.thumb
	.thumb_func
	.type task_wlogo_tt_obj_1, %function
task_wlogo_tt_obj_1: @ 080B76D4
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x24]
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r0, r1
	str r0, [r4, #0x24]
	adds r5, r4, #0x0
	adds r5, #0x0C
	adds r0, r5, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080B76FE
	adds r0, r5, #0x0
	bl AnimUpdate
	str r0, [r4, #0x08]
	movs r0, #0x01
	b _080B7700
_080B76FE:
	movs r0, #0x00
_080B7700:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
