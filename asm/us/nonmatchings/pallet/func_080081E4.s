.syntax unified
	.align 2, 0
	.global func_080081E4
	.thumb
	.thumb_func
	.type func_080081E4, %function
func_080081E4: @ 080081E4
	ldr r3, _080081F0 @ =0x02039B70
	lsls r0, r0, #0x02
	adds r0, r0, r3
	strb r1, [r0, #0x00]
	strb r2, [r0, #0x01]
	bx lr
_080081F0: .4byte 0x02039B70
.syntax divided
