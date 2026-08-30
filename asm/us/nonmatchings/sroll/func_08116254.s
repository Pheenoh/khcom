.syntax unified
	.align 2, 0
	.global func_08116254
	.thumb
	.thumb_func
	.type func_08116254, %function
func_08116254: @ 08116254
	adds r2, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r2, #0x1C]
	lsls r0, r0, #0x03
	cmp r1, r0
	blt _08116264
	movs r1, #0x00
_08116264:
	strh r1, [r2, #0x20]
	bx lr
.syntax divided
