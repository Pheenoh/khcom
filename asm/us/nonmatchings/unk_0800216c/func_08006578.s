.syntax unified
	.align 2, 0
	.global func_08006578
	.thumb
	.thumb_func
	.type func_08006578, %function
func_08006578: @ 08006578
	push {r4, lr}
	bl func_08006548
	bl func_08006554
	ldr r4, _080065A0 @ =0x02034030
	str r0, [r4, #0x00]
	bl func_08006554
	str r0, [r4, #0x04]
	bl func_08006554
	str r0, [r4, #0x08]
	bl func_08006554
	str r0, [r4, #0x0C]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080065A0: .4byte 0x02034030
.syntax divided
