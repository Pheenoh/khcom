.syntax unified
	.align 2, 0
	.global func_080D2D3C
	.thumb
	.thumb_func
	.type func_080D2D3C, %function
func_080D2D3C: @ 080D2D3C
	ldr r2, _080D2D4C @ =0x0203C470
	movs r1, #0x01
	lsls r1, r0
	ldrh r0, [r2, #0x28]
	orrs r1, r0
	strh r1, [r2, #0x28]
	bx lr
	.byte 0x00, 0x00
_080D2D4C: .4byte 0x0203C470
.syntax divided
