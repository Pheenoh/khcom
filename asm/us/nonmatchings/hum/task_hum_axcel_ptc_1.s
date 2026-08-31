.syntax unified
	.align 2, 0
	.global task_hum_axcel_ptc_1
	.thumb
	.thumb_func
	.type task_hum_axcel_ptc_1, %function
task_hum_axcel_ptc_1: @ 08054294
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	adds r4, #0x0C
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080542B4
	adds r0, r4, #0x0
	bl AnimUpdate
	str r0, [r5, #0x08]
	movs r0, #0x01
	b _080542B6
_080542B4:
	movs r0, #0x00
_080542B6:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
