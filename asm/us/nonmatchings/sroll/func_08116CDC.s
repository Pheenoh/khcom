.syntax unified
	.align 2, 0
	.global func_08116CDC
	.thumb
	.thumb_func
	.type func_08116CDC, %function
func_08116CDC: @ 08116CDC
	lsls r0, r0, #0x18
	ldr r1, _08116CE8 @ =0x09A5B470
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	bx lr
_08116CE8: .4byte 0x09A5B470
.syntax divided
