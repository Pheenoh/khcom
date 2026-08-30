.syntax unified
	.align 2, 0
	.global func_080D1710
	.thumb
	.thumb_func
	.type func_080D1710, %function
func_080D1710: @ 080D1710
	ldr r0, _080D1718 @ =0x02034E34
	ldrh r0, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_080D1718: .4byte 0x02034E34
.syntax divided
