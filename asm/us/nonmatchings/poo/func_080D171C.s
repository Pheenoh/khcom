.syntax unified
	.align 2, 0
	.global func_080D171C
	.thumb
	.thumb_func
	.type func_080D171C, %function
func_080D171C: @ 080D171C
	ldr r1, _080D1728 @ =0x02034E36
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_080D1728: .4byte 0x02034E36
.syntax divided
