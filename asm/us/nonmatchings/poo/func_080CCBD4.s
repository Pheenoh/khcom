.syntax unified
	.align 2, 0
	.global func_080CCBD4
	.thumb
	.thumb_func
	.type func_080CCBD4, %function
func_080CCBD4: @ 080CCBD4
	push {lr}
	adds r0, #0x0C
	ldr r1, _080CCBE4 @ =0x02034DF8
	bl func_08000D90
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CCBE4: .4byte 0x02034DF8
.syntax divided
