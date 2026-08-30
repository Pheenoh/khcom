.syntax unified
	.align 2, 0
	.global func_08076374
	.thumb
	.thumb_func
	.type func_08076374, %function
func_08076374: @ 08076374
	push {lr}
	ldr r1, _08076384 @ =0x02034A9C
	movs r0, #0x07
	str r0, [r1, #0x00]
	bl func_0807E248
	pop {r0}
	bx r0
_08076384: .4byte 0x02034A9C
	.byte 0x01, 0x49, 0x09, 0x20, 0x08, 0x60, 0x70, 0x47, 0x9C, 0x4A, 0x03, 0x02
.syntax divided
