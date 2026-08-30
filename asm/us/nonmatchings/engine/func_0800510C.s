.syntax unified
	.align 2, 0
	.global func_0800510C
	.thumb
	.thumb_func
	.type func_0800510C, %function
func_0800510C: @ 0800510C
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	lsls r4, r2, #0x10
	lsrs r4, r4, #0x10
	bl func_08004FC8
	adds r0, r5, #0x0
	bl func_0800514C
	adds r1, r0, #0x0
	adds r0, r6, #0x0
	adds r2, r4, #0x0
	bl func_080043B4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
