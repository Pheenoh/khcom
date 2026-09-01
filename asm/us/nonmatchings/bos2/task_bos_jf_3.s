.syntax unified
	.align 2, 0
	.global task_bos_jf_3
	.thumb
	.thumb_func
	.type task_bos_jf_3, %function
task_bos_jf_3: @ 080BD474
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0x93
	lsls r1, r1, #0x02
	adds r0, r4, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080BD498
	movs r1, #0x88
	lsls r1, r1, #0x01
	adds r0, r4, r1
	bl func_0801B7D8
	adds r0, r4, #0x0
	bl func_0801B7D8
_080BD498:
	movs r1, #0x95
	lsls r1, r1, #0x02
	adds r0, r4, r1
	bl TaskPoolDestroy
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
