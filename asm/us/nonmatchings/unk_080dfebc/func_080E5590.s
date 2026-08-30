.syntax unified
	.align 2, 0
	.global func_080E5590
	.thumb
	.thumb_func
	.type func_080E5590, %function
func_080E5590: @ 080E5590
	lsls r0, r0, #0x18
	ldr r1, _080E55A0 @ =0x02034F24
	lsrs r0, r0, #0x15
	ldr r1, [r1, #0x00]
	adds r1, r1, r0
	adds r0, r1, #0x0
	bx lr
	.byte 0x00, 0x00
_080E55A0: .4byte 0x02034F24
.syntax divided
