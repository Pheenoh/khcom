.syntax unified
	.align 2, 0
	.global task_bos_ursula_mapanime_0
	.thumb
	.thumb_func
	.type task_bos_ursula_mapanime_0, %function
task_bos_ursula_mapanime_0: @ 080DD4C4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _080DD4EC @ =0x02034F10
	str r4, [r0, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x10
	movs r1, #0x01
	bl func_08000E64
	movs r0, #0x00
	str r0, [r4, #0x24]
	movs r0, #0x04
	str r0, [r4, #0x0C]
	movs r0, #0x00
	bl func_080DD69C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DD4EC: .4byte 0x02034F10
.syntax divided
