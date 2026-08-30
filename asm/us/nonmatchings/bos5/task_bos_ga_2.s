.syntax unified
	.align 2, 0
	.global task_bos_ga_2
	.thumb
	.thumb_func
	.type task_bos_ga_2, %function
task_bos_ga_2: @ 080FB86C
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	movs r6, #0x00
	adds r4, r5, #0x0
	adds r4, #0x20
_080FB876:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080F83E0
	movs r0, #0xD4
	lsls r0, r0, #0x01
	adds r4, r4, r0
	adds r6, #0x01
	cmp r6, #0x05
	bls _080FB876
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
