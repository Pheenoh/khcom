.syntax unified
	.align 2, 0
	.global func_08081838
	.thumb
	.thumb_func
	.type func_08081838, %function
func_08081838: @ 08081838
	ldr r0, _08081844 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xD4
	ldrb r0, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_08081844: .4byte 0x02039DD4
.syntax divided
