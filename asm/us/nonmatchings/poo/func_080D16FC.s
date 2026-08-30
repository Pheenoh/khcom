.syntax unified
	.align 2, 0
	.global func_080D16FC
	.thumb
	.thumb_func
	.type func_080D16FC, %function
func_080D16FC: @ 080D16FC
	ldr r1, _080D170C @ =0x02034E34
	ldrh r0, [r1, #0x00]
	cmp r0, #0x0D
	bhi _080D1708
	adds r0, #0x01
	strh r0, [r1, #0x00]
_080D1708:
	bx lr
	.byte 0x00, 0x00
_080D170C: .4byte 0x02034E34
.syntax divided
