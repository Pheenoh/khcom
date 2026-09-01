.syntax unified
	.align 2, 0
	.global func_0801E508
	.thumb
	.thumb_func
	.type func_0801E508, %function
func_0801E508: @ 0801E508
	push {lr}
	str r1, [r0, #0x38]
	adds r0, #0x40
	bl func_0801AF08
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
