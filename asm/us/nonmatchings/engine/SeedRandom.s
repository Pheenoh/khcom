.syntax unified
	.align 2, 0
	.global SeedRandom
	.thumb
	.thumb_func
	.type SeedRandom, %function
SeedRandom: @ 08006578
	push {r4, lr}
	bl SeedRand
	bl Rand
	ldr r4, _080065A0 @ =0x02034030
	str r0, [r4, #0x00]
	bl Rand
	str r0, [r4, #0x04]
	bl Rand
	str r0, [r4, #0x08]
	bl Rand
	str r0, [r4, #0x0C]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080065A0: .4byte 0x02034030
.syntax divided
