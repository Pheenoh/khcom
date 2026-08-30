.syntax unified
	.align 2, 0
	.global func_080BA0F8
	.thumb
	.thumb_func
	.type func_080BA0F8, %function
func_080BA0F8: @ 080BA0F8
	push {lr}
	adds r0, #0x40
	bl func_08012304
	pop {r0}
	bx r0
.syntax divided
