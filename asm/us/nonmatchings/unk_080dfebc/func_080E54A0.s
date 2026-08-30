.syntax unified
	.align 2, 0
	.global func_080E54A0
	.thumb
	.thumb_func
	.type func_080E54A0, %function
func_080E54A0: @ 080E54A0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080E54B4 @ =0x02034F20
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
_080E54B4: .4byte 0x02034F20
.syntax divided
