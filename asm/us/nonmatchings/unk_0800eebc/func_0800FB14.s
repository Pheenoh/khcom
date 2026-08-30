.syntax unified
	.align 2, 0
	.global func_0800FB14
	.thumb
	.thumb_func
	.type func_0800FB14, %function
func_0800FB14: @ 0800FB14
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x35
	bhi _0800FB28
	lsls r0, r0, #0x03
	ldr r1, _0800FB24 @ =0x08133E5C
	adds r0, r0, r1
	b _0800FB2A
_0800FB24: .4byte 0x08133E5C
_0800FB28:
	movs r0, #0x00
_0800FB2A:
	bx lr
.syntax divided
